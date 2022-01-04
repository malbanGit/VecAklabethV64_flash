// used by eprom stuff
// global variables with "fixed" addresses in both banks!

// if included first
// AND
// initialized, than these variables here
// will have a fixed RAM location in both "banks"

unsigned char ds2431Present=0;
unsigned char current_eprom_blocksize=0;
unsigned char current_eprom_blockadr=0;

int last_horizontal1 = 0;
int last_vertical1 = 0;

unsigned int _x = 97; // random "stock"
unsigned int _a = 123;
unsigned int _b = 213;
unsigned int _c = 57;

int alternateTileSet = 1;

char statusString[] = "FOOD 12345  HP 12345  GOLD 12345\x80";

PLAYER     Player;                            // Player data

// for Vectrex double usage of memory
unsigned char memBlock[sizeof(WORLDMAP)];

WORLDMAP   *World = (WORLDMAP *) memBlock;                            // Current world map
DUNGEONMAP *Dungeon = (DUNGEONMAP *) memBlock;                            // Current dungeon map

unsigned int     tenthFood;
const char *tMessage;
unsigned int messageTime;
int _XC;
int _YC; // positioning of strings



unsigned int waitTimer;

// 48 byte == player
// eprom saves 56 byte
// overwriting message buffer upon read
char messageBuffer[40]; // one "line"
char stringBuffer4[4]; // one "int" (8bit)
char stringBuffer6[6]; // one "long" (16bit)
char stringBuffer40[40]; // one "line"
