/*
 * hardwareLed.c
 *
 *  Created on: Apr 22, 2020
 *      Author: felipe
 */


#include "hardwareLed.h"
#include "sapi.h"

void turnOn(lamp_t lamp)
{
	gpioWrite( lamp, ON );
}
void turnOff(lamp_t lamp)
{
	gpioWrite( lamp, OFF );
}

void toggleLed(lamp_t lamp)
{
	gpioToggle(lamp);
}
