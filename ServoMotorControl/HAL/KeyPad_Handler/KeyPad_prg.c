/*
 * KeyBad_prg.c
 *
 *  Created on: Sep 24, 2021
 *      Author: hp
 */
#include"../../LIB/stdtypes.h"
#include"../../MCAL/DIO_V1/DIO_int.h"
#include"KeyPad_cfg.h"
#include"util/delay.h"
#define NOT_PRESSED     (u8)0


extern u8 KEYPAD_u8aKeyPadMap_Calc[4][4];

void KEYPAD_vidInit(void)
{
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_ROW_1,INPUT);
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_ROW_2,INPUT);
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_ROW_3,INPUT);
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_ROW_4,INPUT);

DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_ROW_1,HIGH);
DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_ROW_2,HIGH);
DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_ROW_3,HIGH);
DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_ROW_4,HIGH);

DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_COLUMN_1,OUTPUT);
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_COLUMN_2,OUTPUT);
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_COLUMN_3,OUTPUT);
DIO_u8setPinDirection(KEYPAD_PORT,KEYPAD_COLUMN_4,OUTPUT);

DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_COLUMN_1,HIGH);
DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_COLUMN_2,HIGH);
DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_COLUMN_3,HIGH);
DIO_u8setPinValue(KEYPAD_PORT,KEYPAD_COLUMN_4,HIGH);
}
u8 KEYPAD_u8GetPressed(void)
{
u8 Local_u8PressedSwitch = NOT_PRESSED ;
u8 Local_u8CurrentCol;
u8 Local_u8CurrentRow;
u8 Local_u8CurrentRowStatus;
for(Local_u8CurrentCol = KEYPAD_COLUMN_START ;
		Local_u8CurrentCol<=KEYPAD_COLUMN_END ;
		Local_u8CurrentCol++ )
{
DIO_u8setPinValue(KEYPAD_PORT , Local_u8CurrentCol , LOW);
for(Local_u8CurrentRow = KEYPAD_ROW_START ;
		Local_u8CurrentRow<=KEYPAD_ROW_END ;
		Local_u8CurrentRow++ )
{
DIO_u8getPinValue(KEYPAD_PORT , Local_u8CurrentRow ,& Local_u8CurrentRowStatus);
if(Local_u8CurrentRowStatus == LOW)
{
	Local_u8PressedSwitch = KEYPAD_u8aKeyPadMap_Calc[Local_u8CurrentRow-KEYPAD_ROW_START][Local_u8CurrentCol-KEYPAD_COLUMN_START] ;


	_delay_ms(5);

	while(Local_u8CurrentRowStatus == LOW)
	{
		DIO_u8getPinValue(KEYPAD_PORT , Local_u8CurrentRow , & Local_u8CurrentRowStatus);
	}
	_delay_ms(10);

}

}
DIO_u8setPinValue(KEYPAD_PORT , Local_u8CurrentCol , HIGH);
}

return Local_u8PressedSwitch;
}
