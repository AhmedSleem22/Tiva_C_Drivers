/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: header file for the Tiva C GPIO driver
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_


#include "Common_Macros.h"
#include "Std_Types.h"
#include "gpio_Cfg.h"


/*******************************************************************************
 *                         Macros Declaration                                   *
 *******************************************************************************/
/*
 * Macros for GPIO Status
 */
#define GPIO_INITIALIZED                (1U)
#define GPIO_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for Port_PinType used for covering all available port pins
 * 0 => <number of port pins> */
typedef uint8           Gpio_Pin;

/* Type definition for Port_ChannelType used by the PORT APIs */
typedef uint32         Gpio_Port;

/* Type definition for Port_PinModeType used for covering all available port pins */
//typedef uint32       Gpio_PinModeType;

typedef enum {
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF
} Gpio_PortType;

typedef enum {
    PORT_PIN0,
    PORT_PIN1,
    PORT_PIN2,
    PORT_PIN3,
    PORT_PIN4,
    PORT_PIN5,
    PORT_PIN6,
    PORT_PIN7
} Gpio_PinType;

typedef enum {
    GPIO_PIN_IN,
    GPIO_PIN_OUT
} Gpio_PinDirectionType;

typedef enum {
    GPIO_DISABLE_PULL_UP,
    GPIO_ENABLE_PULL_UP
} Gpio_PinPullUp;

typedef enum {
    GPIO_DISABLE_PULL_DOWN,
    GPIO_ENABLE_PULL_DOWN
} Gpio_PinPullDown;

typedef enum {
    GPIO_INITIAL_LOW,
    GPIO_INITIAL_HIGHT
} Gpio_PinLevelInit;

typedef enum {
    GPIO_DIO,

} Gpio_PinModeType;

typedef struct {
    Gpio_PortType Port;
    Gpio_PinType Pin_Num;
    Gpio_PinDirectionType Direction;
    Gpio_PinPullUp Pin_PullUP;
    Gpio_PinPullDown Pin_PullDown;
    Gpio_PinLevelInit Pin_Level;
    Gpio_PinModeType Pin_Mode;

} Gpio_ConfigChannel;

/* Data Structure required for initializing the Dio Driver */
typedef struct
{
    Gpio_ConfigChannel Channels[GPIO_CONFIGURED_CHANNLES];
} Gpio_ConfigType;


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern volatile uint16 g_PINResult;

/* Extern PB structures to be used by Port and other modules */
extern const Gpio_ConfigType Gpio_Configuration;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the PIN driver.
 */
void Gpio_Init(const Gpio_ConfigType* Config_Ptr);
/*
 * Description :
 * Function responsible for Configure pin(s) for use as GPIO inputs.
 */
uint8 Gpio_ReadChannel(uint8 ChannelId);

/*
 * Description :
 * Function responsible for Configure pin(s) for use as GPIO outputs.
 */
void Gpio_WriteChannel(uint8 ChannelId, uint8 Level);

uint8 Gpio_FlipChanne(uint8 ChannelId);

/*
 * Description :
 * Function responsible for read analog data from a certain PIN channel
 * and convert it to digital using the PIN driver.
 */
void Gpio_SetPinMode(Gpio_PinType Pin, Gpio_PinModeType Mode);



#endif /* GPIO_H_ */
