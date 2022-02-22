//all global variables in cartridge?


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
//




#include <vectrex.h>
#include "../aklabeth.h"
#include "../globalsDef.h"
#include "../controller.h"
#include "../string.h"


#include "Ultima_songs.h"
#include <assert.h>
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

const signed char TitleList[]=
{    (signed char) 0x01, +0x7F, +0x7F, // sync and move to y, x
	(signed char) 0x00, +0x7F, +0x7F, // additional sync move to y, x
	(signed char) 0x00, +0x3E, +0x66, // additional sync move to y, x
	(signed char) 0xFF, -0x14, -0x1C, // draw, y, x
	(signed char) 0xFF, +0x10, -0x1C, // draw, y, x
	(signed char) 0xFF, +0x00, -0x24, // draw, y, x
	(signed char) 0xFF, -0x08, +0x1C, // draw, y, x
	(signed char) 0xFF, -0x14, +0x10, // draw, y, x
	(signed char) 0xFF, -0x08, +0x1C, // draw, y, x
	(signed char) 0xFF, -0x04, +0x28, // draw, y, x
	(signed char) 0xFF, +0x08, +0x18, // draw, y, x
	(signed char) 0xFF, +0x08, +0x30, // draw, y, x
	(signed char) 0xFF, +0x04, -0x44, // draw, y, x
	(signed char) 0xFF, +0x0C, +0x08, // draw, y, x
	(signed char) 0xFF, +0x14, +0x3C, // draw, y, x
	(signed char) 0xFF, -0x08, -0x5C, // draw, y, x
	(signed char) 0x01, -0x7F, +0x7F, // sync and move to y, x
	(signed char) 0x00, -0x31, +0x59, // additional sync move to y, x
	(signed char) 0xFF, +0x1C, +0x08, // draw, y, x
	(signed char) 0xFF, +0x50, -0x18, // draw, y, x
	(signed char) 0xFF, +0x18, +0x0C, // draw, y, x
	(signed char) 0xFF, +0x24, -0x04, // draw, y, x
	(signed char) 0xFF, +0x18, -0x10, // draw, y, x
	(signed char) 0xFF, +0x28, +0x00, // draw, y, x
	(signed char) 0xFF, +0x44, -0x38, // draw, y, x
	(signed char) 0xFF, +0x0E, -0x46, // draw, y, x
	(signed char) 0xFF, +0x0E, -0x46, // draw, y, x
	(signed char) 0xFF, -0x50, -0x68, // draw, y, x
	(signed char) 0xFF, -0x1C, -0x0C, // draw, y, x
	(signed char) 0xFF, -0x5C, -0x40, // draw, y, x
	(signed char) 0xFF, -0x6C, -0x20, // draw, y, x
	(signed char) 0xFF, -0x24, +0x0C, // draw, y, x
	(signed char) 0xFF, -0x24, -0x08, // draw, y, x
	(signed char) 0xFF, -0x3C, -0x34, // draw, y, x
	(signed char) 0x00, -0x0C, +0x10, // mode, y, x
	(signed char) 0xFF, -0x08, +0x0C, // draw, y, x
	(signed char) 0xFF, +0x10, +0x1C, // draw, y, x
	(signed char) 0xFF, +0x18, +0x14, // draw, y, x
	(signed char) 0xFF, +0x10, -0x10, // draw, y, x
	(signed char) 0xFF, +0x10, +0x08, // draw, y, x
	(signed char) 0xFF, +0x04, +0x10, // draw, y, x
	(signed char) 0xFF, -0x10, +0x04, // draw, y, x
	(signed char) 0xFF, +0x04, +0x1C, // draw, y, x
	(signed char) 0xFF, -0x0C, +0x00, // draw, y, x
	(signed char) 0xFF, -0x10, -0x18, // draw, y, x
	(signed char) 0xFF, -0x04, +0x14, // draw, y, x
	(signed char) 0xFF, -0x14, -0x08, // draw, y, x
	(signed char) 0xFF, +0x04, -0x2C, // draw, y, x
	(signed char) 0x01, -0x7F, -0x7F, // sync and move to y, x
	(signed char) 0x00, -0x7F, -0x4D, // additional sync move to y, x
	(signed char) 0x00, -0x26, +0x00, // additional sync move to y, x
	(signed char) 0x00, +0x48, +0x00, // mode, y, x
	(signed char) 0xFF, +0x18, +0x18, // draw, y, x
	(signed char) 0xFF, +0x54, -0x04, // draw, y, x
	(signed char) 0xFF, +0x18, +0x10, // draw, y, x
	(signed char) 0xFF, +0x24, +0x08, // draw, y, x
	(signed char) 0xFF, +0x2C, +0x20, // draw, y, x
	(signed char) 0xFF, +0x34, +0x18, // draw, y, x
	(signed char) 0xFF, -0x18, +0x14, // draw, y, x
	(signed char) 0xFF, -0x18, +0x08, // draw, y, x
	(signed char) 0xFF, +0x38, +0x1C, // draw, y, x
	(signed char) 0xFF, +0x24, +0x04, // draw, y, x
	(signed char) 0xFF, +0x14, +0x18, // draw, y, x
	(signed char) 0xFF, +0x0C, +0x24, // draw, y, x
	(signed char) 0xFF, -0x20, +0x0C, // draw, y, x
	(signed char) 0xFF, -0x1C, +0x00, // draw, y, x
	(signed char) 0xFF, +0x1C, +0x10, // draw, y, x
	(signed char) 0xFF, +0x24, +0x0C, // draw, y, x
	(signed char) 0xFF, -0x10, +0x20, // draw, y, x
	(signed char) 0xFF, -0x1C, +0x14, // draw, y, x
	(signed char) 0xFF, -0x58, +0x04, // draw, y, x
	(signed char) 0xFF, +0x18, +0x10, // draw, y, x
	(signed char) 0xFF, +0x24, +0x04, // draw, y, x
	(signed char) 0xFF, -0x0C, +0x24, // draw, y, x
	(signed char) 0xFF, -0x5C, +0x08, // draw, y, x
	(signed char) 0xFF, -0x18, -0x08, // draw, y, x
	(signed char) 0xFF, -0x70, +0x30, // draw, y, x
	(signed char) 0xFF, -0x3C, -0x04, // draw, y, x
	(signed char) 0xFF, -0x18, +0x0C, // draw, y, x
	(signed char) 0xFF, -0x34, +0x5C, // draw, y, x
	(signed char) 0x01, +0x7F, +0x7F, // sync and move to y, x
	(signed char) 0x00, +0x7F, +0x31, // additional sync move to y, x
	(signed char) 0x00, +0x42, +0x00, // additional sync move to y, x
	(signed char) 0xFF, +0x3C, -0x20, // draw, y, x                                    kesw
	(signed char) 0xFF, -0x4C, -0x30, // draw, y, x
	(signed char) 0x00, -0x44, -0x24, // mode, y, x
	(signed char) 0xFF, +0x34, -0x20, // draw, y, x
	(signed char) 0xFF, -0x1C, -0x1C, // draw, y, x
	(signed char) 0x00, -0x10, -0x18, // mode, y, x
	(signed char) 0xFF, -0x1C, +0x0C, // draw, y, x
	(signed char) 0xFF, +0x18, -0x0C, // draw, y, x
	(signed char) 0x00, +0x54, -0x20, // mode, y, x                aaa
	(signed char) 0xFF, -0x38, -0x10, // draw, y, x
	(signed char) 0xFF, -0x48, -0x24, // draw, y, x
	(signed char) 0xFF, -0x48, -0x24, // draw, y, x
	(signed char) 0x00, +0x04, -0x34, // mode, y, x
	(signed char) 0xFF, +0x18, -0x0C, // draw, y, x
	(signed char) 0x00, +0x14, -0x10, // mode, y, x
	(signed char) 0xFF, +0x10, +0x04, // draw, y, x
	(signed char) 0xFF, +0x0C, -0x08, // draw, y, x
	(signed char) 0x01, +0x7F, +0x7F, // sync and move to y, x
	(signed char) 0x00, +0x19, +0x7F, // additional sync move to y, x
	(signed char) 0x00, +0x00, +0x0E, // additional sync move to y, x
	(signed char) 0xFF, -0x08, +0x08, // draw, y, x
	(signed char) 0xFF, +0x04, +0x14, // draw, y, x
	(signed char) 0x00, -0x5C, +0x2C, // mode, y, x
	(signed char) 0xFF, +0x40, -0x18, // draw, y, x
	(signed char) 0xFF, +0x40, -0x18, // draw, y, x
	(signed char) 0xFF, -0x18, -0x1C, // draw, y, x
	(signed char) 0xFF, -0x0C, -0x20, // draw, y, x
	(signed char) 0xFF, +0x38, -0x08, // draw, y, x
	(signed char) 0xFF, +0x30, -0x1C, // draw, y, x
	(signed char) 0xFF, +0x3C, -0x10, // draw, y, x
	(signed char) 0xFF, -0x10, -0x1C, // draw, y, x
	(signed char) 0xFF, -0x18, -0x0C, // draw, y, x
	(signed char) 0xFF, +0x18, -0x0C, // draw, y, x
	(signed char) 0xFF, +0x04, -0x24, // draw, y, x
	(signed char) 0xFF, -0x40, -0x14, // draw, y, x
	(signed char) 0xFF, -0x24, -0x28, // draw, y, x
	(signed char) 0xFF, -0x1C, -0x10, // draw, y, x
	(signed char) 0xFF, +0x18, +0x04, // draw, y, x
	(signed char) 0xFF, +0x34, -0x18, // draw, y, x
	(signed char) 0xFF, +0x38, -0x0C, // draw, y, x
	(signed char) 0xFF, +0x2C, -0x20, // draw, y, x
	(signed char) 0xFF, -0x34, -0x1C, // draw, y, x
	(signed char) 0xFF, -0x40, -0x24, // draw, y, x
	(signed char) 0xFF, -0x14, -0x18, // draw, y, x
	(signed char) 0xFF, -0x34, -0x14, // draw, y, x
	(signed char) 0xFF, +0x18, -0x04, // draw, y, x
	(signed char) 0x01, +0x7F, -0x7F, // sync and move to y, x
	(signed char) 0x00, +0x39, -0x21, // additional sync move to y, x
	(signed char) 0xFF, +0x14, -0x1C, // draw, y, x
	(signed char) 0xFF, +0x50, -0x18, // draw, y, x
	(signed char) 0xFF, -0x1C, -0x10, // draw, y, x
	(signed char) 0xFF, -0x38, -0x0C, // draw, y, x
	(signed char) 0xFF, -0x38, -0x14, // draw, y, x
	(signed char) 0xFF, -0x34, -0x0C, // draw, y, x
	(signed char) 0xFF, -0x34, -0x10, // draw, y, x
	(signed char) 0xFF, -0x30, -0x1C, // draw, y, x
	(signed char) 0x00, +0x34, +0x08, // mode, y, x
	(signed char) 0xFF, -0x04, -0x2C, // draw, y, x
	(signed char) 0xFF, +0x08, -0x24, // draw, y, x
	(signed char) 0xFF, -0x0C, -0x20, // draw, y, x
	(signed char) 0xFF, +0x04, -0x24, // draw, y, x
	(signed char) 0x00, +0x04, +0x54, // mode, y, x
	(signed char) 0xFF, +0x24, +0x00, // draw, y, x
	(signed char) 0xFF, +0x00, +0x18, // draw, y, x
	(signed char) 0xFF, -0x10, +0x00, // draw, y, x
	(signed char) 0xFF, +0x00, +0x44, // draw, y, x
	(signed char) 0xFF, +0x3C, +0x00, // draw, y, x
	(signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(signed char) 0xFF, -0x08, +0x00, // draw, y, x
	(signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(signed char) 0xFF, +0x08, +0x00, // draw, y, x
	(signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(signed char) 0xFF, -0x3C, +0x00, // draw, y, x
	(signed char) 0x01, -0x38, +0x48, // sync and move to y, x
	(signed char) 0xFF, -0x08, -0x10, // draw, y, x
	(signed char) 0xFF, +0x08, -0x14, // draw, y, x
	(signed char) 0x00, -0x04, -0x14, // mode, y, x
	(signed char) 0xFF, -0x74, -0x1C, // draw, y, x
	(signed char) 0xFF, -0x20, -0x0C, // draw, y, x
	(signed char) 0xFF, +0x10, +0x2C, // draw, y, x
	(signed char) 0xFF, -0x10, +0x38, // draw, y, x
	(signed char) 0xFF, +0x0C, +0x14, // draw, y, x
	(signed char) 0xFF, -0x0C, +0x18, // draw, y, x
	(signed char) 0xFF, +0x42, -0x0E, // draw, y, x
	(signed char) 0xFF, +0x42, -0x0E, // draw, y, x
	(signed char) 0xFF, -0x10, -0x20, // draw, y, x
	(signed char) 0xFF, +0x20, -0x2C, // draw, y, x
	(signed char) 0x00, +0x14, -0x2C, // mode, y, x
	(signed char) 0xFF, +0x14, +0x00, // draw, y, x
	(signed char) 0xFF, +0x0C, +0x08, // draw, y, x
	(signed char) 0x01, -0x08, -0x14, // sync and move to y, x
	(signed char) 0xFF, +0x08, -0x04, // draw, y, x
	(signed char) 0xFF, -0x0C, -0x08, // draw, y, x
	(signed char) 0xFF, +0x10, -0x04, // draw, y, x
	(signed char) 0xFF, -0x0C, -0x0C, // draw, y, x
	(signed char) 0xFF, -0x0C, +0x04, // draw, y, x
	(signed char) 0xFF, -0x18, +0x00, // draw, y, x
	(signed char) 0x00, -0x10, -0x04, // mode, y, x
	(signed char) 0xFF, -0x3C, +0x00, // draw, y, x
	(signed char) 0xFF, +0x24, +0x08, // draw, y, x
	(signed char) 0x00, -0x28, +0x28, // mode, y, x
	(signed char) 0xFF, +0x10, -0x1C, // draw, y, x
	(signed char) 0xFF, +0x18, -0x08, // draw, y, x
	(signed char) 0xFF, +0x14, -0x08, // draw, y, x
	(signed char) 0xFF, +0x10, -0x0C, // draw, y, x
	(signed char) 0xFF, +0x08, +0x20, // draw, y, x
	(signed char) 0xFF, -0x14, -0x04, // draw, y, x
	(signed char) 0x01, -0x3C, -0x1C, // sync and move to y, x
	(signed char) 0xFF, -0x14, +0x08, // draw, y, x
	(signed char) 0xFF, +0x10, +0x14, // draw, y, x
	(signed char) 0xFF, +0x10, +0x24, // draw, y, x
	(signed char) 0xFF, +0x20, -0x04, // draw, y, x
	(signed char) 0xFF, +0x0C, +0x0C, // draw, y, x
	(signed char) 0xFF, +0x04, +0x14, // draw, y, x
	(signed char) 0xFF, -0x10, +0x10, // draw, y, x
	(signed char) 0xFF, -0x24, -0x04, // draw, y, x
	(signed char) 0xFF, -0x1C, +0x18, // draw, y, x
	(signed char) 0xFF, -0x18, +0x08, // draw, y, x
	(signed char) 0xFF, -0x1C, +0x08, // draw, y, x
	(signed char) 0xFF, -0x18, +0x14, // draw, y, x
	(signed char) 0xFF, -0x20, -0x05, // draw, y, x
	(signed char) 0xFF, -0x6C, +0x3D, // draw, y, x
	(signed char) 0xFF, +0x70, -0x44, // draw, y, x                        www
	(signed char) 0x01, -0x7F+0x40, +0x7C-0x50, // sync and move to y, x - for cranky vectrex the difference here is to hi!
	
	(signed char) 0x00, -0x39, +0x00+0x20, // additional sync move to y, x
	(signed char) 0x00, -0x14-0x40, -0x1C+0x30, // mode, y, x
	(signed char) 0xFF, -0x54, -0x08, // draw, y, x
	(signed char) 0xFF, -0x14, +0x00, // draw, y, x
	(signed char) 0xFF, +0x04, +0x14, // draw, y, x
	(signed char) 0xFF, -0x08, +0x0C, // draw, y, x
	(signed char) 0xFF, -0x14, -0x24, // draw, y, x
	(signed char) 0xFF, -0x04, -0x14, // draw, y, x
	(signed char) 0xFF, +0x70, -0x08, // draw, y, x                2222
	(signed char) 0xFF, -0x4C, -0x14, // draw, y, x
	(signed char) 0xFF, -0x18, +0x00, // draw, y, x
	(signed char) 0xFF, -0x0C, -0x08, // draw, y, x
	(signed char) 0xFF, +0x04, -0x20, // draw, y, x
	(signed char) 0xFF, +0x20, -0x10, // draw, y, x
	(signed char) 0xFF, -0x0C, +0x1C, // draw, y, x
	(signed char) 0xFF, +0x34, +0x0C, // draw, y, x
	(signed char) 0xFF, +0x40, -0x0C, // draw, y, x
	(signed char) 0x02 // endmarker
};
#define ZERO_DELAY 2

void draw_synced_list_c(
signed char *u,
unsigned int scaleList)
{
	dp_VIA_t1_cnt_lo = scaleList;
	do
	{
		// resnyc / startsync
		dp_VIA_shift_reg = 0;        // all output is BLANK
		
		// move to zero
		dp_VIA_cntl = 0xcc;    // zero the integrators
		dp_VIA_port_a = 0;            // reset integrator offset
		dp_VIA_port_b = (int)0b10000010;
		
		// delay, till beam is at zero
		// volatile - otherwise delay loop does not work with -O
		for (volatile signed int b=ZERO_DELAY; b>0; b--);
		dp_VIA_port_b= (int)0b10000011;
		
		dp_VIA_cntl = 0xce;    // disable zero, disable all blank
		
		u+=3;
		// moveing test for yx== 0 into the move delay
		if ((*(u-2)!=0) || (*(u-1)!=0))
		{
			// internal moveTo
			dp_VIA_port_a = *(u-2);    // y pos to dac
			dp_VIA_cntl = 0xce;    // disable zero, disable all blank
			dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
			dp_VIA_port_b = 1;            // mux disable, dac only to x
			dp_VIA_port_a = *(u-1);    // dac -> x
			dp_VIA_t1_cnt_hi=0;        // start timer
			
			asm volatile( "pshs     u,cc\n\t" :::"memory"); //wait 16 cycles
			asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
			asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
			asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
			asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
			asm volatile( "puls     u,cc\n\t" :::"memory"); //wait 16 cycles
			
			//            while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
		}
		
		while (1)
		{
			dp_VIA_shift_reg = 0;            // all output is BLANK
			if (*u<0) // draw line
			{
				// draw a vector
				dp_VIA_port_a = *(1+u);        // y pos to dac
				dp_VIA_port_b = 0;                // mux enable, dac to -> integrator y (and x)
				dp_VIA_port_b=1;                // mux disable, dac only to x
				dp_VIA_port_a = *(2+u);        // dac -> x
				dp_VIA_t1_cnt_hi=0;            // start timer
				dp_VIA_shift_reg = 0xff;    // draw complete line
				asm volatile( "pshs     u,cc\n\t" :::"memory"); //wait 16 cycles
				asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
				asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
				asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
				asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
				asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
				asm volatile( "puls     u,cc\n\t" :::"memory"); //wait 16 cycles
				//                while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
				//                dp_VIA_shift_reg = 0;            // all output is BLANK
			}
			else if (*u == 0) // moveTo
			{
				if ((*(u+1)!=0) || (*(u+2)!=0))
				{
					// internal moveTo
					dp_VIA_port_a = *(1+u);    // y pos to dac
					dp_VIA_cntl = 0xce;    // disable zero, disable all blank
					dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
					dp_VIA_port_b =1;            // mux disable, dac only to x
					dp_VIA_port_a = *(2+u);    // dac -> x
					dp_VIA_t1_cnt_hi=0;        // start timer
					asm volatile( "pshs     u,cc\n\t" :::"memory"); //wait 16 cycles
					asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
					asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
					asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
					asm volatile( "nop\n\t" :::"memory"); //wait 16 cycles
					asm volatile( "puls     u,cc\n\t" :::"memory"); //wait 16 cycles
					//                    while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
				}
			}
			else
			{
				break;
			}
			u+=3;
		}
	} while (*u != 2);
}


extern void syncPrintStrd(const int a, const int b, void* const u);
#define Print_Str_d syncPrintStrd

#define printDirect(text) do {Print_Str_d((_YC-=0x10),_XC, (void* const)(text));} while (0)
#define print(text) do {printDirect( (text "\x80")  );} while (0)
#define CLS do{_XC = -0x70;_YC = 0x70;} while(0)
#define ADDLINE do{_YC -= 0x10;} while(0)
#define WAIT(a) do {waitTimer = a;} while (0)

#define TEXT_SCALE (0x44)
#define MESSAGE_SCALE (0x50)

extern void displayImage2();
const char * const lines[];
void introText(const char * const lines[], int count);
void drawAkalabeth();


void beQuiet();

void inputName();

void doSettings()
{
	int pos = 0;
	int buttonState = 0;
	unsigned int play = Vec_Max_Players&0x80;
	if (play) Vec_Max_Players = 0;

	while (1)
	{
		CLS;
		Wait_Recal();
		if (play)
		{
			ym_sound(); // uses 166 bytes of user RAM from 0cb00 onward (Stack area)
			Do_Sound();
		}
		check_buttons();
		check_joysticks();
		Reset0Ref();
		dp_VIA_t1_cnt_lo = TEXT_SCALE; // scale
		
		
		if (joystick_1_up()) pos=0;
		if (joystick_1_down()) pos=1;
		
		if (joystick_1_left())
		{
			if (pos == 0)
			Vec_Max_Players = Vec_Max_Players | 1;
			if (pos == 1)
			Vec_Max_Players = Vec_Max_Players | 2;
		}
		if (joystick_1_right())
		{
			if (pos == 0)
			Vec_Max_Players = Vec_Max_Players & (~1);
			if (pos == 1)
			Vec_Max_Players = Vec_Max_Players & (~2);
		}
		
		Intensity_a(0x5f); // set intensity of vector beam...
		print("SETTINGS" );
		ADDLINE;
		ADDLINE;
		ADDLINE;
		
		if (pos == 0)
		Intensity_a(0x7f); // set intensity of vector beam...
		else
		Intensity_a(0x3f); // set intensity of vector beam...
		
		if (Vec_Max_Players &1)
		print("SIZE: 7 x 7 " );
		else
		print("SIZE: 3 x 3 " );
		
		if (pos == 1)
		Intensity_a(0x7f); // set intensity of vector beam...
		else
		Intensity_a(0x3f); // set intensity of vector beam...
		ADDLINE;
		ADDLINE;
		if (Vec_Max_Players &2)
		print("TILE: MODERN" );
		else
		print("TILE: ORIGINAL" );
		
		ADDLINE;
		ADDLINE;
		ADDLINE;
		ADDLINE;
		Intensity_a(0x5f); // set intensity of vector beam...
		print("JOYSTICK TO CHANGE");
		print("BUTTON TO EXIT");
		
		if (buttonState == 0)
		{
			if (buttons_pressed())
			{
				buttonState=1;
			}
		}
		else
		{
			if (!buttons_pressed())
			{
				break;;
			}
		}
	}
	return;
}


const char * const help[];

extern void checkSavedFlash();

void __attribute__((used)) introImage(void)
{
	int buttonState = 0;
	int intensity = 0;
	long int timer = 0;
	ym_init(&Ultima_III_a_data);
	int intensityMode = 0; // 0 increase, 1 stay, 2 decrease / image 1
#ifdef BUILD_FOR_FLASH
    checkSavedFlash(); // this also respects FIRST start
#endif
/*
            		while (1)
            		{
            			CLS;
            			Wait_Recal();
            			Intensity_a(0x5f); // set intensity of vector beam...
                		VIA_t1_cnt_lo = TEXT_SCALE; // scale
            			ADDLINE;

 printfi("$b000: %",* ((char *) 0xb000  ) );
 printfl("startblock: %",* (( unsigned long *) 0xC831  ) );

            			check_buttons();
            			if (buttons_pressed()) break;
            		}
*/


	while (1)
	{
		Wait_Recal();
		timer++;
		
		ym_sound(); // uses 166 bytes of user RAM from 0cb00 onward (Stack area)
		Do_Sound();
		
		if (intensityMode == 0)
		{
			if (intensity<120)
			intensity++;
			else intensityMode = 1; // stay
		}
		else if (intensityMode == 2)
		{
			if (intensity>0)
			intensity--;
			else intensityMode = 3;
		}
		else if (intensityMode == 3)
		{
			if (intensity<120)
			intensity++;
			else intensityMode = 4; // stay
		}
		else if (intensityMode == 5)
		{
			if (intensity>0)
			intensity--;
			else intensityMode = 0;
		}
		
		Intensity_a((unsigned int)intensity); // set intensity of vector beam...
		
		if (timer == 10L*50L)
		{
			timer = 0;
			intensityMode++;
		}
		
		if (intensityMode <= 2)
		draw_synced_list_c((signed char *)TitleList,0x20);
		else
		displayImage2();
		Intensity_a(0x3f); // set intensity of vector beam...
		Reset0Ref();
		dp_VIA_t1_cnt_lo = 0x6e;
		Vec_Text_Width = 0x28;
#ifdef BUILD_FOR_FLASH
         if (Vec_Num_Players == 0)
        		syncPrintStrd(-0x78, -0x60, "(1)LOAD (2)CONFIG (3)HELP (4)NEW\x80");
         else
#endif
        		syncPrintStrd(-0x78, -0x60, "(2)CONFIG (3)HELP (4)NEW\x80");
		
		check_buttons();

		if (buttonState == 0)
		{
			if (buttons_pressed())
			{
				buttonState=1;
				Vec_Num_Game = 0;
#ifdef BUILD_FOR_FLASH
				if (button_1_1_pressed()) Vec_Num_Game = 1;
#endif
				if (button_1_2_pressed()) Vec_Num_Game = 2;
				if (button_1_3_pressed()) Vec_Num_Game = 3;
				if (button_1_4_pressed()) Vec_Num_Game = 4;
			}
		}
		else
		{
			if (!buttons_pressed())
			{
				if (Vec_Num_Game == 2)
				{
					doSettings();
					buttonState = 0;
					Vec_Num_Game = 0;
					continue;
				}
				if (Vec_Num_Game == 3)
				{
    introText(help, 36);
					buttonState = 0;
					Vec_Num_Game = 0;
					continue;
				}
				break;;
			}
		}
	}
	beQuiet();
	if (Vec_Num_Game == 1) return;
	ym_init(&Ultima_III_b_data);
	Vec_Text_Width = 0x28;
	
	int _XC;
	int _YC;
	
	while (1)
	{
		CLS;
		Wait_Recal();
                            dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
VIA_t1_cnt_lo = 10; // scale
drawAkalabeth();
		ym_sound(); // uses 166 bytes of user RAM from 0cb00 onward (Stack area)
		Do_Sound();
		
		dp_VIA_t1_cnt_lo = TEXT_SCALE; // scale
		
		Intensity_a(0x5f); // set intensity of vector beam...

		ADDLINE;
		ADDLINE;
		ADDLINE;
		ADDLINE;
		print("AKLABETH BY PAUL ROBSON." );
		print("FROM THE APPLE II");
		print("GAME BY RICHARD GARRIOTT.");
		ADDLINE;
		
		print("VECTREX PORT BY MALBAN");
		print("(VERSION 1.00 - RC)");
		check_buttons();
		if (buttons_pressed())
		{
			break;
		}
	}
	
	// be quiet!
	beQuiet();
    introText(lines, 15);
	
}


const char * const lines[]=
{
	"Many, many, many years ago the\x80" ,
	"Dark Lord Mondain, Archfoe of\x80",
	"British, traversed the lands of\x80",
	"Akalabeth spreading evil and death\x80",
	"as he passed.\x80",
	"  \x80",
	"  \x80",
	"By the time Mondain was driven\x80",
	"from the land by British, bearer\x80",
	"of the White Light, he had done\x80",
	"much damage unto the lands.\x80",
	"  \x80",
	"  \x80",
	"'Tis thy duty to help rid Akalabeth\x80",
	"of the foul beasts which infect it,\x80",
	"while trying to stay alive!!!\x80"
};


const char * const help[]=
{
	"GENERAL\x80" ,
	"Button 1\x80",
#ifdef BUILD_FOR_FLASH
	"Show currents stats, save\x80",
	"game and change settings.\x80",
#else
	"Show currents stats\x80",
	"change settings.\x80",
#endif
	" \x80",
	"Button 2\x80",
	"Redisplay last message.\x80",
	" \x80",
	" \x80",
	"MAP\x80" ,
	"Move with joystick, enter\x80",
	"buildings with Button 3.\x80",
	" \x80",
	" \x80",
	"DUNGEON\x80" ,
	"Move with joystick.\x80",
	" \x80",
	"Button 3\x80",
	"Use ladders.\x80",
	" \x80",
	"Button 4\x80",
	"Enter attack mode!\x80",
	" \x80",
	" \x80",
	"ATTACK MODE\x80" ,
	"Chose a weapon by keeping\x80",
	"a button combination pressed.\x80",
	"Execute attack by additionally\x80",
	"pressing button 4.\x80",
	" \x80",
	"Button combinations:\x80" ,
	"no Button  - Hands\x80",
	"Button 1   - Rapier\x80",
	"Button 2   - Axe\x80",
	"Button 3   - Bow\x80",
	"Button 1+2 - Shield\x80",
	"Button 1+3 - Amulet\x80",
};





void introText(const char * const data[], int count)
{
	int _XC;
	int _YC;
	
	//    int buttonState = 0;
	int intensity = 0x3f;
	
	ym_init(&Ultima_III_e_data);
	
	
	
	Intensity_a((unsigned int)intensity); // set intensity of vector beam...
	
	Vec_Text_Width = 0x28;
	
	
	int start_YC = 0x60;
	int startLine = -7;
	int slowDown=3;
	while (1)
	{
		_XC=-110;
		_YC=start_YC;
		
		Wait_Recal();
		ym_sound(); // uses 166 bytes of user RAM from 0cb00 onward (Stack area)
		Do_Sound();
		dp_VIA_t1_cnt_lo = TEXT_SCALE; // scale
		
		Intensity_a(0x5f); // set intensity of vector beam...
		dp_VIA_t1_cnt_lo = 0x50;
		Vec_Text_Width = 0x20;
		
		int currentString = startLine;
		int displayed = 0;
		while (_YC > -40)
		{
			int displayThis = 1;
			if (currentString <0) displayThis = 0;
			if (displayed>6) displayThis = 0;
			
			if (currentString >count) displayThis = 0;
			
			
			if (displayThis)
			{
				unsigned int inti = 0x5f;
				int add = start_YC & 0xf;
				if (displayed == 0) inti = (unsigned int) (0x1f+(0xf-add));
				if (displayed == 1) inti = (unsigned int) (0x3f+(0xf-add));
				
				if (displayed == 6) inti = (unsigned int) (0x1f+add);
				if (displayed == 5) inti = (unsigned int) (0x3f+add);
				
				Intensity_a(inti); // set intensity of vector beam...
				syncPrintStrd(_YC, _XC, (void* const) data[currentString]);
			}
			
			
			displayed++;
			_YC -= 0x10;
			currentString++;
		}
		if (slowDown-- == 0)
		{
			slowDown = 3;
			start_YC+=1;
			if (start_YC==0x60+0x10)
			{
				start_YC=0x60;
				startLine++;
				if (startLine>count+2) startLine = -7;
			}
		}
		
		
		check_buttons();
		if (buttons_pressed())
		{
			break;
		}
	}
	beQuiet();
}
void beQuiet()
{
	// be quiet!
	for (unsigned int i=0; i<= 0x0d; i++)
	{
		if (i!=7)
		Sound_Byte(i,0);
		else
		Sound_Byte(i,0x3f);
	}
}




// unused!
int main(void)
{
}

// ***************************************************************************
// end of file
// ***************************************************************************

#include "../BothBanks.i"
