/*
 * app_entry.c
 *
 *  Created on: Nov 5, 2026
 *      Author: Jayden Anderson
 */

#include "app_entry.h"
#include "main.h"
#include "cmsis_os2.h"

/* ---------------------------------------------------------------------------
 *
 * Includes for separate App files so app_entry knows your tasks exist
 *
 * --------------------------------------------------------------------------- */
#include "ir.h"


/* ---------------------------------------------------------------------------
 *
 * Thread attribute definitions
 *
 * --------------------------------------------------------------------------- */
// Example:
/*
osThreadId_t taskNameTaskHandle;
const osThreadAttr_t taskNameTask_attributes = {
  .name = "taskName",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
*/
osThreadId_t irBlinkTaskHandle;
const osThreadAttr_t irBlinkTask_attributes = {
  .name = "irBlink",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};


void app_main(void)
{
	// Toggle heartbeat pin every 500 ms
	const int HEARTBEAT_TICKS = 500 * osKernelGetTickFreq() / 1000;


	/* ---------------------------------------------------------------------------
	 *
	 * Calls to initialize tasks in other files
	 *
	 * --------------------------------------------------------------------------- */
	irBlinkTaskHandle = osThreadNew(IrBlinkTask, NULL, &irBlinkTask_attributes);

	for(;;)
	{
		HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
    	osDelay(HEARTBEAT_TICKS);
	}
}
