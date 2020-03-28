/*
 * Gpt_Regs.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed M.Sleem
 */

#ifndef GPT_REGS_H_
#define GPT_REGS_H_

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
 * The following are defines for the base address of the timers peripheral.
*****************************************************************************/
#define PWM0_BASE               0x40028000  // Pulse Width Modulator (PWM)
#define PWM1_BASE               0x40029000  // Pulse Width Modulator (PWM)

#define TIMER0_BASE             0x40030000  // Timer0
#define TIMER1_BASE             0x40031000  // Timer1
#define TIMER2_BASE             0x40032000  // Timer2
#define TIMER3_BASE             0x40033000  // Timer3
#define TIMER4_BASE             0x40034000  // Timer4
#define TIMER5_BASE             0x40035000  // Timer5

#define WTIMER0_BASE            0x40036000  // Wide Timer0
#define WTIMER1_BASE            0x40037000  // Wide Timer1
#define WTIMER2_BASE            0x4004C000  // Wide Timer2
#define WTIMER3_BASE            0x4004D000  // Wide Timer3
#define WTIMER4_BASE            0x4004E000  // Wide Timer4
#define WTIMER5_BASE            0x4004F000  // Wide Timer5

/******************************************************************************
 * The following are defines for the Timer register offsets.
*******************************************************************************/
#define TIMER_O_CFG             0x00000000  // GPTM Configuration
#define TIMER_O_TAMR            0x00000004  // GPTM Timer A Mode
#define TIMER_O_TBMR            0x00000008  // GPTM Timer B Mode
#define TIMER_O_CTL             0x0000000C  // GPTM Control
#define TIMER_O_SYNC            0x00000010  // GPTM Synchronize
#define TIMER_O_IMR             0x00000018  // GPTM Interrupt Mask
#define TIMER_O_RIS             0x0000001C  // GPTM Raw Interrupt Status
#define TIMER_O_MIS             0x00000020  // GPTM Masked Interrupt Status
#define TIMER_O_ICR             0x00000024  // GPTM Interrupt Clear
#define TIMER_O_TAILR           0x00000028  // GPTM Timer A Interval Load
#define TIMER_O_TBILR           0x0000002C  // GPTM Timer B Interval Load
#define TIMER_O_TAMATCHR        0x00000030  // GPTM Timer A Match
#define TIMER_O_TBMATCHR        0x00000034  // GPTM Timer B Match
#define TIMER_O_TAPR            0x00000038  // GPTM Timer A Prescale
#define TIMER_O_TBPR            0x0000003C  // GPTM Timer B Prescale
#define TIMER_O_TAPMR           0x00000040  // GPTM Timer A Prescale Match
#define TIMER_O_TBPMR           0x00000044  // GPTM Timer B Prescale Match
#define TIMER_O_TAR             0x00000048  // GPTM Timer A
#define TIMER_O_TBR             0x0000004C  // GPTM Timer B
#define TIMER_O_TAV             0x00000050  // GPTM Timer A Value
#define TIMER_O_TBV             0x00000054  // GPTM Timer B Value
#define TIMER_O_RTCPD           0x00000058  // GPTM RTC Predivide
#define TIMER_O_TAPS            0x0000005C  // GPTM Timer A Prescale Snapshot
#define TIMER_O_TBPS            0x00000060  // GPTM Timer B Prescale Snapshot
#define TIMER_O_TAPV            0x00000064  // GPTM Timer A Prescale Value
#define TIMER_O_TBPV            0x00000068  // GPTM Timer B Prescale Value
#define TIMER_O_DMAEV           0x0000006C  // GPTM DMA Event
#define TIMER_O_ADCEV           0x00000070  // GPTM ADC Event
#define TIMER_O_PP              0x00000FC0  // GPTM Peripheral Properties
#define TIMER_O_CC              0x00000FC8  // GPTM Clock Configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     10          // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     2           // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMR register.
//
//*****************************************************************************
#define TIMER_TAMR_TAPLO        0x00000800  // GPTM Timer A PWM Legacy
                                            // Operation
#define TIMER_TAMR_TAMRSU       0x00000400  // GPTM Timer A Match Register
                                            // Update
#define TIMER_TAMR_TAPWMIE      0x00000200  // GPTM Timer A PWM Interrupt
                                            // Enable
#define TIMER_TAMR_TAILD        0x00000100  // GPTM Timer A Interval Load Write
#define TIMER_TAMR_TASNAPS      0x00000080  // GPTM Timer A Snap-Shot Mode
#define TIMER_TAMR_TAWOT        0x00000040  // GPTM Timer A Wait-on-Trigger
//#define TIMER_TAMR_TAMIE        0x00000020  // GPTM Timer A Match Interrupt
                                            // Enable
#define TIMER_TAMR_TAMIE        5           // GPTM Timer A Match Interrupt
                                            // Enable
//#define TIMER_TAMR_TACDIR       0x00000010  // GPTM Timer A Count Direction
#define TIMER_TAMR_TACDIR       4           // GPTM Timer A Count Direction
#define TIMER_TAMR_TAAMS        0x00000008  // GPTM Timer A Alternate Mode
                                            // Select
#define TIMER_TAMR_TACMR        0x00000004  // GPTM Timer A Capture Mode
#define TIMER_TAMR_TAMR_M       0x00000003  // GPTM Timer A Mode
#define TIMER_TAMR_TAMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TAMR_TAMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TAMR_TAMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMR register.
//
//*****************************************************************************
#define TIMER_TBMR_TBPLO        0x00000800  // GPTM Timer B PWM Legacy
                                            // Operation
#define TIMER_TBMR_TBMRSU       0x00000400  // GPTM Timer B Match Register
                                            // Update
#define TIMER_TBMR_TBPWMIE      0x00000200  // GPTM Timer B PWM Interrupt
                                            // Enable
#define TIMER_TBMR_TBILD        0x00000100  // GPTM Timer B Interval Load Write
#define TIMER_TBMR_TBSNAPS      0x00000080  // GPTM Timer B Snap-Shot Mode
#define TIMER_TBMR_TBWOT        0x00000040  // GPTM Timer B Wait-on-Trigger
//#define TIMER_TBMR_TBMIE        0x00000020  // GPTM Timer B Match Interrupt
                                            // Enable
#define TIMER_TBMR_TBMIE        5           // GPTM Timer B Match Interrupt
                                            // Enable
//#define TIMER_TBMR_TBCDIR       0x00000010  // GPTM Timer B Count Direction
#define TIMER_TBMR_TBCDIR       4           // GPTM Timer B Count Direction
#define TIMER_TBMR_TBAMS        0x00000008  // GPTM Timer B Alternate Mode
                                            // Select
#define TIMER_TBMR_TBCMR        2           // GPTM Timer B Capture Mode
#define TIMER_TBMR_TBMR_M       0x00000003  // GPTM Timer B Mode
#define TIMER_TBMR_TBMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TBMR_TBMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TBMR_TBMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_ICR register.
//
//*****************************************************************************
#define TIMER_ICR_WUECINT       0x00010000  // 32/64-Bit Wide GPTM Write Update
                                            // Error Interrupt Clear
#define TIMER_ICR_TBMCINT       0x00000800  // GPTM Timer B Match Interrupt
                                            // Clear
#define TIMER_ICR_CBECINT       0x00000400  // GPTM Timer B Capture Mode Event
                                            // Interrupt Clear
#define TIMER_ICR_CBMCINT       0x00000200  // GPTM Timer B Capture Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_TBTOCINT      0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Clear
#define TIMER_ICR_TAMCINT       0x00000010  // GPTM Timer A Match Interrupt
                                            // Clear
#define TIMER_ICR_RTCCINT       0x00000008  // GPTM RTC Interrupt Clear
#define TIMER_ICR_CAECINT       0x00000004  // GPTM Timer A Capture Mode Event
                                            // Interrupt Clear
#define TIMER_ICR_CAMCINT       0x00000002  // GPTM Timer A Capture Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_TATOCINT      0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_IMR register.
//
//*****************************************************************************
#define TIMER_IMR_WUEIM         0x00010000  // 32/64-Bit Wide GPTM Write Update
                                            // Error Interrupt Mask
#define TIMER_IMR_TBMIM         0x00000800  // GPTM Timer B Match Interrupt
                                            // Mask
#define TIMER_IMR_CBEIM         0x00000400  // GPTM Timer B Capture Mode Event
                                            // Interrupt Mask
#define TIMER_IMR_CBMIM         0x00000200  // GPTM Timer B Capture Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_TBTOIM        0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Mask
#define TIMER_IMR_TAMIM         0x00000010  // GPTM Timer A Match Interrupt
                                            // Mask
//#define TIMER_IMR_RTCIM         0x00000008  // GPTM RTC Interrupt Mask
#define TIMER_IMR_RTCIM         3           // GPTM RTC Interrupt Mask
#define TIMER_IMR_CAEIM         0x00000004  // GPTM Timer A Capture Mode Event
                                            // Interrupt Mask
#define TIMER_IMR_CAMIM         0x00000002  // GPTM Timer A Capture Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_TATOIM        0x00000001  // GPTM Timer A Time-Out Interrupt
                                            // Mask

//*****************************************************************************
//
// Timer registers (TIMER0)
//
//*****************************************************************************
#define TIMER0_CFG_R            (*((volatile uint32 *)0x40030000))
#define TIMER0_TAMR_R           (*((volatile uint32 *)0x40030004))
#define TIMER0_TBMR_R           (*((volatile uint32 *)0x40030008))
#define TIMER0_CTL_R            (*((volatile uint32 *)0x4003000C))
#define TIMER0_SYNC_R           (*((volatile uint32 *)0x40030010))
#define TIMER0_IMR_R            (*((volatile uint32 *)0x40030018))
#define TIMER0_RIS_R            (*((volatile uint32 *)0x4003001C))
#define TIMER0_MIS_R            (*((volatile uint32 *)0x40030020))
#define TIMER0_ICR_R            (*((volatile uint32 *)0x40030024))
#define TIMER0_TAILR_R          (*((volatile uint32 *)0x40030028))
#define TIMER0_TBILR_R          (*((volatile uint32 *)0x4003002C))
#define TIMER0_TAMATCHR_R       (*((volatile uint32 *)0x40030030))
#define TIMER0_TBMATCHR_R       (*((volatile uint32 *)0x40030034))
#define TIMER0_TAPR_R           (*((volatile uint32 *)0x40030038))
#define TIMER0_TBPR_R           (*((volatile uint32 *)0x4003003C))
#define TIMER0_TAPMR_R          (*((volatile uint32 *)0x40030040))
#define TIMER0_TBPMR_R          (*((volatile uint32 *)0x40030044))
#define TIMER0_TAR_R            (*((volatile uint32 *)0x40030048))
#define TIMER0_TBR_R            (*((volatile uint32 *)0x4003004C))
#define TIMER0_TAV_R            (*((volatile uint32 *)0x40030050))
#define TIMER0_TBV_R            (*((volatile uint32 *)0x40030054))
#define TIMER0_RTCPD_R          (*((volatile uint32 *)0x40030058))
#define TIMER0_TAPS_R           (*((volatile uint32 *)0x4003005C))
#define TIMER0_TBPS_R           (*((volatile uint32 *)0x40030060))
#define TIMER0_TAPV_R           (*((volatile uint32 *)0x40030064))
#define TIMER0_TBPV_R           (*((volatile uint32 *)0x40030068))
#define TIMER0_PP_R             (*((volatile uint32 *)0x40030FC0))

//*****************************************************************************
//
// Timer registers (TIMER1)
//
//*****************************************************************************
#define TIMER1_CFG_R            (*((volatile uint32 *)0x40031000))
#define TIMER1_TAMR_R           (*((volatile uint32 *)0x40031004))
#define TIMER1_TBMR_R           (*((volatile uint32 *)0x40031008))
#define TIMER1_CTL_R            (*((volatile uint32 *)0x4003100C))
#define TIMER1_SYNC_R           (*((volatile uint32 *)0x40031010))
#define TIMER1_IMR_R            (*((volatile uint32 *)0x40031018))
#define TIMER1_RIS_R            (*((volatile uint32 *)0x4003101C))
#define TIMER1_MIS_R            (*((volatile uint32 *)0x40031020))
#define TIMER1_ICR_R            (*((volatile uint32 *)0x40031024))
#define TIMER1_TAILR_R          (*((volatile uint32 *)0x40031028))
#define TIMER1_TBILR_R          (*((volatile uint32 *)0x4003102C))
#define TIMER1_TAMATCHR_R       (*((volatile uint32 *)0x40031030))
#define TIMER1_TBMATCHR_R       (*((volatile uint32 *)0x40031034))
#define TIMER1_TAPR_R           (*((volatile uint32 *)0x40031038))
#define TIMER1_TBPR_R           (*((volatile uint32 *)0x4003103C))
#define TIMER1_TAPMR_R          (*((volatile uint32 *)0x40031040))
#define TIMER1_TBPMR_R          (*((volatile uint32 *)0x40031044))
#define TIMER1_TAR_R            (*((volatile uint32 *)0x40031048))
#define TIMER1_TBR_R            (*((volatile uint32 *)0x4003104C))
#define TIMER1_TAV_R            (*((volatile uint32 *)0x40031050))
#define TIMER1_TBV_R            (*((volatile uint32 *)0x40031054))
#define TIMER1_RTCPD_R          (*((volatile uint32 *)0x40031058))
#define TIMER1_TAPS_R           (*((volatile uint32 *)0x4003105C))
#define TIMER1_TBPS_R           (*((volatile uint32 *)0x40031060))
#define TIMER1_TAPV_R           (*((volatile uint32 *)0x40031064))
#define TIMER1_TBPV_R           (*((volatile uint32 *)0x40031068))
#define TIMER1_PP_R             (*((volatile uint32 *)0x40031FC0))

//*****************************************************************************
//
// Timer registers (TIMER2)
//
//*****************************************************************************
#define TIMER2_CFG_R            (*((volatile uint32 *)0x40032000))
#define TIMER2_TAMR_R           (*((volatile uint32 *)0x40032004))
#define TIMER2_TBMR_R           (*((volatile uint32 *)0x40032008))
#define TIMER2_CTL_R            (*((volatile uint32 *)0x4003200C))
#define TIMER2_SYNC_R           (*((volatile uint32 *)0x40032010))
#define TIMER2_IMR_R            (*((volatile uint32 *)0x40032018))
#define TIMER2_RIS_R            (*((volatile uint32 *)0x4003201C))
#define TIMER2_MIS_R            (*((volatile uint32 *)0x40032020))
#define TIMER2_ICR_R            (*((volatile uint32 *)0x40032024))
#define TIMER2_TAILR_R          (*((volatile uint32 *)0x40032028))
#define TIMER2_TBILR_R          (*((volatile uint32 *)0x4003202C))
#define TIMER2_TAMATCHR_R       (*((volatile uint32 *)0x40032030))
#define TIMER2_TBMATCHR_R       (*((volatile uint32 *)0x40032034))
#define TIMER2_TAPR_R           (*((volatile uint32 *)0x40032038))
#define TIMER2_TBPR_R           (*((volatile uint32 *)0x4003203C))
#define TIMER2_TAPMR_R          (*((volatile uint32 *)0x40032040))
#define TIMER2_TBPMR_R          (*((volatile uint32 *)0x40032044))
#define TIMER2_TAR_R            (*((volatile uint32 *)0x40032048))
#define TIMER2_TBR_R            (*((volatile uint32 *)0x4003204C))
#define TIMER2_TAV_R            (*((volatile uint32 *)0x40032050))
#define TIMER2_TBV_R            (*((volatile uint32 *)0x40032054))
#define TIMER2_RTCPD_R          (*((volatile uint32 *)0x40032058))
#define TIMER2_TAPS_R           (*((volatile uint32 *)0x4003205C))
#define TIMER2_TBPS_R           (*((volatile uint32 *)0x40032060))
#define TIMER2_TAPV_R           (*((volatile uint32 *)0x40032064))
#define TIMER2_TBPV_R           (*((volatile uint32 *)0x40032068))
#define TIMER2_PP_R             (*((volatile uint32 *)0x40032FC0))

//*****************************************************************************
//
// Timer registers (TIMER3)
//
//*****************************************************************************
#define TIMER3_CFG_R            (*((volatile uint32 *)0x40033000))
#define TIMER3_TAMR_R           (*((volatile uint32 *)0x40033004))
#define TIMER3_TBMR_R           (*((volatile uint32 *)0x40033008))
#define TIMER3_CTL_R            (*((volatile uint32 *)0x4003300C))
#define TIMER3_SYNC_R           (*((volatile uint32 *)0x40033010))
#define TIMER3_IMR_R            (*((volatile uint32 *)0x40033018))
#define TIMER3_RIS_R            (*((volatile uint32 *)0x4003301C))
#define TIMER3_MIS_R            (*((volatile uint32 *)0x40033020))
#define TIMER3_ICR_R            (*((volatile uint32 *)0x40033024))
#define TIMER3_TAILR_R          (*((volatile uint32 *)0x40033028))
#define TIMER3_TBILR_R          (*((volatile uint32 *)0x4003302C))
#define TIMER3_TAMATCHR_R       (*((volatile uint32 *)0x40033030))
#define TIMER3_TBMATCHR_R       (*((volatile uint32 *)0x40033034))
#define TIMER3_TAPR_R           (*((volatile uint32 *)0x40033038))
#define TIMER3_TBPR_R           (*((volatile uint32 *)0x4003303C))
#define TIMER3_TAPMR_R          (*((volatile uint32 *)0x40033040))
#define TIMER3_TBPMR_R          (*((volatile uint32 *)0x40033044))
#define TIMER3_TAR_R            (*((volatile uint32 *)0x40033048))
#define TIMER3_TBR_R            (*((volatile uint32 *)0x4003304C))
#define TIMER3_TAV_R            (*((volatile uint32 *)0x40033050))
#define TIMER3_TBV_R            (*((volatile uint32 *)0x40033054))
#define TIMER3_RTCPD_R          (*((volatile uint32 *)0x40033058))
#define TIMER3_TAPS_R           (*((volatile uint32 *)0x4003305C))
#define TIMER3_TBPS_R           (*((volatile uint32 *)0x40033060))
#define TIMER3_TAPV_R           (*((volatile uint32 *)0x40033064))
#define TIMER3_TBPV_R           (*((volatile uint32 *)0x40033068))
#define TIMER3_PP_R             (*((volatile uint32 *)0x40033FC0))

//*****************************************************************************
//
// Timer registers (TIMER4)
//
//*****************************************************************************
#define TIMER4_CFG_R            (*((volatile uint32 *)0x40034000))
#define TIMER4_TAMR_R           (*((volatile uint32 *)0x40034004))
#define TIMER4_TBMR_R           (*((volatile uint32 *)0x40034008))
#define TIMER4_CTL_R            (*((volatile uint32 *)0x4003400C))
#define TIMER4_SYNC_R           (*((volatile uint32 *)0x40034010))
#define TIMER4_IMR_R            (*((volatile uint32 *)0x40034018))
#define TIMER4_RIS_R            (*((volatile uint32 *)0x4003401C))
#define TIMER4_MIS_R            (*((volatile uint32 *)0x40034020))
#define TIMER4_ICR_R            (*((volatile uint32 *)0x40034024))
#define TIMER4_TAILR_R          (*((volatile uint32 *)0x40034028))
#define TIMER4_TBILR_R          (*((volatile uint32 *)0x4003402C))
#define TIMER4_TAMATCHR_R       (*((volatile uint32 *)0x40034030))
#define TIMER4_TBMATCHR_R       (*((volatile uint32 *)0x40034034))
#define TIMER4_TAPR_R           (*((volatile uint32 *)0x40034038))
#define TIMER4_TBPR_R           (*((volatile uint32 *)0x4003403C))
#define TIMER4_TAPMR_R          (*((volatile uint32 *)0x40034040))
#define TIMER4_TBPMR_R          (*((volatile uint32 *)0x40034044))
#define TIMER4_TAR_R            (*((volatile uint32 *)0x40034048))
#define TIMER4_TBR_R            (*((volatile uint32 *)0x4003404C))
#define TIMER4_TAV_R            (*((volatile uint32 *)0x40034050))
#define TIMER4_TBV_R            (*((volatile uint32 *)0x40034054))
#define TIMER4_RTCPD_R          (*((volatile uint32 *)0x40034058))
#define TIMER4_TAPS_R           (*((volatile uint32 *)0x4003405C))
#define TIMER4_TBPS_R           (*((volatile uint32 *)0x40034060))
#define TIMER4_TAPV_R           (*((volatile uint32 *)0x40034064))
#define TIMER4_TBPV_R           (*((volatile uint32 *)0x40034068))
#define TIMER4_PP_R             (*((volatile uint32 *)0x40034FC0))

//*****************************************************************************
//
// Timer registers (TIMER5)
//
//*****************************************************************************
#define TIMER5_CFG_R            (*((volatile uint32 *)0x40035000))
#define TIMER5_TAMR_R           (*((volatile uint32 *)0x40035004))
#define TIMER5_TBMR_R           (*((volatile uint32 *)0x40035008))
#define TIMER5_CTL_R            (*((volatile uint32 *)0x4003500C))
#define TIMER5_SYNC_R           (*((volatile uint32 *)0x40035010))
#define TIMER5_IMR_R            (*((volatile uint32 *)0x40035018))
#define TIMER5_RIS_R            (*((volatile uint32 *)0x4003501C))
#define TIMER5_MIS_R            (*((volatile uint32 *)0x40035020))
#define TIMER5_ICR_R            (*((volatile uint32 *)0x40035024))
#define TIMER5_TAILR_R          (*((volatile uint32 *)0x40035028))
#define TIMER5_TBILR_R          (*((volatile uint32 *)0x4003502C))
#define TIMER5_TAMATCHR_R       (*((volatile uint32 *)0x40035030))
#define TIMER5_TBMATCHR_R       (*((volatile uint32 *)0x40035034))
#define TIMER5_TAPR_R           (*((volatile uint32 *)0x40035038))
#define TIMER5_TBPR_R           (*((volatile uint32 *)0x4003503C))
#define TIMER5_TAPMR_R          (*((volatile uint32 *)0x40035040))
#define TIMER5_TBPMR_R          (*((volatile uint32 *)0x40035044))
#define TIMER5_TAR_R            (*((volatile uint32 *)0x40035048))
#define TIMER5_TBR_R            (*((volatile uint32 *)0x4003504C))
#define TIMER5_TAV_R            (*((volatile uint32 *)0x40035050))
#define TIMER5_TBV_R            (*((volatile uint32 *)0x40035054))
#define TIMER5_RTCPD_R          (*((volatile uint32 *)0x40035058))
#define TIMER5_TAPS_R           (*((volatile uint32 *)0x4003505C))
#define TIMER5_TBPS_R           (*((volatile uint32 *)0x40035060))
#define TIMER5_TAPV_R           (*((volatile uint32 *)0x40035064))
#define TIMER5_TBPV_R           (*((volatile uint32 *)0x40035068))
#define TIMER5_PP_R             (*((volatile uint32 *)0x40035FC0))

//*****************************************************************************
//
// Timer registers (WTIMER0)
//
//*****************************************************************************
#define WTIMER0_CFG_R           (*((volatile uint32 *)0x40036000))
#define WTIMER0_TAMR_R          (*((volatile uint32 *)0x40036004))
#define WTIMER0_TBMR_R          (*((volatile uint32 *)0x40036008))
#define WTIMER0_CTL_R           (*((volatile uint32 *)0x4003600C))
#define WTIMER0_SYNC_R          (*((volatile uint32 *)0x40036010))
#define WTIMER0_IMR_R           (*((volatile uint32 *)0x40036018))
#define WTIMER0_RIS_R           (*((volatile uint32 *)0x4003601C))
#define WTIMER0_MIS_R           (*((volatile uint32 *)0x40036020))
#define WTIMER0_ICR_R           (*((volatile uint32 *)0x40036024))
#define WTIMER0_TAILR_R         (*((volatile uint32 *)0x40036028))
#define WTIMER0_TBILR_R         (*((volatile uint32 *)0x4003602C))
#define WTIMER0_TAMATCHR_R      (*((volatile uint32 *)0x40036030))
#define WTIMER0_TBMATCHR_R      (*((volatile uint32 *)0x40036034))
#define WTIMER0_TAPR_R          (*((volatile uint32 *)0x40036038))
#define WTIMER0_TBPR_R          (*((volatile uint32 *)0x4003603C))
#define WTIMER0_TAPMR_R         (*((volatile uint32 *)0x40036040))
#define WTIMER0_TBPMR_R         (*((volatile uint32 *)0x40036044))
#define WTIMER0_TAR_R           (*((volatile uint32 *)0x40036048))
#define WTIMER0_TBR_R           (*((volatile uint32 *)0x4003604C))
#define WTIMER0_TAV_R           (*((volatile uint32 *)0x40036050))
#define WTIMER0_TBV_R           (*((volatile uint32 *)0x40036054))
#define WTIMER0_RTCPD_R         (*((volatile uint32 *)0x40036058))
#define WTIMER0_TAPS_R          (*((volatile uint32 *)0x4003605C))
#define WTIMER0_TBPS_R          (*((volatile uint32 *)0x40036060))
#define WTIMER0_TAPV_R          (*((volatile uint32 *)0x40036064))
#define WTIMER0_TBPV_R          (*((volatile uint32 *)0x40036068))
#define WTIMER0_PP_R            (*((volatile uint32 *)0x40036FC0))

//*****************************************************************************
//
// Timer registers (WTIMER1)
//
//*****************************************************************************
#define WTIMER1_CFG_R           (*((volatile uint32 *)0x40037000))
#define WTIMER1_TAMR_R          (*((volatile uint32 *)0x40037004))
#define WTIMER1_TBMR_R          (*((volatile uint32 *)0x40037008))
#define WTIMER1_CTL_R           (*((volatile uint32 *)0x4003700C))
#define WTIMER1_SYNC_R          (*((volatile uint32 *)0x40037010))
#define WTIMER1_IMR_R           (*((volatile uint32 *)0x40037018))
#define WTIMER1_RIS_R           (*((volatile uint32 *)0x4003701C))
#define WTIMER1_MIS_R           (*((volatile uint32 *)0x40037020))
#define WTIMER1_ICR_R           (*((volatile uint32 *)0x40037024))
#define WTIMER1_TAILR_R         (*((volatile uint32 *)0x40037028))
#define WTIMER1_TBILR_R         (*((volatile uint32 *)0x4003702C))
#define WTIMER1_TAMATCHR_R      (*((volatile uint32 *)0x40037030))
#define WTIMER1_TBMATCHR_R      (*((volatile uint32 *)0x40037034))
#define WTIMER1_TAPR_R          (*((volatile uint32 *)0x40037038))
#define WTIMER1_TBPR_R          (*((volatile uint32 *)0x4003703C))
#define WTIMER1_TAPMR_R         (*((volatile uint32 *)0x40037040))
#define WTIMER1_TBPMR_R         (*((volatile uint32 *)0x40037044))
#define WTIMER1_TAR_R           (*((volatile uint32 *)0x40037048))
#define WTIMER1_TBR_R           (*((volatile uint32 *)0x4003704C))
#define WTIMER1_TAV_R           (*((volatile uint32 *)0x40037050))
#define WTIMER1_TBV_R           (*((volatile uint32 *)0x40037054))
#define WTIMER1_RTCPD_R         (*((volatile uint32 *)0x40037058))
#define WTIMER1_TAPS_R          (*((volatile uint32 *)0x4003705C))
#define WTIMER1_TBPS_R          (*((volatile uint32 *)0x40037060))
#define WTIMER1_TAPV_R          (*((volatile uint32 *)0x40037064))
#define WTIMER1_TBPV_R          (*((volatile uint32 *)0x40037068))
#define WTIMER1_PP_R            (*((volatile uint32 *)0x40037FC0))



#endif /* GPT_REGS_H_ */
