/*
 * DIO_Prg.c
 *
 *  Created on: Sep 17, 2021
 *      Author: hp
 */
#include"../../LIB/stdtypes.h"
#include"../../LIB/BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#define RT_OK    (u8)   0
#define RT_NOK   (u8)   1
#define NULL     (void *)0


u8 DIO_u8setPortDirection(u8 Copy_u8port,u8 Copy_u8direction)
{   u8 Local_u8errStatus = RT_OK;
switch(Copy_u8port)
{
case PORT_A :DIOA->DDR = Copy_u8direction ;break ;
case PORT_B :DIOB->DDR = Copy_u8direction ;break ;
case PORT_C :DIOC->DDR = Copy_u8direction ;break ;
case PORT_D :DIOD->DDR = Copy_u8direction ;break ;
default : Local_u8errStatus = RT_NOK ;
}
return Local_u8errStatus;
}
u8 DIO_u8setPortValue(u8 Copy_u8port, u8 Copy_u8Value)
{ u8 Local_u8errStatus = RT_OK;
switch(Copy_u8port)
{
case PORT_A :DIOA->PORT = Copy_u8Value ;break ;
case PORT_B :DIOB->PORT = Copy_u8Value ;break ;
case PORT_C :DIOC->PORT = Copy_u8Value ;break ;
case PORT_D :DIOD->PORT = Copy_u8Value ;break ;
default : Local_u8errStatus = RT_NOK ;
}
return Local_u8errStatus;
}

u8 DIO_u8getPortValue(u8 Copy_u8port, u8 * Copy_u8pValue)
{u8 Local_u8errStatus = RT_OK;
if(Copy_u8pValue != NULL)
{
	switch(Copy_u8port)
	{
	case PORT_A : *Copy_u8pValue = DIOA->PIN ;break ;
	case PORT_B : *Copy_u8pValue = DIOB->PIN ;break ;
	case PORT_C : *Copy_u8pValue = DIOC->PIN ;break ;
	case PORT_D : *Copy_u8pValue = DIOD->PIN ;break ;
	default : Local_u8errStatus = RT_NOK ;
	}
}
else
{
	Local_u8errStatus = RT_NOK;
}
return Local_u8errStatus;
}

u8 DIO_u8setPinDirection(u8 Copy_u8port, u8 Copy_u8pin ,u8 Copy_u8direction)
{u8 Local_u8errStatus = RT_OK;
if(Copy_u8pin <=PIN_7)
{
	switch(Copy_u8direction)
	{
	case INPUT :
		switch(Copy_u8port)
		{
		case PORT_A : CLR_BIT(DIOA->DDR,Copy_u8pin);break;
		case PORT_B : CLR_BIT(DIOB->DDR,Copy_u8pin);break;
		case PORT_C : CLR_BIT(DIOC->DDR,Copy_u8pin);break;
		case PORT_D : CLR_BIT(DIOD->DDR,Copy_u8pin);break;
		default : Local_u8errStatus = RT_NOK;
		}
		break;
		case OUTPUT :
			switch(Copy_u8port)
			{
			case PORT_A : SET_BIT(DIOA->DDR,Copy_u8pin);break;
			case PORT_B : SET_BIT(DIOB->DDR,Copy_u8pin);break;
			case PORT_C : SET_BIT(DIOC->DDR,Copy_u8pin);break;
			case PORT_D : SET_BIT(DIOD->DDR,Copy_u8pin);break;
			default : Local_u8errStatus = RT_NOK;
			}
			break;
			default : Local_u8errStatus = RT_NOK;

	}
}
else
{
	Local_u8errStatus = RT_NOK;
}
return Local_u8errStatus;
}

u8 DIO_u8setPinValue(u8 Copy_u8port, u8 Copy_u8pin ,u8 Copy_u8value)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_u8pin <=PIN_7)
	{
		switch(Copy_u8value)
		{
		case LOW :
			switch(Copy_u8port)
			{
			case PORT_A : CLR_BIT(DIOA->PORT,Copy_u8pin);break;
			case PORT_B : CLR_BIT(DIOB->PORT,Copy_u8pin);break;
			case PORT_C : CLR_BIT(DIOC->PORT,Copy_u8pin);break;
			case PORT_D : CLR_BIT(DIOD->PORT,Copy_u8pin);break;
			default : Local_u8errStatus = RT_NOK;
			}
			break;
			case HIGH :
				switch(Copy_u8port)
				{
				case PORT_A : SET_BIT(DIOA->PORT,Copy_u8pin);break;
				case PORT_B : SET_BIT(DIOB->PORT,Copy_u8pin);break;
				case PORT_C : SET_BIT(DIOC->PORT,Copy_u8pin);break;
				case PORT_D : SET_BIT(DIOD->PORT,Copy_u8pin);break;
				default : Local_u8errStatus = RT_NOK;
				}
				break;
				default : Local_u8errStatus = RT_NOK;
		}

	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}
u8 DIO_u8togglePinValue(u8 Copy_u8port, u8 Copy_u8pin)
{

	u8 Local_u8errStatus = RT_OK;
	if(Copy_u8pin <=PIN_7)
	{

		switch(Copy_u8port)
		{
		case PORT_A : TOG_BIT(DIOA->PORT,Copy_u8pin);break;
		case PORT_B : TOG_BIT(DIOB->PORT,Copy_u8pin);break;
		case PORT_C : TOG_BIT(DIOC->PORT,Copy_u8pin);break;
		case PORT_D : TOG_BIT(DIOD->PORT,Copy_u8pin);break;
		default : Local_u8errStatus = RT_NOK;
		}
	}

	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;

}
u8 DIO_u8getPinValue(u8 Copy_u8port, u8 Copy_u8pin ,u8 * Copy_u8pValue)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_u8pValue != NULL)
	{
		if(Copy_u8pin <=PIN_7)
		{
			switch(Copy_u8port)
			{
			case PORT_A :* Copy_u8pValue=GET_BIT(DIOA->PIN,Copy_u8pin);break ;
			case PORT_B :* Copy_u8pValue=GET_BIT(DIOB->PIN,Copy_u8pin);break ;
			case PORT_C :* Copy_u8pValue=GET_BIT(DIOC->PIN,Copy_u8pin);break ;
			case PORT_D :* Copy_u8pValue=GET_BIT(DIOD->PIN,Copy_u8pin);break ;
			default : Local_u8errStatus = RT_NOK ;
			}
		}
		else
		{
			Local_u8errStatus = RT_NOK;
		}
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}

	return Local_u8errStatus;
}



