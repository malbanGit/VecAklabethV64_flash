// !!! ATTENTION
// BANK 0 and BANK 1
// are two TOTALLY seperated "C" programs
//
// but only BANK 1 is initialized
// this means amongst others, that
// EITHER
// ALL global variables must be exactly the same!
//
// OR
// BANK 0 must not have any global variables at all
// unless they OVERWRITE Bank 1 variables!!!
// (also - they will always be uninitialized!)
//
// (or you devise a plan to ensure the RAM does not collide in any other way!)
//
// further thoughts on
// global variables in "globals.h"

extern void subBank0(int);
#define introImage() subBank0(0)
#define TOWNEnter() subBank0(1)
#define WORLDDrawOnce() subBank0(2)
#define loadFlash() subBank0(6)

// MALBAN presents
// a role playing game
// by Richard Garriott / Lord British
// a C port by Paul Robson
// Vectrex port by Malban

// settings GRAPHICS 3 vs / 7
// new tileset!

// instructions






// questing with button not corrct
// questing text size/display
// hit point werde irgendiw nicht korrekt brechnet!

// remember:// DOORS are a location where one can stand in!

// draw only 1 monster max in dungeon!

// return from dungeon show hp gain, and wait!

// add a "wait" after trap!

// have a static status string in RAM -> saves about 4000 cycles!!!

// build a function "update status", which
// updates the string (partial what is needed)
// MAP Icons with smartlist?

// todo draw monster correctly in dungion with
// correct scale position,  right now they are "rnadomly" just about right!
// some draws need not be done by draw VLP, because they don't need P

// diagonals - draw them in one go?

// todo name a hero
// let the player chose a lucky number
// todo "timed" exit on no quest accepted
// overall timing issues
// only upper characters
// "scoring" and counting directly in ASCII to be print "ready"
// intro
// intro grafics
// music?
// button consistency 4 = yes, 1 = no and "similar"
// death seqeucne (no it resets)
// prrinting of HP / Food with tenth values?
// chosen skill level is not set!!!
// debounce buttons?
// town with inventory?
// random world creation - fix random routine? also - (void setRandomSeed(unsigned int n))
// treasure finding -> mage/fighter dependend? (move.c)
// do other dungeon stuff
// correct drawings
// speedup

// hp itoa > 1000 not correct
// hp cant go negative -> 65535...

// attack
//in MOve
// TODO
//        MONSTAttack(p,d);                    // Monster attacks ?

/*
stack problems again in ATTACK (draw wall!) (Attack is deeper call with draw wall!!!
16 max, goes in String 40 -> still Ok!
*/

/*
todo void MOVEEnterExit(WORLDMAP *w,PLAYER *p,DUNGEONMAP *d)
todo void DRAWDungeon(const RECT * const rOut,const RECT * const rIn, int Left,int Centre,int Right, int Room,int Monster)
void DRAWText(char *Format,...)

display bug with "walls" strange lines in some directions
*/

// ***************************************************************************
// main
// ***************************************************************************
// This file was developed by Prof. Dr. Peer Johannsen as part of the
// "Retro-Programming" and "Advanced C Programming" class at
// Pforzheim University, Germany.
//
// It can freely be used, but at one's own risk and for non-commercial
// purposes only. Please respect the copyright and credit the origin of
// this file.
//
// Feedback, suggestions and bug-reports are welcome and can be sent to:
// peer.johannsen@pforzheim-university.de
// ---------------------------------------------------------------------------

#include <vectrex.h>

#include "../aklabeth.h"
#include "../globalsDef.h"
#include "../string.h"
#include "../controller.h"





#define J_NONE  0
#define J_UP    1
#define J_DOWN  2
#define J_LEFT  3
#define J_RIGHT 4


// As default assertions are enabled.
// to disable do a
#define NDEBUG
// or set the gcc option "-D NDEBUG" (Vide project file)


// ---------------------------------------------------------------------------
// cold reset: the vectrex logo is shown, all ram data is cleared
// warm reset: skip vectrex logo and keep ram data
// ---------------------------------------------------------------------------
// at system startup, when powering up the vectrex, a cold reset is performed
// if the reset button is pressed, then a warm reset is performed
// ---------------------------------------------------------------------------
// after each reset, the cartridge title is shown and then main() is called
// ---------------------------------------------------------------------------

static void _MAINCommand(WORLDMAP *,PLAYER *,DUNGEONMAP *);

int main(void)
// ***************************************************************************
// end of file
// ***************************************************************************
{
    Vec_Max_Players = (int)0x80;
	while (1)
	{
		
		introImage(); // bank 0
		
		Wait_Recal();//        WaitForPB6ToSettle
		Wait_Recal();
		
		if (Vec_Num_Game==1) // load is configured out...
		{
              loadFlash();
			if (Vec_Num_Players == 0) // save exists
			{
				UPDATE_FOOD(Player.Object[OB_FOOD]);
				UPDATE_HP(Player.Attr[AT_HP]);
				UPDATE_GOLD(Player.Attr[AT_GOLD]);
				
				if (Player.Level == 0)                        // Above ground, draw it
				    WORLDCreate(&Player,World);            // Create the over world
				else
				    DUNGEONCreate(&Player,Dungeon);            // Create the dungeon map
				PLAYERInv(&Player);
			}
			else
			{
				MAINSetup();                            // Set up the player
			}
		}
		else
		
		{
			MAINSetup();                            // Set up the player
		}
         // settings were changed!
		if ((int)(Vec_Max_Players&0x80) == 0) Player.bits =(unsigned int)Vec_Max_Players;
		do
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			check_buttons();
			check_joysticks();
			Intensity_a(0x5f); // set intensity of vector beam...
			_MAINCommand(World,&Player, Dungeon);        // Do it
			
			if (Player.Level == 0)                        // Above ground, draw it
			WORLDDrawOnce();
			else
			DDRAWDraw(&Player,Dungeon);
			HWStatus(); // Refresh the status bar
		}
		while (((signed long int ) (Player.Attr[AT_HP])) > 0);
		
		
		
		// wait for button release / debounce
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			check_buttons();
			Intensity_a(0x5f); // set intensity of vector beam...
			HWStatus(); // Refresh the status bar
			if ((Vec_Btn_State & 15) == 0)break;
		}
		
		
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			Intensity_a(0x5f); // set intensity of vector beam...
			messageTime =100;
			HWStatus();
			ADDLINE;
			ADDLINE;
			ADDLINE;
			ADDLINE;
			print("ANY BUTTON TO RESTART!");
			check_buttons();
			if (buttons_pressed()) break;
		}
		
	}
	
}
int MAINSuper(void)
{
	return 1;
}

void MAINSetup(void)
{
	tMessage = 0;
	waitTimer = 0;
	PLAYERInit(&Player);                    // Initialise the player
	PLAYERCharacter(&Player);                // Character information
	//    PLAYERDebug(&Player);
	
	UPDATE_FOOD(Player.Object[OB_FOOD]);
	UPDATE_HP(Player.Attr[AT_HP]);
	UPDATE_GOLD(Player.Attr[AT_GOLD]);
	
	WORLDCreate(&Player,World);            // Create the over world
	TOWNEnter();                // Visit the shops
}



//**********************************************************************
//
//                            Execute a command
//
//**********************************************************************

static void _MAINCommand(WORLDMAP *w,PLAYER *p,DUNGEONMAP *d)
{
	if (waitTimer >0)
	{
		waitTimer--;
		return;
	}
	if (joystick_1_leftChange())
	{
		if (p->Level == 0)print_timed("Go West."); else  print_timed("Turn Left.");
		MOVEMove('W',w,p,d,-1,0);
		return;
		
	}
	if (joystick_1_rightChange())
	{
		if (p->Level == 0)print_timed("Go East."); else  print_timed("Turn Right.");
		MOVEMove('E',w,p,d,1,0);
		return;
		
	}
	if (joystick_1_upChange())
	{
		if (p->Level == 0)print_timed("Go North."); else  print_timed("Move.");
		MOVEMove('N',w,p,d,0,-1);
		return;
		
	}
	if (joystick_1_downChange())
	{
		if (p->Level == 0)print_timed("Go South."); else  print_timed("Turn Around.");
		MOVEMove('S',w,p,d,0,1);
		return;
	}
	if (button_1_3_pressed())
	{
		MOVEEnterExit(w,p,d);
		return;
	}
	if (button_1_1_pressed())
	{
		PLAYERInv(&Player);
		return;
	}
	if (button_1_2_pressed())
	{
		messageTime = 50;
		return;
	}
	if (button_1_4_pressed()) // atack!
	{
		if (p->Level != 0)
		{
			print_timed("Attack.");
			ATTACKMonster(p,d);
			
			return;
		}
	}
}

#include "../BothBanks.i"




static struct _MInfStruct const _MInfo[] =
	{
		{ "Skeleton",1 },
		{ "Thief",2 },
		{ "Giant Rat",3 },
		{ "Orc",4 },
		{ "Viper",5 },
		{ "Carrion Crawler",6 },
		{ "Gremlin",7 },
		{ "Mimic",8 },
		{ "Daemon",9 },
		{ "Balrog",10 }
	};
static char * const  _MInfoAttribute[] =
	{
		 "a Skeleton" ,
		 "a Thief" ,
		 "a Giant Rat" ,
		 "an Orc" ,
		 "a Viper",
		 "a Carrion Crawler",
		 "a Gremlin",
		 "a Mimic",
		 "a Daemon",
		 "a Balrog" 
	};
char *GLOMonsterName(unsigned int n)
{
	return _MInfo[n-1].Name;
}
char *GLOMonsterNameAttribute(int n)
{
	return _MInfoAttribute[n-1];
}

unsigned int GLOMonsterLevel(unsigned int n)
{
	return _MInfo[n-1].Level;
}
