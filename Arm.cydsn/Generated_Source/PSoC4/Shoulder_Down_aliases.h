/*******************************************************************************
* File Name: Shoulder_Down.h  
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

#if !defined(CY_PINS_Shoulder_Down_ALIASES_H) /* Pins Shoulder_Down_ALIASES_H */
#define CY_PINS_Shoulder_Down_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Shoulder_Down_0			(Shoulder_Down__0__PC)
#define Shoulder_Down_0_PS		(Shoulder_Down__0__PS)
#define Shoulder_Down_0_PC		(Shoulder_Down__0__PC)
#define Shoulder_Down_0_DR		(Shoulder_Down__0__DR)
#define Shoulder_Down_0_SHIFT	(Shoulder_Down__0__SHIFT)
#define Shoulder_Down_0_INTR	((uint16)((uint16)0x0003u << (Shoulder_Down__0__SHIFT*2u)))

#define Shoulder_Down_INTR_ALL	 ((uint16)(Shoulder_Down_0_INTR))


#endif /* End Pins Shoulder_Down_ALIASES_H */


/* [] END OF FILE */
