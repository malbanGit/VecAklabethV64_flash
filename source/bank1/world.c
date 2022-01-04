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

//**********************************************************************
//
//            Create the world map, set player start position
//
//**********************************************************************

void WORLDCreate(PLAYER *p,WORLDMAP *w)
{
	unsigned int c,x,y,Size;
	//    double v;
	//    srand(p->LuckyNumber);                    // Seed the random number
	setRandSeed(p->LuckyNumber);
	Size = (unsigned int) (MAINSuper()?WORLD_MAP_SIZE-1:20);    // Calculate map size
	w->MapSize = Size;                        // Save the map size
	for (x = 0;x <= Size;x++)                // Draw the boundaries
	{
		w->Map[Size][x] = WT_MOUNTAIN;
		w->Map[0][x] = WT_MOUNTAIN;
		w->Map[x][Size] = WT_MOUNTAIN;
		w->Map[x][0] = WT_MOUNTAIN;
	}
	for (x = 1;x < Size;x++)                // Draw the rest of it
	for (y = 1;y < Size;y++)
	{// c must be a number between: 0-4
		// with a heavy emphasis on lower numbers
		//        c = (int)(pow(RND(),5.0)*4.5);    // Calculate what's there
		//                  if (c == WT_TOWN && RND() > .5)    // Remove half the towns
		//        c = WT_SPACE;
		
		//#define    WT_SPACE        (0)                    /* World Tiles */
		//#define WT_MOUNTAIN        (1)
		//#define WT_TREE            (2)
		//#define    WT_TOWN            (3)
		//#define    WT_DUNGEON        (4)
		//#define    WT_BRITISH        (5)
		//#define    WT_PLAYER        (-1)                /* Used for the player graphic */
		
		
		c = Rand();
		if (c<170) c = 0;
		else if (c<220) c = 1;
		else if (c<248) c = 2;
		else if (c<252) c = 4;
		else  c = 3;
		
		w->Map[x][y] = c;                // Save in map
	}
	// only first time
	x =  Rand() % (Size-1)+1;                // Calculate player start
	y =  Rand() % (Size-1)+1;
	w->Map[x][y] = WT_TOWN;                    // Make it a town
	if ((p->World.x == 0) && (p->World.y == 0))
	{
		p->World.x = x;p->World.y = y;            // Save it
	}
	do                                        // Find place for castle
	{
		x = Rand() % Size + 1;
		y = Rand() % Size + 1;
	}
	while (w->Map[x][y] != WT_SPACE);
	w->Map[x][y] = WT_BRITISH;                // Put LBs castle there
}

//**********************************************************************
//
//                            Read world map value
//
//**********************************************************************

unsigned char WORLDRead(WORLDMAP *w, int x, int y)
{
	if (x < 0 || y < 0) return WT_SPACE;// WT_MOUNTAIN;
	if ((unsigned int)x > 20) return WT_SPACE;
	if ((unsigned int)y > 20) return WT_SPACE;
	return w->Map[x][y];
}
