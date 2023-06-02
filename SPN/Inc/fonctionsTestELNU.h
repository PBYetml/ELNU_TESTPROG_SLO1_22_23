//-----------------------------------------------------------------------------------//
// Nom du projet 				:		ELNU_TestProg"
// Nom du fichier 			:   fonctionTestELNU.h
// Date de création 		:   13.06.2021
// Date de modification : 	24.05.2023
// 
// Auteur 							: 	Philou (Ph. Bovey) 
//
// Description 					: 	HeaderFile pour test de programmation ELNU
//
//
// Remarques						: 	
//----------------------------------------------------------------------------------//
//-- définition de fichier headerfile --// 
#ifndef FONCTION_TESTELNU
#define FONCTION_TESTELNU

//--- librairie à inclure ---// 
//-- libriaire personnelle ou système --// 
#include "main.h"

//-- liabrairie standart --// 
#include <stdint.h>						// pour la normalisation des types entier

//-- déclaration de constante --// 
#define DELTA_U_MAX				20000						// valeur en millivolt => représente 20V 
#define RESOLUTION_ADC		4096						// résolution de l'ADC en 12bits 
#define SEUIL_MAX					5000						// seuil de tension max 
#define SEUIL_MIN					-5000						// seuil de tension min 
#define U_MAX							10000						// valeur en millivolt => représnet 10V 
#define U_MIN			 	 			-10000					// valeur en millivolt => représnet -10V 

//-- déclaration de constantes globale --//
extern const uint16_t TBLedsStarterKit[4]; // = {LED0_Pin, LED1_Pin, LED2_Pin, LED3_Pin}; 

//-- protoytpes des fonctions --// 
void FctAllumerLeds(void); 
void FctChenillard(int8_t positionLeds);
void FctControlSeuilTension(uint16_t valBruteADC);
void FctEteindreLeds(void); 
uint16_t FctLectureADC(uint8_t choixCanal);


#endif 



