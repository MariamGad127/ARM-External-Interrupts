/*
 * MSTK_Private.h
 *
 *  Created on: Feb 6, 2024
 *      Author: HP
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

/************STK REGISTERS************/
#define STK_BASE_ADDRESS	(0xE000E010)

typedef struct {
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;

#define STK	((volatile STK_t*)STK_BASE_ADDRESS)

/************MACROS************/
/*****CLKSOURCE*****/
#define MSTK_AHB		1
#define MSTK_AHB_BY_8	0
// HSI = 16MHz
#define	MSTK_FREQ		16000000

/*****CTRL BITS*****/
#define ENABLE			0
#define TICKINT			1
#define CLKSOURCE		2
#define COUNTFLAG		16

#define MSTK_MAX_PRELOAD 	0x00FFFFFF

#endif /* MSTK_PRIVATE_H_ */
