/*
 * app_entry.c
 *
 *  Created on: Nov 5, 2026
 *      Author: Jayden Anderson
 */

#include "main.h"
#include "cmsis_os2.h"

osThreadId_t irBlinkTaskHandle;
const osThreadAttr_t irBlinkTask_attributes = {
  .name = "irBlink",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};

void StartIrBlinkTask(void *argument);

void app_main(void)
{
	// Toggle heartbeat pin every 500 ms
	const int HEARTBEAT_TICKS = 500 * osKernelGetTickFreq() / 1000;

	irBlinkTaskHandle = osThreadNew(StartIrBlinkTask, NULL, &irBlinkTask_attributes);

	for(;;)
	{
		HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
    	osDelay(HEARTBEAT_TICKS);
	}
}

void StartIrBlinkTask(void *argument)
{
	// 150 ms of delay between LED toggles
	const int BLINK_DELAY_TICKS = 150 * osKernelGetTickFreq() / 1000;

	HAL_GPIO_WritePin(IR1Toggle_GPIO_Port, IR1Toggle_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IR2Toggle_GPIO_Port, IR2Toggle_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IR3Toggle_GPIO_Port, IR3Toggle_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IR4Toggle_GPIO_Port, IR4Toggle_Pin, GPIO_PIN_RESET);

	for(;;)
	{
		HAL_GPIO_TogglePin(IR1Toggle_GPIO_Port, IR1Toggle_Pin);
		osDelay(BLINK_DELAY_TICKS);
		HAL_GPIO_TogglePin(IR2Toggle_GPIO_Port, IR2Toggle_Pin);
		osDelay(BLINK_DELAY_TICKS);
		HAL_GPIO_TogglePin(IR3Toggle_GPIO_Port, IR3Toggle_Pin);
		osDelay(BLINK_DELAY_TICKS);
		HAL_GPIO_TogglePin(IR4Toggle_GPIO_Port, IR4Toggle_Pin);
		osDelay(BLINK_DELAY_TICKS);
	}
}
