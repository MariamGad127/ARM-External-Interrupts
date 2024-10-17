/*
 * MGPIO_Interface.h
 *
 *  Created on: Feb 1, 2024
 *      Author: M
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_


/***********MACROS***********/
/*****PORTS*****/
#define GPIO_PORTA		0
#define GPIO_PORTB		1
#define GPIO_PORTC		2

/*****PINS*****/
#define GPIO_PIN0 	0
#define GPIO_PIN1 	1
#define GPIO_PIN2 	2
#define GPIO_PIN3 	3
#define GPIO_PIN4 	4
#define GPIO_PIN5 	5
#define GPIO_PIN6 	6
#define GPIO_PIN7 	7
#define GPIO_PIN8 	8
#define GPIO_PIN9 	9
#define GPIO_PIN10 	10
#define GPIO_PIN11 	11
#define GPIO_PIN12 	12
#define GPIO_PIN13 	13
#define GPIO_PIN14 	14
#define GPIO_PIN15 	15

/*****PIN MODE*****/
#define GPIO_INPUT		0b00
#define GPIO_OUTPUT		0b01
#define GPIO_ALTERNATE	0b10
#define GPIO_ANALOG		0b11

/*****PIN OUTPUT MODE*****/
#define GPIO_PUSH_PULL		0
#define GPIO_OPEN_DRAIN		1

/*****SPEED MODE*****/
#define GPIO_LOW_SPEED			0b00
#define GPIO_MEDIUM_SPEED		0b01
#define GPIO_HIGH_SPEED			0b10
#define GPIO_VHIGH_SPEED		0b11

/*****PULL UP/DOWN*****/
#define GPIO_NOPUPD		0b00
#define GPIO_PUP		0b01
#define GPIO_PDOWN		0b10

/*****PIN VALUES*****/
#define GPIO_PIN_HIGH	1
#define GPIO_PIN_LOW	0

/*****PIN SET/RESET*****/
#define GPIO_SET	1
#define GPIO_RESET	0

/***********PROTOTYPES***********/
void MGPIO_void_SetPinMode(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_Mode);
void MGPIO_void_SetPinOutputMode(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_OutputMode, u8 copyu8_Speed);
void MGPIO_void_SetPinInputMode(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_InputMode);
void MGPIO_void_SetPinValue(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_Output);
void MGPIO_void_GetPinValue(u8 copyu8_Port, u8 copyu8_Pin, u8 *ptru8_Return);
void MGPIO_void_SetResetPin(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_SetReset);



#endif /* MGPIO_INTERFACE_H_ */
