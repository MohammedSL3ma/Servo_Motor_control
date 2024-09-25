/*
 * LCD_int.h
 *
 *  Created on: Sep 18, 2021
 *      Author: hp
 */

#ifndef HAL_LCD_HANDLER_LCD_INT_H_
#define HAL_LCD_HANDLER_LCD_INT_H_

void LCD_4_BitvidInit(void);
void LCD_8_BitvidInit(void);

void LCD_4_BitvidwriteInt(u32 copy_u8number);
void LCD_4_BitvidsendCommand(u8 Copy_u8command);
void LCD_4_BitvidwriteCharacter(u8 Copy_u8character);
void LCD_4_BitvidwriteString(const char* Copy_p2cString);
void LCD_4_BitvidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos);

void LCD_8_BitvidwriteInt(u32 copy_u8number);
void LCD_8_BitvidsendCommand(u8 Copy_u8command);
void LCD_8_BitvidwriteCharacter(u8 Copy_u8character);
void LCD_8_BitvidwriteString(const char* Copy_p2cString);
void LCD_8_BitvidGoToXY(u8 Copy_u8XPos , u8 Copy_u8YPos);
void LCD_8_BitvidwriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos , u8 Copy_u8YPos);

#endif /* HAL_LCD_HANDLER_LCD_INT_H_ */
