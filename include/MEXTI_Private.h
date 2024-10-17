/*
 * MEXTI_Private.h
 *
 *  Created on: Feb 5, 2024
 *      Author: HP
 */

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_


/********************EXTI REGISTERS********************/
#define EXTI_BASE_ADDRESS (0x40013C00)

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t*)EXTI_BASE_ADDRESS)


/********************SYSCFG REGISTERS********************/
#define SYSCFG_BASE_ADDRESS (0x40013800)

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)


/********************MACROS********************/
typedef struct {
	MEXTI_Line_t Line;
	MEXTI_Port_t Port;
	MEXTI_Mode_t Mode;
	MEXTI_State_t State;

}MEXTI_Configurations_t;


#define EXTI_TOTAL_NUM 			16
#define FOUR_BIT_MASK			0b1111
#define EXTI_NUM_IN_REGISTER	4


#endif /* MEXTI_PRIVATE_H_ */
