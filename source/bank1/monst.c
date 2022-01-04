//**********************************************************************
//**********************************************************************
//
//                        Attacking Monsters Code
//
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"


static int _MONSTAttack(MONSTER *,PLAYER *);
static int _MONSTSteal(MONSTER *,PLAYER *);
static void _MONSTMove(MONSTER *,PLAYER *,DUNGEONMAP *);
static int _MONSTCanMoveTo(DUNGEONMAP *,int,int);

//**********************************************************************
//
//                        Check Monsters Attacking
//
//**********************************************************************

void MONSTAttack(PLAYER *p,DUNGEONMAP *d)
{
	int i,Attacked;
	int Dist;
	MONSTER *m;
	for (i = 0;i < d->MonstCount;i++)            // Go through all monsters
	{
		m = &(d->Monster[i]);                    // Pointer to monster
		signed int d1 = ABS(m->Loc.x-p->Dungeon.x);
		signed int d2 = ABS(m->Loc.y-p->Dungeon.y);
		
		Dist = MAX(d1,d2);
		Dist = d1+d2; // must be 90° to player and only one position away!
		if (m->Alive != 0)                        // If alive
		{
			Attacked = 0;
			if (Dist == 1) Attacked = _MONSTAttack(m,p);                    // If within range
			
			if (Attacked == 0)                // If didn't attack, then move
			{
				if (m->Type != MN_MIMIC || Dist >= 4)  // Mimics only if near enough
				
				_MONSTMove(m,p,d);
				if (m->Strength <   (p->Level * ((unsigned int)p->Skill)))          // Recovers if didn't attack
				
				m->Strength = m->Strength+p->Level;
			}
		}
	}
}

//**********************************************************************
//
//                            Monster Attacks
//
//**********************************************************************

static int _MONSTAttack(MONSTER *m,PLAYER *p)
{
	int n;
	
	if (m->Type == MN_GREMLIN ||  m->Type == MN_THIEF)      // Special case for Gremlin/Thief
	
	if (RandMax(100) > 50)   return _MONSTSteal(m,p);         // Half the time
	
	
	n = (int) RandMax(20);                    // Calculate hit chance
	if (p->Object[OB_SHIELD] > 0) n--;
	n = (int)( ((long unsigned int )n) - p->Attr[AT_STAMINA]);
	n = (int)(((unsigned int)n) + m->Type + p->Level);
	if (n < 0)                            // Missed !
	{
		_fs("% attacks you, it missed!",GLOMonsterName(m->Type));
	}
	else                                // Hit !
	{
		n =  (int)RandMax(m->Type);            // Calculate damage done.
		n = n +  (int)p->Level;
		p->Attr[AT_HP] -= (long unsigned int)n;            // Adjust hit points
		UPDATE_HP(p->Attr[AT_HP]);
		//        DRAWText("Hit !!!\n");
		
		if (((signed long int) (p->Attr[AT_HP])) < (signed long int)0)
		{
			_fs("Killed by %!",GLOMonsterNameAttribute((int)m->Type));
		}
		else
		{
			_fs("% attacks you, HIT!",GLOMonsterName(m->Type));
		}
	}
	print_timed(stringBuffer40);
	return 1;
}

//**********************************************************************
//
//                                Monster Moves
//
//**********************************************************************

static void _MONSTMove(MONSTER *m,PLAYER *p,DUNGEONMAP *d)
{
	int xi,yi,x,y;
	
	xi = yi = 0;                        // Calculate direction
	if (p->Dungeon.x != m->Loc.x)
	xi = (p->Dungeon.x > m->Loc.x) ? 1 : -1;
	if (p->Dungeon.y != m->Loc.y)
	yi = (p->Dungeon.y > m->Loc.y) ? 1 : -1;
	
	// Running away
	if (m->Strength < (unsigned int) (((int)p->Level) * p->Skill)   )
	{
		xi = -xi;yi = -yi;
	}
	x = (int)m->Loc.x;
    y = (int)m->Loc.y;            // Get position
	
	if (ABS(xi) > ABS(yi))                // Check move okay
	{
		if (_MONSTCanMoveTo(d,x+xi,yi)) yi = 0;
		else if (_MONSTCanMoveTo(d,x,y+yi)) xi = 0;
	}
	else
	{
		if (_MONSTCanMoveTo(d,x,y+yi)) xi = 0;
		else if (_MONSTCanMoveTo(d,x+xi,yi)) yi = 0;
	}
	if (xi == 0 && yi == 0) return;        // No move
	x = x + xi;y = y + yi;                // Work out new position
	if (_MONSTCanMoveTo(d,x,y) == 0)    // Fail if can't move there
	return;
	if (x == (int)p->Dungeon.x && y == (int)p->Dungeon.y)           // Can't move onto us
	 return;
	m->Loc.x = (unsigned int) x;
    m->Loc.y = (unsigned int) y;            // Move to new position
}

//**********************************************************************
//
//                        Can monster move to a square
//
//**********************************************************************

static int _MONSTCanMoveTo(DUNGEONMAP *d,int x,int y)
{
	COORD c;
	unsigned int t = d->Map[x][y];                // See what's there
	if (!ISWALKTHRU(t)) return 0;        // Can't walk through walls
	c.x = (unsigned int) x;
    c.y = (unsigned int) y;                    // Set up coord structure
	return DDRAWFindMonster(d,&c) < 0;    // True if no monster here
}

//**********************************************************************
//
//                            Monster Stealing
//
//**********************************************************************

static int _MONSTSteal(MONSTER *m,PLAYER *p)
{
	int n;
	
	if (m->Type == MN_GREMLIN)            // Gremlin
	{
		p->Object[OB_FOOD] = p->Object[OB_FOOD]/2;           // HALVES the food.... aargh
		UPDATE_FOOD(p->Object[OB_FOOD]);
		print_timed("A Gremlin stole some food.");
	}
	
	if (m->Type == MN_THIEF)            // Thief
	{
		do                               // Figure out what stolen
		n = (int) RandMax(p->Objects);
		while (p->Object[n] == 0);
		p->Object[n]--;                    // Stole one
		//        s2 = GLOObjName(n);s1 = "a";
		//        if (strchr("aeiou",tolower(*s2))) s1 = "an";
		//        if (n == 0) s1 = "some";
		//        DRAWText("A Thief stole %s %s.\n",s1,s2);
		if (n == 1)     print_timed("A Thief stole a Rapier!");
		if (n == 2)     print_timed("A Thief stole an Axe!");
		if (n == 3)     print_timed("A Thief stole a Shield!");
		if (n == 4)     print_timed("A Thief stole a Bow+Arrow!");
		if (n == 5)     print_timed("A Thief stole an Amulet!");
	}
	return 1;
}
