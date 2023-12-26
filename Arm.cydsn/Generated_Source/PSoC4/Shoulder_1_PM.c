/*******************************************************************************
* File Name: Shoulder_1.c  
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
#include "Shoulder_1.h"

static Shoulder_1_BACKUP_STRUCT  Shoulder_1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Shoulder_1_Sleep
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
*  \snippet Shoulder_1_SUT.c usage_Shoulder_1_Sleep_Wakeup
*******************************************************************************/
void Shoulder_1_Sleep(void)
{
    #if defined(Shoulder_1__PC)
        Shoulder_1_backup.pcState = Shoulder_1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Shoulder_1_backup.usbState = Shoulder_1_CR1_REG;
            Shoulder_1_USB_POWER_REG |= Shoulder_1_USBIO_ENTER_SLEEP;
            Shoulder_1_CR1_REG &= Shoulder_1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Shoulder_1__SIO)
        Shoulder_1_backup.sioState = Shoulder_1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Shoulder_1_SIO_REG &= (uint32)(~Shoulder_1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Shoulder_1_Wakeup
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
*  Refer to Shoulder_1_Sleep() for an example usage.
*******************************************************************************/
void Shoulder_1_Wakeup(void)
{
    #if defined(Shoulder_1__PC)
        Shoulder_1_PC = Shoulder_1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Shoulder_1_USB_POWER_REG &= Shoulder_1_USBIO_EXIT_SLEEP_PH1;
            Shoulder_1_CR1_REG = Shoulder_1_backup.usbState;
            Shoulder_1_USB_POWER_REG &= Shoulder_1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Shoulder_1__SIO)
        Shoulder_1_SIO_REG = Shoulder_1_backup.sioState;
    #endif
}


/* [] END OF FILE */
