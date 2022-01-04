#include "../string.i"


const char matrix[1][6][6] = {
	{                                // X
		{ 'A', 'B', 'C', 'D', 'E', ' ' },
		{ 'F', 'G', 'H', 'I', 'J', ' ' },
		{ 'K', 'L', 'M', 'N', 'O', ' ' },
		{ 'P', 'Q', 'R', 'S', 'T', ' ' },
		{ 'U', 'V', 'W', 'X', 'Y', ' ' },
		{ 'Z', 'e', 'n', 't', 'e', 'r' }
	}
		// although this field must be 5 chars, that does leave
		// a lot of choice: ENTER or ERASE or SPACE for example.
};

// 0 and smaller terminates!
int strlen(const char *s)
{
	int c = 0;
	while   ( (signed int) (*(s)++)  >0 )
	c++;
	return c;
}

int inputString8(char *input)
{
	int x,y;
	long int cx,cy;
	unsigned int next = 0;
	int set = 0;
	long unsigned  old_hw = Vec_Text_HW;
     Vec_Text_HW = 0xf850;	

	for (;;)
	{
		Wait_Recal();
		check_buttons();
		Joy_Analog();
		
		dp_VIA_t1_cnt_lo = TEXT_SCALE; // scale
		
		if (button_1_3_pressed())
		{ // B3 is erase
			if (next > 0)
			next -= 1;
			input[next] = 0x80;
		}
		Intensity_a(0x7f);
		
		// Display the entered line.  Note there's only room for about 14 characters
		// so we either need multi-line support or to scroll once it gets past the
		// maximum length (so make these lines into a procedure)
		input[next++] = ' ';
		input[next] = 0x80;
		
		Print_Str_d(110, -30, "Name: \x80");
		Print_Str_d(90, -60- (((strlen(input)-7)*16)/2), input);
		input[--next] = (unsigned int)0x80;
/*		
		cx = (Vec_Joy_1_X+128)/(255/6);
		if (cx < 0) cx = 0;
		if (cx>5) cx = 5;
		cy = (-Vec_Joy_1_Y+127)/(255/6);
		if (cy < 0) cy = 0;
		if (cy>5) cy = 5;
*/
         cx = ( Vec_Joy_1_X >= 0
               ? (Vec_Joy_1_X >= 60 ? (Vec_Joy_1_X >= 120 ? 5 : 4) : 3)
               : (Vec_Joy_1_X < -60 ? (Vec_Joy_1_X < -120 ? 0 : 1) : 2));

         cy = ( Vec_Joy_1_Y >= 0
               ? (Vec_Joy_1_Y >= 60 ? (Vec_Joy_1_Y >= 120 ? 0 : 1) : 2)
               : (Vec_Joy_1_Y < -60 ? (Vec_Joy_1_Y < -120 ? 5 : 4) : 3));




		Intensity_a(0x2f);
		
		#define SQUARESIZE 15
		Reset0Ref();
		Intensity_a(0x4f);
		dp_VIA_t1_cnt_lo = TEXT_SCALE; // scale
		
		if ((cy==5) && (cx>0))
		{
			Moveto_d((5-(int)cy)*20-60+3, 20-60+10);
			Draw_Line_d(0, SQUARESIZE*6+6);
			Draw_Line_d(-SQUARESIZE,0);
			Draw_Line_d(0,-(SQUARESIZE*6+6));
			Draw_Line_d(SQUARESIZE,0);
		}
		else
		{
			if (cy<=5)
			{
				Moveto_d((5-(int)cy)*20-60+3, (int)cx*20-60+10);
				Draw_Line_d(0, SQUARESIZE);
				Draw_Line_d(-SQUARESIZE,0);
				Draw_Line_d(0,-SQUARESIZE);
				Draw_Line_d(SQUARESIZE,0);
				
			}
		}
		
		for (y = 0; y <= 5; y++)
		{
			for (x = 0; x <= 5; x++)
			{
				char *line = &messageBuffer[0];
				//                if (y != cy)
				if (y != 22)
				{
					if (!x)
					{ // optimise lines that don't have a highlighted letter
						line[0] = matrix[set][y][x];
						line[1] = matrix[set][y][x+1];
						line[2] = matrix[set][y][x+2];
						line[3] = matrix[set][y][x+3];
						line[4] = matrix[set][y][x+4];
						line[5] = matrix[set][y][x+5];
						line[6] = 0x80;
						Print_Str_d((5-y)*20-60, x*16-60,  line);
					}
				}
				{
					if ((y==5) && (cx>0) && x)
					{
						if ((x==cx) && (y==cy) &&(button_1_4_pressed()))
						{ // B4 is 'accept'
//							input[next++] = '\n';
							input[next] = 0x00;
     Vec_Text_HW = old_hw;
return 0;
// finish input!

						}
					}
					else
					{ // single character
						// still to handle shift key locations
						if ((x==cx) && (y==cy))
						{
							if (button_1_4_pressed())
							{ // B4 is 'accept'
								int c = (int)matrix[set][cy][cx];
								if ((x == 5) && cy)
								{ // (5,0) is data, not a shift key. I'm putting ' ' here consistently.
									// switch sets
									if (c == 'X') set = 0;
//									else if (c == 'x') set = 1;
//									else if (c == '9') set = 2;
//									else if (c == '?') set = 3;
//									else if (c == '!') set = 4;
								}
								else
								{
if (next <MAX_NAME)
{

									input[next++] = (char) c;
									input[next] = (char)0x80;
}
									//fprintf(stderr, "  '%s' adding %d  x=%d y=%d cx=%d cy=%d\n", input,c,x,y,cx,cy);
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

