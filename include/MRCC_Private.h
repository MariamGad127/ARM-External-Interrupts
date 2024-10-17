/*
 * MRCC_Private.h
 *
 *  Created on: Jan 31, 2024
 *      Author: M
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define RCC_BASE_ADDRESS (0x40023800)

/************RCC REGISTERS************/
typedef struct {
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 RES_1;
	u32 RES_2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 RES_3;
	u32 RES_4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 RES_5;
	u32 RES_6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 RES_7;
	u32 RES_8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 RES_9;
	u32 RES_10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 RES_11;
	u32 RES_12;
	u32 BDCR;
	u32 CSR;
	u32 RES_13;
	u32 RES_14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 RES_15;
	u32 DCKCFGR;

}RCC_t;

#define RCC ((volatile RCC_t*)RCC_BASE_ADDRESS)

/*****SYSCLK*****/
#define RCC_HSI		0
#define RCC_HSE		1
#define RCC_PLL		2

#define RCC_READY		1
#define RCC_NOT_READY	0

#define SW_HSI			0b00
#define SW_HSE			0b01
#define SW_PLL			0b10
#define SW_BIT0		 	0
#define TWO_BIT_MASK	0b11
#define THREE_BIT_MASK	0b111

/*****CR (clock control register)*****/
#define RCC_CR_HSION		0
#define RCC_CR_HSIRDY		1
#define RCC_CR_HSEON		16
#define RCC_CR_HSERDY		17
#define RCC_CR_PLLON		24
#define RCC_CR_PLLRDY		25


/*****CFGR (configuration register)*****/
#define RCC_CFGR_HPRE		4
#define RCC_CFGR_PPRE1		10
#define RCC_CFGR_PPRE2		13


#endif /* MRCC_PRIVATE_H_ */
