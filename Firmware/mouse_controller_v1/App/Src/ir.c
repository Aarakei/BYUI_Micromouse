/*
 * ir.c
 *
 *  Created on: Nov 5, 2026
 *      Author: Jayden Anderson
 */

#include "ir.h"
#include "main.h"
#include "cmsis_os2.h"


void IrBlinkTask(void *argument)
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
