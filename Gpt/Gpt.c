/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the Tiva_C GPIO driver
 *
 * Author: Ahmed Sleem
 *
 *******************************************************************************/
#include "Gpt.h"
#include "Gpt_Regs.h"
//#include "arm.h"


STATIC Gpt_ConfigChannel * Gpt_TimerChannels = NULL_PTR;
STATIC uint8 Gpt_Status = GPT_NOT_INITIALIZED;
STATIC uint32 TimersBase[6] = {TIMER0_BASE, TIMER1_BASE, TIMER2_BASE, TIMER3_BASE, TIMER4_BASE, TIMER5_BASE};


/************************************************************************************
 * Service Name: Gpio_Init
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Gpt module.
 ************************************************************************************/
void Gpt_Init(const Gpt_ConfigType* Config_Ptr)
{
    /*
     * Set the module state to initialized and point to the PB configuration structure using a global pointer.
     * This global pointer is global to be used by other functions to read the PB configuration structures
     */
    Gpt_Status       = GPT_INITIALIZED;
    Gpt_TimerChannels = Config_Ptr->Channels;        /* Address of the first Channels structure --> Channels[0] */

    uint8 Channel_Index = 0;
    for ( Channel_Index = 0; Channel_Index < GPT_CONFIGURED_CHANNLES; Channel_Index++)
    {
        switch(Gpt_TimerChannels[Channel_Index].Mode)
        {
        case GPT_ONE_SHOT_MODE:
            /* Enable and provide a clock to 16/32-bit general-purpose timer module in Run mode. */
            SYSCTL_RCGCTIMER_R = SYSCTL_RCGCTIMER_R | (STD_HIGH<<Gpt_TimerChannels[Channel_Index].Block);
            /* Ensure the timer is disabled before making any changes. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);
            /* The value written to this register determines whether the GPTM is in 16- or 32-bit mode */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CFG )  = Gpt_TimerChannels[Channel_Index].Range;
            if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERB)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x1 for One-Shot mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (TIMER_TBMR_TBMR_1_SHOT | TIMER_TBMR_TBMR_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TBMR_TBMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TBMR_TBCDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TBEN);

            }
            else            //if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERA)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x1 for One-Shot mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (TIMER_TAMR_TAMR_1_SHOT | TIMER_TAMR_TAMR_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TAMR_TAMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TAMR_TACDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TAEN);

            }
            /* Enable the timer and start counting. */
            //HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TAEN) | (STD_HIGH<<TIMER_CTL_TBEN);

        case GPT_PERIODIC_MODE:
            /* Enable and provide a clock to 16/32-bit general-purpose timer module in Run mode. */
            SYSCTL_RCGCTIMER_R = SYSCTL_RCGCTIMER_R | (STD_HIGH<<Gpt_TimerChannels[Channel_Index].Block);
            /* Ensure the timer is disabled before making any changes. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);
            /* The value written to this register determines whether the GPTM is in 16- or 32-bit mode */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CFG )  = Gpt_TimerChannels[Channel_Index].Range;
            if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERB)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x2 for Periodic mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (TIMER_TBMR_TBMR_PERIOD | TIMER_TBMR_TBMR_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TBMR_TBMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TBMR_TBCDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TBEN);
            }
            else            //if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERA)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x2 for Periodic mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (TIMER_TAMR_TAMR_PERIOD | TIMER_TAMR_TAMR_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TAMR_TAMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TAMR_TACDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TAEN);
            }

        case GPT_RTC_MODE:
            /* Enable and provide a clock to 16/32-bit general-purpose timer module in Run mode. */
            SYSCTL_RCGCTIMER_R = SYSCTL_RCGCTIMER_R | (STD_HIGH<<Gpt_TimerChannels[Channel_Index].Block);
            /* Ensure the timer is disabled before making any changes. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);
            /* Clear any residual set bits in the GPTM Timer n Mode (GPTMTnMR) register before reconfiguring. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) = STD_LOW;
            /* The value written to this register determines whether the GPTM is in 16- or 32-bit mode */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CFG )  = Gpt_TimerChannels[Channel_Index].Range;

            /* RTC counting continues while the processor is halted by the debugger. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= TIMER_CTL_RTCEN;
            /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_IMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_IMR_RTCIM);

            /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBILR ) = (Gpt_TimerChannels[Channel_Index].Value);
            /* Enable the timer and start counting. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TAEN);

        case GPT_INPUT_EDAGE_TIME:
            /* Enable and provide a clock to 16/32-bit general-purpose timer module in Run mode. */
            SYSCTL_RCGCTIMER_R = SYSCTL_RCGCTIMER_R | (STD_HIGH<<Gpt_TimerChannels[Channel_Index].Block);
            /* Ensure the timer is disabled before making any changes. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);
            /* The value written to this register determines whether the GPTM is in 16- or 32-bit mode */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CFG )  = Gpt_TimerChannels[Channel_Index].Range;

            if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERB)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x3 for Capture mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (TIMER_TBMR_TBMR_CAP | TIMER_TBMR_TBMR_M);
                /* In the GPTM Timer Mode (GPTMTnMR) register, write the TnCMR field to 0x1 in order to choose Edge-Time mode*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) = (STD_HIGH<<TIMER_TBMR_TBCMR);
                /* Configure the type of event that the timer captures by writing the TnEVENT field of the GPTM Control (GPTMCTL) register. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (Gpt_TimerChannels[Channel_Index].Event<<TIMER_CTL_TBEVENT_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TBMR_TBMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TBMR_TBCDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TBEN);

            }
            else            //if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERA)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x1 for One-Shot mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (TIMER_TAMR_TAMR_CAP | TIMER_TAMR_TAMR_M);
                /* In the GPTM Timer Mode (GPTMTnMR) register, write the TnCMR field to 0x1 in order to choose Edge-Time mode*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) = (STD_HIGH<<TIMER_TAMR_TACMR);
                /* Configure the type of event that the timer captures by writing the TnEVENT field of the GPTM Control (GPTMCTL) register. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (Gpt_TimerChannels[Channel_Index].Event<<TIMER_CTL_TAEVENT_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TAMR_TAMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TAMR_TACDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TAEN);

            }

        case GPT_INPUT_EDAGE_COUNT:
            /* Enable and provide a clock to 16/32-bit general-purpose timer module in Run mode. */
            SYSCTL_RCGCTIMER_R = SYSCTL_RCGCTIMER_R | (STD_HIGH<<Gpt_TimerChannels[Channel_Index].Block);
            /* Ensure the timer is disabled before making any changes. */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);
            /* The value written to this register determines whether the GPTM is in 16- or 32-bit mode */
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CFG )  = Gpt_TimerChannels[Channel_Index].Range;

            if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERB)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x3 for Capture mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (TIMER_TBMR_TBMR_CAP | TIMER_TBMR_TBMR_M);
                /* In the GPTM Timer Mode (GPTMTnMR) register, write the TnCMR field to 0x0 in order to choose Edge-Count mode*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) = (STD_LOW<<TIMER_TBMR_TBCMR);
                /* Configure the type of event that the timer captures by writing the TnEVENT field of the GPTM Control (GPTMCTL) register. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (Gpt_TimerChannels[Channel_Index].Event<<TIMER_CTL_TBEVENT_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TBMR_TBMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TBMR_TBCDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TBILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TBEN);

            }
            else            //if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERA)
            {
                /* Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
                 * Write a value of 0x1 for One-Shot mode. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (TIMER_TAMR_TAMR_CAP | TIMER_TAMR_TAMR_M);
                /* In the GPTM Timer Mode (GPTMTnMR) register, write the TnCMR field to 0x0 in order to choose Edge-Count mode*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) = (STD_LOW<<TIMER_TAMR_TACMR);
                /* Configure the type of event that the timer captures by writing the TnEVENT field of the GPTM Control (GPTMCTL) register. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (Gpt_TimerChannels[Channel_Index].Event<<TIMER_CTL_TAEVENT_M);
                /* Configure the TnMTE bit in the GPTMTnMR register to select whether to configure an additional trigger or interrupt. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Status<<TIMER_TAMR_TAMIE);
                /* Configure the TnCDIR bit in the GPTMTnMR register to select whether to count up or down.*/
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAMR ) |= (Gpt_TimerChannels[Channel_Index].Direction<<TIMER_TAMR_TACDIR);
                /* Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_TAILR ) = (Gpt_TimerChannels[Channel_Index].Value);
                /* Enable the timer and start counting. */
                HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_HIGH<<TIMER_CTL_TAEN);

            }
        case GPT_PWM_MODE:
            SYSCTL_RCGCTIMER_R = SYSCTL_RCGCTIMER_R | (STD_HIGH<<Gpt_TimerChannels[Channel_Index].Block);
            HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= STD_LOW<<TIMER_CTL_TAEN | STD_LOW<<TIMER_CTL_TBEN;

        }
    }

}

void Gpt_SetTimerMatch(Gpt_ChannelType ChannelId, uint32 MatchValue)
{
    /* Ensure the timer is disabled before making any changes. */
    HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);

    switch(Gpt_TimerChannels[ChannelId].Direction)
    {
    case GPT_COUNTUP:
        if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERB)
        {
            /* Load the match value into the GPTM Timer n Match Register (GPTMTnMATCHR). */
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_TAMATCHR ) = MatchValue;
        }
        else
        {
            /* Load the match value into the GPTM Timer n Match Register (GPTMTnMATCHR). */
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_TBMATCHR ) = MatchValue;

        }
    case GPT_COUNTDOWN:
        if(Gpt_TimerChannels[Channel_Index].Channel == GPT_TIMERB)
        {
            /* Load the match value into the GPTM Timer n Match Register (GPTMTnMATCHR). */
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_TAMATCHR ) = MatchValue;
        }
        else
        {
            /* Load the match value into the GPTM Timer n Match Register (GPTMTnMATCHR). */
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_TBMATCHR ) = MatchValue;
        }
    }
}

void Gpt_SetTimerPrescale(Gpt_ChannelType ChannelId, uint32 PrescaleValue)
{
    /* Ensure the timer is disabled before making any changes. */
    HWREG(TimersBase[Gpt_TimerChannels[Channel_Index].Block] + TIMER_O_CTL ) |= (STD_LOW<<TIMER_CTL_TAEN) | (STD_LOW<<TIMER_CTL_TBEN);

    switch(Gpt_TimerChannels[ChannelId].Channel)
    {
    case GPT_TIMERA:
        HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_TAPR ) = PrescaleValue;
    case GPT_TIMERB:
        HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_TBPR ) = PrescaleValue;
    }
}
void Gpt_ClearInt(Gpt_ChannelType ChannelId)
{

    switch(Gpt_TimerChannels[ChannelId].Mode)
    {
    case GPT_ONE_SHOT_MODE:
        if(Gpt_TimerChannels[ChannelId].Channel == GPT_TIMERB)
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_TBMCINT;
        }
        else
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_TAMCINT;
        }

    case GPT_PERIODIC_MODE:
        if(Gpt_TimerChannels[ChannelId].Channel == GPT_TIMERB)
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_TBMCINT;
        }
        else
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_TAMCINT;
        }

    case GPT_INPUT_EDAGE_TIME:
        if(Gpt_TimerChannels[ChannelId].Channel == GPT_TIMERB)
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_CBECINT;
        }
        else
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_CAECINT;
        }

    case GPT_INPUT_EDAGE_COUNT:
        if(Gpt_TimerChannels[ChannelId].Channel == GPT_TIMERB)
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_CBMCINT;
        }
        else
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_CAMCINT;
        }

    case GPT_PWM_MODE:
        if(Gpt_TimerChannels[ChannelId].Channel == GPT_TIMERB)
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_CBECINT;
        }
        else
        {
            HWREG(TimersBase[Gpt_TimerChannels[ChannelId].Block] + TIMER_O_ICR ) = TIMER_ICR_CAECINT;
        }

    }
}
