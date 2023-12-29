/*******************************************************************************
* File Name: Light_Switch.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Light_Switch_H) /* Pins Light_Switch_H */
#define CY_PINS_Light_Switch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Light_Switch_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Light_Switch_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Light_Switch_Read(void);
void    Light_Switch_Write(uint8 value);
uint8   Light_Switch_ReadDataReg(void);
#if defined(Light_Switch__PC) || (CY_PSOC4_4200L) 
    void    Light_Switch_SetDriveMode(uint8 mode);
#endif
void    Light_Switch_SetInterruptMode(uint16 position, uint16 mode);
uint8   Light_Switch_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Light_Switch_Sleep(void); 
void Light_Switch_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Light_Switch__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Light_Switch_DRIVE_MODE_BITS        (3)
    #define Light_Switch_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Light_Switch_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Light_Switch_SetDriveMode() function.
         *  @{
         */
        #define Light_Switch_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Light_Switch_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Light_Switch_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Light_Switch_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Light_Switch_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Light_Switch_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Light_Switch_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Light_Switch_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Light_Switch_MASK               Light_Switch__MASK
#define Light_Switch_SHIFT              Light_Switch__SHIFT
#define Light_Switch_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Light_Switch_SetInterruptMode() function.
     *  @{
     */
        #define Light_Switch_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Light_Switch_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Light_Switch_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Light_Switch_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Light_Switch__SIO)
    #define Light_Switch_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Light_Switch__PC) && (CY_PSOC4_4200L)
    #define Light_Switch_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Light_Switch_USBIO_DISABLE              ((uint32)(~Light_Switch_USBIO_ENABLE))
    #define Light_Switch_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Light_Switch_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Light_Switch_USBIO_ENTER_SLEEP          ((uint32)((1u << Light_Switch_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Light_Switch_USBIO_SUSPEND_DEL_SHIFT)))
    #define Light_Switch_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Light_Switch_USBIO_SUSPEND_SHIFT)))
    #define Light_Switch_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Light_Switch_USBIO_SUSPEND_DEL_SHIFT)))
    #define Light_Switch_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Light_Switch__PC)
    /* Port Configuration */
    #define Light_Switch_PC                 (* (reg32 *) Light_Switch__PC)
#endif
/* Pin State */
#define Light_Switch_PS                     (* (reg32 *) Light_Switch__PS)
/* Data Register */
#define Light_Switch_DR                     (* (reg32 *) Light_Switch__DR)
/* Input Buffer Disable Override */
#define Light_Switch_INP_DIS                (* (reg32 *) Light_Switch__PC2)

/* Interrupt configuration Registers */
#define Light_Switch_INTCFG                 (* (reg32 *) Light_Switch__INTCFG)
#define Light_Switch_INTSTAT                (* (reg32 *) Light_Switch__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Light_Switch_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Light_Switch__SIO)
    #define Light_Switch_SIO_REG            (* (reg32 *) Light_Switch__SIO)
#endif /* (Light_Switch__SIO_CFG) */

/* USBIO registers */
#if !defined(Light_Switch__PC) && (CY_PSOC4_4200L)
    #define Light_Switch_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Light_Switch_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Light_Switch_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Light_Switch_DRIVE_MODE_SHIFT       (0x00u)
#define Light_Switch_DRIVE_MODE_MASK        (0x07u << Light_Switch_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Light_Switch_H */


/* [] END OF FILE */
