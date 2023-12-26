/*******************************************************************************
* File Name: Wrist_Up.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Wrist_Up_ALIASES_H) /* Pins Wrist_Up_ALIASES_H */
#define CY_PINS_Wrist_Up_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Wrist_Up_0			(Wrist_Up__0__PC)
#define Wrist_Up_0_PS		(Wrist_Up__0__PS)
#define Wrist_Up_0_PC		(Wrist_Up__0__PC)
#define Wrist_Up_0_DR		(Wrist_Up__0__DR)
#define Wrist_Up_0_SHIFT	(Wrist_Up__0__SHIFT)
#define Wrist_Up_0_INTR	((uint16)((uint16)0x0003u << (Wrist_Up__0__SHIFT*2u)))

#define Wrist_Up_INTR_ALL	 ((uint16)(Wrist_Up_0_INTR))


#endif /* End Pins Wrist_Up_ALIASES_H */


/* [] END OF FILE */
