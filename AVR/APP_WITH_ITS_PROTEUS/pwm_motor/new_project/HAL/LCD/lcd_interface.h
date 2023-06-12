/*
 * lcd_interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: ranah
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "../../Comman/STD_types.h"
#include "lcd_private.h"

void lcd_voidsendchar(u8 copy_char,lcd_info *lcd);
void lcd_voidsendnum(lcd_info* LCD , u8 Copy_u32Num);
void lcd_voidcgram(u8 *arr, u8 loc,lcd_info *lcd);
void lcd_voidclear( lcd_info *lcd);
void lcd_voidsendcommand(u8 copy_char,lcd_info *lcd);
void lcd_voidinit(lcd_info *lcd);
void lcd_voidsendstring(u8 *add_string, lcd_info *lcd);
void lcd_voidgoxy(lcd_info *lcd, u8 Local_XPosition,u8 Local_YPosition);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
