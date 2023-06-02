//-----------------------------------------------------------------------------------//
// Nom du projet 				:		ELNU_TestProg"
// Nom du fichier 			:   fonctionTestELNU.c
// Date de création 		:   13.06.2021
// Date de modification : 	24.05.2023
// 
// Auteur 							: 	Philou (Ph. Bovey) 
//
// Description 					: 	listing C allant avec l'épreuve Genlec2 (solution de 
// 													fonction 
//
//
// Remarques						: 	
//----------------------------------------------------------------------------------//
//--- librairie à inclure ---// 

//-- librairie personnelle --// 
#include "fonctionsTestELNU.h" 
#include "gpio.h"
#include "main.h"
#include "adc.h"
//-- liabrairie standart --// 
#include <stdint.h>						// pour la normalisation des types entier
#include <stdlib.h>						// pour le fonction standart du C 

//-- déclaration de constantes globale --//



//----------------------------------------------------------------------------------//
//-- nom 								: FctChenillard
//-- entrée - sortie 		: positionLeds / - 
//-- description 				: permet d'allumer l'une après l'autres les leds 
//-- remarque 					:
//-- date modification 	: 13.06.2021
//----------------------------------------------------------------------------------//
void FctChenillard(int8_t positionLeds)
{
	if (positionLeds == 1 ) 
	{
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
	}
	if (positionLeds == 0 )
	{
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_RESET);
	}
	if (positionLeds == 2 )
	{
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
	}
	if (positionLeds == 3 )
	{
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
	}
	
}

//----------------------------------------------------------------------------------//
//-- nom 								: FctAllumerLeds
//-- entrée - sortie 		: - / - 
//-- description 				: permet d'allumer toutes les leds -> voir schéma 
//-- remarque 					:
//-- date modification 	: 13.06.2021
//----------------------------------------------------------------------------------//
void FctAllumerLeds()
{
	HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_RESET);
}	

//----------------------------------------------------------------------------------//
//-- nom 								: FctEteindreLeds
//-- entrée - sortie 		: - / - 
//-- description 				: permet d'éteindre toutes les leds -> voir schéma 
//-- remarque 					:
//-- date modification 	: 13.06.2021
//----------------------------------------------------------------------------------//
void FctEteindreLeds()
{
	HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
}	

//----------------------------------------------------------------------------------//
//-- nom 								: FctLectureADC
//-- entrée | sortie		: choixCanal | valeurBrute  
//-- description 				: permet de lire le canal ADC choisi
//-- remarque 					:
//-- date modification 	: 13.06.2021
//----------------------------------------------------------------------------------//
uint16_t FctLectureADC(uint8_t choixCanal)
{
	HAL_ADC_Start(&hadc);
	
	// Note: le Poll met le programme en pause jusqu'à récupération de la valeur convertie
	// Ou jusqu'au dépassement du temps maximal (timeout)
  HAL_ADC_PollForConversion(&hadc, 5);
	return HAL_ADC_GetValue(&hadc);; 
}


//----------------------------------------------------------------------------------//
//-- nom 								: FctControleSeuilTension
//-- entrée | sortie 		: valBruteADC | - 
//-- description 				: décode la valeur brute de l'ADC en milliVolt 
//-- 							  et fonction de cette valeur en miilivolt va gérer 
//--							  les leds 
//-- remarque 					:
//-- date modification 	: 14.06.2021
//----------------------------------------------------------------------------------//
void FctControlSeuilTension(uint16_t valBruteADC)
{
	
	
	
}

