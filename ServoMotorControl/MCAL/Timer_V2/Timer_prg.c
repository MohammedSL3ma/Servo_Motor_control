/*
 * Timer_prg.c
 *
 *  Created on: Nov 4, 2021
 *      Author: hp
 */

#include "../../LIB/stdtypes.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO_V1/DIO_int.h"
#include "Timer_int.h"
#include "Timer_reg.h"
#define RT_OK    (u8)   1
#define RT_NOK   (u8)   0
#define NULL     (void*) 0
#define TIMER_PRE_SCALER_CLR_MUSK  (u8) 0b11111000
#define F_CPU      (u8) 8000000
#define TIMER_0_2_OCR_MAX_VALUE   (u8)  256
#define TIMER_1_OCR_MAX_VALUE   (u16)  65536


typedef struct{
	void (*TIMER_0_OVF_INT)(void);
	void (*TIMER_0_OC_INT)(void);
	void (*TIMER_1_OVF_INT)(void);
	void (*TIMER_1_OCA_INT)(void);
	void (*TIMER_1_OCB_INT)(void);
	void (*TIMER_1_CAPT_INT)(void);
	void (*TIMER_2_OVF_INT)(void);
	void (*TIMER_2_OC_INT)(void);
}TIMER_N_INT_PTR;


TIMER_N_INT_PTR  TIMER_ISR;
/*
 * Timer 0 Group
 */

/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */






void Set_CallBack_TIMER_0_OVF_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_0_OVF_INT = ptr;
	}
}
void __vector_11 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_11 (void)
{
	if(TIMER_ISR.TIMER_0_OVF_INT != NULL)
	{
		TIMER_ISR.TIMER_0_OVF_INT();
	}
}

void Set_CallBack_TIMER_0_OC_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_0_OC_INT = ptr;
	}
}
void __vector_10 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_10 (void)
{
	if(TIMER_ISR.TIMER_0_OC_INT != NULL)
	{
		TIMER_ISR.TIMER_0_OC_INT();
	}
}
/*
 * Timer 1 Group
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */




void Set_CallBack_TIMER_1_OVF_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_1_OVF_INT = ptr;
	}
}
void __vector_9 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_9 (void)
{
	if(TIMER_ISR.TIMER_1_OVF_INT != NULL)
	{
		TIMER_ISR.TIMER_1_OVF_INT();
	}
}

void Set_CallBack_TIMER_1_OCA_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_1_OCA_INT = ptr;
	}
}
void __vector_7 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_7 (void)
{
	if(TIMER_ISR.TIMER_1_OCA_INT != NULL)
	{
		TIMER_ISR.TIMER_1_OCA_INT();
	}
}


void Set_CallBack_TIMER_1_OCB_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_1_OCB_INT = ptr;
	}
}
void __vector_8 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_8 (void)
{
	if(TIMER_ISR.TIMER_1_OCB_INT != NULL)
	{
		TIMER_ISR.TIMER_1_OCB_INT();
	}
}


void Set_CallBack_TIMER_1_CAPT_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_1_CAPT_INT = ptr;
	}
}
void __vector_6 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_6 (void)
{
	if(TIMER_ISR.TIMER_1_CAPT_INT != NULL)
	{
		TIMER_ISR.TIMER_1_CAPT_INT();
	}
}

/*
 * Timer 2 Group
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */



void Set_CallBack_TIMER_2_OVF_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_2_OVF_INT = ptr;
	}
}
void __vector_5 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_5 (void)
{
	if(TIMER_ISR.TIMER_2_OVF_INT != NULL)
	{
		TIMER_ISR.TIMER_2_OVF_INT();
	}
}


void Set_CallBack_TIMER_2_OC_INT(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER_ISR.TIMER_2_OC_INT = ptr;
	}
}
void __vector_4 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_4 (void)
{
	if(TIMER_ISR.TIMER_2_OC_INT != NULL)
	{
		TIMER_ISR.TIMER_2_OC_INT();
	}
}


/*
 * Common Functions
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */



void Timer_init(timer_config_type *timer_config_ptr)
{
	Timer_DeInit(timer_config_ptr->timer);/*deinitialize the desired timer */
	switch(timer_config_ptr->timer)
	{
	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. timer mode CTC or over flow
	 * 3. select prescaler
	 * 4. enable the interrupt module
	 * 5. set the initial value
	 * 6. set the compared value if CTC mode
	 */
	case TIMER_0:
		/* here we want to configure Timer0 as we user want
		 * FOC0= 0 ; because non_pwm mode
		 * select a prescaler
		 * if mode is Normal mode we enable  Timer0 normal mode Interrupt
		 * else if mode is CTC mode we enable Timer0  compare mode Interrupt
		 * */
		TCNT0_REG = timer_config_ptr->initial_value; /*Set Timer0 initial value to 0*/
		SET_BIT(TCC0_REG,7)   ; /* non-pwm mode*/
		if (timer_config_ptr->operated_mode==NORMAL_MODE)
		{
			SET_BIT(TIMSK_REG,0)    ;/* Enable Timer0 over flow Interrupt*/
		}
		else if (timer_config_ptr->operated_mode==CTC_MODE)
		{
			OCR0_REG = timer_config_ptr->compared_value; /*Set Compare Value*/
			SET_BIT(TCC0_REG,3)    ; /* CTC mode */
			SET_BIT(TIMSK_REG,1)    ; /* Enable CTC mode interrupt */
		}
		/*select the clk to start counting */
		TCC0_REG=(TCC0_REG &0b11111000)|(timer_config_ptr->T0_T1_used_freq & 0b00000111 );
		break;
	case TIMER_1:
		TCNT1_REG = timer_config_ptr->initial_value;/*set timer1 initial value */
		SET_BIT(TCC1A_REG,3)   ;/*non-pwm mode */
		if (timer_config_ptr->operated_mode==NORMAL_MODE)
		{
			/********************************************************************/
			/*******************************Normal mode*****************************/
			/********************************************************************/
			/*
			CLEAR_BIT(TCCR1A,WGM10)  ;
			CLEAR_BIT(TCCR1A,WGM11)  ;
			CLEAR_BIT(TCCR1B,WGM12)  ;
			CLEAR_BIT(TCCR1B,WGM13)  ;
			 */
			/**************************************************************************/
			SET_BIT(TIMSK_REG,2)    ;/*Enable Timer1 over flow Interrupt*/
		}
		else if (timer_config_ptr->operated_mode==CTC_MODE)
		{
			if(timer_config_ptr->channels_number == CHANNEL_1A)
			{
				OCR1A_REG = timer_config_ptr->compared_value; /*Set timer1 Compare Value*/
				SET_BIT(TCC1B_REG,3)    ;/* enable CTC  mode*/
				SET_BIT(TIMSK_REG,4)    ; /* enable CTC channel A Interrupt*/
				/********************************************************************/
				/*******************************CTC mode*****************************/
				/********************************************************************/
				/*
			CLEAR_BIT(TCCR1A,WGM10)  ;
			CLEAR_BIT(TCCR1A,WGM11)  ;
			CLEAR_BIT(TCCR1B,WGM13)  ;
				 */
				/**************************************************************************/
			}
			else if (timer_config_ptr->channels_number==CHANNEL_1B)
			{
				SET_BIT(TCC1A_REG,2)   ;/*non-pwm mode channel B*/
				OCR1B_REG = timer_config_ptr->compared_value_B_channel; /*Set timer1 Compare Value*/
				SET_BIT(TIMSK_REG,3);/* enable CTC channel B Interrupt*/
			}
		}

		TCC1B_REG=(TCC1B_REG &0b11111000)|(timer_config_ptr->T0_T1_used_freq & 0b00000111);/*select the prescaler */
		break;
	case TIMER_2:
		/* here we want to configure Timer0 as we user want
		 * FOC0= 0 ; because non_pwm mode
		 * select a prescaler
		 * if mode is Normal mode we enable  Timer0 normal mode Interrupt
		 * and disable Timer0 compare Interrupt
		 * else if mode is CTC mode we enable Timer0  compare mode Interrupt
		 * and disable Timer0 normal Interrupt ad select the state of OSR0 pin
		 * */
		TCNT2_REG = timer_config_ptr->initial_value; /*Set Timer2 initial value */
		SET_BIT(TCC2_REG,7); /* non-pwm mode*/
		if (timer_config_ptr->operated_mode==NORMAL_MODE)
		{
			/*Normal mode*/
			/*
			CLEAR_BIT(TCCR2,WGM21)  ;
			CLEAR_BIT(TCCR2,WGM20)  ;
			 */
			SET_BIT(TIMSK_REG,6)    ;/* Enable Timer0 over flow Interrupt*/
		}
		else if (timer_config_ptr->operated_mode==CTC_MODE)
		{
			OCR2_REG = timer_config_ptr->compared_value; /*Set Compare Value*/
			SET_BIT(TCC2_REG,3)    ; /* CTC mode */
			SET_BIT(TIMSK_REG,7)    ; /* enable CTC Interrupt*/
		}
		/*select the clk to start counting */
		TCC2_REG=(TCC2_REG &0b11111000)|(timer_config_ptr->T2_used_freq & 0b00000111 );
		break;
	case ALL:
		break;
	}
}

/*Description :
 *this an assistant function used after timer initialization
 * it assign the compared value or duty cycle value for
 * every desired timer
 * */

void change_compared_and_duty_value(timer_config_type * config_ptr)
{
	switch(config_ptr->timer)
	{
	case TIMER_0:
		OCR0_REG = (u8)(config_ptr->compared_value); /*Set Compare Value*/
		break ;
	case TIMER_1:
		OCR1A_REG = config_ptr->compared_value; /*Set timer1 Compare Value*/
		if (config_ptr->channels_number==CHANNEL_1B)
		{
			OCR1B_REG = config_ptr->compared_value_B_channel; /*Set timer1 B Compare Value*/
		}
		break ;
	case TIMER_2:
		OCR2_REG = (u8)(config_ptr->compared_value); /*Set Compare Value*/
		break ;
	}
}

/*Description
 * this function is responsible for reset all timer registers
 * */
void Timer_DeInit(TIMER_e timer)
{
	switch(timer)
	{
	case TIMER_0:
		TCC0_REG= 0; /* clear control register*/
		TCNT0_REG= 0; /* clear the timer 0*/
		TIMSK_REG=(TIMSK_REG & 0b11111100);/*Disable module interrupt interrupt*/
		break;
	case TIMER_1:
		TCC1A_REG=0; /* clear control register*/
		TCC1B_REG=0 ;
		TCNT1_REG= 0; /* clear the timer 0*/
		TIMSK_REG=(TIMSK_REG & 0b11100011);/*Disable module interrupt interrupt*/
		break;
	case TIMER_2:
		TCC2_REG= 0; /* clear control register*/
		TCNT2_REG= 0; /* clear the timer 0*/
		TIMSK_REG=(TIMSK_REG & 0b00111111);/*Disable module interrupt interrupt*/
		break;
	case ALL:
		TIMSK_REG=(TIMSK_REG &0b00100000);/*Disable all timers modules interrupt interrupt*/
		/*===============Deinitialize Timer0=============================*/
		TCC0_REG= 0; /* clear control register*/
		TCNT0_REG= 0; /* clear the timer */
		/*===============Deinitialize Timer1=============================*/
		TCC1A_REG= 0; /* clear A control register*/
		TCC1B_REG= 0;/* clear B control register*/
		TCNT1_REG= 0; /* clear the timer */
		/*===============Deinitialize Timer2=============================*/
		TCC2_REG= 0; /* clear control register*/
		TCNT2_REG= 0; /* clear the timer */
		break;
	}
}

/*Description
 * this func used to reset the timer to start count again from the beginning
 * we chose the timer to be cleared
 * */

void clear_timer(TIMER_e timer)
{
	switch(timer)
	{
	case TIMER_0:
		TCNT0_REG = 0; /* Set Timer0 initial value to 0*/
		break;
	case TIMER_1:
		TCNT1_REG = 0; /* Set Timer1 initial value to 0*/
		break;
	case TIMER_2:
		TCNT2_REG = 0; /* Set Timer2 initial value to 0*/
		break;
	case ALL:
		TCNT0_REG = 0;  /* Set Timer0 initial value to 0*/
		TCNT1_REG = 0;  /* Set Timer1 initial value to 0*/
		TCNT2_REG = 0;  /* Set Timer2 initial value to 0*/
		break;
	default:
		break  ;
	}
}

/*Description :
 * this function is responsible for pwm init for the desired timer
 * it take a ptr to struct
 *
 * */
void PWM_timers_init(PWM_timers_config *timer_config)
{

	switch (timer_config->timer)
	{

	case TIMER_0:
		clear_timer(TIMER_0); /* Set Timer Initial Value to 0*/
		OCR0_REG  = timer_config->set_duty_cycle ; /* Set Compare Value*/
		/*Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC*/
		DIO_u8setPinDirection(PORT_B, PIN_3, OUTPUT);
		/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/N
		 *
		 */
		CLR_BIT(TCC0_REG,7);
		if(timer_config->PWM_Mode == FAST_PWM)
		{
			TCC0_REG = (1<<3) | (1<<5) | (1<<6);
		}
		else if(timer_config->PWM_Mode == PHASE_CORRECT_PWM)
		{
			TCC0_REG = (0<<3) | (1<<5) | (1<<6);
		}
		/*select the clk (prescaler)to start counting */
		TCC0_REG=(TCC0_REG & 0b11111000)|(timer_config->T0_T1_used_freq & 0b00000111 );
		break;
	case TIMER_1:
		clear_timer(TIMER_1); /* Set Timer Initial Value to 0*/
		ICR1_REG   = timer_config->timer1_TOP_value; /* Set TOP Value*/
		OCR1A_REG  = timer_config->set_duty_cycle; /* Set Compare Value*/
		/*Configure PD5/OC1A and PD4/OC1B as output pin --> pin where the PWM signal is generated from MC*/
		DIO_u8setPinDirection(PORT_D, PIN_5, OUTPUT);/*OC1A->output*/
		/* Configure timer control register
		 * 1. Fast PWM mode FOC1A=0
		 * 1. Fast PWM mode FOC1B=0
		 * 2. Fast PWM Mode mode 14
		 * 3. Clear OC1A when match occurs (non inverted mode) COM20=0 & COM21=1
		 * 4. clock = F_CPU/N
		 */

		CLR_BIT(TCC1A_REG,3);
		if(timer_config->PWM_Mode == FAST_PWM)
		{

			SET_BIT(TCC1B_REG,4);SET_BIT(TCC1B_REG,3);SET_BIT(TCC1A_REG,1);CLR_BIT(TCC1A_REG,0);
			SET_BIT(TCC1A_REG,7);SET_BIT(TCC1A_REG,5);CLR_BIT(TCC1A_REG,6);CLR_BIT(TCC1A_REG,4);
			if(timer_config->channels_number==BOTH_CHANNELS)
			{
				CLR_BIT(TCC1A_REG,2);
				DIO_u8setPinDirection(PORT_D, PIN_4, OUTPUT) ;/*OC1B->output*/
				SET_BIT(TCC1A_REG,5);/*channel B enable*/
				OCR1B_REG = timer_config->set_duty_cycle_timer1_ch_B ; /* Set Compare Value*/
			}
		}
		else if(timer_config->PWM_Mode == PHASE_CORRECT_PWM)
		{

			SET_BIT(TCC1B_REG,4);CLR_BIT(TCC1B_REG,3);SET_BIT(TCC1A_REG,1);CLR_BIT(TCC1A_REG,0);

			if(timer_config->channels_number==BOTH_CHANNELS)
			{
				CLR_BIT(TCC1A_REG,2);
				DIO_u8setPinDirection(PORT_D, PIN_4, OUTPUT) ;/*OC1B->output*/
				SET_BIT(TCC1A_REG,5);/*channel B enable*/
				OCR1B_REG = timer_config->set_duty_cycle_timer1_ch_B ; /* Set Compare Value*/
			}
		}
			/*select the clk (prescaler)to start counting */
			TCC1B_REG=(TCC1B_REG & 0b11111000)|(timer_config->T0_T1_used_freq&0b00000111 );
			break;
	case TIMER_2:
		clear_timer(TIMER_2); /* Set Timer Initial Value to 0*/
		OCR2_REG  = timer_config->set_duty_cycle/100; /* Set Compare Value*/
		/*Configure PD7/OC2 as output pin --> pin where the PWM signal is generated from MC*/
		DIO_u8setPinDirection(PORT_D, PIN_7, OUTPUT);
		/* Configure timer control register
		 * 1. Fast PWM mode FOC2=0
		 * 2. Fast PWM Mode WGM21=1 & WGM20=1
		 * 3. Clear OC2 when match occurs (non inverted mode) COM20=0 & COM21=1
		 * 4. clock = F_CPU/N
		 *
		 */
		CLR_BIT(TCC2_REG,7);
		if(timer_config->PWM_Mode == FAST_PWM)
		{
			TCC2_REG = (1<<3) | (1<<5) | (1<<6);
		}
		else if(timer_config->PWM_Mode == PHASE_CORRECT_PWM)
		{
			TCC2_REG = (0<<3) | (1<<5) | (1<<6);
		}
		/*select the clk (prescaler)to start counting */
		TCC2_REG=(TCC2_REG & 0b11111000)|(timer_config->T2_used_freq&0b00000111 );
		break;
		}

	}

    void Global_VidINTEnable(void)
	{
		SET_BIT(S_REG,7);
	}

	void Global_VidINTDisable(void)
	{
		CLR_BIT(S_REG,7);
	}

//	void Delay_voidBasyWaitMS(u16 Copy_u8Delay_ms)
//	{
//		/*
//		 *  Delay Function Using Timer2
//		 */
//		f64 Local_Counter=0;
//		f32 Req_Delay_Counts = Copy_u8Delay_ms/(f32)0.256; //Deviding the required delay time by OVF Time
//		TCC2_REG &= TIMER_PRE_SCALER_CLR_MUSK; // clear Timer2 control register
//		TCC2_REG = TIMER_2_PRE_SCALER_e_8; //set timer2 in normal mode with prescaler 8
//		while(Local_Counter<Req_Delay_Counts)
//		{
//			while(GET_BIT(TIF_REG,7)==0);
//			SET_BIT(TIF_REG,7);
//			Local_Counter++;
//		}
//		Local_Counter=0;
//	}

	//u8 Timer_u8SetPWMFreq_DutyCycle(u16 Copy_u16Freq,u8 Copy_u8Duty,u8 Copy_u8Channel,u8 Copy_u8PWM_Mode)
	//{
	//	u8 Local_u8errStatus = RT_OK;
	//	u16 PC_PWM_Freq;
	//	u16 Period_Time;
	//	u16 Comp_Match;
	//	switch(Copy_u8Channel)
	//	{
	//	case CHANNEL_0 :
	//		if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST)
	//		{
	//			Period_Time = 1/Copy_u16Freq;     //Get the Period time (OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR0_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_PHASE_CORRECT)
	//		{
	//			Period_Time = 2*(1/Copy_u16Freq);    //Get the Period time (2 OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR0_REG = Comp_Match;
	//		}
	//		else
	//		{
	//			Local_u8errStatus = RT_NOK;
	//		}
	//		break;
	//	case CHANNEL_1A :
	//		if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST)
	//		{
	//			Period_Time = 1/Copy_u16Freq;     //Get the Period time (OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR1A_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_PHASE_CORRECT)
	//		{
	//			Period_Time = 2*(1/Copy_u16Freq);    //Get the Period time (2 OVF Time) from Frequency
	//			Period_Time*=1000000;;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR1A_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST_ANY_FREQ)
	//		{
	//			Period_Time = 1/Copy_u16Freq;    //Get the Period time (OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			ICR1_REG = Period_Time;                 //Set Period time (of chosen frequency) in INPUT Capture REG
	//			Comp_Match = Copy_u8Duty*Period_Time;      //Get Compare_Match_value
	//			OCR1A_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST_ANY_FREQ)
	//		{
	//			Period_Time = 2*(1/Copy_u16Freq);   //Get the Period time (2 OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			ICR1_REG = Period_Time;              //Set Period time (of chosen frequency) in INPUT Capture REG
	//			Comp_Match = Copy_u8Duty*Period_Time;   //Get Compare_Match_value
	//			OCR1A_REG = Comp_Match;
	//		}
	//		else
	//		{
	//			Local_u8errStatus = RT_NOK;
	//		}
	//		break;
	//
	//	case CHANNEL_1B :
	//		if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST)
	//		{
	//			Period_Time = 1/Copy_u16Freq;     //Get the Period time (OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR1B_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_PHASE_CORRECT)
	//		{
	//			Period_Time = 2*(1/Copy_u16Freq);    //Get the Period time (2 OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR1B_REG= Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST_ANY_FREQ)
	//		{
	//			Period_Time = 1/Copy_u16Freq;    //Get the Period time (OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			ICR1_REG = Period_Time;                 //Set Period time (of chosen frequency) in INPUT Capture REG
	//			Comp_Match = Copy_u8Duty*Period_Time;      //Get Compare_Match_value
	//			OCR1B_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST_ANY_FREQ)
	//		{
	//			Period_Time = 2*(1/Copy_u16Freq);   //Get the Period time (2 OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			ICR1_REG = Period_Time;              //Set Period time (of chosen frequency) in INPUT Capture REG
	//			Comp_Match = Copy_u8Duty*Period_Time;   //Get Compare_Match_value
	//			OCR1B_REG = Comp_Match;
	//		}
	//		else
	//		{
	//			Local_u8errStatus = RT_NOK;
	//		}
	//		break;
	//
	//	case CHANNEL_2 :
	//		if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_FAST)
	//		{
	//			Period_Time = 1/Copy_u16Freq;     //Get the Period time (OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR2_REG = Comp_Match;
	//		}
	//		else if(Copy_u8PWM_Mode == TIMER_PWM_MODE_e_PHASE_CORRECT)
	//		{
	//			Period_Time = 2*(1/Copy_u16Freq);    //Get the Period time (2 OVF Time) from Frequency
	//			Period_Time*=1000000;
	//			Comp_Match = Copy_u8Duty*Period_Time; //Get Compare_Match_value
	//			OCR2_REG = Comp_Match;
	//		}
	//		else
	//		{
	//			Local_u8errStatus = RT_NOK;
	//		}
	//		break;
	//	default: Local_u8errStatus = RT_NOK;
	//	}
	//	return Local_u8errStatus;
	//
	//}
