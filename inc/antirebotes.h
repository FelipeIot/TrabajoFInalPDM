/*
 * antirebotes.h
 *
 *  Created on: Apr 18, 2020
 *      Author: felipe
 */

#ifndef MISINTENTOS_SISTEMASOP_INC_ANTIREBOTES_H_
#define MISINTENTOS_SISTEMASOP_INC_ANTIREBOTES_H_
#include "sapi.h"


#define DEBOUNCE_TIME 40

typedef enum{
	UP,
	FALLING,
	DOWN,
	RISING
}debounceState_t;

typedef struct {
	bool_t buttonPressed;
	bool_t buttonReleased;
	bool_t flag;
	gpioMap_t key;
	debounceState_t buttonState;
	delay_t FSMdelay;
} debounceButton_t;



void debounceSM_Init(debounceButton_t *pButton, gpioMap_t key);
void debounceSM_Update(debounceButton_t *pButton);


#endif /* MISINTENTOS_SISTEMASOP_INC_ANTIREBOTES_H_ */
