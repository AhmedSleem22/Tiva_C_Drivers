/******************************************************************************
 *
 * Module: SysTick
 *
 * File Name: SysTick_Regs.h
 *
 * Description: SysTick Timer Registers.
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/
#ifndef SYSTICK_REGS_H_
#define SYSTICK_REGS_H_

/*****************************************************************************
* Macros for hardware access, both direct and via the bit-band region.
******************************************************************************/
#define HWREG(x)                                                                \
        (*((volatile uint32 *)(x)))
#define HWREGH(x)                                                               \
        (*((volatile uint16 *)(x)))
#define HWREGB(x)                                                               \
        (*((volatile uint8 *)(x)))
#define HWREGBITW(x, b)                                                         \
        HWREG(((uint32)(x) & 0xF0000000) | 0x02000000 |                         \
              (((uint32)(x) & 0x000FFFFF) << 5) | ((b) << 2))
#define HWREGBITH(x, b)                                                         \
        HWREGH(((uint32)(x) & 0xF0000000) | 0x02000000 |                        \
               (((uint32)(x) & 0x000FFFFF) << 5) | ((b) << 2))
#define HWREGBITB(x, b)                                                         \
        HWREGB(((uint32)(x) & 0xF0000000) | 0x02000000 |                        \
               (((uint32)(x) & 0x000FFFFF) << 5) | ((b) << 2))

/*****************************************************************************
 * NVIC registers
******************************************************************************/

#define NVIC_ST_CTRL_R          (*((volatile uint32 *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32 *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32 *)0xE000E018))

/******************************************************************************
 * The following are defines for the bit fields in the NVIC_ST_CTRL register.
*******************************************************************************/
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count Flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt Enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Enable

//**********************************************************


#endif /* SYSTICK_REGS_H_ */
