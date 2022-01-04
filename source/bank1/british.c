//**********************************************************************
//**********************************************************************
//
//                            Lord British's Castle
//
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"

void getName();

//**********************************************************************
//
//                            Visit Lord British
//
//**********************************************************************

void BRITISHEnter(WORLDMAP *w,PLAYER *p)
{
	w=0; // dummy so there is no warning
	int NextTask = p->Task+1;
	//    int c,i;
	int i;
	int startTask = 0;
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		Intensity_a(0x5f); // set intensity of vector beam...
		if ((p->Task == 0) && (startTask == 0))
		{
			if (*p->Name == '\0')                    // Require the player name
			{
				getName();
				continue;
			}
			
			//print("Welcome, peasant into the Halls");
			printfs("Welcome, % into the Halls", p->Name);
			
			ADDLINE;
			print("of the mighty Lord British.");
			ADDLINE;
			
			print("Herein thou may choose to do ");
			ADDLINE;
			print("battle with the evil creatures ");
			ADDLINE;
			print("of the depths, for great reward.");
			ADDLINE;
			ADDLINE;
			
			// Great adventure question
			print("Doest thou wish for");
			ADDLINE;
			print("great adventure? YES(4)");
			ADDLINE;
			
			// button 4 yes
			// button 1 no
			
			if (button_1_1_pressed())
			{
				// todo timed out going
				print("Then leave and begone!");
				//            strcpy(p->Name,"");
				return;
			}
			
			if (button_1_4_pressed())
			{
				startTask = 1;
			}
			continue;
		} // if ((p->Task == 0) && (startTask == 0))
		
		if (p->Task > 0)                        // Set a task before ?
		{
			if (p->TaskCompleted == 0)            // Outstanding task
			{
				int bpressed = 0;
				while (!bpressed)
				{
					CLS;
					Wait_Recal();
					Do_Sound();
					VIA_t1_cnt_lo = TEXT_SCALE; // scale
					check_buttons();
					Intensity_a(0x5f); // set intensity of vector beam...
					printfs("%, why hast thou returned?",    p->Name);
					ADDLINE;
					printfs("Thou must kill %.",GLOMonsterNameAttribute(p->Task));
					ADDLINE;
					print("Go now and complete thy quest!");
					if (buttons_pressed())
					{
						return;
					}
				} // while (bpressed != 2)
			}
			else // if (p->TaskCompleted == 0)
			{
				if (p->Task == MAX_MONSTERS)
				{
					int bpressed = 0;
					while (bpressed != 2)
					{
						CLS;
						Wait_Recal();
						Do_Sound();
						VIA_t1_cnt_lo = TEXT_SCALE; // scale
						check_buttons();
						Intensity_a(0x5f); // set intensity of vector beam...
						printfs("Aaaahhhh.... %.",p->Name);
						ADDLINE;
						ADDLINE;
						print("Thou has accomplished");
						ADDLINE;
						print("thy quest.");
						if (bpressed == 0)
						{
							if (buttons_pressed())
							{
								bpressed = 1;
							}
						}
						else
						{
							if (!buttons_pressed())
							{
								bpressed = 2;
							}
						}
					} // while (bpressed != 2)
					bpressed = 0;
					while (bpressed != 2)
					{
						CLS;
						Wait_Recal();
						Do_Sound();
						VIA_t1_cnt_lo = TEXT_SCALE; // scale
						check_buttons();
						Intensity_a(0x5f); // set intensity of vector beam...
						printfs("Lord %, thou hast",p->Name);
						ADDLINE;
						print("proved thyself worthy of");
						ADDLINE;
						print("Knighthood, continue if thou");
						ADDLINE;
						print("doth wish but thou hast");
						ADDLINE;
						print("accomplished the main");
						ADDLINE;
						print("objective of the game.");
						if (bpressed == 0)
						{
							if (buttons_pressed())
							{
								bpressed = 1;
							}
						}
						else
						{
							if (!buttons_pressed())
							{
								bpressed = 2;
							}
						}
					} // while (bpressed != 2)
					bpressed = 0;
					while (bpressed != 2)
					{
						CLS;
						Wait_Recal();
						Do_Sound();
						VIA_t1_cnt_lo = TEXT_SCALE; // scale
						check_buttons();
						Intensity_a(0x5f); // set intensity of vector beam...
						print("Now, maybe thou art");
						ADDLINE;
						print("foolhardy enough to try");
						ADDLINE;
						ADDLINE;
						printfi("difficulty level %.",(unsigned int)(p->Skill+1));
						
						
						
						
						if (buttons_pressed())
						{
							return;
						}
					} // while (bpressed != 2)
				} // if (p->Task == MAX_MONSTERS)
				else
				{
					int bpressed = 0;
					while (bpressed != 2)
					{
						CLS;
						Wait_Recal();
						Do_Sound();
						VIA_t1_cnt_lo = TEXT_SCALE; // scale
						check_buttons();
						Intensity_a(0x5f); // set intensity of vector beam...
						printfs("Aaaahhhh.... %.",p->Name);
						ADDLINE;
						ADDLINE;
						print("Thou has accomplished");
						ADDLINE;
						print("thy quest.");
						if (bpressed == 0)
						{
							if (buttons_pressed())
							{
								bpressed = 1;
							}
						}
						else
						{
							if (!buttons_pressed())
							{
								bpressed = 2;
							}
						}
					} // while (bpressed != 2)
					
					bpressed = 0;
					while (bpressed != 2)
					{
						CLS;
						Wait_Recal();
						Do_Sound();
						VIA_t1_cnt_lo = TEXT_SCALE; // scale
						check_buttons();
						Intensity_a(0x5f); // set intensity of vector beam...
						print("Unfortunately, this");
						ADDLINE;
						print("is not enough to");
						ADDLINE;
						print("become a knight.");
						ADDLINE;
						ADDLINE;
						printfs("Thou must now kill %.",GLOMonsterNameAttribute(NextTask));
						if (bpressed == 0)
						{
							if (buttons_pressed())
							{
								bpressed = 1;
							}
						}
						else
						{
							if (!buttons_pressed())
							{
								bpressed = 2;
							}
						}
					} // while (bpressed != 2)
					
					
					
				} // if (p->Task == MAX_MONSTERS)
			} // else // if (p->TaskCompleted == 0)
		}
		
		if (p->Task == 0)                        // Need a new task.....
		{
			int bpressed = 0;
			while (bpressed != 2)
			{
				CLS;
				Wait_Recal();
				Do_Sound();
				VIA_t1_cnt_lo = TEXT_SCALE; // scale
				check_buttons();
				Intensity_a(0x5f); // set intensity of vector beam...
				if (NextTask == 1)
				{
					print("Good! Thou shalt try to become");
					ADDLINE;
					print("a knight. Thy first task is ");
					ADDLINE;
					print("to go into the dungeons and");
					ADDLINE;
					print("return only after");
					ADDLINE;
					printfs("killing %.",    GLOMonsterNameAttribute(NextTask));
				}
				if (bpressed == 0)
				{
					if (buttons_pressed())
					{
						bpressed = 1;
					}
				}
				else
				{
					if (!buttons_pressed())
					{
						bpressed = 2;
					}
				}
			}
		}
		
		
		while (1)
		{
			CLS;
			Wait_Recal();
			Do_Sound();
			VIA_t1_cnt_lo = TEXT_SCALE; // scale
			check_buttons();
			Intensity_a(0x5f); // set intensity of vector beam...
			print("Go now upon this Quest, and may");
			ADDLINE;
			print("lady luck fair be upon you.");
			ADDLINE;
			ADDLINE;
			print("Also I, Lord British, have");
			ADDLINE;
			print("increased each of your");
			ADDLINE;
			print("attribute by one.");
			
			if (buttons_pressed())
			{
				p->Task = NextTask;
				p->TaskCompleted = 0;
				for (i = 0;i < (int)(p->Attributes);i++)    // LB gives you extra attribs
				p->Attr[i]++;
				return;
			}
		}
	}
}




extern int inputString8(char *input);


void getName()
{
	int bpressed = 0;
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = TEXT_SCALE; // scale
		check_buttons();
		Intensity_a(0x5f); // set intensity of vector beam...
		
		print("Welcome, Peasant into the Halls");
		ADDLINE;
		print("of the mighty Lord British.");
		ADDLINE;
		print("Herein thou may choose to do battle");
		ADDLINE;
		print("with the evil creatures of the");
		ADDLINE;
		print("depths, for great reward.");
		ADDLINE;
		ADDLINE;
		print("What is thy name, Peasant ?");
		ADDLINE;
		if (bpressed == 0)
		if (buttons_pressed()) bpressed=1;
		if ((buttons_pressed()==0) && (bpressed==1)) break;
		
	}
     inputString8(Player.Name);

}
