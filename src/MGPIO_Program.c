/*
 * MGPIO_Program.c
 *
 *  Created on: Feb 1, 2024
 *      Author: M
 */

/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../include/MGPIO_Config.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MGPIO_Private.h"

void MGPIO_void_SetPinMode(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_Mode){

	if((copyu8_Port == GPIO_PORTA) && ((copyu8_Pin == GPIO_PIN13) || (copyu8_Pin == GPIO_PIN14) || (copyu8_Pin == GPIO_PIN15))) {
		return;
	}
	else if((copyu8_Port == GPIO_PORTB) && ((copyu8_Pin == GPIO_PIN3) || (copyu8_Pin == GPIO_PIN4))) {
		return;
	}

	switch(copyu8_Port){
	case GPIO_PORTA:
		GPIOA->MODER &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOA->MODER |= (copyu8_Mode << (copyu8_Pin*2));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOB->MODER |= (copyu8_Mode << (copyu8_Pin*2));
		break;
	case GPIO_PORTC:
		GPIOC->MODER &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOC->MODER |= (copyu8_Mode << (copyu8_Pin*2));
		break;
	default: break;
	}
}

void MGPIO_void_SetPinOutputMode(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_OutputMode, u8 copyu8_Speed){

	if((copyu8_Port == GPIO_PORTA) && ((copyu8_Pin == GPIO_PIN13) || (copyu8_Pin == GPIO_PIN14) || (copyu8_Pin == GPIO_PIN15))) {
		return;
	}
	else if((copyu8_Port == GPIO_PORTB) && ((copyu8_Pin == GPIO_PIN3) || (copyu8_Pin == GPIO_PIN4))) {
		return;
	}

	switch(copyu8_Port){
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOA->OSPEEDR |= (copyu8_Speed << (copyu8_Pin*2));

		switch(copyu8_OutputMode){
		case GPIO_OPEN_DRAIN:
			SET_BIT(GPIOA->OTYPER, copyu8_Pin);
			break;
		case GPIO_PUSH_PULL:
			CLR_BIT(GPIOA->OTYPER, copyu8_Pin);
			break;
		default: break;
		}
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOB->OSPEEDR |= (copyu8_Speed << (copyu8_Pin*2));

		switch(copyu8_OutputMode){
		case GPIO_OPEN_DRAIN:
			SET_BIT(GPIOB->OTYPER, copyu8_Pin);
			break;
		case GPIO_PUSH_PULL:
			CLR_BIT(GPIOB->OTYPER, copyu8_Pin);
			break;
		default: break;
		}
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOC->OSPEEDR |= (copyu8_Speed << (copyu8_Pin*2));

		switch(copyu8_OutputMode){
		case GPIO_OPEN_DRAIN:
			SET_BIT(GPIOC->OTYPER, copyu8_Pin);
			break;
		case GPIO_PUSH_PULL:
			CLR_BIT(GPIOC->OTYPER, copyu8_Pin);
			break;
		default: break;
		}
		break;
	default: break;
	}
}

void MGPIO_void_SetPinInputMode(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_InputMode){

	if((copyu8_Port == GPIO_PORTA) && ((copyu8_Pin == GPIO_PIN13) || (copyu8_Pin == GPIO_PIN14) || (copyu8_Pin == GPIO_PIN15))) {
		return;
	}
	else if((copyu8_Port == GPIO_PORTB) && ((copyu8_Pin == GPIO_PIN3) || (copyu8_Pin == GPIO_PIN4))) {
		return;
	}

	switch(copyu8_Port){
	case GPIO_PORTA:
		GPIOA->PUPDR &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOA->PUPDR |= (copyu8_InputMode << (copyu8_Pin*2));
		break;
	case GPIO_PORTB:
		GPIOB->PUPDR &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOB->PUPDR |= (copyu8_InputMode << (copyu8_Pin*2));
		break;
	case GPIO_PORTC:
		GPIOC->PUPDR &= ~(TWO_BIT_MASK << (copyu8_Pin*2));
		GPIOC->PUPDR |= (copyu8_InputMode << (copyu8_Pin*2));
		break;
	default: break;
	}
}

void MGPIO_void_SetPinValue(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_Output){
	if((copyu8_Port == GPIO_PORTA) && ((copyu8_Pin == GPIO_PIN13) || (copyu8_Pin == GPIO_PIN14) || (copyu8_Pin == GPIO_PIN15))) {
		return;
	}
	else if((copyu8_Port == GPIO_PORTB) && ((copyu8_Pin == GPIO_PIN3) || (copyu8_Pin == GPIO_PIN4))) {
		return;
	}

	switch(copyu8_Port){
	case GPIO_PORTA:
		switch(copyu8_Output){
		case GPIO_PIN_HIGH:
			SET_BIT(GPIOA->ODR, copyu8_Pin);
			break;
		case GPIO_PIN_LOW:
			CLR_BIT(GPIOA->ODR, copyu8_Pin);
			break;
		default: break;
		}
		break;
	case GPIO_PORTB:
		switch(copyu8_Output){
		case GPIO_PIN_HIGH:
			SET_BIT(GPIOB->ODR, copyu8_Pin);
			break;
		case GPIO_PIN_LOW:
			CLR_BIT(GPIOB->ODR, copyu8_Pin);
			break;
		default: break;
		}
		break;
	case GPIO_PORTC:
		switch(copyu8_Output){
		case GPIO_PIN_HIGH:
			SET_BIT(GPIOC->ODR, copyu8_Pin);
			break;
		case GPIO_PIN_LOW:
			CLR_BIT(GPIOC->ODR, copyu8_Pin);
			break;
		default: break;
		}
		break;
	default: break;
	}
}

void MGPIO_void_GetPinValue(u8 copyu8_Port, u8 copyu8_Pin, u8 *ptru8_Return){
	if((copyu8_Port == GPIO_PORTA) && ((copyu8_Pin == GPIO_PIN13) || (copyu8_Pin == GPIO_PIN14) || (copyu8_Pin == GPIO_PIN15))) {
		return;
	}
	else if((copyu8_Port == GPIO_PORTB) && ((copyu8_Pin == GPIO_PIN3) || (copyu8_Pin == GPIO_PIN4))) {
		return;
	}

	switch(copyu8_Port){
	case GPIO_PORTA:
		*ptru8_Return = GET_BIT(GPIOA->IDR, copyu8_Pin);
		break;
	case GPIO_PORTB:
		*ptru8_Return = GET_BIT(GPIOB->IDR, copyu8_Pin);
		break;
	case GPIO_PORTC:
		*ptru8_Return = GET_BIT(GPIOC->IDR, copyu8_Pin);
		break;
	default: break;
	}
}

void MGPIO_void_SetResetPin(u8 copyu8_Port, u8 copyu8_Pin, u8 copyu8_SetReset){
	if((copyu8_Port == GPIO_PORTA) && ((copyu8_Pin == GPIO_PIN13) || (copyu8_Pin == GPIO_PIN14) || (copyu8_Pin == GPIO_PIN15))) {
		return;
	}
	else if((copyu8_Port == GPIO_PORTB) && ((copyu8_Pin == GPIO_PIN3) || (copyu8_Pin == GPIO_PIN4))) {
		return;
	}

	switch(copyu8_Port){
	case GPIO_PORTA:
		switch(copyu8_SetReset){
		case GPIO_SET:
			SET_BIT(GPIOA->BSRR, copyu8_Pin);
			break;
		case GPIO_RESET:
			SET_BIT(GPIOA->BSRR, (copyu8_Pin + 16));
			break;
		default: break;
		}
		break;
	case GPIO_PORTB:
		switch(copyu8_SetReset){
		case GPIO_SET:
			SET_BIT(GPIOB->BSRR, copyu8_Pin);
			break;
		case GPIO_RESET:
			SET_BIT(GPIOB->BSRR, (copyu8_Pin + 16));
			break;
		default: break;
		}
		break;
	case GPIO_PORTC:
		switch(copyu8_SetReset){
		case GPIO_SET:
			SET_BIT(GPIOC->BSRR, copyu8_Pin);
			break;
		case GPIO_RESET:
			SET_BIT(GPIOC->BSRR, (copyu8_Pin + 16));
			break;
		default: break;
		}
		break;
	default: break;
	}
}


