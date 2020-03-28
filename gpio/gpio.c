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
#include "gpio.h"
#include "gpio_Regs.h"
#include "arm.h"


STATIC Gpio_ConfigChannel * Gpio_PortChannels = NULL_PTR;
STATIC uint8 Gpio_Status = GPIO_NOT_INITIALIZED;

/************************************************************************************
 * Service Name: Gpio_Init
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Gpio module.
 ************************************************************************************/
void Gpio_Init(const Gpio_ConfigType* Config_Ptr)
{
    uint8 Pin_Index = STD_OFF;

    /*
     * Set the module state to initialized and point to the PB configuration structure using a global pointer.
     * This global pointer is global to be used by other functions to read the PB configuration structures
     */
    Gpio_Status       = GPIO_INITIALIZED;
    Gpio_PortChannels = Config_Ptr->Channels;        /* Address of the first Channels structure --> Channels[0] */

    for ( Pin_Index = 0; Pin_Index < GPIO_CONFIGURED_CHANNLES; Pin_Index++)
    {
        switch(Gpio_PortChannels[Pin_Index].Port)
        {
        /* Enable a clock gating control is provided a clock and accesses to module registers are allowed. */
        case GPIO_PORTA: SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | SYSCTL_RCGCGPIO_R0;                /* Enable clock gating control for PORTA */
        while(BIT_IS_CLEAR(HWREG(GPIO_PR_BASE+GPIO_O_RP), Gpio_PortChannels[Pin_Index].Port)){};    /* Check if the GPIO modules are ready to be accessed */
        HWREG(GPIO_PORTA_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;                                       /* Unlocked the locked register*/
        HWREG(GPIO_PORTA_BASE + GPIO_O_CR) = 0x000000FC;                                            /* Write the corresponding pins on commit register */
        HWREG(GPIO_PORTA_BASE + GPIO_O_DIR) = \
                (Gpio_PortChannels[Pin_Index].Direction<<Gpio_PortChannels[Pin_Index].Pin_Num);     /* Configures the direction to the corresponding pin */
        HWREG(GPIO_PORTA_BASE + GPIO_O_PUR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullUP<<Gpio_PortChannels[Pin_Index].Pin_Num);    /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTA_BASE + GPIO_O_PDR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullDown<<Gpio_PortChannels[Pin_Index].Pin_Num);  /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTA_BASE + GPIO_O_AFSEL) = STD_LOW;                                            /* Disable the Alternate Function Select and use it as GPIO */
        HWREG(GPIO_PORTA_BASE + GPIO_O_AMSEL) = STD_LOW;                                            /* Disable the Analog Function Select and use it as Digital */
        HWREG(GPIO_PORTA_BASE + GPIO_O_DEN) = \
                (STD_HIGH<<Gpio_PortChannels[Pin_Index].Pin_Num);                                  /* To use the pin as a digital input or output */
        break;

        case GPIO_PORTB: SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | SYSCTL_RCGCGPIO_R1;                /* Enable clock gating control for PORTB */
        while(BIT_IS_CLEAR(HWREG(GPIO_PR_BASE+GPIO_O_RP), Gpio_PortChannels[Pin_Index].Port)){};    /* Check if the GPIO modules are ready to be accessed */
        HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;                                       /* Unlocked the locked register*/
        HWREG(GPIO_PORTB_BASE + GPIO_O_CR) = 0x000000FF;                                            /* Write the corresponding pins on commit register */
        HWREG(GPIO_PORTB_BASE + GPIO_O_DIR) = \
                (Gpio_PortChannels[Pin_Index].Direction<<Gpio_PortChannels[Pin_Index].Pin_Num);     /* Configures the direction to the corresponding pin */
        HWREG(GPIO_PORTB_BASE + GPIO_O_PUR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullUP<<Gpio_PortChannels[Pin_Index].Pin_Num);    /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTB_BASE + GPIO_O_PDR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullDown<<Gpio_PortChannels[Pin_Index].Pin_Num);  /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTB_BASE + GPIO_O_AFSEL) = STD_LOW;                                            /* Disable the Alternate Function Select and use it as GPIO */
        HWREG(GPIO_PORTB_BASE + GPIO_O_AMSEL) = STD_LOW;                                            /* Disable the Analog Function Select and use it as Digital */
        HWREG(GPIO_PORTB_BASE + GPIO_O_DEN) = \
                (STD_HIGH<<Gpio_PortChannels[Pin_Index].Pin_Num);                                  /* To use the pin as a digital input or output */
        break;
        case GPIO_PORTC: SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | SYSCTL_RCGCGPIO_R2;                /* Enable clock gating control for PORTC */
        while(BIT_IS_CLEAR(HWREG(GPIO_PR_BASE+GPIO_O_RP), Gpio_PortChannels[Pin_Index].Port)){};    /* Check if the GPIO modules are ready to be accessed */
        HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;                                       /* Unlocked the locked register*/
        HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x000000F0;                                            /* Write the corresponding pins on commit register */
        HWREG(GPIO_PORTC_BASE + GPIO_O_DIR) = \
                (Gpio_PortChannels[Pin_Index].Direction<<Gpio_PortChannels[Pin_Index].Pin_Num);     /* Configures the direction to the corresponding pin */
        HWREG(GPIO_PORTC_BASE + GPIO_O_PUR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullUP<<Gpio_PortChannels[Pin_Index].Pin_Num);    /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTC_BASE + GPIO_O_PDR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullDown<<Gpio_PortChannels[Pin_Index].Pin_Num);  /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) = STD_LOW;                                            /* Disable the Alternate Function Select and use it as GPIO */
        HWREG(GPIO_PORTC_BASE + GPIO_O_AMSEL) = STD_LOW;                                            /* Disable the Analog Function Select and use it as Digital */
        HWREG(GPIO_PORTC_BASE + GPIO_O_DEN) = \
                (STD_HIGH<<Gpio_PortChannels[Pin_Index].Pin_Num);                                  /* To use the pin as a digital input or output */
        break;

        case GPIO_PORTD: SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | SYSCTL_RCGCGPIO_R3;                /* Enable clock gating control for PORTD */
        while(BIT_IS_CLEAR(HWREG(GPIO_PR_BASE+GPIO_O_RP), Gpio_PortChannels[Pin_Index].Port)){};    /* Check if the GPIO modules are ready to be accessed */
        HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;                                       /* Unlocked the locked register*/
        HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0x000000CF;                                            /* Write the corresponding pins on commit register */
        HWREG(GPIO_PORTD_BASE + GPIO_O_DIR) = \
                (Gpio_PortChannels[Pin_Index].Direction<<Gpio_PortChannels[Pin_Index].Pin_Num);     /* Configures the direction to the corresponding pin */
        HWREG(GPIO_PORTD_BASE + GPIO_O_PUR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullUP<<Gpio_PortChannels[Pin_Index].Pin_Num);    /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTD_BASE + GPIO_O_PDR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullDown<<Gpio_PortChannels[Pin_Index].Pin_Num);  /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTD_BASE + GPIO_O_AFSEL) = STD_LOW;                                            /* Disable the Alternate Function Select and use it as GPIO */
        HWREG(GPIO_PORTD_BASE + GPIO_O_DEN) = \
                (STD_HIGH<<Gpio_PortChannels[Pin_Index].Pin_Num);                                  /* To use the pin as a digital input or output */
        break;

        case GPIO_PORTE: SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | SYSCTL_RCGCGPIO_R4;                /* Enable clock gating control for PORTE */
        while(BIT_IS_CLEAR(HWREG(GPIO_PR_BASE+GPIO_O_RP), Gpio_PortChannels[Pin_Index].Port)){};    /* Check if the GPIO modules are ready to be accessed */
        HWREG(GPIO_PORTE_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;                                       /* Unlocked the locked register*/
        HWREG(GPIO_PORTE_BASE + GPIO_O_CR) = 0x0000003F;                                            /* Write the corresponding pins on commit register */
        HWREG(GPIO_PORTE_BASE + GPIO_O_DIR) = \
                (Gpio_PortChannels[Pin_Index].Direction<<Gpio_PortChannels[Pin_Index].Pin_Num);     /* Configures the direction to the corresponding pin */
        HWREG(GPIO_PORTE_BASE + GPIO_O_PUR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullUP<<Gpio_PortChannels[Pin_Index].Pin_Num);    /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTE_BASE + GPIO_O_PDR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullDown<<Gpio_PortChannels[Pin_Index].Pin_Num);  /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTE_BASE + GPIO_O_AFSEL) = STD_LOW;                                            /* Disable the Alternate Function Select and use it as GPIO */
        HWREG(GPIO_PORTE_BASE + GPIO_O_AMSEL) = STD_LOW;                                            /* Disable the Analog Function Select and use it as Digital */
        HWREG(GPIO_PORTE_BASE + GPIO_O_DEN) = \
                (STD_HIGH<<Gpio_PortChannels[Pin_Index].Pin_Num);                                   /* To use the pin as a digital input or output */
        break;

        case GPIO_PORTF: SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R | SYSCTL_RCGCGPIO_R5;                /* Enable clock gating control for PORTF */
        while(BIT_IS_CLEAR(HWREG(GPIO_PR_BASE+GPIO_O_RP), Gpio_PortChannels[Pin_Index].Port)){};    /* Check if the GPIO modules are ready to be accessed */
        HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;                                       /* Unlocked the locked register*/
        HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x0000001F;                                            /* Write the corresponding pins on commit register */
        HWREG(GPIO_PORTF_BASE + GPIO_O_DIR) = \
                (Gpio_PortChannels[Pin_Index].Direction<<Gpio_PortChannels[Pin_Index].Pin_Num);     /* Configures the direction to the corresponding pin */
        HWREG(GPIO_PORTF_BASE + GPIO_O_PUR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullUP<<Gpio_PortChannels[Pin_Index].Pin_Num);    /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTF_BASE + GPIO_O_PDR) = \
                (Gpio_PortChannels[Pin_Index].Pin_PullDown<<Gpio_PortChannels[Pin_Index].Pin_Num);  /* Configures the Pull Up resister for the corresponding pin */
        HWREG(GPIO_PORTF_BASE + GPIO_O_AFSEL) = STD_LOW;                                            /* Disable the Alternate Function Select and use it as GPIO */
        HWREG(GPIO_PORTF_BASE + GPIO_O_AMSEL) = STD_LOW;                                            /* Disable the Analog Function Select and use it as Digital */
        HWREG(GPIO_PORTF_BASE + GPIO_O_DEN) = \
                (STD_HIGH<<Gpio_PortChannels[Pin_Index].Pin_Num);                                  /* To use the pin as a digital input or output */
        break;

        }
    }
}
/************************************************************************************
 * Service Name: Gpio_WriteChannel
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - ID of DIO channel.
 *                  Level - Value to be written.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set a level of a channel.
 ************************************************************************************/
uint8 Gpio_ReadChannel(uint8 ChannelId)
{
    Gpio_Port * Port_Ptr = NULL_PTR;
    uint8 output = STD_LOW;
    boolean error = FALSE;

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (GPIO_NOT_INITIALIZED == Gpio_Status)
    {
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* Check if the used channel is within the valid range */
    if (GPIO_CONFIGURED_CHANNLES <= ChannelId)
    {

        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
#endif

    /* In-case there are no errors */
    if(FALSE == error)
    {
        /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
        switch(Gpio_PortChannels[ChannelId].Port)
        {
        case GPIO_PORTA: Port_Ptr = &HWREG(GPIO_PORTA_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTB: Port_Ptr = &HWREG(GPIO_PORTB_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTC: Port_Ptr = &HWREG(GPIO_PORTC_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTD: Port_Ptr = &HWREG(GPIO_PORTD_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTE: Port_Ptr = &HWREG(GPIO_PORTE_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTF: Port_Ptr = &HWREG(GPIO_PORTF_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        }

        /* Read the required channel */
        if(BIT_IS_SET(*Port_Ptr, (Gpio_PortChannels[ChannelId].Pin_Num) )
        )
        {
            output = STD_HIGH;
        }
        else
        {
            output = STD_LOW;
        }
        return output;
    }
    else
    {
        /* No Action Required */
    }
}

void Gpio_WriteChannel(uint8 ChannelId, uint8 Level)
{
    Gpio_Port * Port_Ptr = NULL_PTR;
    boolean error = FALSE;

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (GPIO_NOT_INITIALIZED == Gpio_Status)
    {
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* Check if the used channel is within the valid range */
    if (GPIO_CONFIGURED_CHANNLES <= ChannelId)
    {

        Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
#endif

    /* In-case there are no errors */
    if(FALSE == error)
    {
        /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
        switch(Gpio_PortChannels[ChannelId].Port)
        {
        case GPIO_PORTA: Port_Ptr = &HWREG(GPIO_PORTA_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTB: Port_Ptr = &HWREG(GPIO_PORTB_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTC: Port_Ptr = &HWREG(GPIO_PORTC_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTD: Port_Ptr = &HWREG(GPIO_PORTD_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTE: Port_Ptr = &HWREG(GPIO_PORTE_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        case GPIO_PORTF: Port_Ptr = &HWREG(GPIO_PORTF_BASE + (STD_HIGH<<(Gpio_PortChannels[ChannelId].Pin_Num +2)) );
        break;
        }

        if(Level == STD_HIGH)
        {
            /* Write Logic High */
            SET_BIT(*Port_Ptr, (Gpio_PortChannels[ChannelId].Pin_Num) );
        }
        else if(Level == STD_LOW)
        {
            /* Write Logic Low */
            CLEAR_BIT(*Port_Ptr, (Gpio_PortChannels[ChannelId].Pin_Num) );
        }
    }
    else
    {
        /* No Action Required */
    }

}
/************************************************************************************
* Service Name: Gpio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
uint8 Gpio_FlipChanne(uint8 ChannelId)
{

}
/************************************************************************************
 * Service Name: Gpio_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin ->Port Pin ID number
                    Mode ->New Port Pin mode to be set on port pin.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Port_LevelType
 * Description: Function shall set the port pin mode of the referenced pin during runtime.
 ************************************************************************************/
void Gpio_SetPinMode(Gpio_PinType Pin, Gpio_PinModeType Mode)
{
    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (Port_Status == PORT_NOT_INITIALIZED)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_UNINIT);
    }
    else
    {
        /* No Action Required */
    }
    /* Check if the used channel is within the valid range */
    if(PORT_CONFIGURED_CHANNLES <= Pin)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
#endif
    /*HWREG(ui32Port + GPIO_O_AFSEL) = ((ui32PinIO & 2) ?
                                          (HWREG(ui32Port + GPIO_O_AFSEL) |
                                           ui8Pins) :
                                          (HWREG(ui32Port + GPIO_O_AFSEL) &
                                           ~(ui8Pins)));*/
}


