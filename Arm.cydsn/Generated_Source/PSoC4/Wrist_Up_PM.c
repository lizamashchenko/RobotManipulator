/*******************************************************************************
* File Name: Wrist_Up.c  
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
#include "Wrist_Up.h"

static Wrist_Up_BACKUP_STRUCT  Wrist_Up_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Wrist_Up_Sleep
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
*  \snippet Wrist_Up_SUT.c usage_Wrist_Up_Sleep_Wakeup
*******************************************************************************/
void Wrist_Up_Sleep(void)
{
    #if defined(Wrist_Up__PC)
        Wrist_Up_backup.pcState = Wrist_Up_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Wrist_Up_backup.usbState = Wrist_Up_CR1_REG;
            Wrist_Up_USB_POWER_REG |= Wrist_Up_USBIO_ENTER_SLEEP;
            Wrist_Up_CR1_REG &= Wrist_Up_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Wrist_Up__SIO)
        Wrist_Up_backup.sioState = Wrist_Up_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Wrist_Up_SIO_REG &= (uint32)(~Wrist_Up_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Wrist_Up_Wakeup
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
*  Refer to Wrist_Up_Sleep() for an example usage.
*******************************************************************************/
void Wrist_Up_Wakeup(void)
{
    #if defined(Wrist_Up__PC)
        Wrist_Up_PC = Wrist_Up_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Wrist_Up_USB_POWER_REG &= Wrist_Up_USBIO_EXIT_SLEEP_PH1;
            Wrist_Up_CR1_REG = Wrist_Up_backup.usbState;
            Wrist_Up_USB_POWER_REG &= Wrist_Up_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Wrist_Up__SIO)
        Wrist_Up_SIO_REG = Wrist_Up_backup.sioState;
    #endif
}


/* [] END OF FILE */
