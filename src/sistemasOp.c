/*=============================================================================
 * Copyright (c) 2020, felipesarche <sarche_2004@hotmail.com>
 * All rights reserved.
 * License:  (see LICENSE.txt)
 * Date: 2020/04/15
 *===========================================================================*/

/*=====[Definition macros of private constants]==============================*/

// The maximum number of tasks required at any one time during the execution
// of the program. MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCHEDULER_MAX_TASKS   (10)

/*=====[Inclusions of function dependencies]=================================*/

#include "sapi.h"
#include "seos_pont.h"
#include "userTasks.h"
#include "RGBSCREEN.h"
#include "antirebotes.h"

/*=====[Main function, program entry point after power on or reset]==========*/
debounceButton_t tecla1;

int main( void )
{
   boardInit();



   rgb_t pantalla; //estructura pantalla

   rgb_screen_init(&pantalla);



   debounceSM_Init( &tecla1 ,TEC1);


   // Initialize myTask   
   myTaskInit(0); // Parameter passed into the task init.

   // Initialize scheduler
   schedulerInit();

   // Se agrega la tarea tarea1 al planificador
   schedulerAddTask( myTaskUpdate, // Function that implements the task update.
                     0,            // Parameter passed into the task update.
                     0,            // Execution offset in ticks.
                     50           // Periodicity of task execution in ticks.
                   );
  schedulerAddTask( Lectorsw, // Function that implements the task update.
                     &tecla1,            // Parameter passed into the task update.
                     0,            // Execution offset in ticks.
                     1           // Periodicity of task execution in ticks.
                   );
   schedulerAddTask( RGBPRINT, // Function that implements the task update.
		   	   	   	 &pantalla,            // Parameter passed into the task update.
                     0,            // Execution offset in ticks.
                     30           // Periodicity of task execution in ticks.
                   );

   // Initialize task scheduler each 1ms.
   schedulerStart( 1 );


   while( TRUE ){
      // Dispatch (execute) tasks that are mark to be execute by scheduler.
      schedulerDispatchTasks();

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
