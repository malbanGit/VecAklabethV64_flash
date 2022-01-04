/************************************************************************/
/************************************************************************/
/*                                                                        */
/*                            Draw World Objects                            */
/*                                                                        */
/************************************************************************/
/************************************************************************/
#include <vectrex.h>

#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"


/************************************************************************/
/*                                                                        */
/*                    Draw object in a given rectangle                    */
/*                                                                        */
/************************************************************************/
void drawTown();
void drawTree();
void drawDungeon();
void drawMountain();
void drawCastle();

void drawTownA();
void drawTreeA();
void drawDungeonA();
void drawMountainA();
void drawCastleA();

void drawTown3();
void drawTree3();
void drawDungeon3();
void drawMountain3();
void drawCastle3();

void drawTown3A();
void drawTree3A();
void drawDungeon3A();
void drawMountain3A();
void drawCastle3A();

void DRAWTile7(unsigned char Obj)
{
	switch(Obj)                                /* Decide on the object */
	{
		case WT_MOUNTAIN:                        /* Mountain the cracked effect */
		VIA_t1_cnt_lo = 12; // scale
		drawMountain();
		break;
		case WT_TOWN:                            // Down is 5 boxes
		VIA_t1_cnt_lo = 10; // scale
		drawTown();
		break;
		case WT_TREE:                            // Tree is just a box
		VIA_t1_cnt_lo = 3; // scale
		drawTree();
		break;
		case WT_DUNGEON:                        // Dungeon is a cross
		VIA_t1_cnt_lo = 7; // scale
		drawDungeon();
		break;
		case WT_BRITISH:                        // British castle
		VIA_t1_cnt_lo = 12; // scale
		drawCastle();
		break;
		default:
		break;
	}
}
void DRAWTile7A(unsigned char Obj)
{
	switch(Obj)                                /* Decide on the object */
	{
		case WT_MOUNTAIN:                        /* Mountain the cracked effect */
		VIA_t1_cnt_lo = 10; // scale
		drawMountainA();
		break;
		case WT_TOWN:                            // Down is 5 boxes
		VIA_t1_cnt_lo = 10; // scale
		drawTownA();
		break;
		case WT_TREE:                            // Tree is just a box
		VIA_t1_cnt_lo = 10; // scale
		drawTreeA();
		break;
		case WT_DUNGEON:                        // Dungeon is a cross
		VIA_t1_cnt_lo = 10; // scale
		drawDungeonA();
		break;
		case WT_BRITISH:                        // British castle
		VIA_t1_cnt_lo = 12; // scale
		drawCastleA();
		break;
		default:
		break;
	}
}


void DRAWTile3(unsigned char Obj)
{
	switch(Obj)                                /* Decide on the object */
	{
		case WT_MOUNTAIN:                        /* Mountain the cracked effect */
		VIA_t1_cnt_lo = 12; // scale
		drawMountain3();
		break;
		case WT_TOWN:                            // Down is 5 boxes
		VIA_t1_cnt_lo = 10; // scale
		drawTown3();
		break;
		case WT_TREE:                            // Tree is just a box
		VIA_t1_cnt_lo = 3; // scale
		drawTree3();
		break;
		case WT_DUNGEON:                        // Dungeon is a cross
		VIA_t1_cnt_lo = 7; // scale
		drawDungeon3();
		break;
		case WT_BRITISH:                        // British castle
		VIA_t1_cnt_lo = 12; // scale
		drawCastle3();
		break;
		default:
		break;
	}
}

void DRAWTile3A(unsigned char Obj)
{
	switch(Obj)                                /* Decide on the object */
	{
		case WT_MOUNTAIN:                        /* Mountain the cracked effect */
		VIA_t1_cnt_lo = 9; // scale
		drawMountain3A();
		break;
		case WT_TOWN:                            // Down is 5 boxes
		VIA_t1_cnt_lo = 9; // scale
		drawTown3A();
		break;
		case WT_TREE:                            // Tree is just a box
		VIA_t1_cnt_lo = 9; // scale
		drawTree3A();
		break;
		case WT_DUNGEON:                        // Dungeon is a cross
		VIA_t1_cnt_lo = 9; // scale
		drawDungeon3A();
		break;
		case WT_BRITISH:                        // British castle
		VIA_t1_cnt_lo = 9; // scale
		drawCastle3A();
		break;
		default:
		break;
	}
}

