//**********************************************************************
//**********************************************************************
//
//                            Dungeon Drawing Code
//
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"


const unsigned int const xWidthHalf[] =
{
	(MAX_WIDTH/1)/2, // level 1
	(MAX_WIDTH/2)/2, // level 2
	(MAX_WIDTH/3)/2, // level 3
	(MAX_WIDTH/4)/2, // level 4
	(MAX_WIDTH/5)/2, // level 5
	(MAX_WIDTH/6)/2, // level 6
	(MAX_WIDTH/7)/2, // level 7
	(MAX_WIDTH/8)/2, // level 8
	(MAX_WIDTH/9)/2 // level 9
};
const unsigned int const  yHeightHalf[] =
{
	(MAX_HEIGHT/1)/2, // level 1
	(MAX_HEIGHT/2)/2, // level 2
	(MAX_HEIGHT/3)/2, // level 3
	(MAX_HEIGHT/4)/2, // level 4
	(MAX_HEIGHT/5)/2, // level 5
	(MAX_HEIGHT/6)/2, // level 6
	(MAX_HEIGHT/7)/2, // level 7
	(MAX_HEIGHT/8)/2, // level 8
	(MAX_HEIGHT/9)/2 // level 9
};

#define _DDRAWCalcRect(r,Level) \
(r)->left =  -xWidthHalf[Level];  \
(r)->right = +xWidthHalf[Level]; \
(r)->top =   +yHeightHalf[Level]; \
(r)->bottom= -yHeightHalf[Level];




const signed const int s_dscale[] =
{
	//        0xff,
	-128,
	0x40,
	0x20,
	0x10,
	0x08,
	0x04,
	0x02,
	0x01,
	0x00,
	0x00,
	0x00,
	0x00,
};

//**********************************************************************
//
//                            Draw the dungeon
//
//**********************************************************************
#define START_UPPER_LEFT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(*y_depth, -*x_depth);\
	VIA_t1_cnt_lo = *dscale;\
} while (0)
#define START_UPPER_RIGHT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(*y_depth, *x_depth);\
	VIA_t1_cnt_lo = *dscale;\
} while (0)
#define START_LOWER_LEFT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(-*y_depth, -*x_depth);\
	VIA_t1_cnt_lo = *dscale;\
} while (0)
#define START_LOWER_RIGHT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(-*y_depth, *x_depth);\
	VIA_t1_cnt_lo = *dscale;\
} while (0)

#define START_UPPER_LEFT_NEXT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(*(y_depth+1), -*(x_depth+1));\
	VIA_t1_cnt_lo = *(dscale+1);\
} while (0)
#define START_UPPER_RIGHT_NEXT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(*(y_depth+1), *(x_depth+1));\
	VIA_t1_cnt_lo = *(dscale+1);\
} while (0)
#define START_LOWER_LEFT_NEXT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(-*(y_depth+1), -*(x_depth+1));\
	VIA_t1_cnt_lo = *(dscale+1);\
} while (0)
#define START_LOWER_RIGHT_NEXT() do {\
	VIA_t1_cnt_lo = 0x80;\
	Reset0Ref();\
	Moveto_d(-*(y_depth+1), *(x_depth+1));\
	VIA_t1_cnt_lo = *(dscale+1);\
} while (0)
const signed char const WallBackFull[]=
{    (const signed char) 0x00, +0x12, -0x26,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x4B,  // pattern, y, x
	(const signed char) 0xFF, -0x25, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x4B,  // pattern, y, x
	(const signed char) 0xFF, +0x25, +0x00,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const Pit[]=
{    (const signed char) 0x00, -0x16, -0x1E,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x3B,  // pattern, y, x
	(const signed char) 0xFF, -0x0B, +0x0F,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x59,  // pattern, y, x
	(const signed char) 0xFF, +0x0B, +0x0F,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const SceneList_3[]=
{    (const signed char) 0x00, -0x1B, -0x15,  // pattern, y, x
	(const signed char) 0xFF, +0x35, +0x00,  // pattern, y, x
	(const signed char) 0x00, -0x08, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x29,  // pattern, y, x
	(const signed char) 0x00, +0x08, +0x00,  // pattern, y, x
	(const signed char) 0xFF, -0x35, +0x00,  // pattern, y, x
	(const signed char) 0x00, +0x06, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x29,  // pattern, y, x
	(const signed char) 0x00, +0x0D, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x29,  // pattern, y, x
	(const signed char) 0x00, +0x0D, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x29,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallSideLeftOpen[]=
{    (const signed char) 0x00, -0x13, -0x26,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x26,  // pattern, y, x
	(const signed char) 0x00, -0x12, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x49, +0x00,  // pattern, y, x
	(const signed char) 0x00, -0x12, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x26,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallSideRightOpen[]=
{    (const signed char) 0x00, -0x13, +0x25,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x26,  // pattern, y, x
	(const signed char) 0x00, -0x12, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x49, +0x00,  // pattern, y, x
	(const signed char) 0x00, -0x12, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x26,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const RightDoor[]=
{    (const signed char) 0x00, -0x18, +0x32,  // pattern, y, x
	(const signed char) 0xFF, +0x1D, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x0C,  // pattern, y, x
	(const signed char) 0xFF, -0x23, +0x00,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const LeftDoor[]=
{    (const signed char) 0x00, -0x1F, -0x40,  // pattern, y, x
	(const signed char) 0xFF, +0x24, +0x00,  // pattern, y, x
	(const signed char) 0xFF, -0x01, +0x0C,  // pattern, y, x
	(const signed char) 0xFF, -0x1D, +0x00,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const CenterDoor[]=
{    (const signed char) 0x00, -0x13, -0x0C,  // pattern, y, x
	(const signed char) 0xFF, +0x16, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x17,  // pattern, y, x
	(const signed char) 0xFF, -0x16, +0x00,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallLeftDiagonals[]=
{    (const signed char) 0x00, -0x25, -0x4C,  // pattern, y, x
	(const signed char) 0xFF, +0x12, +0x26,  // pattern, y, x
	(const signed char) 0x00, +0x25, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x12, -0x26,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallRightDiagonals[]=
{    (const signed char) 0x00, -0x25, +0x4B,  // pattern, y, x
	(const signed char) 0xFF, +0x12, -0x26,  // pattern, y, x
	(const signed char) 0x00, +0x25, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x12, +0x26,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallBackOpen[]=
{    (const signed char) 0x00, +0x12, -0x26,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x4B,  // pattern, y, x
	(const signed char) 0x00, -0x25, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x4B,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const LadderUp[]=
{    (const signed char) 0x00, -0x08, -0x15,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x29,  // pattern, y, x
	(const signed char) 0x00, +0x0D, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x29,  // pattern, y, x
	(const signed char) 0x00, +0x0D, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x29,  // pattern, y, x
	(const signed char) 0x00, +0x08, +0x00,  // pattern, y, x
	(const signed char) 0xFF, -0x35, +0x00,  // pattern, y, x
	(const signed char) 0x00, +0x06, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x29,  // pattern, y, x
	(const signed char) 0x00, -0x06, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x35, +0x00,  // pattern, y, x
	(const signed char) 0x00, +0x06, -0x18,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x59,  // pattern, y, x
	(const signed char) 0xFF, -0x0B, -0x0F,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x3B,  // pattern, y, x
	(const signed char) 0xFF, +0x0B, -0x0F,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const LadderDown[]=
{    (const signed char) 0x00, -0x1B, -0x15,  // pattern, y, x
	(const signed char) 0xFF, +0x35, +0x00,  // pattern, y, x
	(const signed char) 0x00, -0x08, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x29,  // pattern, y, x
	(const signed char) 0x00, +0x08, +0x00,  // pattern, y, x
	(const signed char) 0xFF, -0x35, +0x00,  // pattern, y, x
	(const signed char) 0x00, +0x06, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x29,  // pattern, y, x
	(const signed char) 0x00, -0x01, -0x09,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x3B,  // pattern, y, x
	(const signed char) 0xFF, -0x0B, +0x0F,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x59,  // pattern, y, x
	(const signed char) 0xFF, +0x0B, +0x0F,  // pattern, y, x
	(const signed char) 0x00, +0x0E, +0x09,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x29,  // pattern, y, x
	(const signed char) 0x00, +0x0D, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x29,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallBackRightOpen[]=
{    (const signed char) 0x00, -0x13, +0x25,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x4B,  // pattern, y, x
	(const signed char) 0xFF, +0x25, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x4B,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
const signed char const WallBackLeftOpen[]=
{    (const signed char) 0x00, +0x12, -0x26,  // pattern, y, x
	(const signed char) 0xFF, +0x00, +0x4B,  // pattern, y, x
	(const signed char) 0xFF, -0x25, +0x00,  // pattern, y, x
	(const signed char) 0xFF, +0x00, -0x4B,  // pattern, y, x
	(const signed char) 0x01 // endmarker (high bit in pattern not set)
};
void Draw_VLp_lessGap(void* const x);

#define DRAW(list) \
dp_VIA_cntl = 0xce; \
Draw_VLp_lessGap((void* const)list); \
Reset0Ref();

void _DRAWDungeon(unsigned int Left,unsigned int Centre,unsigned int Right, int Room, int Monster, unsigned int distance)
{
	//    int x1,y1,x,y,y2;
	//    RECT r;
	
	// draw from outer to inner
	if (ISDRAWOPEN(Left))                    // Do we draw the left edge
	{
		DRAW(WallSideLeftOpen);
	}
	else                                    // If closed, draw left diags
	{
		DRAW(WallLeftDiagonals);
	}
	
	if (ISDRAWOPEN(Right))                    // Do we draw the right edge
	{
		DRAW(WallSideRightOpen);
	}
	else                                    // If closed draw right diags
	{
		DRAW(WallRightDiagonals);
	}
	
	// draw inner
	if (!ISDRAWOPEN(Centre))                // Back wall ?
	{
		if ((!ISDRAWOPEN(Left)) && (!ISDRAWOPEN(Right)))
		{
			// draw a square
			DRAW(WallBackFull);
		}
		else  if (!ISDRAWOPEN(Left))
		{
			// draw three sides right open
			DRAW(WallBackRightOpen);
		}
		else  if (!ISDRAWOPEN(Right))
		{
			// draw three sides Left open
			DRAW(WallBackLeftOpen);
		}
		else
		{
			// draw bottom and top
			DRAW(WallBackOpen);
		}
	}
	if (Left == DT_DOOR)
	{
		DRAW(LeftDoor);
	}
	if (Right == DT_DOOR)
	{
		DRAW(RightDoor);
	}
	if (Centre == DT_DOOR)
	{
		DRAW(CenterDoor);
	}
	
	if (Room == DT_LADDERUP)
	{
		DRAW(LadderUp);
	}
	else if (Room == DT_LADDERDN)
	{
		DRAW(LadderDown);
	}
	else if (Room == DT_PIT)
	{
		DRAW(Pit);
	}
	else if (Room == DT_GOLD)                // Draw the gold (as a mimic)
	{
		DRAWMonster(MN_MIMIC,distance);
		Reset0Ref();
	}
	if (Monster > 0)                    // Monster here ?
	{
		DRAWMonster(Monster,distance);
		Reset0Ref();
	}
	
}





void DDRAWDraw(PLAYER *p,DUNGEONMAP *d)
{
unsigned int *dscale;
COORD /*Dir*/Pos,Next;
	dscale = (unsigned int *)s_dscale;
	int monsterDone = 0;
	unsigned int x,y;
	unsigned int  Level = 0;
	int Monster;
	unsigned int Front,Left,Right;
	Pos = p->Dungeon;                        // Get position
	x= p->DungDir.x;
	y= p->DungDir.y;
	Reset0Ref();

       
    if (y == 0)
    {
		Next.y = Pos.y;
	do
	{
		dp_VIA_t1_cnt_lo = *dscale;
		Level++;                            // Next level
		Next.x = Pos.x +x;        // Next position
		Front = d->Map[Next.x][Next.y];        // What's in front ?
		
		Left = d->Map[Pos.x][Pos.y-x];
		Right = d->Map[Pos.x][Pos.y+x];
		if (monsterDone == 0)
		{
			Monster = DDRAWFindMonster(d,&Pos);    // Find ID of monster here
			if (Monster >= 0)                    // Find Type if Found
			{
				Monster = (int)d->Monster[Monster].Type;
        			monsterDone =1;
			}
		}
		else
		    Monster = -1;
		_DRAWDungeon(Left,Front,Right, (int)d->Map[Pos.x][Pos.y], Monster, Level);               // Draw the dungeon
		
		Pos = Next;                            // Next position down
		dscale++;
		
	}
	while (Level < MAX_VIEW_DEPTH && ISDRAWOPEN(Front));
	
            }
    else
    {
		Next.x = Pos.x;
	do
	{
		dp_VIA_t1_cnt_lo = *dscale;
		Level++;                            // Next level
		Next.y = Pos.y +y;
		Front = d->Map[Next.x][Next.y];        // What's in front ?
		
			Left = d->Map[Pos.x+y][Pos.y];
			Right = d->Map[Pos.x-y][Pos.y];
		if (monsterDone == 0)
		{
			Monster = DDRAWFindMonster(d,&Pos);    // Find ID of monster here
			if (Monster >= 0)                    // Find Type if Found
			{
				Monster = (int)d->Monster[Monster].Type;
			monsterDone =1;
			}
		}
		else
		Monster = -1;
		_DRAWDungeon(Left,Front,Right,(int) d->Map[Pos.x][Pos.y],Monster,Level);               // Draw the dungeon
		
		Pos = Next;                            // Next position down
		dscale++;
		
	}
	while (Level < MAX_VIEW_DEPTH && ISDRAWOPEN(Front));
    }
	
	if (monsterDone == 0)
    {
        	// check for one more monster in a "doorway"
        	if (! ISDRAWOPEN(Front))
        	{
        		Monster = DDRAWFindMonster(d,&Pos);    // Find ID of monster here
        		if (Monster >= 0)                    // Find Type if Found
        		{
        			Level++;                            // Next level
        			Monster = (int)d->Monster[Monster].Type;
        			DRAWMonster(Monster,Level);
        		}
        	}
    }
}

//**********************************************************************
//
//                    Find Monster ID at given location
//
//**********************************************************************

int DDRAWFindMonster(DUNGEONMAP *d,COORD *c)
{
	int i,n = -1;
	for (i = 0;i < d->MonstCount;i++)
	    if (c->x == d->Monster[i].Loc.x && c->y == d->Monster[i].Loc.y && d->Monster[i].Alive != 0)
	        n = i;
	return n;
}
