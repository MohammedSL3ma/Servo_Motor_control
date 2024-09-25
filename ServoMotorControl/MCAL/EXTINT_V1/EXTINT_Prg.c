/*
 * EXTINT_Prg.c
 *
 *  Created on: Oct 11, 2021
 *      Author: hp
 */
#include"../../LIB/stdtypes.h"
#include"../../LIB/BIT_MATH.h"
#include "EXTINT_int.h"
#include "EXTINT_reg.h"

#define NULL     (void*) 0
#define RT_OK    (u8)   0
#define RT_NOK   (u8)   1
#define INT0_SC_CLR_MASK    (u8)0b11111100
#define INT1_SC_CLR_MASK    (u8)0b11110011
#define INT2_SC_CLR_MASK    (u8)0b10111111
volatile u8 Temp_Reg;
volatile u8 EN_Reg;


typedef struct{
	void (*EXTINT_0)(void);
	void (*EXTINT_1)(void);
	void (*EXTINT_2)(void);
}EXTINT_N_PTR;

EXTINT_N_PTR  EXTINT_ISR;


void Set_CallBack_EXTINT_0(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		EXTINT_ISR.EXTINT_0 = ptr;
	}
}
void __vector_1 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_1 (void)
{
	if(EXTINT_ISR.EXTINT_0 != NULL)
	{
		EXTINT_ISR.EXTINT_0();
	}
}

void Set_CallBack_EXTINT_1(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		EXTINT_ISR.EXTINT_1 = ptr;
	}
}
void __vector_2 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_2 (void)
{
	if(EXTINT_ISR.EXTINT_1 != NULL)
	{
		EXTINT_ISR.EXTINT_1();
	}
}

void Set_CallBack_EXTINT_2(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		EXTINT_ISR.EXTINT_2 = ptr;
	}
}
void __vector_3 (void)  __attribute__ ((signal,__INTR_ATTRS));
void __vector_3 (void)
{
	if(EXTINT_ISR.EXTINT_2 != NULL)
	{
		EXTINT_ISR.EXTINT_2();
	}
}

u8 EXTINT_u8Enable(u8 Copy_u8ExtInt)
{
	u8 Local_u8errStatus = RT_OK;
	S_REG |= GLOBAL_INTERRUPT_ENABLE;
	switch(Copy_u8ExtInt)
	{
	case INT_0 : GIC_REG |= INT0_EN ; break;
	case INT_1 : GIC_REG |= INT1_EN ; break;
	case INT_2 : GIC_REG |= INT2_EN ; break;
	default : Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus;
}

u8 EXTINT_u8Disable(u8 Copy_u8ExtInt)
{
	u8 Local_u8errStatus = RT_OK;

	switch(Copy_u8ExtInt)
	{
	case INT_0 : CLR_BIT(GIC_REG,6) ; break;
	case INT_1 : CLR_BIT(GIC_REG,7) ; break;
	case INT_2 : CLR_BIT(GIC_REG,5) ; break;
	case G_DIS : CLR_BIT(S_REG,7) ; break;
	default : Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}

u8 EXTINT_u8SenseCtrl(u8 Copy_u8ExtInt,u8 Copy_u8ISCStatus)
{
	u8 Local_u8errStatus = RT_OK;
	switch(Copy_u8ExtInt)
	{
	case INT_0 :
		Temp_Reg = MCUC_REG;
		Temp_Reg &= INT0_SC_CLR_MASK;
		Temp_Reg |= Copy_u8ISCStatus;
		MCUC_REG = Temp_Reg;
		break;
	case INT_1 :
		Temp_Reg = MCUC_REG;
		Temp_Reg &= INT1_SC_CLR_MASK;
		Temp_Reg |= Copy_u8ISCStatus;
		MCUC_REG = Temp_Reg;
		break;
	case INT_2 :
		Temp_Reg = MCUCS_REG;
		Temp_Reg &= INT2_SC_CLR_MASK;
		Temp_Reg |= Copy_u8ISCStatus;
		MCUCS_REG = Temp_Reg;
		break;
	default : Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}

