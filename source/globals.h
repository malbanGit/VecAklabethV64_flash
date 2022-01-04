// used by eprom stuff
// global variables with "fixed" addresses in both banks!

// if included first
// AND
// initialized, than these variables here
// will have a fixed RAM location in both "banks"

extern unsigned char ds2431Present;
extern unsigned char current_eprom_blocksize;
extern unsigned char current_eprom_blockadr;

extern int last_horizontal1;
extern int last_vertical1;

extern unsigned int _x; // random "stock"
extern unsigned int _a;
extern unsigned int _b;
extern unsigned int _c;

extern int alternateTileSet;

extern char statusString[];

extern PLAYER Player;                            // Player data

// for Vectrex double usage of memory
extern unsigned char memBlock[sizeof(WORLDMAP)];

extern WORLDMAP   *World;                            // Current world map
extern DUNGEONMAP *Dungeon;                            // Current dungeon map

extern unsigned int     tenthFood;
extern const char *tMessage;
extern unsigned int messageTime;
extern int _XC;
extern int _YC; // positioning of strings

extern unsigned int waitTimer;

// 48 byte == player
// eprom saves 56 byte
// overwriting message buffer upon read
extern char messageBuffer[40]; // one "line"
extern char stringBuffer4[4]; // one "int" (8bit)
extern char stringBuffer6[6]; // one "long" (16bit)
extern char stringBuffer40[40]; // one "line"
