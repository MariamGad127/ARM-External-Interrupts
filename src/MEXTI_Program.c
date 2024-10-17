/*
 * MEXTI_Program.c
 *
 *  Created on: Feb 5, 2024
 *      Author: HP
 */

/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../include/MEXTI_Config.h"
#include "../include/MEXTI_Interface.h"
#include "../include/MEXTI_Private.h"

extern MEXTI_Configurations_t MEXTI_Config[MEXTI_MAX_NUM];
static PtrToFunc_void MEXTI_Callback[EXTI_TOTAL_NUM];

void MEXTI_void_Init(void){
	u8 localu8_Itreator = 0;
	for(localu8_Itreator = 0; localu8_Itreator < MEXTI_MAX_NUM; localu8_Itreator++) {

		MEXTI_void_SelectPort(MEXTI_Config[localu8_Itreator].Line, MEXTI_Config[localu8_Itreator].Port);

		MEXTI_void_SetMode(MEXTI_Config[localu8_Itreator].Line, MEXTI_Config[localu8_Itreator].Mode);

		if(MEXTI_Config[localu8_Itreator].State == MEXTI_ENABLED){
			SET_BIT(EXTI->IMR, MEXTI_Config[localu8_Itreator].Line);
		}
		else {
			CLR_BIT(EXTI->IMR, MEXTI_Config[localu8_Itreator].Line);
		}
	}
}

void MEXTI_void_EnableEXTILine(MEXTI_Line_t copy_MEXTI_Line){
	SET_BIT(EXTI->IMR, copy_MEXTI_Line);
}

void MEXTI_void_DisableEXTILine(MEXTI_Line_t copy_MEXTI_Line){
	CLR_BIT(EXTI->IMR, copy_MEXTI_Line);
}

void MEXTI_void_SetCallback(MEXTI_Line_t copy_MEXTI_Line, PtrToFunc_void copy_CallbackFunc){
	MEXTI_Callback[copy_MEXTI_Line] = copy_CallbackFunc;
}

void MEXTI_void_SWIRequest(MEXTI_Line_t copy_MEXTI_Line){
	SET_BIT(EXTI->SWIER, copy_MEXTI_Line);
}

void MEXTI_void_ClearPendingFlag(MEXTI_Line_t copy_MEXTI_Line){
	SET_BIT(EXTI->PR, copy_MEXTI_Line);
}

void MEXTI_void_SelectPort(MEXTI_Line_t copy_MEXTI_Line, MEXTI_Port_t copy_MEXTI_Port){
	SYSCFG->EXTICR[copy_MEXTI_Line / EXTI_NUM_IN_REGISTER] &= ~(FOUR_BIT_MASK << ((copy_MEXTI_Line % EXTI_NUM_IN_REGISTER) * 4));
	SYSCFG->EXTICR[copy_MEXTI_Line / EXTI_NUM_IN_REGISTER] |= (copy_MEXTI_Port << ((copy_MEXTI_Line % EXTI_NUM_IN_REGISTER) * 4));
}

void MEXTI_void_SetMode(MEXTI_Line_t copy_MEXTI_Line, MEXTI_Mode_t copy_MEXTI_Mode){
	if(copy_MEXTI_Mode == MEXTI_FALLING_EDGE) {
		SET_BIT(EXTI->FTSR, copy_MEXTI_Line);
	}
	else if(copy_MEXTI_Mode == MEXTI_RISING_EDGE) {
		SET_BIT(EXTI->RTSR, copy_MEXTI_Line);
	}
	else {
		SET_BIT(EXTI->FTSR, copy_MEXTI_Line);
		SET_BIT(EXTI->RTSR, copy_MEXTI_Line);
	}
}
