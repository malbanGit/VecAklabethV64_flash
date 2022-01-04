//**********************************************************************
//**********************************************************************
//																		
//							Data Structures								
//																		
//**********************************************************************
//**********************************************************************

typedef struct _Coord						// Coordinate structure 
{ unsigned int x,y; } COORD;

//**********************************************************************

typedef struct _Rect						// Rectangle structure 
{
	int left,top,right,bottom;				// Rectangle coords 
} RECT;

//**********************************************************************

typedef struct _WorldMap					// World Map structure 
{
	unsigned int MapSize;							// Size of map 
	unsigned char Map[WORLD_MAP_SIZE]		// Map information 
							[WORLD_MAP_SIZE];
} WORLDMAP;

//**********************************************************************

typedef struct _Monster						// Monster structure 
{
	COORD Loc;								// Position 
	unsigned int	  Type;								// Monster type 
	unsigned int	  Strength;							// Strength 
	int	  Alive;							// Alive flag 
} MONSTER;

//**********************************************************************

typedef struct _DungeonMap					// Dungeon Map Structure 
{
	unsigned int MapSize;							// Size of Map 
	unsigned char Map[DUNGEON_MAP_SIZE]		// Map information 
							[DUNGEON_MAP_SIZE];
	int	MonstCount;							// Number of Monsters 
	MONSTER Monster[MAX_MONSTERS];			// Monster records 
} DUNGEONMAP;

//**********************************************************************

// 10 + 6 + 9 + 24
// 49 byte
typedef struct _Player						// Player structure 
{
	char  Name[MAX_NAME+1];				// 9 Player Name 
	COORD World;							// 2 World map position 
	COORD Dungeon;						// 2 Dungeon map position 
	COORD DungDir;						// 2 Dungeon direction facing 
	char  Class;							// 1 Player class (F or M) 
	unsigned int   HPGain;					// 1 HPs gained in dungeon 
	unsigned int	  Level;					// 1 Dungeon level, 0 = world map 
	int	  Skill;							// 1 Skill level 
	int	  Task;							// 1 Task set (-1 = none) 
	int	  TaskCompleted;					// 1 Task completed 
	unsigned int	  LuckyNumber;			// 1 Value used for seeding 
	unsigned int	  Attributes;				// 1 Number of attributes 
	unsigned int	  Objects;				// 1 Number of objects 
	unsigned long int  Attr[MAX_ATTR];		// 12 Attribute values 
	unsigned long int  Object[MAX_OBJ];		// 12 Object counts 
     unsigned bits;                           // 1 0000 00AT; T = 0 -> map size == 3, T = 1map size == 4
                                              //          ; A = 0 -> no alternate tile set, T = 1 alternate tile set
} PLAYER;

