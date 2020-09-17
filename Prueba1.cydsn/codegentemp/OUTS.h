/*******************************************************************************
* File Name: OUTS.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_OUTS_H) /* Pins OUTS_H */
#define CY_PINS_OUTS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OUTS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OUTS__PORT == 15 && ((OUTS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OUTS_Write(uint8 value);
void    OUTS_SetDriveMode(uint8 mode);
uint8   OUTS_ReadDataReg(void);
uint8   OUTS_Read(void);
void    OUTS_SetInterruptMode(uint16 position, uint16 mode);
uint8   OUTS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OUTS_SetDriveMode() function.
     *  @{
     */
        #define OUTS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OUTS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OUTS_DM_RES_UP          PIN_DM_RES_UP
        #define OUTS_DM_RES_DWN         PIN_DM_RES_DWN
        #define OUTS_DM_OD_LO           PIN_DM_OD_LO
        #define OUTS_DM_OD_HI           PIN_DM_OD_HI
        #define OUTS_DM_STRONG          PIN_DM_STRONG
        #define OUTS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OUTS_MASK               OUTS__MASK
#define OUTS_SHIFT              OUTS__SHIFT
#define OUTS_WIDTH              1u

/* Interrupt constants */
#if defined(OUTS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OUTS_SetInterruptMode() function.
     *  @{
     */
        #define OUTS_INTR_NONE      (uint16)(0x0000u)
        #define OUTS_INTR_RISING    (uint16)(0x0001u)
        #define OUTS_INTR_FALLING   (uint16)(0x0002u)
        #define OUTS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OUTS_INTR_MASK      (0x01u) 
#endif /* (OUTS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUTS_PS                     (* (reg8 *) OUTS__PS)
/* Data Register */
#define OUTS_DR                     (* (reg8 *) OUTS__DR)
/* Port Number */
#define OUTS_PRT_NUM                (* (reg8 *) OUTS__PRT) 
/* Connect to Analog Globals */                                                  
#define OUTS_AG                     (* (reg8 *) OUTS__AG)                       
/* Analog MUX bux enable */
#define OUTS_AMUX                   (* (reg8 *) OUTS__AMUX) 
/* Bidirectional Enable */                                                        
#define OUTS_BIE                    (* (reg8 *) OUTS__BIE)
/* Bit-mask for Aliased Register Access */
#define OUTS_BIT_MASK               (* (reg8 *) OUTS__BIT_MASK)
/* Bypass Enable */
#define OUTS_BYP                    (* (reg8 *) OUTS__BYP)
/* Port wide control signals */                                                   
#define OUTS_CTL                    (* (reg8 *) OUTS__CTL)
/* Drive Modes */
#define OUTS_DM0                    (* (reg8 *) OUTS__DM0) 
#define OUTS_DM1                    (* (reg8 *) OUTS__DM1)
#define OUTS_DM2                    (* (reg8 *) OUTS__DM2) 
/* Input Buffer Disable Override */
#define OUTS_INP_DIS                (* (reg8 *) OUTS__INP_DIS)
/* LCD Common or Segment Drive */
#define OUTS_LCD_COM_SEG            (* (reg8 *) OUTS__LCD_COM_SEG)
/* Enable Segment LCD */
#define OUTS_LCD_EN                 (* (reg8 *) OUTS__LCD_EN)
/* Slew Rate Control */
#define OUTS_SLW                    (* (reg8 *) OUTS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OUTS_PRTDSI__CAPS_SEL       (* (reg8 *) OUTS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OUTS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OUTS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OUTS_PRTDSI__OE_SEL0        (* (reg8 *) OUTS__PRTDSI__OE_SEL0) 
#define OUTS_PRTDSI__OE_SEL1        (* (reg8 *) OUTS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OUTS_PRTDSI__OUT_SEL0       (* (reg8 *) OUTS__PRTDSI__OUT_SEL0) 
#define OUTS_PRTDSI__OUT_SEL1       (* (reg8 *) OUTS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OUTS_PRTDSI__SYNC_OUT       (* (reg8 *) OUTS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OUTS__SIO_CFG)
    #define OUTS_SIO_HYST_EN        (* (reg8 *) OUTS__SIO_HYST_EN)
    #define OUTS_SIO_REG_HIFREQ     (* (reg8 *) OUTS__SIO_REG_HIFREQ)
    #define OUTS_SIO_CFG            (* (reg8 *) OUTS__SIO_CFG)
    #define OUTS_SIO_DIFF           (* (reg8 *) OUTS__SIO_DIFF)
#endif /* (OUTS__SIO_CFG) */

/* Interrupt Registers */
#if defined(OUTS__INTSTAT)
    #define OUTS_INTSTAT            (* (reg8 *) OUTS__INTSTAT)
    #define OUTS_SNAP               (* (reg8 *) OUTS__SNAP)
    
	#define OUTS_0_INTTYPE_REG 		(* (reg8 *) OUTS__0__INTTYPE)
#endif /* (OUTS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OUTS_H */


/* [] END OF FILE */
