

/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MEXTI_Interface.h"

#include "../../First_ARM_Project/include/MSTK_Interface.h"


void Handler1 (void);
void Handler2 (void);

void main (void) {
	// Initialize RCC and SYSTICK
	MRCC_void_Init();
	MSTK_void_Init();

	// Select interrupt priority
	MNVIC_void_SetInterruptGroupMode(Group16_NoSub);
	MNVIC_void_SetInterruptPriority(6,0,0);
	MNVIC_void_SetInterruptPriority(7,1,0);

	// Enable clock for peripherals
	MRCC_void_EnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);
	MRCC_void_EnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOB);
	MRCC_void_EnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);

	// Configure port A [pins 0 to 7] as output, and set its output mode (LEDs)
	u8 localu8_Iterator = 0;
	for ( localu8_Iterator = 0 ; localu8_Iterator < 8 ; localu8_Iterator++) {
		MGPIO_void_SetPinMode(GPIO_PORTA , localu8_Iterator , GPIO_OUTPUT);
		MGPIO_void_SetPinOutputMode(GPIO_PORTA , localu8_Iterator , GPIO_PUSH_PULL , GPIO_LOW_SPEED);
		// Initial state of LEDs
		if( localu8_Iterator %2 == 0) {
			MGPIO_void_SetResetPin(GPIO_PORTA , localu8_Iterator , GPIO_RESET);
		}
		else {
			MGPIO_void_SetResetPin(GPIO_PORTA , localu8_Iterator , GPIO_SET);
		}
	}

	// Set input mode of pins 0 and 1 in port B (push buttons)
	MGPIO_void_SetPinMode(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
	MGPIO_void_SetPinInputMode(GPIO_PORTB, GPIO_PIN0, GPIO_PUP);
	MGPIO_void_SetPinMode(GPIO_PORTB, GPIO_PIN1, GPIO_INPUT);
	MGPIO_void_SetPinInputMode(GPIO_PORTB, GPIO_PIN1, GPIO_PUP);

	// Enable EXTI0 and EXTI1
	MEXTI_void_Init();
	MEXTI_void_SetCallback(MEXTI_LINE0 , Handler1);
	MEXTI_void_SetCallback(MEXTI_LINE1 , Handler2);
	MNVIC_void_EnablePeripheralInterrupt(6);
	MNVIC_void_EnablePeripheralInterrupt(7);
	MEXTI_void_EnableEXTILine(MEXTI_LINE0);
	MEXTI_void_EnableEXTILine(MEXTI_LINE1);

	while (1) {

	}

}


void Handler1 (void) {
	// All LEDs are on
	u8 localu8_Iterator = 0;
	for ( localu8_Iterator = 0 ; localu8_Iterator < 8 ; localu8_Iterator++) {
		MGPIO_void_SetResetPin(GPIO_PORTA , localu8_Iterator , GPIO_SET);
	}
	while (1) {

	}
}

void EXTI0_IRQHandler(void){
	Handler1();
}

void Handler2 (void) {
	// LEDs are initially low
	u8 localu8_Iterator = 0;
	for ( localu8_Iterator = 0 ; localu8_Iterator < 8 ; localu8_Iterator++) {
		MGPIO_void_SetResetPin(GPIO_PORTA , localu8_Iterator , GPIO_RESET);
	}

	u16 localu16_delayTime = 1000;
	// Toggle LEDs sequentially
	while (1) {
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN7,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN0,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN0,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN1,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN1,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN2,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN2,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN3,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN3,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN4,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN4,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN5,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN5,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN6,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);

		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN6,GPIO_RESET);
		MGPIO_void_SetResetPin(GPIO_PORTA,GPIO_PIN7,GPIO_SET);
		MSTK_void_Delayms(localu16_delayTime);
	}
}

void EXTI1_IRQHandler(void){
	Handler2();
}



