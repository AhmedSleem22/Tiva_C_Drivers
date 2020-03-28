 /******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for GPT Module.
 *
 * Author: Ahmed Sleem
 ******************************************************************************/

#ifndef GPT_CFG_H
#define GPT_CFG_H

/*
 * Module Version 1.0.0
 */
#define GPT_CFG_SW_MAJOR_VERSION              (1U)
#define GPT_CFG_SW_MINOR_VERSION              (0U)
#define GPT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define GPT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define GPT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define GPT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define GPT_DEV_ERROR_DETECT                (STD_OFF)

/* Pre-compile option for Version Info API */
#define GPT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of GPT_FlipChannel API */
#define GPT_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured GPT Channels */
#define GPT_CONFIGURED_CHANNLES             (1U)

/* Channel Index in the array of structures in GPT_PBcfg.c */
#define GptConf_TIMER1A_CAP_CHANNEL_ID_INDEX        (uint8)0x00
#define GptConf_LED2_CHANNEL_ID_INDEX        (uint8)0x01
#define GptConf_BUTTON1_CHANNEL_ID_INDEX     (uint8)0x02
#define GptConf_BUTTON2_CHANNEL_ID_INDEX     (uint8)0x03

/* GPT Configured Port ID's  */
#define GptConf_LED1_PORT_NUM                (Gpt_PortType)5 /* PORTF */
#define GptConf_LED2_PORT_NUM                (Gpt_PortType)5 /* PORTF */
#define GptConf_BUTTON1_PORT_NUM             (Gpt_PortType)5 /* PORTA */
#define GptConf_BUTTON2_PORT_NUM             (Gpt_PortType)5 /* PORTB */

/* GPT Configured Channel ID's */
#define GptConf_LED1_CHANNEL_NUM             (Gpt_ChannelType)1 /* Pin 3 in PORTC */
#define GptConf_LED2_CHANNEL_NUM             (Gpt_ChannelType)2 /* Pin 6 in PORTD */
#define GptConf_BUTTON1_CHANNEL_NUM          (Gpt_ChannelType)4 /* Pin 2 in PORTA */
#define GptConf_BUTTON2_CHANNEL_NUM          (Gpt_ChannelType)0 /* Pin 4 in PORTB */

#endif /* GPT_CFG_H */
