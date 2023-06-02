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


//-- liabrairie standart --// 
#include <stdint.h>						// pour la normalisation des types entier
#include <stdlib.h>						// pour le fonction standart du C 

//-- déclaration de constantes globale --//



//----------------------------------------------------------------------------------//
//-- nom 								: FctChenillard
//-- entrée - sortie 		: positionLeds / - 
//-- description 				: permet d'allumer l'une après l'autres les leds 
//-- remarque 					:
//-- date modification 	: 26.05.2023
//----------------------------------------------------------------------------------//
void FctChenillard(int8_t positionLeds)
{
	GPIOC->BSRR = 0xFFF0; 		//Eteind toutes les leds, 0x00F0 correspond au masque des leds
	HAL_GPIO_WritePin(GPIOC, 0x0010U << positionLeds, 0);	//Allume la led
}

//----------------------------------------------------------------------------------//
//-- nom 								: FctAllumerLeds
//-- entrée - sortie 		: - / - 
//-- description 				: permet d'allumer toutes les leds -> voir schéma 
//-- remarque 					:
//-- date modification 	: 26.05.2023
//----------------------------------------------------------------------------------//
void FctAllumerLeds()
{
	// Allumer led0
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
	// Allumer led1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	// Allumer led2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
	// Allumer led3
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
}	

//----------------------------------------------------------------------------------//
//-- nom 								: FctEteindreLeds
//-- entrée - sortie 		: - / - 
//-- description 				: permet d'éteindre toutes les leds -> voir schéma 
//-- remarque 					:
//-- date modification 	: 26.05.2023
//----------------------------------------------------------------------------------//
void FctEteindreLeds()
{
	// Éteindre led0
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
	// Éteindre led1
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
	// Éteindre led2
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
	// Éteindre led3
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
}	

//----------------------------------------------------------------------------------//
//-- nom 								: FctLectureADC
//-- entrée | sortie		: choixCanal | valeurBrute  
//-- description 				: permet de lire le canal ADC choisi
//-- remarque 					:
//-- date modification 	: 26.05.2023
//----------------------------------------------------------------------------------//
uint16_t FctLectureADC(uint8_t choixCanal)
{
	HAL_ADC_Start(&hadc);	// Démarrage de l'adc
	return (HAL_ADC_GetValue(&hadc)); 	// Retourne la valeur de l'adc
}


//----------------------------------------------------------------------------------//
//-- nom 								: FctControleSeuilTension
//-- entrée | sortie 		: valBruteADC | - 
//-- description 				: décode la valeur brute de l'ADC en milliVolt 
//-- 							  et fonction de cette valeur en miilivolt va gérer 
//--							  les leds 
//-- remarque 					:
//-- date modification 	: 26.05.2023
//----------------------------------------------------------------------------------//
void FctControlSeuilTension(uint16_t valBruteADC)
{
	int16_t valMiliVolt = 0;
	
	valMiliVolt = (valBruteADC * DELTA_U_MAX/RESOLUTION_ADC) + U_MIN;
	if(valMiliVolt < 0)	// Si la valeur de l'adc est plus petite que la moitier
	{
		if(valMiliVolt < SEUIL_MIN)
		{
			// Allumer led0
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
			// Éteindre led1
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
			// Éteindre led2
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
			// Éteindre led3
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
		}
		else if(valMiliVolt < 0)
		{
			// Allumer led1
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
			// Éteindre led0
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			// Éteindre led2
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
			// Éteindre led3
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
		}
		else if(valMiliVolt == 0)
		{
			// Allumer led2
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
			// Allumer led1
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
			// Éteindre led0
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			// Éteindre led3
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
		}
		else if(valMiliVolt < SEUIL_MAX)
		{
			// Allumer led2
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);
			// Éteindre led0
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			// Éteindre led1
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
			// Éteindre led3
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
		}
		else
		{
			// Allumer led3
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
			// Éteindre led0
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			// Éteindre led1
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
			// Éteindre led2
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);
		}
	}
}

