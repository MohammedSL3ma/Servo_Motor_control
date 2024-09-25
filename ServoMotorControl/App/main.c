/*
 * main.c
 *
 *  Created on: May 18, 2023
 *      Author: BatMan
 */

#include "../LIB/stdtypes.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO_V1/DIO_int.h"
#include "../MCAL/EXTINT_V1/EXTINT_int.h"
#include "../MCAL/Timer_V2/Timer_int.h"
#include "../MCAL/Timer_V2/Timer_reg.h"

#include "../HAL/LCD_Handler/LCD_int.h"
#include "../HAL/KeyPad_Handler/KeyPad_int.h"


typedef enum{
	Init_Angle,
	Angle_90,
	Angle_180
}Angles;
u8 global_u8Angles = Init_Angle;


//void DelaySec(void)
////ISR(TIMER0_OVF_vect)
//{
//	static u16 Local_u16OVFCounter=0;
//
//	Local_u16OVFCounter++;
//
//	if(Local_u16OVFCounter == DELAY_1_SEC)
//	{
//		global_u8Angles = Angle_90;
//		DIO_u8setPinValue(PORT_A,PIN_2,HIGH);
//		DIO_u8setPinValue(PORT_A,PIN_3,LOW);
//	}
//	else if(Local_u16OVFCounter == DELAY_4_SECS)
//	{
//		global_u8Angles = Angle_180;
//		DIO_u8setPinValue(PORT_A,PIN_3,HIGH);
//		DIO_u8setPinValue(PORT_A,PIN_2,LOW);
//		Local_u16OVFCounter = 0;
//	}
//
//}



void Angles_PWM(void)
{
	static u8 Local_u8OVFCounter=0;
	Local_u8OVFCounter++;

	switch(global_u8Angles)
	{
	case Angle_90:
		if(Local_u8OVFCounter==2)
		{
			DIO_u8setPinValue(PORT_B,PIN_1,LOW);
		}

		else if(Local_u8OVFCounter==20)
		{
			DIO_u8setPinValue(PORT_B,PIN_1,HIGH);
			Local_u8OVFCounter=0;
		}
		break;
	case Init_Angle:
		if(Local_u8OVFCounter==6)
		{
			DIO_u8setPinValue(PORT_B,PIN_1,LOW);
		}

		else if(Local_u8OVFCounter==20)
		{
			DIO_u8setPinValue(PORT_B,PIN_1,HIGH);
			Local_u8OVFCounter=0;
		}
		break;
	case Angle_180:
		if(Local_u8OVFCounter==8)
		{
			DIO_u8setPinValue(PORT_B,PIN_1,LOW);
		}

		else if(Local_u8OVFCounter==20)
		{
			DIO_u8setPinValue(PORT_B,PIN_1,HIGH);
			Local_u8OVFCounter=0;
		}
		break;
	}
}

void main (void)
{
	u8 KeyValue = 0; //value[3] = {0};
	DIO_u8setPinDirection(PORT_B,PIN_1,OUTPUT);

	LCD_4_BitvidInit();
	KEYPAD_vidInit();



	timer_config_type Servo_Angles;
	Servo_Angles.timer = TIMER_2;
	Servo_Angles.operated_mode = NORMAL_MODE;
	Servo_Angles.T2_used_freq = TIMER_2_PRE_SCALER_e_8;
	Timer_init(&Servo_Angles);
	Set_CallBack_TIMER_2_OVF_INT(Angles_PWM);


	Global_VidINTEnable();
	while(1)
	{

		KeyValue = KEYPAD_u8GetPressed();


		switch(KeyValue)
		{
		case'1':LCD_4_BitvidsendCommand(0b00000001); LCD_4_BitvidwriteString("ANGLE = 90"); global_u8Angles = Angle_90; break;
		case'0':LCD_4_BitvidsendCommand(0b00000001); LCD_4_BitvidwriteString("ANGLE = 0"); global_u8Angles = Init_Angle; break;
		case'3':LCD_4_BitvidsendCommand(0b00000001); LCD_4_BitvidwriteString("ANGLE = 180"); global_u8Angles = Angle_180; break;
		}


	}

}


