 /******************************************************************************
 *
 * Module: ModuleTest
 *
 * File Name: Gpio_ModuleTest.c
 *
 * Description: Source file for the Gpio Test Cases.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "gpio.h"
#include "gpio_Regs.h"

/************************************************************************************
* Test ID :TestCase1
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the two leds shall be turned on.
*                  2. Press the second button the two leds shall be turned on.
*************************************************************************************/

void TestCase1(void)
{
	uint8 button1 = STD_LOW;
	uint8 button2 = STD_LOW;

	/* Wait until the first button is pressed */
	while(button1 != STD_HIGH)
	{
		button1 = Gpio_ReadChannel(GpioConf_BUTTON1_CHANNEL_ID_INDEX);
	}

	/* Turn on the two Leds */
	Gpio_WriteChannel(GpioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
	Gpio_WriteChannel(GpioConf_LED2_CHANNEL_ID_INDEX,STD_HIGH);

	/* Wait until the second button is pressed */
	while(button2 != STD_HIGH)
	{
		button2 = Gpio_ReadChannel(GpioConf_BUTTON2_CHANNEL_ID_INDEX);
	}

	/* Turn off the two Leds */
	Gpio_WriteChannel(GpioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);
	Gpio_WriteChannel(GpioConf_LED2_CHANNEL_ID_INDEX,STD_LOW);
}

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Write and Read Channel API's functionality.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. Press the first button the two leds shall be flipped (OFF --> ON).
*                  2. Press the second button the two leds shall be flipped (ON --> OFF).
*************************************************************************************/
void TestCase2(void)
{
	uint8 button1 = STD_LOW;
	uint8 button2 = STD_LOW;

	/* Wait until the first button is pressed */
	while(button1 != STD_HIGH)
	{
		button1 = Gpio_ReadChannel(GpioConf_BUTTON1_CHANNEL_ID_INDEX);
	}

	/* Flip the two Leds */
	//Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	//Dio_FlipChannel(DioConf_LED2_CHANNEL_ID_INDEX);

	/* Wait until the second button is pressed */
	while(button2 != STD_HIGH)
	{
		button2 = Gpio_ReadChannel(GpioConf_BUTTON2_CHANNEL_ID_INDEX);
	}

	/* Flip the two Leds */
	//Dio_FlipChannel(GpioConf_LED1_CHANNEL_ID_INDEX);
	//Dio_FlipChannel(GpioConf_LED2_CHANNEL_ID_INDEX);
}

int main(void)
{
	/* Initialize the Gpio Driver */
	Gpio_Init(&Gpio_Configuration);

	/* Run the First Test Case */
	TestCase1();

	/* Run the Second Test Case */
	//TestCase2();
}
