///*********************************************************************
///*********************************************************************
//
//                            Manage Player Structures
//
///*********************************************************************
///*********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"


///*********************************************************************
//
//                    Initialise the player character
//
///*********************************************************************

void PLAYERInit(PLAYER *p)
{
	unsigned tmp=1;
	memset(p,0xFF,sizeof(PLAYER));            // Fill with character $FF
	p->Name[0] = '\0';
	p->World.x = p->World.y = 0;
	p->Dungeon.x = p->Dungeon.y = 0;
	p->DungDir.x = p->DungDir.y = 0;
	p->Class = '?';
	p->Level = 0;
	p->Skill = 0;
	p->Task = 0;
	p->TaskCompleted = 0;
	p->HPGain = 0;
	p->LuckyNumber = Rand();                // We do the lucky number !
	p->Attributes = p->Objects = 6;            // Aklabeth standards
	p->bits = 3;            // Aklabeth standards
	
	if (MAINSuper())                         // Super Aklabeth : more
	{
		p->Attributes = MAX_ATTR;
		p->Objects = MAX_OBJ;
	}
	for (tmp = 0;tmp < p->Attributes;tmp++) p->Attr[tmp] = 0;
	for (tmp = 0;tmp < p->Objects;tmp++) p->Object[tmp] = 0;
	tenthFood = 0;
}

//**********************************************************************
//
//                            Manage Player Structures
//
//**********************************************************************

void PLAYERDebug(PLAYER *p)
{
	unsigned int i;
	vstrcpy(p->Name,"Debuggo");                // Characters Name
	p->Class = 'M';                            // Fighter
	p->LuckyNumber = 42;                    // Always the same.....
	p->Skill = 1;                            // Skill level 1
	for (i = 0;i < p->Attributes;i++)        // Nice high attributes
	p->Attr[i] = 99;
	p->Attr[AT_HP] = 1200;//999;
	p->Attr[AT_GOLD] = 9999;
	for (i = 0;i < p->Objects;i++)            // Lots of nice objects
	p->Object[i] = (unsigned long int) ((i == OB_FOOD || i == OB_BOW) ? 9999 : 99);
}

void PLAYERDemo(PLAYER *p)
{
	unsigned int i;
	vstrcpy(p->Name,"Demo");                    // Characters Name
	p->Class = 'F';                            // Fighter
	p->LuckyNumber = 42;                    // Always the same.....
	p->Skill = 1;                            // Skill level 1
	for (i = 0;i < p->Attributes;i++)        // Nice high attributes
	p->Attr[i] = 15;
	p->Attr[AT_HP] = 18;
	p->Attr[AT_GOLD] = 99;
	for (i = 0;i < p->Objects;i++)            // Lots of nice objects
	p->Object[i] = (unsigned long int) ((i == OB_FOOD || i == OB_BOW) ? 999 : 4);
}

///*********************************************************************
//
//                        Create a player character
//
///*********************************************************************
extern void printfslrs(const char *s1, const char *s2, const unsigned long i);

void PLAYERCharacter(PLAYER *p)
{
	unsigned int tmp=1;
	
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		check_joysticks();
		Intensity_a(0x5f); // set intensity of vector beam...
		if (joystick_1_left())  if (tmp>0) tmp--;
		if (joystick_1_right()) if (tmp<15) tmp++;
		
		print("Select skill level.");
		ADDLINE;
		print("(left/right - button to finish)");
		ADDLINE;
		printfi("Level %.",tmp);
		
		if (buttons_pressed())
		{
			p->Skill = (int) tmp;
			break;
		}
	}
	
	tmp = 32;
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		check_joysticks();
		Intensity_a(0x5f); // set intensity of vector beam...
		if (joystick_1_left())  if (tmp>0) tmp--;
		if (joystick_1_right()) if (tmp<255) tmp++;
		
		print("Chose lucky number.");
		ADDLINE;
		print("(left/right - button to finish)");
		ADDLINE;
		printfi("Lucky number %.",tmp);
		
		if (buttons_pressed())
		{
			p->LuckyNumber = tmp;
			break;
		}
	}
	
	
	
	
	int generateAttirbutes = 1;
	while (1)
	{
		if (generateAttirbutes == 1)
		{
			for (tmp = 0;tmp < p->Attributes;tmp++)
			{
				p->Attr[tmp] = Rand()/12+4;
			}
			
			generateAttirbutes = 0;
		}
		CLS;
		Wait_Recal();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		Intensity_a(0x5f); // set intensity of vector beam...
		
		printfi("Game Number: %",p->LuckyNumber);
		ADDLINE;
		
		for (tmp = 0;tmp < p->Attributes;tmp++)
		{
			printfslrs("%: %",GLOAttribName(tmp),p->Attr[tmp]);
		}
		ADDLINE;
		print("Wilt thou play with these");
		ADDLINE;
		print("qualities? YES(1)  NO(4)");
		
		if (button_1_1_pressed()) break;
		if (button_1_4_pressed()) generateAttirbutes = 1;
	}
	
	
	
	
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		check_joysticks();
		Intensity_a(0x5f); // set intensity of vector beam...
		
		print("And shalt thou be a Fighter or");
		print("a Mage?");
		ADDLINE;
		print("FIGHTER(1)  MAGE(4)");
		if (button_1_1_pressed())
		{
			p->Class = 'F';
			break;
		}
		if (button_1_4_pressed())
		{
			p->Class = 'M';
			break;
		}
	}
}



//**********************************************************************
//
//                                Player Inventory
//
//**********************************************************************
extern void subBank0(int);
#define doSettings() subBank0(4)
#define saveFlash() subBank0(5)

void PLAYERInv(PLAYER *p)
{
	int iState = 0; // 0 = stats
	unsigned  int i;
	while (1)
	{
		CLS;
		check_buttons();
		check_joysticks();
		Wait_Recal();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		Intensity_a(0x5f); // set intensity of vector beam...
		//        HWStatus(p->Object[OB_FOOD],    p->Attr[AT_HP],p->Attr[AT_GOLD]);        // Refresh the status
		if (p->Name[0] != '\0')                    // Display the name
		{
			printfss("% the %.",p->Name,GLOClassName(p->Class));
		}
		else
		{
			printfs("A %.",GLOClassName(p->Class));
		}
		
		ADDLINE;
		if (iState == 0)
		{
			for (i = 0;i < p->Attributes;i++)        // Display the attributes
			{
				if (i != AT_HP && i != AT_GOLD)
				{
					printfsl("%: %",GLOAttribName(i),p->Attr[i]);
				}
			}
			ADDLINE;
		}
		if (iState == 1)
		{
			for (i = 0;i < p->Objects;i++)            // Display the objects
			{
				if (i != OB_FOOD)
				{
					printfsl("%: %",GLOObjName(i),(unsigned long)p->Object[i]);
				}
			}
		}
		ADDLINE;
		ADDLINE;
		//        print("Stats(1) Inventory(2) Save(3)");
#ifdef BUILD_FOR_FLASH
		print("Config(1) Save(3) Scroll(Joy)");
#else
		print("Config(1) Scroll(Joy)");
#endif
		//        print("Config(1) Scroll(Joy)");
		
		if ( button_1_1_pressed())
		{
			Vec_Max_Players = (int)p->bits;
			doSettings();
			p->bits = (unsigned int)Vec_Max_Players;
		}
		
		if (joystick_1_up()) iState = 0;
		if (joystick_1_down()) iState = 1;
		
#ifdef BUILD_FOR_FLASH
		if ( button_1_3_pressed())
		{
              saveFlash();
              if (Vec_Num_Players != 0)
              {
            		while (1)
            		{
            			CLS;
            			Wait_Recal();
            			Intensity_a(0x5f); // set intensity of vector beam...
                		VIA_t1_cnt_lo = TEXT_SCALE; // scale
            			ADDLINE;
            			print("ERROR SAVING TO FLASH");
            			check_buttons();
            			if (buttons_pressed()) break;
            		}

              }
              else
              {
            		while (1)
            		{
            			CLS;
            			Wait_Recal();
            			Intensity_a(0x5f); // set intensity of vector beam...
                		VIA_t1_cnt_lo = TEXT_SCALE; // scale
            			ADDLINE;
            			print("SAVING DONE!");
            			check_buttons();
            			if (buttons_pressed()) break;
            		}
              }
        		while (1)
        		{
        			check_buttons();
        			if (!buttons_pressed()) break;
        		}

              // need to recreate the world
              // since the saver uses that RAM for
              // its RAM copied su routines
			if (Player.Level == 0)                        // Above ground, draw it
			    WORLDCreate(&Player,World);            // Create the over world
			else
			    DUNGEONCreate(&Player,Dungeon);            // Create the dungeon map
			
		}
#endif		
		if ( button_1_4_pressed())
		{
			break;
		}
	}
	
}
