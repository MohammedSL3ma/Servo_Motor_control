/*
 * KeyBad_int.h
 *
 *  Created on: Sep 24, 2021
 *      Author: hp
 */

#ifndef HAL_KEYPAD_HANDLER_KEYPAD_INT_H_
#define HAL_KEYPAD_HANDLER_KEYPAD_INT_H_

void KEYPAD_vidInit(void);
//u8 KEYPAD_u8IsPressed(u8 Copy_u8SwitchID);
u8 KEYPAD_u8GetPressed(void);
//u8* KEYPAD_u8pGetAll(void);



#endif /* HAL_KEYPAD_HANDLER_KEYPAD_INT_H_ */
