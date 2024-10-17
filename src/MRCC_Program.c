/*
 * MRCC_Program.c
 *
 *  Created on: Jan 31, 2024
 *      Author: M
 */


/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../include/MRCC_Config.h"
#include "../include/MRCC_Interface.h"
#include "../include/MRCC_Private.h"


void MRCC_void_Init(void){
	// Initialize the selected clock source
#if SYSCLK == RCC_HSI
	// Enable HSI
	SET_BIT(RCC->CR, RCC_CR_HSION);
	// Wait till HSI is ready
	while(GET_BIT(RCC->CR, RCC_CR_HSIRDY) == RCC_NOT_READY);
	// Mask the switching bits
	RCC->CFGR &= ~(TWO_BIT_MASK << SW_BIT0);
	// Select the HSI as SYSCLK
	RCC->CFGR |= (SW_HSI << SW_BIT0);

#elif SYSCLK == RCC_HSE
	// Enable HSE
	SET_BIT(RCC->CR, RCC_CR_HSEON);
	// Wait till HSE is ready
	while(GET_BIT(RCC->CR, RCC_CR_HSERDY) == RCC_NOT_READY);
	// Mask the switching bits
	RCC->CFGR &= ~(TWO_BIT_MASK << SW_BIT0);
	// Select the HSE as SYSCLK
	RCC->CFGR |= (SW_HSE << SW_BIT0);

#elif SYSCLK == RCC_PLL
	// Enable PLL
	SET_BIT(RCC->CR, RCC_CR_PLLON);
	// Wait till PLL is ready
	while(GET_BIT(RCC->CR, RCC_CR_PLLRDY) == RCC_NOT_READY);
	// Mask the switching bits
	RCC->CFGR &= ~(TWO_BIT_MASK << SW_BIT0);
	// Select the HSI as SYSCLK
	RCC->CFGR |= (SW_PLL << SW_BIT0);

#else
#error "Wrong SYSCLK configuration"
#endif
}

void MRCC_void_EnablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral){
	if(copyu32_BusAddress > RCC_AHB2){
		return;
	}

	switch(copyu32_BusAddress){
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR, copyu32_Peripheral);
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR, copyu32_Peripheral);
		break;
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR, copyu32_Peripheral);
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR, copyu32_Peripheral);
		break;
	default: break;
	}
}

void MRCC_void_DisablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral){
	if(copyu32_BusAddress > RCC_AHB2){
		return;
	}

	switch(copyu32_BusAddress){
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR, copyu32_Peripheral);
		break;
	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR, copyu32_Peripheral);
		break;
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR, copyu32_Peripheral);
		break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR, copyu32_Peripheral);
		break;
	default: break;
	}
}

void MRCC_void_SetAPB1Prescaler(u8 copyu8_APB1Prescaler){
	// Clear the prescaler bits
	RCC->CFGR &= ~(THREE_BIT_MASK << RCC_CFGR_PPRE1);
	// Set the prescaler with selected value
	RCC->CFGR |= (copyu8_APB1Prescaler << RCC_CFGR_PPRE1);
}

void MRCC_void_SetAPB2Prescaler(u8 copyu8_APB2Prescaler){
	// Clear the prescaler bits
	RCC->CFGR &= ~(THREE_BIT_MASK << RCC_CFGR_PPRE2);
	// Set the prescaler with selected value
	RCC->CFGR |= (copyu8_APB2Prescaler << RCC_CFGR_PPRE1);
}

void MRCC_void_SetAHBPrescaler(u8 copyu8_AHBPrescaler){
	// Clear the prescaler bits
	RCC->CFGR &= ~(THREE_BIT_MASK << RCC_CFGR_HPRE);
	// Set the prescaler with selected value
	RCC->CFGR |= (copyu8_AHBPrescaler << RCC_CFGR_PPRE1);
}
