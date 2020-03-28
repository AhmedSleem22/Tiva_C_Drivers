/*
 * Gpt.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed M.Sleem
 */

#ifndef GPT_H_
#define GPT_H_

#include "Common_Macros.h"
#include "Std_Types.h"
#include "gpt_Cfg.h"


/*******************************************************************************
 *                         Macros Declaration                                   *
 *******************************************************************************/
/*
 * Macros for GPIO Status
 */
#define GPT_INITIALIZED                (1U)
#define GPT_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                                Error Codes                                  *
 *******************************************************************************/
#define GPT_E_UNINIT                        0x0A
#define GPT_E_BUSY                          0x0B
#define GPT_E_NOT_STARTED                   0x0C
#define GPT_E_ALREADY_INITIALIZED           0x0D
#define GPT_E_PARAM_CHANNEL                 0x14
#define GPT_E_PARAM_VALUE                   0x15
#define GPT_E_PARAM_MODE                    0x1F
#define GPT_E_PARAM_CONFIG                  0x0E

/** name Service id's */
#define GPT_INIT_SERVICE_ID                 0x01
#define GPT_DEINIT_SERVICE_ID               0x02
#define GPT_GETTIMEELAPSED_SERVICE_ID       0x03
#define GPT_GETTIMEREMAINING_SERVICE_ID     0x04
#define GPT_STARTTIMER_SERVICE_ID           0x05
#define GPT_STOPTIMER_SERVICE_ID            0x06
#define GPT_ENABLENOTIFICATION_SERVICE_ID   0x07
#define GPT_DISABLENOTIFICATION_SERVICE_ID  0x08
#define GPT_SETMODE_SERVIVCE_ID             0x09
#define GPT_DISABLEWAKEUP_SERVICE_ID        0x0A
#define GPT_ENABLEWAKEUP_SERVICE_ID         0x0B
#define GPT_CBK_CHECKWAKEUP_SERVICE_ID      0x0C

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for Gpt_ChannelType used for covering all available gpt pins
 * 0 => <number of Gpt Channels> */
typedef uint8           Gpt_ChannelType;

/* Type for reading and setting the timer values (in number of ticks). */
typedef uint32         Gpt_ValueType;

typedef enum {
    GPT_TIMER0,
    GPT_TIMER1,
    GPT_TIMER2,
    GPT_TIMER3,
    GPT_TIMER4,
    GPT_TIMER5
}Gpt_TimerBlock;

typedef enum {
    GPT_TIMERA,
    GPT_TIMERB,
    GPT_CONCAT
}Gpt_TimerChannel;

typedef enum {
    GPT_ONE_SHOT_MODE,
    GPT_PERIODIC_MODE,
    GPT_RTC_MODE,
    GPT_INPUT_EDAGE_TIME,
    GPT_INPUT_EDAGE_COUNT,
    GPT_PWM_MODE,
}GPT_ChannelMode;

typedef enum {
    GPT_32BITS,
    GPT_32BITSRTC,
    GPT_16BITS=0x4,
}Gpt_BitRange;

typedef enum {
    GPT_POSITIVEEDGE,
    GPT_NEGATIVEEDGE,
    Reserved,
    BOTHEDGES
}Gpt_EventMode;

typedef enum {
    GPT_CHANNEL_CLKSRC_SYS,
    GPT_EXTERNAL_CLOCK,
    GPT_PLL_CLOCK,
    GPT_CHANNEL_CLKSRC_EXT /* NOT SUPPORT */
}Gpt_ChannelClkSrcType;

typedef enum {
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
}Gpt_ModeType;

typedef enum {
    GPT_COUNTDOWN,
    GPT_COUNTUP
}GPT_ChannelCountDirection;

typedef enum {
    GPT_POLLING,
    GPT_INTERRUPT
}GPT_ChannelStatus;


typedef struct {
    Gpt_TimerBlock Block;
    Gpt_TimerChannel Channel;
    GPT_ChannelMode Mode;
    Gpt_BitRange Range;
    GPT_ChannelCountDirection Direction;
    Gpt_ValueType Value;
    GPT_ChannelStatus Status;
    Gpt_EventMode Event;

}Gpt_ConfigChannel;

typedef struct
{
    Gpt_ConfigChannel Channels[GPT_CONFIGURED_CHANNLES];
}Gpt_ConfigType;

#endif /* GPT_H_ */
