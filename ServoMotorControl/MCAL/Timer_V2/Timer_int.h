/*
 * Timer_int.h
 *
 *  Created on: Nov 4, 2021
 *      Author: hp
 */

#ifndef MCAL_TIMER_V2_TIMER_INT_H_
#define MCAL_TIMER_V2_TIMER_INT_H_

#include "../../LIB/stdtypes.h"
/*
 *  OC0  = PB3
 *  OC1A = PD5
 *  OC1B = PD4
 *  OC2  = PD7
 */


/*
 * Timer 0 Group
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */
#define TIMER_0_F_PWM_FREQ_e_PRE_SCALER_1      (f32)  31250
#define TIMER_0_F_PWM_FREQ_e_PRE_SCALER_8      (f32)  3906.25
#define TIMER_0_F_PWM_FREQ_e_PRE_SCALER_64     (f32)  488.28125
#define TIMER_0_F_PWM_FREQ_e_PRE_SCALER_256    (f32)  122.0703125
#define TIMER_0_F_PWM_FREQ_e_PRE_SCALER_1024   (f32)  30.51757813

#define TIMER_0_PC_PWM_FREQ_e_PRE_SCALER_1     (f32)  15686.27451
#define TIMER_0_PC_PWM_FREQ_e_PRE_SCALER_8     (f32)  1960.784314
#define TIMER_0_PC_PWM_FREQ_e_PRE_SCALER_64    (f32)  245.0980392
#define TIMER_0_PC_PWM_FREQ_e_PRE_SCALER_256   (f32)  61.2745098
#define TIMER_0_PC_PWM_FREQ_e_PRE_SCALER_1024  (f32)  15.31862745


typedef enum
{
	TIMER_0_MODE_e_NORMAL,
	TIMER_0_MODE_e_PWM_PC,
	TIMER_0_MODE_e_CTC,
	TIMER_0_MODE_e_F_PWM
}TIMER_0_MODE_e;

typedef enum
{
	TIMER_0_OP_COM_MODE_NO_PWM_e_OC0_DIS,
	TIMER_0_OP_COM_MODE_NO_PWM_e_TOG_OC0,
	TIMER_0_OP_COM_MODE_NO_PWM_e_CLR_OC0,
	TIMER_0_OP_COM_MODE_NO_PWM_e_SET_OC0
}TIMER_0_OP_COM_MODE_NO_PWM_e;

typedef enum
{
	TIMER_0_OP_COM_MODE_F_AND_PC_PWM_e_DIS,
	TIMER_0_OP_COM_MODE_F_AND_PC_PWM_e_NON_INV,
	TIMER_0_OP_COM_MODE_F_AND_PC_PWM_e_INV

}TIMER_0_OP_COM_MODE_F_AND_PC_PWM_e;




void Set_CallBack_TIMER_0_OVF_INT(void (*ptr)(void));
void Set_CallBack_TIMER_0_OC_INT(void (*ptr)(void));
/*
 * Timer 1 Group
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */


#define TIMER_1_F_PWM_FREQ_e_PRE_SCALER_1      (f32)   122.0684499
#define TIMER_1_F_PWM_FREQ_e_PRE_SCALER_8      (f32)   15.25855624
#define TIMER_1_F_PWM_FREQ_e_PRE_SCALER_64     (f32)   1.907319529
#define TIMER_1_F_PWM_FREQ_e_PRE_SCALER_256    (f32)   0.4768298824
#define TIMER_1_F_PWM_FREQ_e_PRE_SCALER_1024   (f32)   0.1192074706

#define TIMER_1_PC_PWM_FREQ_e_PRE_SCALER_1     (f32)   64.03515625
#define TIMER_1_PC_PWM_FREQ_e_PRE_SCALER_8     (f32)   7.629394531
#define TIMER_1_PC_PWM_FREQ_e_PRE_SCALER_64    (f32)   0.953674316
#define TIMER_1_PC_PWM_FREQ_e_PRE_SCALER_256   (f32)   0.2384185791
#define TIMER_1_PC_PWM_FREQ_e_PRE_SCALER_1024  (f32)   0.05960464478




typedef enum
{
	TIMER_1_MODE_e_NORMAL,
	TIMER_1_MODE_e_PWM_PC_8_BIT,
	TIMER_1_MODE_e_PWM_PC_9_BIT,
	TIMER_1_MODE_e_PWM_PC_10_BIT,
	TIMER_1_MODE_e_CTC_OCR_1A,
	TIMER_1_MODE_e_F_PWM_8_BIT,
	TIMER_1_MODE_e_F_PWM_9_BIT,
	TIMER_1_MODE_e_F_PWM_10_BIT,
	TIMER_1_MODE_e_PWM_PFC_ICR1,
	TIMER_1_MODE_e_PWM_PFC_OCR_1A,
	TIMER_1_MODE_e_PWM_PC_ICR1,
	TIMER_1_MODE_e_PWM_PC_OCR_1A,
	TIMER_1_MODE_e_CTC_ICR1,
	TIMER_1_MODE_e_F_PWM_ICR1,
	TIMER_1_MODE_e_F_PWM_OCR_1A
}TIMER_1_MODE_e;

typedef enum
{
	TIMER_1_OP_COM_MODE_NO_PWM_e_OC1A_OC1B_DIS,
	TIMER_1_OP_COM_MODE_NO_PWM_e_TOG_OC1A_OC1B,
	TIMER_1_OP_COM_MODE_NO_PWM_e_CLR_OC1A_OC1B,
	TIMER_1_OP_COM_MODE_NO_PWM_e_SET_OC1A_OC1B
}TIMER_1_OP_COM_MODE_NO_PWM_e;

typedef enum
{
	TIMER_1_OP_COM_MODE_F_PWM_e_OC1A_OC1B_DIS,
	TIMER_1_OP_COM_MODE_F_PWM_e_TOG_OC1A_OC1B_DIS,
	TIMER_1_OP_COM_MODE_F_PWM_e_NON_INV,
	TIMER_1_OP_COM_MODE_F_PWM_e_INV
}TIMER_1_OP_COM_MODE_F_PWM_e;
typedef enum
{
	TIMER_1_OP_COM_MODE_PC_PFC_PWM_e_OC1A_OC1B_DIS,
	TIMER_1_OP_COM_MODE_PC_PFC_PWM_e_TOG_OC1A_OC1B_DIS,
	TIMER_1_OP_COM_MODE_PC_PFC_PWM_e_NON_INV,
	TIMER_1_OP_COM_MODE_PC_PFC_PWM_e_INV
}TIMER_1_OP_COM_MODE_PC_PFC_PWM_e;
typedef enum
{
	TIMER_1_INT_MODE_e_OVF_1A,
	TIMER_1_INT_MODE_e_OVF_1B,
	TIMER_1_INT_MODE_e_CTC_OCR1A,
	TIMER_1_INT_MODE_e_CTC_ICR1
}TIMER_1_INT_MODE_e;

typedef enum
{
	TIMER_1_REG_SEL_e_OCR1A,
	TIMER_1_REG_SEL_e_ICR1

}TIMER_1_REG_SEL_e;




void Set_CallBack_TIMER_1_OVF_INT(void (*ptr)(void));
void Set_CallBack_TIMER_1_OCA_INT(void (*ptr)(void));
void Set_CallBack_TIMER_1_OCB_INT(void (*ptr)(void));
void Set_CallBack_TIMER_1_CAPT_INT(void (*ptr)(void));

/*
 * Timer 2 Group
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */
#define TIMER_2_PC_PWM_FREQ_e_PRE_SCALER_1     (f32) 15686.27451
#define	TIMER_2_PC_PWM_FREQ_e_PRE_SCALER_8     (f32) 1960.784314
#define	TIMER_2_PC_PWM_FREQ_e_PRE_SCALER_32    (f32) 490.1960784
#define	TIMER_2_PC_PWM_FREQ_e_PRE_SCALER_64    (f32) 245.0980392
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_128    (f32) 122.5490196
#define	TIMER_2_PC_PWM_FREQ_e_PRE_SCALER_256   (f32) 61.2745098
#define	TIMER_2_PC_PWM_FREQ_e_PRE_SCALER_1024  (f32) 15.31862745

#define TIMER_2_F_PWM_FREQ_e_PRE_SCALER_1      (f32) 31250
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_8      (f32) 3906.25
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_32     (f32) 976.5625
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_64     (f32) 488.28125
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_128    (f32) 244.140625
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_256    (f32) 122.0703125
#define	TIMER_2_F_PWM_FREQ_e_PRE_SCALER_1024   (f32) 30.51757813

typedef enum
{
	TIMER_2_MODE_e_NORMAL,
	TIMER_2_MODE_e_PWM_PC,
	TIMER_2_MODE_e_CTC,
	TIMER_2_MODE_e_F_PWM
}TIMER_2_MODE_e;
typedef enum
{
	TIMER_2_OP_COM_MODE_NO_PWM_e_OC2_DIS,
	TIMER_2_OP_COM_MODE_NO_PWM_e_TOG_OC2,
	TIMER_2_OP_COM_MODE_NO_PWM_e_CLR_OC2,
	TIMER_2_OP_COM_MODE_NO_PWM_e_SET_OC2
}TIMER_2_OP_COM_MODE_NO_PWM_e;
typedef enum
{
	TIMER_2_OP_COM_MODE_F_AND_PC_PWM_e_DIS,
	TIMER_2_OP_COM_MODE_F_AND_PC_PWM_e_NON_INV,
	TIMER_2_OP_COM_MODE_F_AND_PC_PWM_e_INV

}TIMER_2_OP_COM_MODE_F_AND_PC_PWM_e;
typedef enum
{
	TIMER_2_PRE_SCALER_e_NO_CLK,
	TIMER_2_PRE_SCALER_e_NO_PRE,
	TIMER_2_PRE_SCALER_e_8,
	TIMER_2_PRE_SCALER_e_32,
	TIMER_2_PRE_SCALER_e_64,
	TIMER_2_PRE_SCALER_e_128,
	TIMER_2_PRE_SCALER_e_256,
	TIMER_2_PRE_SCALER_e_1024
}TIMER_2_PRE_SCALER_e;


void Set_CallBack_TIMER_2_OVF_INT(void (*ptr)(void));
void Set_CallBack_TIMER_2_OC_INT(void (*ptr)(void));

/*
 * Common Functions
 */
/*
 *
 *
 * -----------------------------------------------------------------------------------------------------------
 */


typedef enum {
	NORMAL_MODE,
	CTC_MODE,
	FAST_PWM,
	PHASE_CORRECT_PWM
}MODE_e;

typedef enum
{
	CHANNEL_1A,
	CHANNEL_1B,
	BOTH_CHANNELS
}TIMER_1_CHANNEL_e;

typedef enum
{
	TIMER_0_1_PRE_SCALER_e_NO_CLK,
	TIMER_0_1_PRE_SCALER_e_NO_PRE,
	TIMER_0_1_PRE_SCALER_e_8,
	TIMER_0_1_PRE_SCALER_e_64,
	TIMER_0_1_PRE_SCALER_e_256,
	TIMER_0_1_PRE_SCALER_e_1024,
	TIMER_0_1_PRE_SCALER_e_EXT_CLK_FALL_EDGE,
	TIMER_0_1_PRE_SCALER_e_EXT_CLK_RISE_EDGE
}TIMER_0_1_PRE_SCALER_e;


typedef enum
{
	TIMER_0_2_INT_MODE_e_OVF,
	TIMER_0_2_INT_MODE_e_CTC
}TIMER_0_2_INT_MODE_e;

typedef enum
{
	TIMER_0,
	TIMER_1,
	TIMER_2,
	ALL
}TIMER_e;

typedef enum
{
	TIMER_PWM_MODE_e_FAST,
	TIMER_PWM_MODE_e_PHASE_CORRECT,
	TIMER_PWM_MODE_e_FAST_ANY_FREQ,
	TIMER_PWM_MODE_e_PHASE_CORRECT_ANY_FREQ
}TIMER_PWM_MODE_e;

typedef struct
{
	u16 timer1_TOP_value;
	u16 set_duty_cycle;
	u16 set_duty_cycle_timer1_ch_B;
	TIMER_0_1_PRE_SCALER_e T0_T1_used_freq;/* must be set at all modes of operation  */
	TIMER_2_PRE_SCALER_e T2_used_freq;/* must be set at all modes of operation  */
	MODE_e PWM_Mode;
	TIMER_e timer;
	TIMER_1_REG_SEL_e reg_sel;
	TIMER_1_CHANNEL_e channels_number;
}PWM_timers_config;

typedef struct
{
	u16 compared_value ;
	u16 compared_value_B_channel ;
	u16 initial_value  ;
	TIMER_0_1_PRE_SCALER_e T0_T1_used_freq ;/* must be set at all modes of operation  */
	TIMER_2_PRE_SCALER_e T2_used_freq ;/* must be set at all modes of operation  */
	MODE_e operated_mode ;
	TIMER_e timer    ;
	TIMER_1_CHANNEL_e channels_number ;

}timer_config_type;

typedef struct{

	u16 Copy_u16Freq;
	u16 Copy_u16Duty_Cycle;
	u8 Copy_u8_PWM_Mode;
	u8 Copy_u8PreScaler;
	u8 Copy_u8Channel;
}TIMER_PWM_FREQ_DUTY_ARGU;


void Delay_voidBasyWaitMS(u16 Copy_u8Delay_ms);
void Global_VidINTEnable(void);
void Global_VidINTDisable(void);
void Timer_init(timer_config_type * timer_config_ptr);
void PWM_timers_init(PWM_timers_config * timer_config);
void clear_timer(TIMER_e timer);
void Timer_DeInit(TIMER_e timer);
void change_compared_and_duty_value(timer_config_type * config_ptr);

#endif /* MCAL_TIMER_V2_TIMER_INT_H_ */
