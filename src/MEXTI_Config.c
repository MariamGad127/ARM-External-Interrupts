/*
 * MEXTI_Config.c
 *
 *  Created on: Feb 5, 2024
 *      Author: HP
 */

/************LIBRARIES************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/************MCAL************/
#include "../include/MEXTI_Interface.h"
#include "../include/MEXTI_Private.h"
#include "../include/MEXTI_Config.h"


MEXTI_Configurations_t MEXTI_Config[MEXTI_MAX_NUM] = {
		{
				MEXTI_LINE0,
				MEXTI_PORTB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		},
		{
				MEXTI_LINE1,
				MEXTI_PORTB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		}
};

