/*******************************************************************************
* File Name: Gripper_Out.h  
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

#if !defined(CY_PINS_Gripper_Out_ALIASES_H) /* Pins Gripper_Out_ALIASES_H */
#define CY_PINS_Gripper_Out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Gripper_Out_0			(Gripper_Out__0__PC)
#define Gripper_Out_0_PS		(Gripper_Out__0__PS)
#define Gripper_Out_0_PC		(Gripper_Out__0__PC)
#define Gripper_Out_0_DR		(Gripper_Out__0__DR)
#define Gripper_Out_0_SHIFT	(Gripper_Out__0__SHIFT)
#define Gripper_Out_0_INTR	((uint16)((uint16)0x0003u << (Gripper_Out__0__SHIFT*2u)))

#define Gripper_Out_INTR_ALL	 ((uint16)(Gripper_Out_0_INTR))


#endif /* End Pins Gripper_Out_ALIASES_H */


/* [] END OF FILE */
