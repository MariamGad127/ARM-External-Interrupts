/*
 * MRCC_Interface.h
 *
 *  Created on: Jan 31, 2024
 *      Author: M
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/************MACROS************/
#define RCC_APB1	0
#define RCC_APB2	1
#define RCC_AHB1	2
#define RCC_AHB2	3

/*****AHB1*****/
#define RCC_AHB1_GPIOA		0
#define RCC_AHB1_GPIOB		1
#define RCC_AHB1_GPIOC		2
#define RCC_AHB1_GPIOD		3
#define RCC_AHB1_GPIOE		4
#define RCC_AHB1_GPIOH		7
#define RCC_AHB1_CRC		12
#define RCC_AHB1_DMA1		21
#define RCC_AHB1_DMA2		22

/*****AHB2*****/
#define RCC_AHB2_OTGFS		7

/*****APB1*****/
#define RCC_APB1_TIM2		0
#define RCC_APB1_TIM3		1
#define RCC_APB1_TIM4		2
#define RCC_APB1_TIM5		3
#define RCC_APB1_WWDG		11
#define RCC_APB1_SPI2		14
#define RCC_APB1_SPI3		15
#define RCC_APB1_USART2		17
#define RCC_APB1_I2C1		21
#define RCC_APB1_I2C2		22
#define RCC_APB1_I2C3		23
#define RCC_APB1_PWR		28

/*****APB2*****/
#define RCC_APB2_TIM1		0
#define RCC_APB2_USART1		4
#define RCC_APB2_USART6		5
#define RCC_APB2_ADC1		8
#define RCC_APB2_SDIO		11
#define RCC_APB2_SPI1		12
#define RCC_APB2_SPI4		13
#define RCC_APB2_SYSCFG		14
#define RCC_APB2_TIM9		16
#define RCC_APB2_TIM10		17
#define RCC_APB2_TIM11		18


/*****PRESCALER*****/
#define RCC_APB_PRSC_1		0b000
#define RCC_APB_PRSC_2		0b100
#define RCC_APB_PRSC_4		0b101
#define RCC_APB_PRSC_8		0b110

/************PROTOTYPES************/
void MRCC_void_Init(void);
void MRCC_void_EnablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral);
void MRCC_void_DisablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral);
void MRCC_void_SetAPB1Prescaler(u8 copyu8_APB1Prescaler);
void MRCC_void_SetAPB2Prescaler(u8 copyu8_APB2Prescaler);
void MRCC_void_SetAHBPrescaler(u8 copyu8_AHBPrescaler);


#endif /* MRCC_INTERFACE_H_ */
