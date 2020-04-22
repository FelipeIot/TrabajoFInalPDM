/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/04/15
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/

#include "userTasks.h"
 
/*=====[Inclusions of private function dependencies]=========================*/
#include "RGBSCREEN.h"
#include "antirebotes.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

// Task initialization implementation
void myTaskInit( void* taskParmPtr )
{
   printf( "Blinky with SEOS Pont and sAPI.\r\n" );
}

// Task update implementation
void myTaskUpdate( void* taskParmPtr )
{
   //gpioToggle( LED );

}

void blinkYellow( void* taskParmPtr )
{

   debounceSM_Update(taskParmPtr);
   //printf( "Blink!\r\n" );
}
void RGBPRINT(void* taskParmPtr)
{
	rgb_screen_sm(taskParmPtr);
	//printf( "Blink!\r\n" );

}


/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

