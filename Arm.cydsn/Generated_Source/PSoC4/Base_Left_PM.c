/*******************************************************************************
* File Name: Base_Left.c  
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
#include "Base_Left.h"

static Base_Left_BACKUP_STRUCT  Base_Left_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Base_Left_Sleep
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
*  \snippet Base_Left_SUT.c usage_Base_Left_Sleep_Wakeup
*******************************************************************************/
void Base_Left_Sleep(void)
{
    #if defined(Base_Left__PC)
        Base_Left_backup.pcState = Base_Left_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Base_Left_backup.usbState = Base_Left_CR1_REG;
            Base_Left_USB_POWER_REG |= Base_Left_USBIO_ENTER_SLEEP;
            Base_Left_CR1_REG &= Base_Left_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Base_Left__SIO)
        Base_Left_backup.sioState = Base_Left_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Base_Left_SIO_REG &= (uint32)(~Base_Left_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Base_Left_Wakeup
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
*  Refer to Base_Left_Sleep() for an example usage.
*******************************************************************************/
void Base_Left_Wakeup(void)
{
    #if defined(Base_Left__PC)
        Base_Left_PC = Base_Left_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Base_Left_USB_POWER_REG &= Base_Left_USBIO_EXIT_SLEEP_PH1;
            Base_Left_CR1_REG = Base_Left_backup.usbState;
            Base_Left_USB_POWER_REG &= Base_Left_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Base_Left__SIO)
        Base_Left_SIO_REG = Base_Left_backup.sioState;
    #endif
}


/* [] END OF FILE */
