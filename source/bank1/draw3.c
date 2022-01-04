//**********************************************************************
//**********************************************************************
//																		
//							Draw Monster Graphics						
//																		
//**********************************************************************
//**********************************************************************

#include <vectrex.h>
#include "../aklabeth.h"
#include "../globals.h"
#include "../string.h"
#include "../controller.h"


#define BLOW_UP 1

const signed char const SkeletonSyncList[]=
{	(const signed char) 0x01, -0x75*BLOW_UP, +0x4E*BLOW_UP, // sync and move to y, x
	(const signed char) 0x00, -0x03*BLOW_UP, +0x00*BLOW_UP, // additional sync move to y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x30*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x4E*BLOW_UP, +0x45*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x75*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x15*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x09*BLOW_UP, -0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x09*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, +0x09*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, +0x09*BLOW_UP, // draw, y, x
	(const signed char) 0x01, +0x69*BLOW_UP, +0x21*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x09*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x48*BLOW_UP, -0x36*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, +0x2D*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x12*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x15*BLOW_UP, +0x03*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x12*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x18*BLOW_UP, -0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x0C*BLOW_UP, +0x1E*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x09*BLOW_UP, +0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x09*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x30*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const ThiefSyncList[]=
{	(const signed char) 0x01, -0x48*BLOW_UP, +0x00*BLOW_UP, // sync and move to y, x
	(const signed char) 0x00, -0x1B*BLOW_UP, +0x00*BLOW_UP, // additional sync move to y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x45*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x42*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x39*BLOW_UP, -0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x48*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x48*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x45*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x01, -0x36*BLOW_UP, -0x48*BLOW_UP, // sync and move to y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x12*BLOW_UP, // additional sync move to y, x
	(const signed char) 0xFF, +0x42*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x39*BLOW_UP, +0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x21*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0C*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0C*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x21*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x18*BLOW_UP, -0x1E*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const RatSyncList[]=
{	(const signed char) 0x01, +0x27*BLOW_UP, +0x09*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x4B*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x4B*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x12*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0x01, +0x3C*BLOW_UP, -0x24*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x36*BLOW_UP, -0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x1E*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x2D*BLOW_UP, +0x09*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const OrcSyncList[]=
{	(const signed char) 0x01, +0x5D*BLOW_UP, -0x18*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x30*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x15*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x5A*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x45*BLOW_UP, -0x15*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x30*BLOW_UP, // mode, y, x
	(const signed char) 0x01, +0x30*BLOW_UP, -0x18*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x30*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, -0x30*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, +0x2D*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x5A*BLOW_UP, -0x5D*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x2D*BLOW_UP, +0x45*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x2D*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x01, -0x42*BLOW_UP, -0x18*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x42*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0x01, +0x5D*BLOW_UP, +0x18*BLOW_UP, // sync and move to y, x
	(const signed char) 0x00, +0x15*BLOW_UP, +0x00*BLOW_UP, // additional sync move to y, x
	(const signed char) 0xFF, -0x15*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x42*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, -0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x15*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x15*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x2D*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const ViperSyncList[]=
{	(const signed char) 0x01, +0x36*BLOW_UP, -0x0F*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, -0x2D*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, -0x2D*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x0F*BLOW_UP, +0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x0F*BLOW_UP, +0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x4B*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x0F*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0x01, +0x09*BLOW_UP, +0x0F*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x0F*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x1E*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x5A*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2D*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x5A*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x0F*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x5A*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x0F*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x5A*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const CarrionSyncList[]=
{	(const signed char) 0x01, -0x09*BLOW_UP, -0x4B*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x06*BLOW_UP, -0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x0F*BLOW_UP, +0x3C*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x4B*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x18*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x01, +0x33*BLOW_UP, -0x0F*BLOW_UP, // sync and move to y, x
	(const signed char) 0x00, +0x0F*BLOW_UP, +0x3C*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x45*BLOW_UP, -0x1E*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x30*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x06*BLOW_UP, -0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0C*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x78*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0C*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x63*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const GremlinSyncList[]=
{	(const signed char) 0x01, -0x1E*BLOW_UP, +0x15*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x09*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, -0x09*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x0C*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, -0x09*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x09*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x18*BLOW_UP, +0x0F*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x03*BLOW_UP, +0x03*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x06*BLOW_UP, -0x03*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x12*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x06*BLOW_UP, -0x03*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x03*BLOW_UP, +0x03*BLOW_UP, // draw, y, x
	(const signed char) 0x01, -0x06*BLOW_UP, +0x06*BLOW_UP, // sync and move to y, x
	(const signed char) 0x00, +0x06*BLOW_UP, +0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0C*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0C*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};

const signed char const MimicSyncList[]=
{	(const signed char) 0x01, +0x09*BLOW_UP, -0x24*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x3C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, -0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x1E*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x0F*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const DemonSyncList[]=
{	(const signed char) 0x01, -0x54*BLOW_UP, +0x69*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, -0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x72*BLOW_UP, -0x2A*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, -0x12*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x0C*BLOW_UP, -0x12*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x1B*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x15*BLOW_UP, +0x36*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1E*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x01, -0x3C*BLOW_UP, +0x45*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x24*BLOW_UP, -0x54*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x24*BLOW_UP, -0x54*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1E*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, +0x36*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x18*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x1E*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0F*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x1B*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0C*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0C*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0F*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x01, +0x12*BLOW_UP, -0x63*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, +0x57*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, +0x57*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x09*BLOW_UP, -0x06*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x06*BLOW_UP, -0x12*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x03*BLOW_UP, +0x12*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, +0x12*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x57*BLOW_UP, -0x7E*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x36*BLOW_UP, +0x2A*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x42*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x30*BLOW_UP, -0x2A*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x45*BLOW_UP, +0x00*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x15*BLOW_UP, +0x60*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x03*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x2A*BLOW_UP, -0x42*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x12*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x03*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x03*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x30*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x01, +0x4E*BLOW_UP, -0x2D*BLOW_UP, // sync and move to y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, +0x12*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, +0x18*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x09*BLOW_UP, +0x12*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x09*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0x00, +0x00*BLOW_UP, -0x48*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, +0x54*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x03*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x0C*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x15*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x15*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x15*BLOW_UP, -0x0C*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x0C*BLOW_UP, -0x18*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x03*BLOW_UP, +0x06*BLOW_UP, // draw, y, x
	(const signed char) 0x00, -0x03*BLOW_UP, +0x0C*BLOW_UP, // mode, y, x
	(const signed char) 0xFF, -0x03*BLOW_UP, -0x06*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x00*BLOW_UP, -0x12*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x1B*BLOW_UP, -0x36*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, -0x18*BLOW_UP, +0x00*BLOW_UP, // draw, y, x
	(const signed char) 0xFF, +0x06*BLOW_UP, +0x18*BLOW_UP, // draw, y, x
	(const signed char) 0x02 // endmarker 
};
const signed char const BalrogSyncList[]=
{	(const signed char) 0x01, +0x54, -0x12, // sync and move to y, x
	(const signed char) 0xFF, -0x0C, +0x06, // draw, y, x
	(const signed char) 0x00, +0x00, +0x18, // mode, y, x
	(const signed char) 0xFF, +0x0C, +0x06, // draw, y, x
	(const signed char) 0x00, +0x24, +0x66, // mode, y, x
	(const signed char) 0xFF, +0x12, -0x06, // draw, y, x
	(const signed char) 0xFF, +0x00, +0x0C, // draw, y, x
	(const signed char) 0xFF, -0x12, -0x06, // draw, y, x
	(const signed char) 0xFF, -0x6C, +0x00, // draw, y, x
	(const signed char) 0x00, -0x1E, -0x4B, // mode, y, x
	(const signed char) 0xFF, +0x00, +0x2D, // draw, y, x
	(const signed char) 0xFF, -0x5A, +0x5A, // draw, y, x
	(const signed char) 0xFF, +0x3C, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x5A, -0x2D, // draw, y, x
	(const signed char) 0xFF, +0x2D, -0x17, // draw, y, x
	(const signed char) 0xFF, +0x2D, -0x16, // draw, y, x
	(const signed char) 0xFF, -0x2D, -0x24, // draw, y, x
	(const signed char) 0xFF, -0x2D, -0x24, // draw, y, x
	(const signed char) 0xFF, -0x0F, +0x0C, // draw, y, x
	(const signed char) 0xFF, +0x2D, +0x5A, // draw, y, x
	(const signed char) 0xFF, -0x1E, +0x00, // draw, y, x
	(const signed char) 0xFF, -0x2D, -0x4B, // draw, y, x
	(const signed char) 0x01, -0x03, +0x2D, // sync and move to y, x
	(const signed char) 0xFF, -0x2D, +0x00, // draw, y, x
	(const signed char) 0xFF, -0x1E, +0x09, // draw, y, x
	(const signed char) 0xFF, -0x1E, +0x00, // draw, y, x
	(const signed char) 0xFF, -0x0C, +0x06, // draw, y, x
	(const signed char) 0xFF, -0x12, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(const signed char) 0xFF, +0x0F, -0x03, // draw, y, x
	(const signed char) 0xFF, -0x0F, -0x03, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(const signed char) 0xFF, +0x12, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x0C, +0x06, // draw, y, x
	(const signed char) 0xFF, +0x1E, -0x06, // draw, y, x
	(const signed char) 0xFF, +0x0F, -0x0C, // draw, y, x
	(const signed char) 0x00, +0x00, -0x24, // mode, y, x
	(const signed char) 0xFF, -0x39, +0x12, // draw, y, x
	(const signed char) 0xFF, -0x12, +0x1E, // draw, y, x
	(const signed char) 0xFF, +0x18, -0x12, // draw, y, x
	(const signed char) 0xFF, +0x33, +0x06, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x12, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x12, // draw, y, x
	(const signed char) 0xFF, -0x0F, -0x0C, // draw, y, x
	(const signed char) 0x01, -0x4E, -0x1E, // sync and move to y, x
	(const signed char) 0xFF, -0x1E, -0x06, // draw, y, x
	(const signed char) 0xFF, -0x0C, +0x06, // draw, y, x
	(const signed char) 0xFF, -0x12, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(const signed char) 0xFF, +0x0F, -0x03, // draw, y, x
	(const signed char) 0xFF, -0x0F, -0x03, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x0C, // draw, y, x
	(const signed char) 0xFF, +0x12, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x0C, +0x06, // draw, y, x
	(const signed char) 0xFF, +0x1E, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x1E, +0x09, // draw, y, x
	(const signed char) 0xFF, +0x2D, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x2D, -0x4B, // draw, y, x
	(const signed char) 0xFF, +0x1E, +0x00, // draw, y, x
	(const signed char) 0xFF, -0x2D, +0x5A, // draw, y, x
	(const signed char) 0xFF, +0x0F, +0x0C, // draw, y, x
	(const signed char) 0x00, +0x0C, +0x12, // mode, y, x
	(const signed char) 0xFF, -0x0C, +0x00, // draw, y, x
	(const signed char) 0x00, +0x00, +0x12, // mode, y, x
	(const signed char) 0xFF, +0x2A, +0x0C, // draw, y, x
	(const signed char) 0xFF, +0x12, -0x0C, // draw, y, x
	(const signed char) 0x01, +0x66, +0x12, // sync and move to y, x
	(const signed char) 0xFF, +0x00, -0x06, // draw, y, x
	(const signed char) 0xFF, +0x06, -0x03, // draw, y, x
	(const signed char) 0xFF, -0x06, -0x03, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x06, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x06, // draw, y, x
	(const signed char) 0xFF, +0x06, -0x03, // draw, y, x
	(const signed char) 0xFF, -0x06, -0x03, // draw, y, x
	(const signed char) 0xFF, +0x00, -0x06, // draw, y, x
	(const signed char) 0xFF, -0x12, -0x0C, // draw, y, x
	(const signed char) 0xFF, -0x2A, +0x0C, // draw, y, x
	(const signed char) 0xFF, +0x2D, -0x24, // draw, y, x
	(const signed char) 0xFF, +0x2D, -0x24, // draw, y, x
	(const signed char) 0xFF, -0x2D, -0x16, // draw, y, x
	(const signed char) 0xFF, -0x2D, -0x17, // draw, y, x
	(const signed char) 0xFF, -0x5A, -0x2D, // draw, y, x
	(const signed char) 0xFF, -0x3C, +0x00, // draw, y, x
	(const signed char) 0xFF, +0x5A, +0x5A, // draw, y, x
	(const signed char) 0xFF, +0x00, +0x2D, // draw, y, x
	(const signed char) 0x00, +0x48, -0x4B, // mode, y, x
	(const signed char) 0xFF, +0x4E, +0x00, // draw, y, x
	(const signed char) 0xFF, -0x1E, -0x24, // draw, y, x
	(const signed char) 0x02 // endmarker 
};

const int const Scale[] =
{
    0x20,
    0x10,
    0x08,
    0x04,
    0x02,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
};


//**********************************************************************
//																		
//							Draw Monster Graphics						
//																		
//**********************************************************************
extern void draw_synced_list( int scaleVector , int scaleMove, unsigned long yxPos, void *synclist);

void DRAWMonster(int Monster,unsigned int distance)
{
	switch(Monster)							// Call appropriate function 
	{
		case MN_SKELETON:   draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)SkeletonSyncList);break;
        	case MN_THIEF:      draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)ThiefSyncList);break;
		case MN_RAT:        draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)RatSyncList);break;
		case MN_ORC:        draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)OrcSyncList);break;
		case MN_VIPER:      draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)ViperSyncList);break;
		case MN_CARRION:    draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)CarrionSyncList);break;
		case MN_GREMLIN:    draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)GremlinSyncList);break;
		case MN_MIMIC:      draw_synced_list( Scale[distance-2], Scale[distance-2], 0x9c00, (void *)MimicSyncList);break;
		case MN_DAEMON:     draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)DemonSyncList);break;
		case MN_BALROG:     draw_synced_list( Scale[distance-2], Scale[distance-2], 0xce00, (void *)BalrogSyncList);break;
	}

}



