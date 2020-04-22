/*
 * hardwareLed.h
 *
 *  Created on: Apr 22, 2020
 *      Author: felipe
 */

#ifndef MISINTENTOS_SISTEMASOP_INC_HARDWARELED_H_
#define MISINTENTOS_SISTEMASOP_INC_HARDWARELED_H_
#include "sapi.h"

typedef gpioMap_t lamp_t;

void turnOn(lamp_t lamp);
void turnOff(lamp_t lamp);
void toggleLed(lamp_t lamp);




#endif /* MISINTENTOS_SISTEMASOP_INC_HARDWARELED_H_ */
