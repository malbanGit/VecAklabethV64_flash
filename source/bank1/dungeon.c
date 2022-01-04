//**********************************************************************
//**********************************************************************
//																		
//					  Dungeon Create and Draw Code						
//																		
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"


static unsigned char _DUNGEONContents(unsigned char);
static void _DUNGEONAddMonster(DUNGEONMAP *,PLAYER *,int);

//**********************************************************************
//																		
//							Create Dungeon Level						
//																		
//**********************************************************************

void DUNGEONCreate(PLAYER *p,DUNGEONMAP *d)
{
	int i,n;
     unsigned int Size,x,y;
    setRandSeed((unsigned int)(p->LuckyNumber - p->World.x - p->World.y*10 - p->Level));
    
    
	Size=(unsigned int)(MAINSuper()?DUNGEON_MAP_SIZE-1:10);	// Calculate map size 
	d->MapSize = Size;						// Save the map size 

	for (x = 0;x < Size;x++)        		// Clear the dungeon 
		for (y = 0;y < Size;y++)
			d->Map[x][y] = DT_SPACE;

	for (x = 0;x <= Size;x++)				// Draw the boundaries 
	{
		d->Map[Size][x] = DT_SOLID;
		d->Map[0][x] = DT_SOLID;
		d->Map[x][Size] = DT_SOLID;
		d->Map[x][0] = DT_SOLID;
	}
	for (x = 2;x < Size;x = x+2)			// Fill with checkerboard 
		for (y = 1;y < Size;y++)
		{
		d->Map[x][y] = DT_SOLID;
		d->Map[y][x] = DT_SOLID;
		}
	for (x = 2;x < Size;x = x+2)			// Fill with stuff 
		for (y = 1;y < Size;y = y+2)
		{
			d->Map[x][y] = _DUNGEONContents(d->Map[x][y]);
			d->Map[y][x] = _DUNGEONContents(d->Map[y][x]);
		}

		d->Map[2][1] = DT_SPACE;			// Put stairs in 
		if (p->Level % 2 == 0)				// Different ends each level 
		{
			d->Map[Size-3][3] = DT_LADDERDN;
			d->Map[3][Size-3] = DT_LADDERUP;
		}
		else
		{
			d->Map[Size-3][3] = DT_LADDERUP;
			d->Map[3][Size-3] = DT_LADDERDN;
		}

		if (p->Level == 1)					// On first floor 
		{
			d->Map[1][1] = DT_LADDERUP;		// Ladder at top left 
			d->Map[Size-3][3] = DT_SPACE;	// No other ladder up 
		}

		d->MonstCount = 0;					// No monsters 
		n = MAINSuper() ? MAX_MONSTERS:10;	// How many might there be ? 
		for (i = 1;i <= n;i++)				// Go through the monsters 
				_DUNGEONAddMonster(d,p,i);	// Maybe adding them as you go 
}

//**********************************************************************
//																		
//							Generate some contents						
//																		
//**********************************************************************

static unsigned char _DUNGEONContents(unsigned char c)
{
    /*
	if (RND() > .95) 	c= DT_TRAP;
	if (RND() > .6) 	c= DT_HIDDENDOOR;
	if (RND() > .6) 	c= DT_DOOR;
	if (RND() > .97) 	c= DT_PIT;
	if (RND() > .94) 	c= DT_GOLD;
    */
 //   There is non such a thing a s atrap
//	if (Rand() > (unsigned int)(255*0.95) ) 	c= DT_TRAP;
	if (Rand() > (unsigned int)(255*0.95)) 	c= DT_TRAP; // not seen
	if (Rand() > (unsigned int)(255*0.6)) 	c= DT_HIDDENDOOR;
	if (Rand() > (unsigned int)(255*0.6)) 	c= DT_DOOR;
	if (Rand() > (unsigned int)(255*0.97)) 	c= DT_PIT; // seen
	if (Rand() > (unsigned int)(255*0.94)) 	c= DT_GOLD;
    /*
540 IF RND>.95 THEN DN%(X,Y)=2
541 IF RND>.95 THEN DN%(Y,X)=2
542 IF RND>.6 THEN DN%(Y,X)=3
543 IF RND>.6 THEN DN%(X,Y)=3
544 IF RND>.6 THEN DN%(X,Y)=4
545 IF RND>.6 THEN DN%(Y,X)=4
546 IF RND>.97 THEN DN%(Y,X)=9
547 IF RND>.97 THEN DN%(X,Y)=9
548 IF RND>.94 THEN DN%(X,Y)=5
549 IF RND>.94 THEN DN%(Y,X)=5    
    */
    
	return c;
}

//**********************************************************************
//																		
//					Maybe add a monster of the given type				
//																		
//**********************************************************************

static void _DUNGEONAddMonster(DUNGEONMAP *d,PLAYER *p,int Type)
{
	MONSTER *m;
	unsigned int x,y;
	unsigned int Level = GLOMonsterLevel((unsigned int)Type);		// Read the level 

	if (   (signed int)(Level - 2) > ((signed int)(p->Level)) ) return;		// Limit monsters to levels 
	if (Rand() > (unsigned int)(255*0.4)) return;				// Not always there anyway 

	m = &(d->Monster[(d->MonstCount)++]);	// Get monster record 

	m->Type = (unsigned int)Type;							// Fill in details 
	m->Strength = Level + 3 + p->Level;
	m->Alive = 1;

	do  									// Find a place for it 
	{
		x = RandMax(d->MapSize);
		y = RandMax(d->MapSize);
	} while (d->Map[x][y] != DT_SPACE || (x == p->Dungeon.x && y == p->Dungeon.y)); // Must be empty, not player 

	m->Loc.x = x;m->Loc.y = y;				// Record position 
}



