// ***************************************************************************
// cartridge
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

#include "../aklabeth.h"
#include "../cartridge.i"

extern void introImage();
extern void TOWNEnter();
extern void WORLDDrawOnce();

extern void doSettings();
extern void saveFlash();
extern void loadFlash();


const void* const bankFunctions[NUMBER_OF_FUNCTIONS] __attribute__((section(".bankswitch.data"), used)) = 
{
    (void*) introImage,
    (void*) TOWNEnter,
    (void*) WORLDDrawOnce,
    (void*) 1,
    (void*) doSettings,
    (void*) saveFlash, // 5
    (void*) loadFlash, // 6
    (void*)1,
    (void*)1,
    (void*)1
};
