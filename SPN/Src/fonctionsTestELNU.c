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
	HAL_GPIO_WritePin(GPIOC, (0x0010U<<positionLeds), GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, (0x0010U<<(positionLeds + 1)), GPIO_PIN_SET);

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
			// allumage de tout les LEDs
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);

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
		// éteint tout les LEDs
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);


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
	uint32_t value = 0; 
	
	//Activate the ADC peripheral and start conversions using function 
	HAL_ADC_Start(&hadc);

	//Wait for ADC conversion completion using function 
	HAL_ADC_PollForConversion(&hadc,1);
	
	//Retrieve conversion results using function 
	value = HAL_ADC_GetValue(&hadc);
	
	//Stop conversion and disable the ADC peripheral using function 
	HAL_ADC_Stop(&hadc);	
	
	//cast en 16 bit et retourne
	return((uint16_t)value);		
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
	int16_t adc_brut  = 0;
	int16_t val_millivolt = 0;
	
	adc_brut = FctLectureADC(1);
	
	//convesion de la valeur brute de l ADC en milivolte ax+b
	val_millivolt = ((20000/4095)*adc_brut -10000);
	
	if(val_millivolt < -5000)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
	}
	else if((val_millivolt > - 5000)&(val_millivolt < 0))
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
	}
	else if(val_millivolt == 0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
	}
	else if((val_millivolt < - 5000)&(val_millivolt < 0))
	{
	
	
	}
	
	
	
	
	
	
}

