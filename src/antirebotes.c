/*
 * antirebotes.c
 *
 *  Created on: Apr 18, 2020
 *      Author: felipe
 */

#include "antirebotes.h"
#include "sapi.h"




void debounceSM_Init(debounceButton_t *pButton, gpioMap_t key)
{
	pButton->buttonPressed = FALSE;
	pButton->buttonReleased = TRUE;
	pButton->key = key;
	pButton->buttonState = UP;
	pButton->flag = FALSE;
}
void debounceSM_Update(debounceButton_t *pButton)
{
	switch(pButton->buttonState)
	{
		case UP:
			pButton->buttonPressed = FALSE;
			pButton->buttonReleased = TRUE;
			if(!gpioRead(pButton->key))
			{
				delayInit(&pButton->FSMdelay, DEBOUNCE_TIME);
				pButton->buttonState = FALLING;
			}
			break;
		case FALLING:
			pButton->buttonPressed = FALSE;
			pButton->buttonReleased = TRUE;
			if(delayRead(&pButton->FSMdelay))
			{
				if(!gpioRead(pButton->key))
				{
					pButton->buttonState = DOWN;
					pButton->flag = TRUE;
				}
				else
				{
					pButton->buttonState = UP;
				}
			}
			break;
		case DOWN:
			pButton->buttonPressed = TRUE;
			pButton->buttonReleased = FALSE;
			if(gpioRead(pButton->key))
			{
				delayInit(&pButton->FSMdelay,DEBOUNCE_TIME);
				pButton->buttonState = RISING;
			}
			break;
		case RISING:
			pButton->buttonPressed = TRUE;
			pButton->buttonReleased = FALSE;
			if(delayRead(&pButton->FSMdelay))
			{
				if(!gpioRead(pButton->key))
				{
					pButton->buttonState = DOWN;
				}
				else
				{
					pButton->buttonState = UP;
				}
			}
			break;
		default:
			pButton->buttonState = UP;
			break;
	}
}
