/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

int LedsState = 0;
int cinqSec = 0;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void FctChenillard(int8_t positionLeds);
void FctAllumerLeds();
void FctEteindreLeds();
void FctControlSeuilTension(uint16_t valBruteADC);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCDRW_Pin GPIO_PIN_13
#define LCDRW_GPIO_Port GPIOC
#define LCDRS_Pin GPIO_PIN_14
#define LCDRS_GPIO_Port GPIOC
#define LCDBL_Pin GPIO_PIN_15
#define LCDBL_GPIO_Port GPIOC
#define OSCIN_Pin GPIO_PIN_0
#define OSCIN_GPIO_Port GPIOF
#define OSCOUT_Pin GPIO_PIN_1
#define OSCOUT_GPIO_Port GPIOF
#define BTN0_Pin GPIO_PIN_0
#define BTN0_GPIO_Port GPIOC
#define BTN1_Pin GPIO_PIN_1
#define BTN1_GPIO_Port GPIOC
#define BTN2_Pin GPIO_PIN_2
#define BTN2_GPIO_Port GPIOC
#define BTN3_Pin GPIO_PIN_3
#define BTN3_GPIO_Port GPIOC
#define SPISCK_Pin GPIO_PIN_5
#define SPISCK_GPIO_Port GPIOA
#define SPIMISO_Pin GPIO_PIN_6
#define SPIMISO_GPIO_Port GPIOA
#define LED0_Pin GPIO_PIN_4
#define LED0_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_7
#define LED3_GPIO_Port GPIOC
#define LCDDB4_Pin GPIO_PIN_8
#define LCDDB4_GPIO_Port GPIOC
#define LCDDB5_Pin GPIO_PIN_9
#define LCDDB5_GPIO_Port GPIOC
#define _SPICSLM70_Pin GPIO_PIN_15
#define _SPICSLM70_GPIO_Port GPIOA
#define LCDDB6_Pin GPIO_PIN_10
#define LCDDB6_GPIO_Port GPIOC
#define LCDDB7_Pin GPIO_PIN_11
#define LCDDB7_GPIO_Port GPIOC
#define LCDE_Pin GPIO_PIN_12
#define LCDE_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
