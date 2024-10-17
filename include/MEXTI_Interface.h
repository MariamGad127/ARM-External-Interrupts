/*
 * MEXTI_Interface.h
 *
 *  Created on: Feb 5, 2024
 *      Author: HP
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

/***********ENUMS***********/
typedef enum{
	MEXTI_LINE0 = 0,
	MEXTI_LINE1,
	MEXTI_LINE2,
	MEXTI_LINE3,
	MEXTI_LINE4,
	MEXTI_LINE5,
	MEXTI_LINE6,
	MEXTI_LINE7,
	MEXTI_LINE8,
	MEXTI_LINE9,
	MEXTI_LINE10,
	MEXTI_LINE11,
	MEXTI_LINE12,
	MEXTI_LINE13,
	MEXTI_LINE14,
	MEXTI_LINE15,

}MEXTI_Line_t;

typedef enum{
	MEXTI_PORTA = 0,
	MEXTI_PORTB,
	MEXTI_PORTC,

}MEXTI_Port_t;

typedef enum{
	MEXTI_RISING_EDGE = 0,
	MEXTI_FALLING_EDGE,
	MEXTI_ON_CHANGE,

}MEXTI_Mode_t;

typedef enum{
	MEXTI_DISABLED = 0,
	MEXTI_ENABLED,

}MEXTI_State_t;



/***********PROTOTYPES***********/
void MEXTI_void_Init(void);

void MEXTI_void_EnableEXTILine(MEXTI_Line_t copy_MEXTI_Line);
void MEXTI_void_DisableEXTILine(MEXTI_Line_t copy_MEXTI_Line);

void MEXTI_void_SetCallback(MEXTI_Line_t copy_MEXTI_Line, PtrToFunc_void copy_CallbackFunc);

void MEXTI_void_SWIRequest(MEXTI_Line_t copy_MEXTI_Line);

void MEXTI_void_ClearPendingFlag(MEXTI_Line_t copy_MEXTI_Line);

void MEXTI_void_SelectPort(MEXTI_Line_t copy_MEXTI_Line, MEXTI_Port_t copy_MEXTI_Port);

void MEXTI_void_SetMode(MEXTI_Line_t copy_MEXTI_Line, MEXTI_Mode_t copy_MEXTI_Mode);

#endif /* MEXTI_INTERFACE_H_ */
