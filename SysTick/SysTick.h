/******************************************************************************
 *
 * Module: SysTick Timer
 *
 * File Name: SysTick.h
 *
 * Description: Header file for the Tiva_C SysTick Timer driver
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "Common_Macros.h"
#include "Std_Types.h"


/*******************************************************************************
 *                         Macros Declaration                                   *
 *******************************************************************************/
/*
 * Macros for GPIO Status
 */
#define SysTick_INITIALIZED                (1U)
#define SysTick_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for SysTick_ChannelType used for covering all available gpt pins
 * 0 => <number of SysTick Channels> */
typedef uint8           SysTick_ChannelType;

/* Type for reading and setting the timer values (in number of ticks). */
typedef uint32         SysTick_ValueType;

typedef enum {
    SysTick_POLLING,
    SysTick_INTERRUPT,
} SysTick_Mode;

typedef enum {
    SysTick_CPU,
    SysTick_CPU_4
} SysTick_CLOCK;

typedef struct {
    SysTick_Mode Mode;
    SysTick_CLOCK Clock;
}SysTick_ConfigType;

/*******************************************************************************
 *                          Prototypes for the APIs.                           *
 *******************************************************************************/

extern void SysTick_Init(SysTick_ConfigType* Config_Ptr);
extern void SysTick_Deinit(void);
extern void SysTick_PeriodSet(uint32 Period);
extern uint32 SysTick_PeriodGet(void);
extern uint32 SysTick_ValueGet(void);

#endif /* SYSTICK_H_ */
