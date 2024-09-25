/*
 * DIO_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: hp
 */
#include "../../LIB/stdtypes.h"
#ifndef DIO_V1_DIO_INT_H_
#define DIO_V1_DIO_INT_H_

typedef enum
{
 PORT_A,
 PORT_B,
 PORT_C,
 PORT_D
}PORT_e;

typedef enum
{
 PIN_0,
 PIN_1,
 PIN_2,
 PIN_3,
 PIN_4,
 PIN_5,
 PIN_6,
 PIN_7
}PIN_e;

typedef enum
{
 INPUT,
 OUTPUT
}DIRECTION_e;

typedef enum
{
 LOW,
 HIGH
}STATE_e;

#define HALF_OUTPUT_HALF_INPUT    (u8) 0X0F
#define HALF_INPUT_HALF_OUTPUT    (u8) 0XF0
#define HALF_HIGH_HALF_LOW        (u8) 0X0F
#define HALF_LOW_HALF_HIGH        (u8) 0XF0
#define FULL_INPUT                (u8) 0X00
#define FULL_OUTPUT               (u8) 0XFF
#define FULL_LOW                (u8) 0X00
#define FULL_HIGH               (u8) 0XFF
u8 DIO_u8setPortDirection(u8 Copy_u8port,u8 Copy_u8direction);
u8 DIO_u8setPortValue(u8 Copy_u8port, u8 Copy_u8Value);
u8 DIO_u8getPortValue(u8 Copy_u8port, u8 * Copy_u8pValue);

u8 DIO_u8setPinDirection(u8 Copy_u8port, u8 Copy_u8pin ,u8 Copy_u8direction);
u8 DIO_u8setPinValue(u8 Copy_u8port, u8 Copy_u8pin ,u8 Copy_u8value);
u8 DIO_u8togglePinValue(u8 Copy_u8port, u8 Copy_u8pin);
u8 DIO_u8getPinValue(u8 Copy_u8port, u8 Copy_u8pin ,u8 * Copy_u8pValue);


#endif /* DIO_V1_DIO_INT_H_ */
