//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "leds.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut led1(LED1);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void opLedInit()
{   
    led1 = OFF;
}

void opLedUpdate()
{
    led1 = !led1;
}

bool opLedRead()
{
    return led1;
}

//=====[Implementations of private functions]==================================