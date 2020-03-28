/******************************************************************************
 *
 * Module: SysTick Timer
 *
 * File Name: SysTick.c
 *
 * Description: Source file for the Tiva_C SysTick Timer driver
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/
#include "SysTick.h"
#include "SysTick_Regs.h"
#include "tm4c123gh6pm.h"

/******************************************************************************
 * Service Name: SysTick_Init
 * Service ID[hex]: 0x--
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the SysTick timer module.
 * *******************************************************************************/
void SysTick_Init(SysTick_ConfigType* Config_Ptr)
{
    NVIC_ST_CTRL_R |=  (Config_Ptr->Clock << 2)| (Config_Ptr->Mode << 1) | NVIC_ST_CTRL_ENABLE;

}

/******************************************************************************
 * Service Name: SysTick_PeriodSet
 * Service ID[hex]: 0x--
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the period of the SysTick counter.
*******************************************************************************/
void SysTick_PeriodSet(uint32 Period)
{
    /* Check the arguments. */
    if((Period > 0) && (Period <= 0xFFFFFF))
    {
        /* No action required */
    }
    else
    {
        NVIC_ST_RELOAD_R = Period - 1;     /* Set the period of the SysTick counter. */
    }
}

/******************************************************************************
 * Service Name: SysTick_PeriodGet
 * Service ID[hex]: 0x--
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: The period of the SysTick counter.
 * Description: Function to get the period of the SysTick counter.
*******************************************************************************/
uint32 SysTick_PeriodGet(void)
{
    uint32 SysTick_Period = NVIC_ST_RELOAD_R +1;

    return (SysTick_Period);                    /* Return the period of the SysTick counter. */
}

/******************************************************************************
 * Service Name: SysTick_ValueGet
 * Service ID[hex]: 0x--
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: the current value of the SysTick counter.
 * Description: Function to get the current value of the SysTick counter.
*******************************************************************************/
uint32 SysTick_ValueGet(void)
{
    uint32 SysTick_Value = NVIC_ST_CURRENT_R;

    return (SysTick_Value);                     /* Return the current value of the SysTick counter. */
}
