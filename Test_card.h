// **********************************************************************************
// Test de la carte Home automation
// **********************************************************************************
// Creative Commons Attrib Share-Alike License
// You are free to use/extend this library but please abide with the CC-BY-SA license:
// http://creativecommons.org/licenses/by-sa/4.0/
//
//
// Written by Stéphane CHARGUI
//
// History : V1.00 2018-09-09 - Creation
//
// All text above must be included in any redistribution.
//
// **********************************************************************************
#ifndef __TEST_CARD_H__
#define __TEST_CARD_H__

#include "Home_Automation_Module.h"

// Variables exported to other source file
// ========================================


// Function exported to other source file
// =======================================
void testLed(void);
void relayToogle (int num, int pin, int delayUp, int delayDown);
void testRelay(void);

#endif
