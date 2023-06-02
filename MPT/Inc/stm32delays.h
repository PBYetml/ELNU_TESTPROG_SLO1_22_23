/*--------------------------------------------------------*/
//	stm32delays.h
/*--------------------------------------------------------*/
//	Description :	Fonctions de delay afin
//			de pouvoir utiliser la m�me syntaxe
//			que sous CCS.
//
//	Auteurs 		: 	SCA
//
//	Version		:	V1.0
//	Compilateur	:	Keil 5.24
//
// Revu / modifi�: 
// -
/*--------------------------------------------------------*/

#ifndef __STM32DELAYS_H
#define __STM32DELAYS_H

#include "stm32f0xx.h"	//n�cessaire pour __NOP


/*--------------------------------------------------------*/
// D�finition des fonctions prototypes
/*--------------------------------------------------------*/

//attention : le nop ne garantit pas un d�lai en architecture ARM
// (d� au pipeline du CPU)
// son utilit� est plut�t du padding m�moire pour aligner le code.
#define delay_cycle() __nop()

void delay500ns(void); // n�cessaire pour lcd
void delay_us(uint32_t); // 32 bits
void delay_ms(uint32_t); // 32 bits

#endif
