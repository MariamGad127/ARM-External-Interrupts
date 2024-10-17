/*
 * MNVIC_Program.c
 *
 *  Created on: Feb 4, 2024
 *      Author: HP
 */


/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../include/MNVIC_Config.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MNVIC_Private.h"

static MNVIC_GroupMode_t sglobal_MNVIC_GroupMode_t;

void MNVIC_void_EnablePeripheralInterrupt(u8 copyu8_Peripheral) {
	/* e.g. ISER0 has interrupts from 0 to 31 ==>
	 * reg = peripheral / 32  since [int/int=int]
	 * bit = remainder of reg
	 */
	SET_BIT( NVIC->ISER[copyu8_Peripheral / WORD], (copyu8_Peripheral % WORD) );
}

void MNVIC_void_DisablePeripheralInterrupt(u8 copyu8_Peripheral) {
	SET_BIT( NVIC->ICER[copyu8_Peripheral / WORD], (copyu8_Peripheral % WORD) );
}

void MNVIC_void_SetPendingFlag(u8 copyu8_Peripheral) {
	SET_BIT( NVIC->ISPR[copyu8_Peripheral / WORD], (copyu8_Peripheral % WORD) );
}
void MNVIC_void_ClearPendingFlag(u8 copyu8_Peripheral) {
	SET_BIT( NVIC->ICPR[copyu8_Peripheral / WORD], (copyu8_Peripheral % WORD) );
}

void MNVIC_void_GetInterruptState(u8 copyu8_Peripheral, u8 *ptrReturn) {
	*ptrReturn = GET_BIT( NVIC->IABR[copyu8_Peripheral / WORD], (copyu8_Peripheral % WORD) );
}

void MNVIC_void_SetInterruptGroupMode(MNVIC_GroupMode_t MNVIC_GroupMode) {
	sglobal_MNVIC_GroupMode_t = MNVIC_GroupMode;
	SCB_AIRCR =  (SCB_AIRCR_VECTKEY | MNVIC_GroupMode << SCB_AICIR_PRIGROUP_B0);
}

void MNVIC_void_SetInterruptPriority(u8 copyu8_Peripheral, u8 copyu8_GroupNum, u8 copyu8_SubGroupNum) {
	switch(sglobal_MNVIC_GroupMode_t) {
	case Group16_NoSub:
		// bits[3:0] read as zero and ignore writes, hence the shift by 4
		NVIC->IPR[copyu8_Peripheral] = (copyu8_GroupNum<<4);
		break;
	case Group8_Sub2:
		NVIC->IPR[copyu8_Peripheral] = (copyu8_GroupNum<<5 | copyu8_SubGroupNum<<4);
		break;
	case Group4_Sub4:
		NVIC->IPR[copyu8_Peripheral] = (copyu8_GroupNum<<6 | copyu8_SubGroupNum<<4);
		break;
	case Group2_Sub8:
		NVIC->IPR[copyu8_Peripheral] = (copyu8_GroupNum<<7 | copyu8_SubGroupNum<<4);
		break;
	case NoGroup_Sub16:
		NVIC->IPR[copyu8_Peripheral] = (copyu8_SubGroupNum<<4);
		break;
	default: break;
	}
}

