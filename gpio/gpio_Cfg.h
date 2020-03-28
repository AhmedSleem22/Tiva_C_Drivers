 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for GPIO Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef GPIO_CFG_H
#define GPIO_CFG_H

/*
 * Module Version 1.0.0
 */
#define GPIO_CFG_SW_MAJOR_VERSION              (1U)
#define GPIO_CFG_SW_MINOR_VERSION              (0U)
#define GPIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define GPIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define GPIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define GPIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define GPIO_DEV_ERROR_DETECT                (STD_OFF)

/* Pre-compile option for Version Info API */
#define GPIO_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of GPIO_FlipChannel API */
#define GPIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured GPIO Channels */
#define GPIO_CONFIGURED_CHANNLES             (4U)

/* Channel Index in the array of structures in GPIO_PBcfg.c */
#define GpioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define GpioConf_LED2_CHANNEL_ID_INDEX        (uint8)0x01
#define GpioConf_BUTTON1_CHANNEL_ID_INDEX     (uint8)0x02
#define GpioConf_BUTTON2_CHANNEL_ID_INDEX     (uint8)0x03

/* GPIO Configured Port ID's  */
#define GpioConf_LED1_PORT_NUM                (Gpio_PortType)5 /* PORTF */
#define GpioConf_LED2_PORT_NUM                (Gpio_PortType)5 /* PORTF */
#define GpioConf_BUTTON1_PORT_NUM             (Gpio_PortType)5 /* PORTA */
#define GpioConf_BUTTON2_PORT_NUM             (Gpio_PortType)5 /* PORTB */

/* GPIO Configured Channel ID's */
#define GpioConf_LED1_CHANNEL_NUM             (Gpio_ChannelType)1 /* Pin 3 in PORTC */
#define GpioConf_LED2_CHANNEL_NUM             (Gpio_ChannelType)2 /* Pin 6 in PORTD */
#define GpioConf_BUTTON1_CHANNEL_NUM          (Gpio_ChannelType)4 /* Pin 2 in PORTA */
#define GpioConf_BUTTON2_CHANNEL_NUM          (Gpio_ChannelType)0 /* Pin 4 in PORTB */

#endif /* GPIO_CFG_H */
