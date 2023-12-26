/*******************************************************************************
* File Name: Shoulder_Up.h  
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

#if !defined(CY_PINS_Shoulder_Up_ALIASES_H) /* Pins Shoulder_Up_ALIASES_H */
#define CY_PINS_Shoulder_Up_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Shoulder_Up_0			(Shoulder_Up__0__PC)
#define Shoulder_Up_0_PS		(Shoulder_Up__0__PS)
#define Shoulder_Up_0_PC		(Shoulder_Up__0__PC)
#define Shoulder_Up_0_DR		(Shoulder_Up__0__DR)
#define Shoulder_Up_0_SHIFT	(Shoulder_Up__0__SHIFT)
#define Shoulder_Up_0_INTR	((uint16)((uint16)0x0003u << (Shoulder_Up__0__SHIFT*2u)))

#define Shoulder_Up_INTR_ALL	 ((uint16)(Shoulder_Up_0_INTR))


#endif /* End Pins Shoulder_Up_ALIASES_H */


/* [] END OF FILE */
