/*******************************************************************************
* File Name: Shoulder_Down.h  
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

#if !defined(CY_PINS_Shoulder_Down_H) /* Pins Shoulder_Down_H */
#define CY_PINS_Shoulder_Down_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Shoulder_Down_aliases.h"


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
} Shoulder_Down_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Shoulder_Down_Read(void);
void    Shoulder_Down_Write(uint8 value);
uint8   Shoulder_Down_ReadDataReg(void);
#if defined(Shoulder_Down__PC) || (CY_PSOC4_4200L) 
    void    Shoulder_Down_SetDriveMode(uint8 mode);
#endif
void    Shoulder_Down_SetInterruptMode(uint16 position, uint16 mode);
uint8   Shoulder_Down_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Shoulder_Down_Sleep(void); 
void Shoulder_Down_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Shoulder_Down__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Shoulder_Down_DRIVE_MODE_BITS        (3)
    #define Shoulder_Down_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Shoulder_Down_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Shoulder_Down_SetDriveMode() function.
         *  @{
         */
        #define Shoulder_Down_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Shoulder_Down_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Shoulder_Down_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Shoulder_Down_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Shoulder_Down_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Shoulder_Down_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Shoulder_Down_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Shoulder_Down_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Shoulder_Down_MASK               Shoulder_Down__MASK
#define Shoulder_Down_SHIFT              Shoulder_Down__SHIFT
#define Shoulder_Down_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Shoulder_Down_SetInterruptMode() function.
     *  @{
     */
        #define Shoulder_Down_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Shoulder_Down_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Shoulder_Down_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Shoulder_Down_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Shoulder_Down__SIO)
    #define Shoulder_Down_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Shoulder_Down__PC) && (CY_PSOC4_4200L)
    #define Shoulder_Down_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Shoulder_Down_USBIO_DISABLE              ((uint32)(~Shoulder_Down_USBIO_ENABLE))
    #define Shoulder_Down_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Shoulder_Down_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Shoulder_Down_USBIO_ENTER_SLEEP          ((uint32)((1u << Shoulder_Down_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Shoulder_Down_USBIO_SUSPEND_DEL_SHIFT)))
    #define Shoulder_Down_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Shoulder_Down_USBIO_SUSPEND_SHIFT)))
    #define Shoulder_Down_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Shoulder_Down_USBIO_SUSPEND_DEL_SHIFT)))
    #define Shoulder_Down_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Shoulder_Down__PC)
    /* Port Configuration */
    #define Shoulder_Down_PC                 (* (reg32 *) Shoulder_Down__PC)
#endif
/* Pin State */
#define Shoulder_Down_PS                     (* (reg32 *) Shoulder_Down__PS)
/* Data Register */
#define Shoulder_Down_DR                     (* (reg32 *) Shoulder_Down__DR)
/* Input Buffer Disable Override */
#define Shoulder_Down_INP_DIS                (* (reg32 *) Shoulder_Down__PC2)

/* Interrupt configuration Registers */
#define Shoulder_Down_INTCFG                 (* (reg32 *) Shoulder_Down__INTCFG)
#define Shoulder_Down_INTSTAT                (* (reg32 *) Shoulder_Down__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Shoulder_Down_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Shoulder_Down__SIO)
    #define Shoulder_Down_SIO_REG            (* (reg32 *) Shoulder_Down__SIO)
#endif /* (Shoulder_Down__SIO_CFG) */

/* USBIO registers */
#if !defined(Shoulder_Down__PC) && (CY_PSOC4_4200L)
    #define Shoulder_Down_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Shoulder_Down_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Shoulder_Down_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Shoulder_Down_DRIVE_MODE_SHIFT       (0x00u)
#define Shoulder_Down_DRIVE_MODE_MASK        (0x07u << Shoulder_Down_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Shoulder_Down_H */


/* [] END OF FILE */
