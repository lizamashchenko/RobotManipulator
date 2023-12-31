/*******************************************************************************
* File Name: Gripper_In.c  
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
#include "Gripper_In.h"

static Gripper_In_BACKUP_STRUCT  Gripper_In_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Gripper_In_Sleep
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
*  \snippet Gripper_In_SUT.c usage_Gripper_In_Sleep_Wakeup
*******************************************************************************/
void Gripper_In_Sleep(void)
{
    #if defined(Gripper_In__PC)
        Gripper_In_backup.pcState = Gripper_In_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Gripper_In_backup.usbState = Gripper_In_CR1_REG;
            Gripper_In_USB_POWER_REG |= Gripper_In_USBIO_ENTER_SLEEP;
            Gripper_In_CR1_REG &= Gripper_In_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Gripper_In__SIO)
        Gripper_In_backup.sioState = Gripper_In_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Gripper_In_SIO_REG &= (uint32)(~Gripper_In_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Gripper_In_Wakeup
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
*  Refer to Gripper_In_Sleep() for an example usage.
*******************************************************************************/
void Gripper_In_Wakeup(void)
{
    #if defined(Gripper_In__PC)
        Gripper_In_PC = Gripper_In_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Gripper_In_USB_POWER_REG &= Gripper_In_USBIO_EXIT_SLEEP_PH1;
            Gripper_In_CR1_REG = Gripper_In_backup.usbState;
            Gripper_In_USB_POWER_REG &= Gripper_In_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Gripper_In__SIO)
        Gripper_In_SIO_REG = Gripper_In_backup.sioState;
    #endif
}


/* [] END OF FILE */
