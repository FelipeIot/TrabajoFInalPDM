/*
 * RGBSCREEN.h
 *
 *  Created on: Apr 16, 2020
 *      Author: felipe
 */

#ifndef MISINTENTOS_SISTEMASOP_INC_RGBSCREEN_H_
#define MISINTENTOS_SISTEMASOP_INC_RGBSCREEN_H_

#include "sapi.h"
#include "antirebotes.h"

#define mediociclo 1000



typedef enum {horizontal, vertical, apagado, prendido} modergb_t;
typedef enum {pantallauno,pantallados} pantalla_t;
typedef int veces_t;

typedef struct
{
	modergb_t 	mode;		//este es el estado actual de la maquina
	veces_t 	ciclos;		//numero de ciclos antes de cambiar de estado
	delay_t 	timeCiclo;	//tiempo en segundos de medio ciclo
	pantalla_t  frame; 		//posibles efectos
}rgb_t;

void rgb_screen_init(rgb_t *pRgb);
void rgb_screen_sm(rgb_t *pRgb);








#endif /* MISINTENTOS_SISTEMASOP_INC_RGBSCREEN_H_ */
