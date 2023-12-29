/*******************************************************************************
* File Name: Base_Right.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Base_Right.h"

static Base_Right_BACKUP_STRUCT  Base_Right_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Base_Right_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Base_Right_SUT.c usage_Base_Right_Sleep_Wakeup
*******************************************************************************/
void Base_Right_Sleep(void)
{
    #if defined(Base_Right__PC)
        Base_Right_backup.pcState = Base_Right_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Base_Right_backup.usbState = Base_Right_CR1_REG;
            Base_Right_USB_POWER_REG |= Base_Right_USBIO_ENTER_SLEEP;
            Base_Right_CR1_REG &= Base_Right_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Base_Right__SIO)
        Base_Right_backup.sioState = Base_Right_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Base_Right_SIO_REG &= (uint32)(~Base_Right_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Base_Right_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Base_Right_Sleep() for an example usage.
*******************************************************************************/
void Base_Right_Wakeup(void)
{
    #if defined(Base_Right__PC)
        Base_Right_PC = Base_Right_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Base_Right_USB_POWER_REG &= Base_Right_USBIO_EXIT_SLEEP_PH1;
            Base_Right_CR1_REG = Base_Right_backup.usbState;
            Base_Right_USB_POWER_REG &= Base_Right_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Base_Right__SIO)
        Base_Right_SIO_REG = Base_Right_backup.sioState;
    #endif
}


/* [] END OF FILE */
