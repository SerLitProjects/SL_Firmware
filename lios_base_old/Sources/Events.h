#include "task.h"

void FreeRTOS_vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName);
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

void FreeRTOS_vApplicationTickHook(void);
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

void FreeRTOS_vApplicationIdleHook(void);
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

void FreeRTOS_vApplicationMallocFailedHook(void);
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

