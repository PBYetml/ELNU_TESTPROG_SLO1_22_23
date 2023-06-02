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
#include "stm32driverlcd.h"
#include "adc.h"
#include "main.h"


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
	if(positionLeds == 0)
	{
		GPIOC->BSRR = 0xFFF0; //Eteind toutes les leds 
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_RESET); //allume la led 0 
	}
		if(positionLeds == 1)
	{
		GPIOC->BSRR = 0xFFF0; //Eteind toutes les leds 
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_RESET); //allume la led 1 
	}
			if(positionLeds == 2)
	{
		GPIOC->BSRR = 0xFFF0; //Eteind toutes les leds 
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_RESET); //allume la led 1 
	}
			if(positionLeds == 3)
	{
		GPIOC->BSRR = 0xFFF0; //Eteind toutes les leds 
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_RESET); //allume la led 1 
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
	static uint8_t i;
	for (i = 0; i < 5; i++) // Selon données : durant 5 secondes à l'initialisation chemina
	{
		HAL_GPIO_TogglePin(GPIOC, LED0_Pin);
		HAL_GPIO_TogglePin(GPIOC, LED1_Pin);
		HAL_GPIO_TogglePin(GPIOC, LED2_Pin);
		HAL_GPIO_TogglePin(GPIOC, LED3_Pin);

	}	
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
	HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
 	HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, LED3_Pin, GPIO_PIN_SET);
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
	
	HAL_ADC_PollForConversion(&hadc, 5);

	return HAL_ADC_GetValue(&hadc);
	
	return 0; 
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
	if(valBruteADC < TENSION_NEGATIVE) 
	{
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_RESET);
	}
	if(valBruteADC > TENSION_NEGATIVE && < TENSION_NULLE) 
	{
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_RESET);
	}
	if(valBruteADC == TENSION_NULLE) 
	{
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, GPIO_PIN_RESET);
	}
}

