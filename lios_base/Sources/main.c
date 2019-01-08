/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K14x
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
#include "Events.h"
//#include "Events.c"
/*#include "Events.c"*/

  volatile int exit_code = 0;

  /*
  ** ===================================================================
  INFO: empty Drivers\common\GeneralDamage.inc file
  **     Description :
  **         if enabled, this hook will be called in case of a stack
  **         overflow.
  **     Parameters  :
  **         NAME            - DESCRIPTION
  **         pxTask          - Task handle
  **       * pcTaskName      - Pointer to task name
  **     Returns     : Nothing
  ** ===================================================================
  */
//  #include "Events.h"
//  #include "task.h"
  void FreeRTOS_vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
  {
    /* This will get called if a stack overflow is detected during the context
       switch.  Set configCHECK_FOR_STACK_OVERFLOWS to 2 to also check for stack
       problems within nested interrupts, but only do this for debug purposes as
       it will increase the context switch time. */
    (void)pxTask;
    (void)pcTaskName;
    taskDISABLE_INTERRUPTS();
    /* Write your code here ... */
    for(;;) {}
  }

  /*
  ** ===================================================================
  INFO: empty Drivers\common\GeneralDamage.inc file
  **     Description :
  **         If enabled, this hook will be called by the RTOS for every
  **         tick increment.
  **     Parameters  : None
  **     Returns     : Nothing
  ** ===================================================================
  */
  void FreeRTOS_vApplicationTickHook(void)
  {
    /* Called for every RTOS tick. */
    /* Write your code here ... */
  }

  /*
  ** ===================================================================
  INFO: empty Drivers\common\GeneralDamage.inc file
  **     Description :
  **         If enabled, this hook will be called when the RTOS is idle.
  **         This might be a good place to go into low power mode.
  **     Parameters  : None
  **     Returns     : Nothing
  ** ===================================================================
  */
  void FreeRTOS_vApplicationIdleHook(void)
  {
    /* Called whenever the RTOS is idle (from the IDLE task).
       Here would be a good place to put the CPU into low power mode. */
    /* Write your code here ... */
  }

  /*
  ** ===================================================================
  INFO: empty Drivers\common\GeneralDamage.inc file
  **     Description :
  **         If enabled, the RTOS will call this hook in case memory
  **         allocation failed.
  **     Parameters  : None
  **     Returns     : Nothing
  ** ===================================================================
  */
  void FreeRTOS_vApplicationMallocFailedHook(void)
  {
    /* Called if a call to pvPortMalloc() fails because there is insufficient
       free memory available in the FreeRTOS heap.  pvPortMalloc() is called
       internally by FreeRTOS API functions that create tasks, queues, software
       timers, and semaphores.  The size of the FreeRTOS heap is set by the
       configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
    taskDISABLE_INTERRUPTS();
    /* Write your code here ... */
    for(;;) {}
  }




/* User includes (#include below this line is not maintained by Processor Expert) */

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/

  static void Components_Init(void)
  {
    #define CPU_INIT_MCUONECLIPSE_DRIVERS
    /* IMPORTANT: copy the content from Cpu.c! */
  /*------------------------------------------------------------------*/
  /* copy-paste code from Cpu.c below: */
#ifdef CPU_INIT_MCUONECLIPSE_DRIVERS
  MCUC1_Init(); /* ### McuLibConfig "MCUC1" init code ... */
#endif
#ifdef CPU_INIT_MCUONECLIPSE_DRIVERS
  UTIL1_Init(); /* ### Utility "UTIL1" init code ... */
#endif
#ifdef CPU_INIT_MCUONECLIPSE_DRIVERS
  /* PEX_RTOS_INIT() is a macro should already have been called either from main()
     or Processor Expert startup code. So we don't call it here again. */
  /* PEX_RTOS_INIT(); */ /* ### FreeRTOS "FreeRTOS" init code ... */
#endif
  /*------------------------------------------------------------------*/
  }

int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
    Components_Init();
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
