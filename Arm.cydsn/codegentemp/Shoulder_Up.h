/*******************************************************************************
* File Name: Shoulder_Up.h  
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

#if !defined(CY_PINS_Shoulder_Up_H) /* Pins Shoulder_Up_H */
#define CY_PINS_Shoulder_Up_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Shoulder_Up_aliases.h"


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
} Shoulder_Up_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Shoulder_Up_Read(void);
void    Shoulder_Up_Write(uint8 value);
uint8   Shoulder_Up_ReadDataReg(void);
#if defined(Shoulder_Up__PC) || (CY_PSOC4_4200L) 
    void    Shoulder_Up_SetDriveMode(uint8 mode);
#endif
void    Shoulder_Up_SetInterruptMode(uint16 position, uint16 mode);
uint8   Shoulder_Up_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Shoulder_Up_Sleep(void); 
void Shoulder_Up_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Shoulder_Up__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Shoulder_Up_DRIVE_MODE_BITS        (3)
    #define Shoulder_Up_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Shoulder_Up_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Shoulder_Up_SetDriveMode() function.
         *  @{
         */
        #define Shoulder_Up_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Shoulder_Up_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Shoulder_Up_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Shoulder_Up_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Shoulder_Up_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Shoulder_Up_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Shoulder_Up_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Shoulder_Up_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Shoulder_Up_MASK               Shoulder_Up__MASK
#define Shoulder_Up_SHIFT              Shoulder_Up__SHIFT
#define Shoulder_Up_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Shoulder_Up_SetInterruptMode() function.
     *  @{
     */
        #define Shoulder_Up_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Shoulder_Up_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Shoulder_Up_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Shoulder_Up_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Shoulder_Up__SIO)
    #define Shoulder_Up_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Shoulder_Up__PC) && (CY_PSOC4_4200L)
    #define Shoulder_Up_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Shoulder_Up_USBIO_DISABLE              ((uint32)(~Shoulder_Up_USBIO_ENABLE))
    #define Shoulder_Up_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Shoulder_Up_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Shoulder_Up_USBIO_ENTER_SLEEP          ((uint32)((1u << Shoulder_Up_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Shoulder_Up_USBIO_SUSPEND_DEL_SHIFT)))
    #define Shoulder_Up_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Shoulder_Up_USBIO_SUSPEND_SHIFT)))
    #define Shoulder_Up_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Shoulder_Up_USBIO_SUSPEND_DEL_SHIFT)))
    #define Shoulder_Up_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Shoulder_Up__PC)
    /* Port Configuration */
    #define Shoulder_Up_PC                 (* (reg32 *) Shoulder_Up__PC)
#endif
/* Pin State */
#define Shoulder_Up_PS                     (* (reg32 *) Shoulder_Up__PS)
/* Data Register */
#define Shoulder_Up_DR                     (* (reg32 *) Shoulder_Up__DR)
/* Input Buffer Disable Override */
#define Shoulder_Up_INP_DIS                (* (reg32 *) Shoulder_Up__PC2)

/* Interrupt configuration Registers */
#define Shoulder_Up_INTCFG                 (* (reg32 *) Shoulder_Up__INTCFG)
#define Shoulder_Up_INTSTAT                (* (reg32 *) Shoulder_Up__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Shoulder_Up_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Shoulder_Up__SIO)
    #define Shoulder_Up_SIO_REG            (* (reg32 *) Shoulder_Up__SIO)
#endif /* (Shoulder_Up__SIO_CFG) */

/* USBIO registers */
#if !defined(Shoulder_Up__PC) && (CY_PSOC4_4200L)
    #define Shoulder_Up_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Shoulder_Up_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Shoulder_Up_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Shoulder_Up_DRIVE_MODE_SHIFT       (0x00u)
#define Shoulder_Up_DRIVE_MODE_MASK        (0x07u << Shoulder_Up_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Shoulder_Up_H */


/* [] END OF FILE */
