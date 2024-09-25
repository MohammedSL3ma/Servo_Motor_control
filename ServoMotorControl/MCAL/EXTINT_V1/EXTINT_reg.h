/*
 * EXTINT_reg.h
 *
 *  Created on: Oct 11, 2021
 *      Author: hp
 */
#include "../../LIB/stdtypes.h"
#ifndef EXTINT_V1_EXITINT_REG_H_
#define EXTINT_V1_EXTINT_REG_H_
/*
 * MCU Control Register
 */
#define MCUC_REG       *((volatile u8*)0X55)
/*
 * MCU Control & Status Register
 */
#define MCUCS_REG       *((volatile u8*)0X54)
/*
 * General Interrupt Control Register
 */
#define GIC_REG        *((volatile u8*)0X5B)
/*
 * General Interrupt Flag Register
 */
#define GIF_REG        *((volatile u8*)0X5A)
/*
 * Status Register
 */
#define S_REG        *((volatile u8*)0X5F)


#endif /* ISR_V1_ISR_REG_H_ */
