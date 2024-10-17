/*
 * MSTK_Interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: HP
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

void MSTK_void_Init(void);

void MSTK_void_ClearCurrentValue(void);

void MSTK_void_SetPreloadValue(u32 copyu32_Preload);

void MSTK_void_GetFlag(u8 *ptrReturn);

void MSTK_void_EnableSTK(void);
void MSTK_void_DisableSTK(void);

void MSTK_void_GetElapedTime(u8 *ptrReturn);
void MSTK_void_GetRemainingTime(u8 *ptrReturn);

void MSTK_void_EnableInterrupt(void);
void MSTK_void_DisableInterrupt(void);

void MSTK_void_Delayms(u32 copyu32_Delayms);
void MSTK_void_Delayus(u32 copyu32_Delayus);

void MSTK_void_SetIntervalPeriodic(u32 copyu32_NumOfCounts, void(*localPtrToFunc)(void));

#endif /* MSTK_INTERFACE_H_ */
