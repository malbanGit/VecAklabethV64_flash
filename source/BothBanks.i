
//**********************************************************************
//
//                        Redraw the main display
//
//**********************************************************************


// the status bar alone (without message)
void HWStatus()
{
	dp_VIA_t1_cnt_lo = MESSAGE_SCALE; // scale
	if (messageTime>0)
	{
		messageTime--;
		Print_Str_d(127, -128, (void* const) messageBuffer);
	}
	else
	{
		Print_Str_d(127, -128, statusString);
	}
}




/************************************************************************/
/************************************************************************/
/*																		*/
/*				Global Constants : Lists of things, etc.				*/
/*																		*/
/************************************************************************/
/************************************************************************/

struct _OInfStruct
		{ char *Name; unsigned int Cost; unsigned int MaxDamage; char Key; };
struct _MInfStruct
		{ char *Name; unsigned int Level; };

static struct _OInfStruct const _OInfo[] =
	{
		{ "Food",1,0,'F' },
		{ "Rapier",8,10,'R' },
		{ "Axe",5,5,'A' },
		{ "Shield",6,1,'S' },
		{ "Bow+Arrow",3,4,'B' },
		{ "Amulet",15,0,'M' }
	};

static char * const _AName[] =
	{ 	"HP",		"Strength",	"Dexterity",	"Stamina",
		"Wisdom",	"Gold"  };

/************************************************************************/
/*																		*/
/*						Return name of object							*/
/*																		*/
/************************************************************************/

char *GLOObjName(unsigned int n)
{ return _OInfo[n].Name; }


void GLOGetInfo(unsigned int n,unsigned int *pDamage,unsigned int *pCost,char *pKey)
{
	if (pDamage != NULL) *pDamage = _OInfo[n].MaxDamage;
	if (pCost != NULL) 	 *pCost = _OInfo[n].Cost;
	if (pKey != NULL) 	 *pKey = _OInfo[n].Key;
}

/************************************************************************/
/*																		*/
/*						Return name of attribute						*/
/*																		*/
/************************************************************************/

char *GLOAttribName(unsigned int n)
{
return _AName[n];
}

/************************************************************************/
/*																		*/
/*							Return name of class						*/
/*																		*/
/************************************************************************/

char *GLOClassName(char c)
{
	return (c == 'F') ? "Fighter":"Mage";
}



