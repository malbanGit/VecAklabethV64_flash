//**********************************************************************
//**********************************************************************
//                                                                        
//                        Enter town (shopkeeper code)                    
//                                                                        
//**********************************************************************
//**********************************************************************
#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../controller.h"
#include "../string.h"


//void TOWNEnter(PLAYER *p)
void TOWNEnter()
{
    PLAYER *p = &Player;
	int buying = -1;
	unsigned int Cost;
	unsigned long Incr;
	
	unsigned int selected = 0;
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		check_joysticks();
		Intensity_a(0x5f); // set intensity of vector beam... 
		if (joystick_1_upChange())  if (selected>0) selected--;
		if (joystick_1_downChange()) if (selected<5) selected++;
		
		HWStatus(); // / Refresh the status bar
		
		print("Welcome to the Adventure shop.");
		ADDLINE;
		
		
		
		print("What shalt thou buy?");
		ADDLINE;
		ADDLINE;
		
		
              if (selected == 0) printfl("Food      (1GP): %",p->Object[0]);
			if (selected == 1) printfl("Rapier    (8GP): %",p->Object[1]);
			if (selected == 2) printfl("Axe       (5GP): %",p->Object[2]);
			if (selected == 3) printfl("Shield    (6GP): %",p->Object[3]);
			if (selected == 4) printfl("Bow&Arrow (3GP): %",p->Object[4]);
			if (selected == 5) printfl("Amulet   (15GP): %",p->Object[5]);
            		ADDLINE;
		ADDLINE;

			print("Select(up/down) Buy(4)");
			print("Exit(1)");
		
		if (button_1_4_pressed())
		{
			// buying
			buying = (int) selected;
			if (p->Class == 'M')                // Some things mages can't use
			{
				if (selected == OB_BOW || selected == OB_RAPIER)
				{
					MessageBox("I'm sorry, Mages can't use that.");
					buying = -1;
				}
			}
			if (buying >= 0)                        // Something selected
			{
				GLOGetInfo(selected,NULL,&Cost,NULL);
				if (Cost > p->Attr[AT_GOLD])
				MessageBox("M'Lord thou cannot afford that item.");
				else
				{
					p->Attr[AT_GOLD] -= Cost;   // Lose the money
 UPDATE_GOLD(p->Attr[AT_GOLD]); 
					
					Incr = 1;if (selected == OB_FOOD) Incr = 10;
					p->Object[selected] += Incr;    // Add 1 or 10 on
 UPDATE_FOOD(p->Object[OB_FOOD]);
				}
			}
		}
		
		
		if (button_1_1_pressed())
		{
			break;
		}
	}
	MessageBox("Bye.");
}


