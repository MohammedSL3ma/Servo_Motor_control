/*
 * Timer_reg.h
 *
 *  Created on: Nov 4, 2021
 *      Author: hp
 */

#ifndef MCAL_TIMER_V2_TIMER_REG_H_
#define MCAL_TIMER_V2_TIMER_REG_H_

#define SFIO_REG       *((volatile u8*)0X50)
#define S_REG          *((volatile u8*)0X5F)
#define TIF_REG        *((volatile u8*)0X58)
#define TIMSK_REG      *((volatile u8*)0X59)
/*
 * Timer_0 Group
 */
#define TCC0_REG       *((volatile u8*)0X53)
#define TCNT0_REG      *((volatile u8*)0X52)
#define OCR0_REG       *((volatile u8*)0X5C)
/*
 * Timer_1 Group
 */
#define TCC1A_REG      *((volatile u8*)0X4F)
#define TCC1B_REG      *((volatile u8*)0X4E)
#define TCNT1_REG     *((volatile u16*)0X4C)
#define OCR1A_REG     *((volatile u16*)0X4A)
#define OCR1B_REG     *((volatile u16*)0X48)
#define ICR1_REG      *((volatile u16*)0X46)

/*
 * Timer_2 Group
 */
#define TCC2_REG       *((volatile u8*)0X45)
#define TCNT2_REG      *((volatile u8*)0X44)
#define OCR2_REG       *((volatile u8*)0X43)

#endif /* MCAL_TIMER_V2_TIMER_REG_H_ */
