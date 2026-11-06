/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOE
#define MotorNFault_Pin GPIO_PIN_1
#define MotorNFault_GPIO_Port GPIOC
#define IR1Read_Pin GPIO_PIN_0
#define IR1Read_GPIO_Port GPIOA
#define IR1Toggle_Pin GPIO_PIN_1
#define IR1Toggle_GPIO_Port GPIOA
#define MotorNSleep_Pin GPIO_PIN_4
#define MotorNSleep_GPIO_Port GPIOA
#define IR2Read_Pin GPIO_PIN_0
#define IR2Read_GPIO_Port GPIOB
#define IR2Toggle_Pin GPIO_PIN_1
#define IR2Toggle_GPIO_Port GPIOB
#define Motor2In2_Pin GPIO_PIN_13
#define Motor2In2_GPIO_Port GPIOE
#define Motor2In1_Pin GPIO_PIN_14
#define Motor2In1_GPIO_Port GPIOE
#define Motor1In1_Pin GPIO_PIN_11
#define Motor1In1_GPIO_Port GPIOB
#define IR3Read_Pin GPIO_PIN_12
#define IR3Read_GPIO_Port GPIOD
#define IR3Toggle_Pin GPIO_PIN_13
#define IR3Toggle_GPIO_Port GPIOD
#define IR4Read_Pin GPIO_PIN_8
#define IR4Read_GPIO_Port GPIOC
#define IR4Toggle_Pin GPIO_PIN_9
#define IR4Toggle_GPIO_Port GPIOC
#define Motor1In2_Pin GPIO_PIN_15
#define Motor1In2_GPIO_Port GPIOA
#define Q9_Pin GPIO_PIN_3
#define Q9_GPIO_Port GPIOD
#define D6_Pin GPIO_PIN_4
#define D6_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
