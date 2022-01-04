//**********************************************************************
//**********************************************************************
//
//                              World Map Code
//
//**********************************************************************
//**********************************************************************
#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"




// **********************************************************************
//
//                            Draw world map
//
// **********************************************************************

#define BLOW_UP 12
const signed char const PlayerList[]=
{    (const signed char) 0x00, -0x01*BLOW_UP, +0x00*BLOW_UP,  // pattern, y, x
	(const signed char) 0xFF, +0x02*BLOW_UP, +0x00*BLOW_UP,  // pattern, y, x
	(const signed char) 0x00, -0x01*BLOW_UP, +0x01*BLOW_UP,  // pattern, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x02*BLOW_UP,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};

#define BLOW_UP2 35
const signed char const PlayerList3[]=
{    (const signed char) 0x00, -0x01*BLOW_UP2, +0x00*BLOW_UP2,  // pattern, y, x
	(const signed char) 0xFF, +0x02*BLOW_UP2, +0x00*BLOW_UP2,  // pattern, y, x
	(const signed char) 0x00, -0x01*BLOW_UP2, +0x01*BLOW_UP2,  // pattern, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP2, -0x02*BLOW_UP2,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};


//**********************************************************************
//
//                            Read world map value
//
//**********************************************************************
	void drawMan7();

unsigned char WORLDRead(WORLDMAP *w, int x, int y)
{
	if (x < 0 || y < 0) return WT_SPACE;// WT_MOUNTAIN;
	if ((unsigned int)x > 20) return WT_SPACE;
	if ((unsigned int)y > 20) return WT_SPACE;
	return w->Map[x][y];
}

void WORLDDrawOnce()
{
	int x1; 
	int y1;
	int x,y, drawX;
	unsigned char *toDraw_p;
     x=-128;
    Intensity_a(0x2f); // set intensity of vector beam...

    #define GRID 3
    #define _W_ ((unsigned int)(255/GRID))
    #define _H_ ((unsigned int)(255/GRID))


    if (!(Player.bits & 1)) // 3 map
    {
        	x1 = (int)Player.World.x-(GRID/2);    // Which cell ?
        	y1 = (int)Player.World.y+(GRID/2);
        	
        	while (x1<0)
        	{
        		x1++;
        		x+=(int)_W_;
        	}
            
        	toDraw_p = (unsigned char *)( &World->Map[x1][y1]);
        if (!(Player.bits & 2)) // not alternate
        {
            	for (;x < GRID*_W_-128;x+=(int)_W_)            // For all grid cells
            	{
            		if (x1>20) break;
            		for (y=-128;y < GRID*_H_-128;y+=(int)_H_)
            		{
            			if ((y1<0) || (y1>20)) {y1--;toDraw_p--; continue;}
                        if (*toDraw_p != WT_SPACE)
                        {
                            dp_VIA_t1_cnt_lo = 0x4d; // scale
                            				
                            // Moveto_d(y,x);
                            dp_VIA_port_a = y;            // y pos to dac
                            dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
                            dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
                            drawX = x+40;
        //                    asm(" nop"); // cranky vectrex "wait
        //                    asm(" nop"); // cranky vectrex "wait
                            dp_VIA_port_b++;            // mux disable, dac only to x
        //                    dp_VIA_port_a = x;            // dac -> x
                            dp_VIA_port_a = drawX;            // dac -> x
                            dp_VIA_t1_cnt_hi=0;        // start timer
                            y1--;
                            DRAWTile3(*toDraw_p--);
                            dp_VIA_cntl = (unsigned int)0xcc;            // enable zero, enable all blank
                        }
            			else
            			{
            				y1--;
            				toDraw_p--;
            			}
            		}
            		y1+=GRID;
            		toDraw_p+=21+GRID;
            		x1++;
            	}
            	// playeris always right in the middle!
            	
            	VIA_t1_cnt_lo = 0x4d; // scale
            	
            	dp_VIA_port_a = (GRID/2)*_H_-128;            // y pos to dac
            	dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
            	dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
            	dp_VIA_port_b++;            // mux disable, dac only to x
              dp_VIA_port_a = (GRID/2)*_W_-128+40;            // dac -> x
            	dp_VIA_t1_cnt_hi=0;        // start timer
            	
            	
            	VIA_t1_cnt_lo = 0x60/4 +3-6; // scale
            while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
            Draw_VLp((void* const)PlayerList3);
            return;
        }
        else // 3alternate 
        {
            	for (;x < GRID*_W_-128;x+=(int)_W_)            // For all grid cells
            	{
            		if (x1>20) break;
            		for (y=-128;y < GRID*_H_-128;y+=(int)_H_)
            		{
            			if ((y1<0) || (y1>20)) {y1--;toDraw_p--; continue;}
                        if (*toDraw_p != WT_SPACE)
                        {
                            dp_VIA_t1_cnt_lo = 0x4d; // scale
                            				
                            // Moveto_d(y,x);
                            dp_VIA_port_a = y;            // y pos to dac
                            dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
                            dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
                            drawX = x+40;
        //                    asm(" nop"); // cranky vectrex "wait
        //                    asm(" nop"); // cranky vectrex "wait
                            dp_VIA_port_b++;            // mux disable, dac only to x
        //                    dp_VIA_port_a = x;            // dac -> x
                            dp_VIA_port_a = drawX;            // dac -> x
                            dp_VIA_t1_cnt_hi=0;        // start timer
                            y1--;
                            DRAWTile3A(*toDraw_p--);
                            dp_VIA_cntl = (unsigned int)0xcc;            // enable zero, enable all blank
                        }
            			else
            			{
            				y1--;
            				toDraw_p--;
            			}
            		}
            		y1+=GRID;
            		toDraw_p+=21+GRID;
            		x1++;
            	}
            	// playeris always right in the middle!
            	
    Intensity_a(0x3f); // set intensity of vector beam...
            	
            	VIA_t1_cnt_lo = 0x4d; // scale
            	
            	dp_VIA_port_a = (GRID/2)*_H_-128;            // y pos to dac
            	dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
            	dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
            	dp_VIA_port_b++;            // mux disable, dac only to x
            dp_VIA_port_a = (GRID/2)*_W_-128+40;            // dac -> x
            	dp_VIA_t1_cnt_hi=0;        // start timer
            	
            	
 //           	VIA_t1_cnt_lo = 0x60/4 +3-6; // scale
//            while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
//            Draw_VLp((void* const)PlayerList3);    



         VIA_t1_cnt_lo = 8; // scale
        while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
	     drawMan7();


            return;
        }


    }
#undef GRID
#undef _W_
#undef _H_

#define GRID 7
#define _W_ ((unsigned int)(255/GRID))
#define _H_ ((unsigned int)(255/GRID))
	
    	x1 = (int)Player.World.x-(GRID/2);    // Which cell ?
    	y1 = (int)Player.World.y+(GRID/2);
	
    	while (x1<0)
    	{
    		x1++;
    		x+=(int)_W_;
    	}
    
    	toDraw_p = (unsigned char *)( &World->Map[x1][y1]);
    	
     if (!(Player.bits & 2)) // not alternate
    {
        	for (;x < GRID*_W_-128;x+=(int)_W_)            // For all grid cells
        	{
        		if (x1>20) break;
        		for (y=-128;y < GRID*_H_-128;y+=(int)_H_)
        		{
        			if ((y1<0) || (y1>20)) {y1--;toDraw_p--; continue;}
                        if (*toDraw_p != WT_SPACE)
                        {
                            dp_VIA_t1_cnt_lo = 0x4d; // scale
                            				
                            // Moveto_d(y,x);
                            dp_VIA_port_a = y;            // y pos to dac
                            dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
                            dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
                            asm(" nop"); // cranky vectrex "wait
                            asm(" nop"); // cranky vectrex "wait
                            dp_VIA_port_b++;            // mux disable, dac only to x
                            dp_VIA_port_a = x;            // dac -> x
                            dp_VIA_t1_cnt_hi=0;        // start timer
                            y1--;
                            DRAWTile7(*toDraw_p--);
                            dp_VIA_cntl = (unsigned int)0xcc;            // enable zero, enable all blank
                        }
        			else
        			{
        				y1--;
        				toDraw_p--;
        			}
        		}
        		y1+=GRID;
        		toDraw_p+=21+GRID;
        		x1++;
        	}
        	// playeris always right in the middle!
    	
    	
        	VIA_t1_cnt_lo = 0x4d; // scale
        	
        	dp_VIA_port_a = (GRID/2)*_H_-128;            // y pos to dac
        	dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
        	dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
        	dp_VIA_port_b++;            // mux disable, dac only to x
            dp_VIA_port_a = (GRID/2)*_W_-128;            // dac -> x
        	dp_VIA_t1_cnt_hi=0;        // start timer
        	
        	
        	VIA_t1_cnt_lo = 0x60/4 +3-6; // scale
        while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
        Draw_VLp((void* const)PlayerList);    
        return;
    }
    else // 7 alternate
    {
        	for (;x < GRID*_W_-128;x+=(int)_W_)            // For all grid cells
        	{
        		if (x1>20) break;
        		for (y=-128;y < GRID*_H_-128;y+=(int)_H_)
        		{
        			if ((y1<0) || (y1>20)) {y1--;toDraw_p--; continue;}
                        if (*toDraw_p != WT_SPACE)
                        {
                            dp_VIA_t1_cnt_lo = 0x4d; // scale
                            				
                            // Moveto_d(y,x);
                            dp_VIA_port_a = y;            // y pos to dac
                            dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
                            dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
                            asm(" nop"); // cranky vectrex "wait
                            asm(" nop"); // cranky vectrex "wait
                            dp_VIA_port_b++;            // mux disable, dac only to x
                            dp_VIA_port_a = x;            // dac -> x
                            dp_VIA_t1_cnt_hi=0;        // start timer
                            y1--;
                            DRAWTile7A(*toDraw_p--);
                            dp_VIA_cntl = (unsigned int)0xcc;            // enable zero, enable all blank
                        }
        			else
        			{
        				y1--;
        				toDraw_p--;
        			}
        		}
        		y1+=GRID;
        		toDraw_p+=21+GRID;
        		x1++;
        	}
        	// playeris always right in the middle!
    	
		Intensity_a(0x3f); // set intensity of vector beam...
    	
        	VIA_t1_cnt_lo = 0x4d; // scale
        	
        	dp_VIA_port_a = (GRID/2)*_H_-128;            // y pos to dac
        	dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
        	dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
        	dp_VIA_port_b++;            // mux disable, dac only to x
            dp_VIA_port_a = (GRID/2)*_W_-128;            // dac -> x
        	dp_VIA_t1_cnt_hi=0;        // start timer
        	
        	
         VIA_t1_cnt_lo = 5; // scale
        while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes

	     drawMan7();

        return;
    }

}

#undef GRID
#undef _W_
#undef _H_


void WORLDDraw()
{
	while (1)
	{
		CLS;
		Wait_Recal();
		Do_Sound();
		VIA_t1_cnt_lo = 0x80; // scale
		Intensity_a(0x5f); /* set intensity of vector beam... */
		
		WORLDDrawOnce();
		
		check_buttons();
		if (buttons_pressed())
		{
			break;
		}
		
	}
}
