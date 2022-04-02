// READ!!!
//
// if not defined, build will be done for a 64k cart
// if using VIDE
// You also MUST change the project settings
// DISABLE 
//           48k ROM
//           Flash support
//
// otherwise the bin file will be the wrong size 
// and you can not burn it to an eprom
//
// ******
// FLASH - the produced "bin" will be 128kB
// ******
// to burn it to a flash with 256kB storage, this must still be doubled
// just concatinate the file twice to result in a 256kB file.
// if your flash ROM "only" has 128kB, than you can use the file out of the box
// (saving/loading to flash is enabled)
//
//
// ******
// 64k Bankswitch
// ******
// Do as said above (switching projct settingsm and disable the define below)
// than a 64Kb bin will be created by Vide, that can be burned to any
// PB6 bank switched 64k card
// (saving/loading is disabled)
#define BUILD_FOR_FLASH 1



/************************************************************************/
/************************************************************************/
/*                                                                        */
/*                            Standard Include File                        */
/*                                                                        */
/************************************************************************/
/************************************************************************/

//#define DEBUG_PRINT 1

#define     AKVERSION            (1.000)            /* Version number */

#define ABS(a) ((signed int) ( ((signed int)(a))>0?((signed int)(a)):(-((signed int)(a)))  )  )
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


#define  WORLD_MAP_SIZE        (21)            /* Size of world map */
#define  DUNGEON_MAP_SIZE    (11)            /* Size of dungeon map */
#define  MAX_MONSTERS        (10)            /* Number of Monsters */
#define  MAX_ATTR            (6)                /* Attributes */
#define  MAX_OBJ            (6)                /* Objects */
#define  WORLD_GRID_SIZE    (3)                /* Visible part of map is axa */
#define  MAX_NAME            (8)                /* Max size player name */
#define  MAX_VIEW_DEPTH        (9)                /* Max viewing depth */

//#include <stdio.h>                            /* Some standard include files */
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
#include "struct.h"                            /* Our structure file */

/* Convert RGB to Colour Code */
#define RGB(r,g,b)  ((r?4:0)+(g?2:0)+(b?1:0))

#define C_BLACK        RGB(0,0,0)                /* Some Colours */
#define C_RED        RGB(1,0,0)
#define C_GREEN        RGB(0,1,0)
#define C_BLUE        RGB(0,0,1)
#define C_YELLOW    RGB(1,1,0)
#define C_WHITE     RGB(1,1,1)
#define C_CYAN        RGB(0,1,1)


//void DRAWTile(RECT *,unsigned char);                    /* DRAW.C prototyping */
void DRAWTile7(unsigned char );
void DRAWTile7A(unsigned char );
void DRAWTile3(unsigned char );
void DRAWTile3A(unsigned char );
void _DRAWSetRect(RECT *, int, int, int, int);
void DRAWMonster(int,unsigned int);
void DRAWDungeon(const RECT *, const RECT *,int,int,int,int,int, int);
void DRAWText(char *,...);

void MONSTAttack(PLAYER *,DUNGEONMAP *);    /* MONST.C prototyping */

int  MAINSuper(void);                        /* MAIN.C prototyping */
void MAINSetup(void);
void MAINStart(void);

void PLAYERInit(PLAYER *);                     /* PLAYER.C prototyping */
void PLAYERDebug(PLAYER *);
void PLAYERDemo(PLAYER *);
void PLAYERCharacter(PLAYER *);
void PLAYERInv(PLAYER *);

void DEADCode(PLAYER *);                    /* DEAD.C prototyping */
int  DEADGetYesNo(void);

char *GLOObjName(unsigned int);                        /* GLOBAL.C prototyping */
char *GLOAttribName(unsigned int);
char *GLOClassName(char);
char *GLOMonsterName(unsigned int);
char *GLOMonsterNameAttribute(int);
unsigned int GLOMonsterLevel(unsigned int);
void GLOGetInfo(unsigned int n,unsigned int *,unsigned int *,char *);

void BRITISHEnter(WORLDMAP *,PLAYER *);        /* BRITISH.C prototyping */

void WORLDCreate(PLAYER *,WORLDMAP *);        /* WORLD.C prototyping */
void WORLDDraw();
unsigned char WORLDRead(WORLDMAP *, int, int);

void DUNGEONCreate(PLAYER *,DUNGEONMAP *);    /* DUNGEON.C prototyping */

void DDRAWDraw(PLAYER *,DUNGEONMAP *);        /* DDRAW.C prototyping */
int DDRAWFindMonster(DUNGEONMAP *,COORD *);

void ATTACKMonster(PLAYER *,DUNGEONMAP *);    /* ATTACK.C prototyping */

/* MOVE.C prototyping */
void MOVEEnterExit(WORLDMAP *,PLAYER *,DUNGEONMAP *);
void MOVEMove(int,WORLDMAP *,PLAYER *,DUNGEONMAP *, int, int);
void MOVERotLeft(COORD *);
#define MAX_WIDTH 200
#define MAX_HEIGHT 100 // complete height can be drawn in one go!

#define RND()            (((double)rand())/RAND_MAX)

#define WT_SPACE        (0)                    /* World Tiles */
#define WT_MOUNTAIN        (1)
#define WT_TREE            (2)
#define WT_TOWN            (3)
#define WT_DUNGEON        (4)
#define WT_BRITISH        (5)
#define WT_PLAYER        (255)                /* Used for the player graphic */

#define DT_SPACE        (0)                    /* Dungeon tiles */
#define DT_SOLID        (1)
#define DT_TRAP            (2)
#define DT_HIDDENDOOR    (3)
#define DT_DOOR            (4)
#define DT_GOLD            (5)
#define DT_LADDERDN        (7)
#define DT_LADDERUP        (8)
#define DT_PIT            (9)

#define ISWALKTHRU(x)    ((x) != DT_SOLID)    /* Tests for them */
#define ISDRAWWALL(x)    ((x) == DT_SOLID || (x) == DT_HIDDENDOOR)
#define ISDRAWDOOR(x)   ((x) == DT_DOOR)
#define ISDRAWOPEN(x)    (ISDRAWWALL(x) == 0 && ISDRAWDOOR(x) == 0)


#define COL_WALL        (C_GREEN)            /* Object Colours */
#define COL_LADDER        (C_RED)
#define COL_DOOR        (C_BLUE)
#define COL_HOLE        (C_RED)
#define COL_MONSTER        (C_WHITE)
#define COL_MOUNTAIN    (C_YELLOW)
#define COL_TREE        (C_GREEN)
#define COL_DUNGEON        (C_RED)
#define COL_TOWN        (C_BLUE)
#define COL_BRITISH        (C_WHITE)
#define COL_PLAYER        (C_CYAN)

#define MN_SKELETON     (1)                    /* Monster types */
#define MN_THIEF        (2)
#define MN_RAT          (3)
#define MN_ORC          (4)
#define MN_VIPER        (5)
#define MN_CARRION      (6)
#define MN_GREMLIN      (7)
#define MN_MIMIC        (8)
#define MN_DAEMON       (9)
#define MN_BALROG       (10)

#define AT_HP            (0)                /* Player attributes */
#define AT_STRENGTH        (1)
#define AT_DEXTERITY    (2)
#define AT_STAMINA        (3)
#define AT_WISDOM        (4)
#define AT_GOLD            (5)

#define OB_FOOD            (0)                /* Object Attributes */
#define OB_RAPIER        (1)
#define OB_AXE            (2)
#define OB_SHIELD        (3)
#define OB_BOW            (4)
#define OB_AMULET        (5)

//#define Print_List syncPrintList
#define Print_Str_d syncPrintStrd

#define NULL 0

extern unsigned int tenthFood;
void HWStatus();


#define UPDATE_FOOD(f) ltoaP((f), statusString+5)
#define UPDATE_HP(h) ltoaP((h), statusString+15)
#define UPDATE_GOLD(g) ltoaP((g), statusString+27)

// the status bar alone (without message)
// uses 8600 cycles!!!
extern char statusString[];
