/*
 * MNVIC_Interface.h
 *
 *  Created on: Feb 4, 2024
 *      Author: HP
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

typedef enum{
	Group16_NoSub = 3, //0b0xx
	Group8_Sub2, 		//0b100
	Group4_Sub4,
	Group2_Sub8,
	NoGroup_Sub16,

}MNVIC_GroupMode_t;

void MNVIC_void_EnablePeripheralInterrupt(u8 copyu8_Peripheral);
void MNVIC_void_DisablePeripheralInterrupt(u8 copyu8_Peripheral);

void MNVIC_void_SetPendingFlag(u8 copyu8_Peripheral);
void MNVIC_void_ClearPendingFlag(u8 copyu8_Peripheral);

void MNVIC_void_GetInterruptState(u8 copyu8_Peripheral, u8* ptrReturn);

void MNVIC_void_SetInterruptGroupMode(MNVIC_GroupMode_t MNVIC_GroupMode);

void MNVIC_void_SetInterruptPriority(u8 copyu8_Peripheral, u8 copyu8_GroupNum, u8 copyu8_SubGroupNum);

#endif /* MNVIC_INTERFACE_H_ */
