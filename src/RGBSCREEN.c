/*
 * RGBSCREEN.c
 *
 *  Created on: Apr 18, 2020
 *      Author: felipe
 */



#include "sapi.h"
#include "RGBSCREEN.h"
#include "antirebotes.h"

static int h;

extern debounceButton_t tecla1;

static void horizontal1()
{
	for(h=0;h<8;h++)
	{
		printf("****************\n\r");
		printf("                \n\r");
	}

}

static void horizontal2()
{
	for(h=0;h<8;h++)
	{
		printf("                \n\r");
		printf("****************\n\r");
	}

}

static void encendido()
{
	for(h=0;h<16;h++)
	{
		printf("****************\n\r");
	}
}

static void shutdown()
{
	for(h=0;h<16;h++)
	{
		printf("               \n\r");
	}
}

static void vertical1()
{
	for(h=0;h<16;h++)
	{
		printf("* * * * * * * * \n\r");
	}
}

static void vertical2()
{
	for(h=0;h<16;h++)
	{
		printf(" * * * * * * * *\n\r");
	}
}

void rgb_screen_init(rgb_t *pRgb)
{
	pRgb->mode = horizontal; // modo inicial prendido
	pRgb->ciclos = 4; //configuración inicial de cuatro ciclos antes del cambio de estado
	pRgb->frame = pantallauno;
	delayInit(&pRgb->timeCiclo,mediociclo); //inicializo el tiempo del medio ciclo en un segundo
}

void rgb_screen_sm(rgb_t *pRgb)
{

	if(delayRead(&pRgb->timeCiclo))
	{
		switch(pRgb->mode)
		{
			case horizontal:
			{
				 gpioWrite( LED1, ON );
				 gpioWrite( LED2, OFF );
				 gpioWrite( LED3, OFF );
				 printf("\033c");

				 if(pRgb->frame == pantallauno)
				 {
					 horizontal1();
					 pRgb->frame = pantallados;
				 }
				 else if(pRgb->frame == pantallados)
				 {
					 horizontal2();
					 pRgb->frame = pantallauno;
				 }
				 delayInit(&pRgb->timeCiclo,mediociclo);
				 if(tecla1.flag)
				 {
					 pRgb->mode = vertical;
					 tecla1.flag = FALSE;
				 }
				 break;

			}
			case vertical:
			{

				 gpioWrite( LED1, OFF );
				 gpioWrite( LED2, ON );
				 gpioWrite( LED3, OFF );
				 printf("\033c");

				 if(pRgb->frame == pantallauno)
				 {
					 vertical1();
					 pRgb->frame = pantallados;
				 }
				 else if(pRgb->frame == pantallados)
				 {
					 vertical2();
					 pRgb->frame = pantallauno;
				 }
				 delayInit(&pRgb->timeCiclo,mediociclo);

				 if(tecla1.flag)
				 {
					 pRgb->mode = prendido;
					 tecla1.flag = FALSE;
				 }

				 break;
			}
			case prendido:
			{

				 gpioWrite( LED1, OFF );
				 gpioWrite( LED2, OFF );
				 gpioWrite( LED3, ON );
				 printf("MODO PRENDIDO \n\r");
				 printf("\033c");
				 encendido();
				 delayInit(&pRgb->timeCiclo,mediociclo);

				 if(tecla1.flag)
				 {
					 pRgb->mode = apagado;
					 tecla1.flag = FALSE;
				 }
				 break;
			}
			case apagado:
			{

				 gpioWrite( LED1, ON );
				 gpioWrite( LED2, ON );
				 gpioWrite( LED3, ON );
				 printf("MODO APAGADO \n\r");
				 printf("\033c");
				 shutdown();
				 delayInit(&pRgb->timeCiclo,mediociclo);
				 if(tecla1.flag)
				 {
					 pRgb->mode = horizontal;
					 tecla1.flag = FALSE;
				 }


				 break;
			}
			default:
			{
				 pRgb->mode = horizontal;
				 delayInit(&pRgb->timeCiclo,mediociclo);

			}

		}
	}
}
