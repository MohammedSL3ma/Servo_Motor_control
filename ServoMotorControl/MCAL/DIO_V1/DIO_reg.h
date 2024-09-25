/*
 * DIO_reg.h
 *
 *  Created on: Sep 17, 2021
 *      Author: hp
 */
#ifndef MCAL_DIO_V1_DIO_REG_H_
#define MCAL_DIO_V1_DIO_REG_H_

/* Dereferencing the address 0X3A which is casted as char* to equlize it with the value
   that the user wants to access the register with */
typedef struct{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}PORT_t;
#define DIOA    	((volatile PORT_t*)0X39)
#define DIOB    	((volatile PORT_t*)0X36)
#define DIOC	    ((volatile PORT_t*)0X33)
#define DIOD    	((volatile PORT_t*)0X30)

#endif /* MCAL_DIO_V1_DIO_REG_H_ */
