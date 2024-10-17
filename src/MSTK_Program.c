/*
 * MSTK_Program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: HP
 */


/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../../First_ARM_Project/include/MSTK_Config.h"
#include "../../First_ARM_Project/include/MSTK_Interface.h"
#include "../../First_ARM_Project/include/MSTK_Private.h"


void(*global_voidPtrToFunc)(void) = NULL;
u8 global_SingleFlag = 1;


void MSTK_void_Init(void){
#if (MSTK_CLKSOURCE == MSTK_AHB_BY_8)
	CLR_BIT(STK->CTRL, CLKSOURCE);
#elif (MSTK_CLKSOURCE == MSTK_AHB)
	SET_BIT(STK->CTRL, CLKSOURCE);
#else
#error "Wrong STK CLK Source Configuration"
#endif
}

void MSTK_void_ClearCurrentValue(void){
	// Writing any value to VAL register, clears it
	STK->VAL = 0;
}

void MSTK_void_SetPreloadValue(u32 copyu32_Preload){
	STK->LOAD = copyu32_Preload;
}

void MSTK_void_GetFlag(u8 *ptrReturn){
	*ptrReturn = GET_BIT(STK->CTRL, COUNTFLAG);
}

void MSTK_void_EnableSTK(void){
	SET_BIT(STK->CTRL, ENABLE);
}

void MSTK_void_DisableSTK(void){
	CLR_BIT(STK->CTRL, ENABLE);
}

void MSTK_void_GetElapsedTime(u8 *ptrReturn){
	*ptrReturn = (STK->LOAD) - (STK->VAL);
}

void MSTK_void_GetRemainingTime(u8 *ptrReturn){
	*ptrReturn = STK->VAL;
}

void MSTK_void_EnableInterrupt(void){
	SET_BIT(STK->CTRL, TICKINT);
}

void MSTK_void_DisableInterrupt(void){
	CLR_BIT(STK->CTRL, TICKINT);
}

void MSTK_void_Delayms(u32 copyu32_Delayms){

	if( (copyu32_Delayms * (MSTK_FREQ / 1000)) <= MSTK_MAX_PRELOAD) {
		// Calculate the preload value:
		// preload = desired / period   [in seconds]
		u32 localu32_Preload = copyu32_Delayms * (MSTK_FREQ / 1000);
		STK->LOAD = localu32_Preload;
		// Reset STK current value
		STK->VAL = 0;
		// Enable STK
		SET_BIT(STK->CTRL, ENABLE);
		// Wait on the flag
		while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
	}
	else {
		u32 localu32_TotalReloads = (copyu32_Delayms * (MSTK_FREQ / 1000)) / MSTK_MAX_PRELOAD;
		u32 localu32_LastPreload = ((copyu32_Delayms * (MSTK_FREQ / 1000)) % MSTK_MAX_PRELOAD) * MSTK_MAX_PRELOAD;


		while(localu32_TotalReloads != 0) {
			STK->LOAD = MSTK_MAX_PRELOAD;
			// Reset STK current value
			STK->VAL = 0;
			// Enable STK
			SET_BIT(STK->CTRL, ENABLE);
			// Wait on the flag
			while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);

			localu32_TotalReloads--;
		}

		STK->LOAD = localu32_LastPreload;
		// Reset STK current value
		STK->VAL = 0;
		// Enable STK
		SET_BIT(STK->CTRL, ENABLE);
		// Wait on the flag
		while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
	}

}

void MSTK_void_Delayus(u32 copyu32_Delayus){
	if( (copyu32_Delayus * (MSTK_FREQ / 1000000)) <= MSTK_MAX_PRELOAD) {
		// Calculate the preload value:
		// preload = desired / period   [in seconds]
		u32 localu32_Preload = copyu32_Delayus * (MSTK_FREQ / 1000000);
		STK->LOAD = localu32_Preload;
		// Reset STK current value
		STK->VAL = 0;
		// Enable STK
		SET_BIT(STK->CTRL, ENABLE);
		// Wait on the flag
		while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
	}
	else {
		u32 localu32_TotalReloads = (copyu32_Delayus * (MSTK_FREQ / 1000000)) / MSTK_MAX_PRELOAD;
		u32 localu32_LastPreload = ((copyu32_Delayus * (MSTK_FREQ / 1000000)) % MSTK_MAX_PRELOAD) * MSTK_MAX_PRELOAD;


		while(localu32_TotalReloads != 0) {
			STK->LOAD = MSTK_MAX_PRELOAD;
			// Reset STK current value
			STK->VAL = 0;
			// Enable STK
			SET_BIT(STK->CTRL, ENABLE);
			// Wait on the flag
			while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);

			localu32_TotalReloads--;
		}

		STK->LOAD = localu32_LastPreload;
		// Reset STK current value
		STK->VAL = 0;
		// Enable STK
		SET_BIT(STK->CTRL, ENABLE);
		// Wait on the flag
		while(GET_BIT(STK->CTRL, COUNTFLAG) == 0);
	}
}

void MSTK_void_SetIntervalPeriodic(u32 copyu32_NumOfCounts, void(*localPtrToFunc)(void)){
	global_voidPtrToFunc = localPtrToFunc;
	// Enable STK Interrupt
	SET_BIT(STK->CTRL, TICKINT);
	// Preload value
	STK->LOAD = copyu32_NumOfCounts;
	// Enable STK
	SET_BIT(STK->CTRL, ENABLE);

	global_SingleFlag = 0;
}
