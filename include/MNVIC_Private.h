/*
 * MNVIC_Private.h
 *
 *  Created on: Feb 4, 2024
 *      Author: HP
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct{
	// Interrupt set-enable register
	u32 ISER[8];
	u32 RES_1[24];
	// Interrupt clear-enable register
	u32 ICER[8];
	u32 RES_2[24];
	// Interrupt set-pending register
	u32 ISPR[8];
	u32 RES_3[24];
	// Interrupt clear-pending register
	u32 ICPR[8];
	u32 RES_4[24];
	// Interrupt active bit register
	u32 IABR[8];
	u32 RES_5[56];
	// Interrupt priority register, byte accessible
	u8 IPR[240];
	u32 RES_6[580];
	// Software trigger interrupt register
	u32 STIR;
}NVIC_t;

#define NVIC ((volatile NVIC_t*)NVIC_BASE_ADDRESS)

// Application interrupt and reset control register:
// includes VECTKEY and PRIGROUP
#define SCB_AIRCR (*(volatile u32*)0xE000ED0C)

#define WORD 	32
#define SCB_AIRCR_VECTKEY 	0x05FA0000
#define SCB_AICIR_PRIGROUP_B0 	8

#endif /* MNVIC_PRIVATE_H_ */
