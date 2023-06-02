/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>

#include "fonctionsTestELNU.h" 
#include "stm32DriverLcd.h"
#include "stm32f0xx_it.h"
#include "fonctionsTestELNU.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
enum etat {STATE_INIT, STATE_EXEC, STATE_WAIT};

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
enum etat etatActuel = STATE_INIT;
uint8_t positionLeds = 0; 
 
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	//-- déclaration de variable --// 

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_TIM14_Init();
  MX_ADC_Init();
  /* USER CODE BEGIN 2 */
	//-- initialisation LCD avec message utilisateur --// 
	lcd_init(); 	
	lcd_bl_on(); 
  lcd_gotoxy(1,1); 
	printf_lcd("TEST ELNU 23"); 
	lcd_gotoxy(1,2);
	printf_lcd("SOLUS PERRET"); 
	
	
	//-- activation du timer 6 avec interruption --//
 	HAL_TIM_Base_Start_IT(&htim6);
	
	
	//-- calibration pour l'ADC --// 
	HAL_ADCEx_Calibration_Start(&hadc);
	
	//-- lancement du timer14 avec interruption --//
	HAL_TIM_Base_Start_IT(&htim14);
	
	
//Fonction interruption Tim6
	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim6)		// Fonction d'interruption toutes les 1ms 
{
	static uint8_t delai = 0;
	delai += DELAI_INTERRUPTION;
	if(delai >= DELAI_MISE_A_JOUR) // On rentre dans le if toutes les 1ms
	{
		etatActuel = STATE_INIT
	}
		delai = 0;
}

	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		//-- Machine d'état --// 
			switch(etatActuel)
		{
				//-- Initialisation --// 
			case STATE_INIT:  
				//-- appel fonction chenillard --//
				FctChenillard(positionLeds);
				if(positionLeds > 5)
				{
					FctAllumerLeds(); 				//-- allumer les leds pendant 5s --//
				}
				else
				{
					FctEteindreLeds(); 				//-- eteindre les leds --// 
				}
				break;
			case STATE_EXEC:
				
				break;
			case STATE_WAIT:
				break;
		}
	}

				//-- mise à jour de la machine d'état --//

		
			//-- Execution --// 

				//-- lecture de l'ADC => canal 1 --// 

				//-- controle des seuils --// 

			
				//-- test si touches sont activée actif à 1 (actif toutes les 100ms)--// 

				//-- action selon l'état des touches --// 

					//-- appel de la fonction CreationDentScieGauche --//
					
					//-- appel de la fonction CreationDentSciedroite --//

					//-- appel de la fonction CreationTriangle --//
				
					//-- mise à du tableau à zéro --//
 

			//-- Attente --// 
					
					//-- ne fait rien 
		
		}	
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI14|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
