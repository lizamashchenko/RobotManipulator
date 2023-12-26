/*******************************************************************************
* File Name: Wrist_2.h  
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

#if !defined(CY_PINS_Wrist_2_H) /* Pins Wrist_2_H */
#define CY_PINS_Wrist_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Wrist_2_aliases.h"


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
} Wrist_2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Wrist_2_Read(void);
void    Wrist_2_Write(uint8 value);
uint8   Wrist_2_ReadDataReg(void);
#if defined(Wrist_2__PC) || (CY_PSOC4_4200L) 
    void    Wrist_2_SetDriveMode(uint8 mode);
#endif
void    Wrist_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Wrist_2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Wrist_2_Sleep(void); 
void Wrist_2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Wrist_2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Wrist_2_DRIVE_MODE_BITS        (3)
    #define Wrist_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Wrist_2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Wrist_2_SetDriveMode() function.
         *  @{
         */
        #define Wrist_2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Wrist_2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Wrist_2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Wrist_2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Wrist_2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Wrist_2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Wrist_2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Wrist_2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Wrist_2_MASK               Wrist_2__MASK
#define Wrist_2_SHIFT              Wrist_2__SHIFT
#define Wrist_2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Wrist_2_SetInterruptMode() function.
     *  @{
     */
        #define Wrist_2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Wrist_2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Wrist_2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Wrist_2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Wrist_2__SIO)
    #define Wrist_2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Wrist_2__PC) && (CY_PSOC4_4200L)
    #define Wrist_2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Wrist_2_USBIO_DISABLE              ((uint32)(~Wrist_2_USBIO_ENABLE))
    #define Wrist_2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Wrist_2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Wrist_2_USBIO_ENTER_SLEEP          ((uint32)((1u << Wrist_2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Wrist_2_USBIO_SUSPEND_DEL_SHIFT)))
    #define Wrist_2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Wrist_2_USBIO_SUSPEND_SHIFT)))
    #define Wrist_2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Wrist_2_USBIO_SUSPEND_DEL_SHIFT)))
    #define Wrist_2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Wrist_2__PC)
    /* Port Configuration */
    #define Wrist_2_PC                 (* (reg32 *) Wrist_2__PC)
#endif
/* Pin State */
#define Wrist_2_PS                     (* (reg32 *) Wrist_2__PS)
/* Data Register */
#define Wrist_2_DR                     (* (reg32 *) Wrist_2__DR)
/* Input Buffer Disable Override */
#define Wrist_2_INP_DIS                (* (reg32 *) Wrist_2__PC2)

/* Interrupt configuration Registers */
#define Wrist_2_INTCFG                 (* (reg32 *) Wrist_2__INTCFG)
#define Wrist_2_INTSTAT                (* (reg32 *) Wrist_2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Wrist_2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Wrist_2__SIO)
    #define Wrist_2_SIO_REG            (* (reg32 *) Wrist_2__SIO)
#endif /* (Wrist_2__SIO_CFG) */

/* USBIO registers */
#if !defined(Wrist_2__PC) && (CY_PSOC4_4200L)
    #define Wrist_2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Wrist_2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Wrist_2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Wrist_2_DRIVE_MODE_SHIFT       (0x00u)
#define Wrist_2_DRIVE_MODE_MASK        (0x07u << Wrist_2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Wrist_2_H */


/* [] END OF FILE */
