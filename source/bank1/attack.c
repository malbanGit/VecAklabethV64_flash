//**********************************************************************
//**********************************************************************
//
//                        Attack any nearby monsters
//
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"



static void _ATTACKWeapon(PLAYER *,DUNGEONMAP *,unsigned int);
static int  _ATTACKMissile(PLAYER *,DUNGEONMAP *,unsigned int);
static void _ATTACKKill(MONSTER *,PLAYER *);
static void _ATTACKAmulet(PLAYER *,DUNGEONMAP *);
static void _ATTACKHitMonster(PLAYER *,DUNGEONMAP *,unsigned int,COORD *);

//**********************************************************************
//
//                    Attack any nearby monsters
//
//**********************************************************************

void ATTACKMonster(PLAYER *p,DUNGEONMAP *d)
{
//	int c,Key,i,n,Damage;
	int n,Damage;
	
	// wait for button release / debounce
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		check_buttons();
		
		Intensity_a(0x5f); // set intensity of vector beam...
		DDRAWDraw(p,d);
		//        VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
		//        Print_Str_d(-128+5+6, -128, (void* const) messageBuffer);
		//            print_timed(127, -128, (void* const) messageBuffer);
		HWStatus(); // Refresh the status bar
		if ((Vec_Btn_State & 8) != 8)break;
	}
	
	
	
	// chose weapon
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		check_buttons();
		
		Intensity_a(0x5f); // set intensity of vector beam...
		DDRAWDraw(p,d);
		print_timed("With what ? ");                // Which weapon
		VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
		n = -1;
		if ((Vec_Btn_State &7) == 0b00000001) {n = 1;print_timed("Attack with Rapier?");} //Rapier
		if ((Vec_Btn_State &7) == 0b00000010) {n = 2;print_timed("Attack with Axe?");} //Axe
		if ((Vec_Btn_State &7) == 0b00000011) {n = 3;print_timed("Attack with Shield?");} //Shield
		if ((Vec_Btn_State &7) == 0b00000100) {n = 4;print_timed("Attack with Bow?");} //Bow+Arrow
		if ((Vec_Btn_State &7) == 0b00000101) {n = 5;print_timed("Attack with Amulet?");} //Amulet
		if ((Vec_Btn_State & 8) == 8) break;
		
		if (messageTime>0)
		{
			Print_Str_d(127, -128, (void* const) messageBuffer);
		}
	}
	
	if (n < 0)                               // Check the result
	{
		Damage = 0;print_timed("Attack with hands.");
	}
	else
	{
		_fs("Attack with %.",GLOObjName((unsigned int)n));
		print_timed(stringBuffer40);
		GLOGetInfo((unsigned int)n,(unsigned int *) (&Damage),NULL,NULL);

		if (p->Object[n] == 0)                    // Must own an object
		{
			_fs("% not owned.",GLOObjName((unsigned int)n));
			print_timed(stringBuffer40);
			return;
		}
	}
	
	
	if (p->Class == 'M' && (n == OB_BOW || n == OB_RAPIER))                    // Mages are limited
	{
		_fs("Mages can't use %s.\n",GLOObjName((unsigned int)n) );
		print_timed(stringBuffer40);
		return;
	}
	
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		check_buttons();
		
		Intensity_a(0x5f); // set intensity of vector beam...
		DDRAWDraw(p,d);
		VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
		
		if (messageTime>0)
		{
			messageTime--;
			Print_Str_d(127, -128, (void* const) messageBuffer);
		}
		else break;
	}
	
	
	if (n == OB_AMULET)                        // Use an amulet
	{
		_ATTACKAmulet(p,d);
		return;
	}
	
	if (n == OB_BOW || n == OB_AXE)            // Check for axe work
	{
		if (_ATTACKMissile(p,d,(unsigned int)n) == 0)        // Throw code
		_ATTACKWeapon(p,d,(unsigned int)n);    // if not thrown, use as weapon
	}
	else
		_ATTACKWeapon(p,d,(unsigned int)n);                // use as bashing weapon
}

// **********************************************************************
//
//                Attack using object as a hand held weapon
//
// **********************************************************************

static void _ATTACKWeapon(PLAYER *p,DUNGEONMAP *d,unsigned int Weapon)
{
	COORD c;
	c.x = p->Dungeon.x+p->DungDir.x;        // Look at what's there
	c.y = p->Dungeon.y+p->DungDir.y;
	_ATTACKHitMonster(p,d,Weapon,&c);
}

// **********************************************************************
//
//                        Use weapon on monster
//
// **********************************************************************

static void _ATTACKHitMonster(PLAYER *p,DUNGEONMAP *d,unsigned int Weapon,COORD *c)
{
	unsigned int n = 0,Damage;
	int Monster;
	MONSTER *m;

	Monster = DDRAWFindMonster(d,c);        // Is there a monster there ?
	if (Monster < 0)                        // Set up a pointer
	    return;
     	m = &(d->Monster[Monster]);
	n = m->Type;
	
	Damage = 0;                                // Get weaponry info, hands = Weapon = 255
	if (Weapon < 100 && Weapon != OB_AMULET)
        	GLOGetInfo(Weapon,&Damage,NULL,NULL);
	
   	if (Weapon == OB_AMULET)                   // Amulet Special Case
		Damage = 10 + p->Level;
	
	if (Monster < 0 || p->Attr[AT_DEXTERITY]-RandMax(25) < n + p->Level)                        // If no, or not dexterous
	{
		print_timed("You missed !!");
		return;
	}
	
	n = 0;                                  // Calculate HPs lost
	if (Damage > 0) 
        	n = (unsigned int)(RandMax(Damage) );

	n = (unsigned int) (n + p->Attr[AT_STRENGTH]/5);
	m->Strength = m->Strength - n;            // Lose them
	if (((signed int)(m->Strength)) < 0) 
        	m->Strength = 0;
	
	if (m->Strength == 0)
        	_ATTACKKill(m,p);    // Killed it ?
	else
	{
		
		_fsi("Hit! % Hit Points now: %", GLOMonsterName(m->Type),m->Strength);
		print_timed(stringBuffer40);
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			check_buttons();
			
			Intensity_a(0x5f); // set intensity of vector beam...
			DDRAWDraw(p,d);
			VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
			
			if (messageTime>0)
			{
				messageTime--;
				Print_Str_d(127, -128, (void* const) messageBuffer);
			}
			else break;
		}
	}
}

// **********************************************************************
//
//                           Kill off a monster
//
// **********************************************************************

static void _ATTACKKill(MONSTER *m,PLAYER *p)
{
	unsigned int n;
	m->Alive = 0;                            // Deaded
	n = (m->Type + p->Level);                // Amount of Gold
	
	_fi("Killed! You get % pieces of eight.",n );
	print_timed(stringBuffer40);
	
	
	p->Attr[AT_GOLD] += n;
	UPDATE_GOLD(p->Attr[AT_GOLD]);
	if ((m->Type * p->Level)/2>0)
        	p->HPGain +=  ((m->Type * p->Level)/2);    // Calculate Gain
	else  p->HPGain +=1;
	
	if (m->Type == (unsigned int)p->Task)                    // Check done LB's task
	p->TaskCompleted = 1;
}

// **********************************************************************
//
//                    Attack using object as a missile
//
// **********************************************************************

static int _ATTACKMissile(PLAYER *p,DUNGEONMAP *d,unsigned int Weapon)
{
	int n,y,Dist;
//	char ch;
	COORD c,c1;
	
	
	// wait for button release / debounce
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		check_buttons();
		
		Intensity_a(0x5f); // set intensity of vector beam...
		DDRAWDraw(p,d);
		VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
		Print_Str_d(127, -128, (void* const) messageBuffer);
		if ((Vec_Btn_State & 8) != 8)break;
	}
	
	
	if (Weapon == OB_AXE)                // Axes can be thrown or swung
	{
		print_timed("Throw(1) or Swing(2)?");
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			check_buttons();
			
			Intensity_a(0x5f); // set intensity of vector beam...
			DDRAWDraw(p,d);
			VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
			Print_Str_d(127, -128, (void* const) messageBuffer);
			if ( button_1_1_pressed())
			{
				// throw
				p->Object[OB_AXE]--;            // Lose a thrown axe
				break;
			}
			if ( button_1_2_pressed())
			{
				// swing
				return 0;
			}
		}
		
		
	}
	c.x = p->Dungeon.x;                    // See what's to hit
	c.y = p->Dungeon.y;
	Dist = -1;
	for (y = 0;y < 5;y++)                // A maximum distance of 5
	{
		c.x = c.x + p->DungDir.x;        // Next position
		c.y = c.y + p->DungDir.y;
		n = DDRAWFindMonster(d,&c);        // Monster there ?
		if (n >= 0)
		{
			c1=c;
			Dist = n;
		}    // If so , record that
		if (!ISDRAWOPEN(d->Map[c.x][c.y]))                    // If wall, or door, stop
		y = 99;
	}
	if (Dist < 0)                        // Hit nothing
	print_timed("You missed !!");
	else
	_ATTACKHitMonster(p,d,Weapon,&c1);
	return 1;
}

// **********************************************************************
//
//                            Use an amulet
//
// **********************************************************************

static void _ATTACKAmulet(PLAYER *p,DUNGEONMAP *d)
{
	unsigned int i,Magic = RandMax(4);
	if (p->Class == 'M')                // Mages use them properly !
	{
		// debounce
		// wait for button release / debounce
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			check_buttons();
			
			Intensity_a(0x5f); // set intensity of vector beam...
			DDRAWDraw(p,d);
			VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
			Print_Str_d(127, -128, (void* const) messageBuffer);
			if ((Vec_Btn_State & 8) != 8)break;
		}
		print_timed("Up(1) Down(2) Attack(3) Bad Magic(4)");
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			check_buttons();
			
			Intensity_a(0x5f); // set intensity of vector beam...
			DDRAWDraw(p,d);
			VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
			Print_Str_d(127, -128, (void* const) messageBuffer);
			if (button_1_1_pressed())  {Magic = 0;break;}
			if (button_1_2_pressed())  {Magic = 1;break;}
			if (button_1_3_pressed())  {Magic = 2;break;}
			if (button_1_4_pressed())  {Magic = 3;break;}
		}
		
	}
	if (RandMax(5)  == 0)                // Last charge
	{
		while (buttons_pressed()) check_buttons();
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			VIA_t1_cnt_lo = TEXT_SCALE; // scale
			check_buttons();
			Intensity_a(0x5f); // set intensity of vector beam...
			DDRAWDraw(p,d);
			VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
			Print_Str_d(127, -128, "Last charge on this Amulet.");
			if (buttons_pressed())
			{
				break;
			}
		} // while (bpressed != 2)
		
		
		
		
		
		p->Object[OB_AMULET]--;
	}
	switch(Magic)
	{
		case 0:                            // Ladder up
		d->Map[p->Dungeon.x][p->Dungeon.y] = DT_LADDERUP;
		break;
		case 1:                            // Ladder down
		d->Map[p->Dungeon.x][p->Dungeon.y] = DT_LADDERDN;
		break;
		case 2:                            // Amulet Attack
		_ATTACKMissile(p,d,OB_AMULET);
		break;
		case 3:                           // Bad Magic
		switch(RandMax(3) )
		{
			case 0:
			print_timed("You have been turned into a Toad.");
			for (i = AT_STRENGTH;i <= AT_WISDOM;i++)
			p->Attr[i] = 3;
			break;
			case 1:
			print_timed("You have been turned into a Lizard Man.");
			for (i = AT_HP;i <= AT_WISDOM;i++)
			p->Attr[i] = (p->Attr[i] * 5/2);
			break;
			case 2:
			print_timed("Backfire!!!");
			p->Attr[AT_HP] = (p->Attr[AT_HP]+1)/2;
			break;
		}
		break;
	}
	
}
