//**********************************************************************
//**********************************************************************
//
//                        Moving and Entry/Exit Code
//
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"



extern void subBank0(int); 
#define introImage() subBank0(0)
#define TOWNEnter() subBank0(1)


// **********************************************************************
//
//                                Movement code
//
// **********************************************************************

void MOVEMove(int c,WORLDMAP *w,PLAYER *p,DUNGEONMAP *d, int xi,int yi)
{
	int x1,y1,Moved;
	unsigned int z;
	double n;
	COORD New;
	if (p->Level == 0)                        // If above ground in world map
	{
		x1 = (int) (p->World.x) + xi;                // Calculate new position
		y1 = (int) (p->World.y) + yi;
		if (WORLDRead(w,x1,y1) == WT_MOUNTAIN)
		{
			print_timed("You can't pass the mountains.");
		}
		else
		{
			p->World.x = (unsigned int) x1;                // Move
			p->World.y = (unsigned int) y1;
		}
	}
	
	else                                    // If in the dungeon
	{
		switch(c)
		{
			case 'N':
			x1 = (int)(p->Dungeon.x + p->DungDir.x);
			y1 = (int)(p->Dungeon.y + p->DungDir.y);
			New.x = (unsigned int)x1;
			New.y = (unsigned int)y1;
			if (ISWALKTHRU(d->Map[x1][y1]) && DDRAWFindMonster(d,&New) < 0)
			{
				Moved = 1;
				p->Dungeon = New;
			}
			else if ( DDRAWFindMonster(d,&New) >= 0)
			{
				print_timed("A monster blocks your way!");
			}
			else
			{
				print_timed("You bang your head on the wall!");
			}
			break;
			
			case 'E':
			MOVERotLeft(&(p->DungDir));
			MOVERotLeft(&(p->DungDir));
			MOVERotLeft(&(p->DungDir));
			break;
			case 'W':
			MOVERotLeft(&(p->DungDir));
			break;
			case 'S':
			MOVERotLeft(&(p->DungDir));
			MOVERotLeft(&(p->DungDir));
			break;
		}
		
		if (Moved != 0)
		{
			n = d->Map[p->Dungeon.x][p->Dungeon.y];        // What's here ?
			
			if (n == DT_TRAP)                // Fell in a pit
			{
				p->Level++;                    // Down a level
				p->Attr[AT_HP] -=    (3+Rand() % (3*p->Level));        // It hurts !
				
				UPDATE_HP(p->Attr[AT_HP]);
				
				if (((signed long int ) (p->Attr[AT_HP])) < 0)
				{
					_fs("Killed by fall thru a %!","trap!");
				}
				else
				{
					_fi("Aarghh! A Trap! Falling to Level %.",p->Level);
				}
				
				
				WAIT(25);
				print_timed(stringBuffer40);
				DUNGEONCreate(p,d);            // Create the new level
			}
			if (n == DT_PIT)                // Fell in a pit
			{
				p->Level++;                    // Down a level
				// climbing down does not hurt
				//                p->Attr[AT_HP] -=    (3+Rand() % (3*p->Level));        // It hurts !
				//                DRAWText("Falling to Level %d.\n",p->Level);
				_fi("You climb down to level %.",p->Level);
				print_timed(stringBuffer40);
				DUNGEONCreate(p,d);            // Create the new level
			}
			if (n == DT_GOLD)                // Gold here
			{
				d->Map[p->Dungeon.x] [p->Dungeon.y] = 0;       // Remove the gold
				
				unsigned int go = (Rand() % (5*p->Level)) + p->Level;  // Calculate amount
				p->Attr[AT_GOLD] += go;        // Add to total
				UPDATE_GOLD(p->Attr[AT_GOLD]);
				if (go >0)
				{
					z = Rand()%(p->Objects);// Decide which object
					p->Object[z]++;            // Bump the total
					if (z == 0) _fi("Treasure! % gold and some food!",p->Level);
					if (z == 1) _fi("Treasure! % gold and a Rapier!",p->Level);
					if (z == 2) _fi("Treasure! % gold and an Axe!",p->Level);
					if (z == 3) _fi("Treasure! % gold and a shield!",p->Level);
					if (z == 4) _fi("Treasure! % gold and a Bow+Arrow!",p->Level);
					if (z == 5) _fi("Treasure! % gold and an Amulet!",p->Level);
					print_timed(stringBuffer40);
					
				}
			}
		}
		MONSTAttack(p,d);                    // Monster attacks ?
	}
	
	n = p->Object[OB_FOOD];
	
	if (p->Level > 0)
	{
		tenthFood++;
		if (tenthFood>=10)
		{
			tenthFood = 0;
			p->Object[OB_FOOD] = p->Object[OB_FOOD] -  1;    // Consume some food
			UPDATE_FOOD(p->Object[OB_FOOD]);
		}
	}
	else
	{
		p->Object[OB_FOOD] = p->Object[OB_FOOD] -  1;    // Consume some food
		UPDATE_FOOD(p->Object[OB_FOOD]);
	}
	
	if ( ((signed long int)p->Object[OB_FOOD]) <= 0)            // Starved us ?
	{
		print_timed("You have starved...");
		messageTime= 255;
		p->Attr[AT_HP] = 0;                    // Dead
	}
}


//**********************************************************************
//
//                            Handle entry,exit
//
//**********************************************************************

void MOVEEnterExit(WORLDMAP *w,PLAYER *p,DUNGEONMAP *d)
{
	unsigned int t;
	int Done = 0;
	if (p->Level == 0)                    // Entry/Exit on world map
	{
		t = WORLDRead(w,(int)p->World.x,    (int)p->World.y);    // Read tile
		
		Done = 1;
		switch(t)
		{
			case WT_TOWN:                    // Enter the town
			print_timed("Enter Town.");
			TOWNEnter();
			break;
			case WT_DUNGEON:                // Enter the dungeon
			print_timed("Enter Dungeon.");
			p->Level = 1;                // Go to level 1
			p->Dungeon.x = 1;            // Set initial position
			p->Dungeon.y = 1;
			p->DungDir.x = 1;            // And direction
			p->DungDir.y = 0;
			DUNGEONCreate(p,d);            // Create the dungeon map
			break;
			case WT_BRITISH:                // Enter the castle
			print_timed("Enter Castle.");
			BRITISHEnter(w,p);
			break;
			default:                           // Nope....
			Done = 0;break;
		}
	}
	else                                // Entry/Exit in dungeons
	{
		t = d->Map[p->Dungeon.x]        // Identify what's there
		[p->Dungeon.y];
		if (t == DT_LADDERUP)            // Climbing up a ladder
		{
			p->Level--;
			Done = 1;
			if (p->Level == 0)
			{
				//                print_timed("Leave the Dungeon.");
				//                 printfi("Thou has gained %d hit points.\n",p->HPGain);
				
				
				_fi("Leaving! Thou has gained % HP.",p->HPGain);
				WAIT(25);
				print_timed(stringBuffer40); messageTime=75;
				p->Attr[AT_HP] += p->HPGain;
				UPDATE_HP(p->Attr[AT_HP]);
				p->HPGain = 0;
				// due to memory reasons -> recreate the world
				WORLDCreate(p,w);            // Create the over world
			}
			else
			//            DRAWText("Go up to Level %d.\n",p->Level);
			{
				_fi("Go up to Level %.",p->Level);
				print_timed(stringBuffer40);
			}
		}
		if (t == DT_LADDERDN)            // Climbing down a ladder
		{
			p->Level++;
			Done = 1;
			//            DRAWText("Go down to Level %d.\n",p->Level);
			_fi("Go down to Level %.",p->Level);
			print_timed(stringBuffer40);
		}
		if (Done != 0 && p->Level > 0)    // New Dungeon Map Required
		DUNGEONCreate(p,d);
	}
	if (Done == 0)                       // Can't do it
	print_timed("Huh???");
}

// **********************************************************************
//
//                        Rotate a direction left
//
// **********************************************************************

void MOVERotLeft(COORD *Dir)
{
	if (Dir->y == 0)
	{
		Dir->y = -Dir->x;
		Dir->x = 0;
	}
	else
	{
		Dir->x = Dir->y;
		Dir->y = 0;
	}
}
