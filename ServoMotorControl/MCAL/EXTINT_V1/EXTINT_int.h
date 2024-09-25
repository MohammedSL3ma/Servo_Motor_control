/*
 * EXTINT_int.h
 *
 *  Created on: Oct 11, 2021
 *      Author: hp
 */

#ifndef EXTINT_V1_EXTINT_INT_H_
#define EXTINT_V1_EXTINT_INT_H_
/*
 * EXTINT0 = PD2
 * EXTINT1 = PD3
 * EXTINT2 = PB2
 */


typedef enum
{
 INT_0,
 INT_1,
 INT_2,
 G_DIS
}EXT_INT_N;

#define INT0_EN                      (u8)0b01000000
#define INT1_EN                      (u8)0b10000000
#define INT2_EN                      (u8)0b00100000
#define GLOBAL_INTERRUPT_ENABLE      (u8)0b10000000


typedef enum
{
INT0_LOW_LEVEL_EN = 0b00000000,
INT0_LOGIC_CHG_EN = 0b00000001,
INT0_FALL_EDGE_EN = 0b00000010,
INT0_RISE_EDGE_EN = 0b00000011
}EXT_INT_0_SC_e;

typedef enum
{
INT1_LOW_LEVEL_EN = 0b00000000,
INT1_LOGIC_CHG_EN = 0b00000100,
INT1_FALL_EDGE_EN = 0b00001000,
INT1_RISE_EDGE_EN = 0b00001100
}EXT_INT_1_SC_e;

typedef enum
{
INT2_FALL_EDGE_EN = 0b00000000,
INT2_RISE_EDGE_EN = 0b01000000
}EXT_INT_2_SC_e;



void Set_CallBack_EXTINT_0(void (*ptr)(void));
void Set_CallBack_EXTINT_1(void (*ptr)(void));
void Set_CallBack_EXTINT_2(void (*ptr)(void));

u8 EXTINT_u8Enable(u8 Copy_u8ExtInt);
u8 EXTINT_u8Disable(u8 Copy_u8ExtInt);
u8 EXTINT_u8SenseCtrl(u8 Copy_u8ExtInt,u8 Copy_u8ISCStatus);
void Vector_CallBack(void);

#endif /* ISR_V1_ISR_INT_H_ */
