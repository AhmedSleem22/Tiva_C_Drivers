 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for Dio Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "gpio.h"

/*
 * Module Version 1.0.0
 */

/* PB structure used with Dio_Init API */
const Gpio_ConfigType Gpio_Configuration = { GPIO_PORTB, PORT_PIN0, GPIO_PIN_IN, GPIO_DISABLE_PULL_UP, GPIO_DISABLE_PULL_DOWN, GPIO_INITIAL_LOW, GPIO_DIO};
