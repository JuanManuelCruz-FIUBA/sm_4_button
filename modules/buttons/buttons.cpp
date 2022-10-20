//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "buttons.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn b1(BUTTON1);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void opButtonInit()
{   
    b1.mode(PullDown);
}

void opButtonUpdate()
{
}

uint32_t opButtonRead()
{
    return b1.read();
}

//=====[Implementations of private functions]==================================