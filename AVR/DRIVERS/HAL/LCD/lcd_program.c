/*
 * lcd_program.c

 *
 *  Created on: Mar 25, 2023
 *      Author: ranah
 */


#include "lcd_interface.h"
#include <util/delay.h>
void lcd_voidsendcommand(u8 copy_command,lcd_info *lcd)
{
	/*rs->low*/
	DIO_ErrStateSetPinValue(lcd->rs_g, lcd->rs_p, DIO_Low);
	/*rw->low*/
	DIO_ErrStateSetPinValue(lcd->rw_g, lcd->rw_p, DIO_Low);
	//group==command
	DIO_ErrStateSetGroupValue(lcd->data_g, copy_command);
	//enable
	DIO_ErrStateSetPinValue(lcd->e_g, lcd->e_p, DIO_High);
	_delay_ms(1);
	DIO_ErrStateSetPinValue(lcd->e_g, lcd->e_p, DIO_Low);
	_delay_ms(1);

}
void lcd_voidgoxy(lcd_info *lcd, u8 Local_XPosition,u8 Local_YPosition)
{
	u8 l_add=0;
	if(Local_XPosition == 0)
	{
		l_add= Local_YPosition;
	}
	else if(Local_XPosition == 1)
	{
		l_add= Local_YPosition+ 0x40;
	}
	lcd_voidsendcommand(0x80+l_add,lcd);
}
void lcd_voidsendchar(u8 copy_char,lcd_info *lcd)
{
    	/*rs->high*/
		DIO_ErrStateSetPinValue(lcd->rs_g, lcd->rs_p, DIO_High);
		/*rw->low*/
		DIO_ErrStateSetPinValue(lcd->rw_g, lcd->rw_p, DIO_Low);
		//group==command
		DIO_ErrStateSetGroupValue(lcd->data_g, copy_char);
		//enable
		DIO_ErrStateSetPinValue(lcd->e_g, lcd->e_p, DIO_High);
		_delay_ms(1);
		DIO_ErrStateSetPinValue(lcd->e_g, lcd->e_p, DIO_Low);
		_delay_ms(1);
}
void lcd_voidcgram(u8 *arr, u8 loc, lcd_info *lcd)
{
	 lcd_voidsendchar(loc,lcd);
	lcd_voidsendcommand(0x40+(loc*8),lcd);
	for (int i=0; i<8; i++)
		{
			lcd_voidsendchar(arr[i],lcd);

		}

}
void lcd_voidsendnum(lcd_info* LCD , u8 Copy_u32Num)
	{
	u8 Revers_num = 0;
	u8 displayed_num = 0;
	u8 multiplier = 1, i = 0;
	if (Copy_u32Num == 0)
	{
		lcd_voidsendchar ('0',LCD);
	}

	while(Copy_u32Num != 0)
	{
	Revers_num = (Revers_num * 10) + Copy_u32Num % 10;
	if (Revers_num == 0)
	multiplier *= 10;
	Copy_u32Num /= 10;
	if (Copy_u32Num==0)
	{
		break;
	}
	}
	while (Revers_num != i)
	{
	displayed_num = Revers_num % 10;
	lcd_voidsendchar (displayed_num + 48 ,LCD); //48 -> '0' Revers_num/=10;
	if (Revers_num == 0 && multiplier >= 10)
	{
	i = 1;
	Revers_num = multiplier;
	}
	}
}
void lcd_voidsendstring(u8 *add_string, lcd_info *lcd)
{
	u8 l_c=0;
	while(add_string[l_c]!='\0')
	{
		lcd_voidsendchar(add_string[l_c],lcd);
		l_c++;
	}

}
void lcd_voidclear( lcd_info *lcd)
{
	DIO_ErrStateSetPinValue(lcd->rs_g, lcd->rs_p, DIO_Low);
		/*rw->low*/
		DIO_ErrStateSetPinValue(lcd->rw_g, lcd->rw_p, DIO_Low);
		//group==command
		DIO_ErrStateSetGroupValue(lcd->data_g, 0x01);
		//enable
		DIO_ErrStateSetPinValue(lcd->e_g, lcd->e_p, DIO_High);
		_delay_ms(1);
		DIO_ErrStateSetPinValue(lcd->e_g, lcd->e_p, DIO_Low);
		_delay_ms(1);

}
void lcd_voidinit(lcd_info *lcd)
{
	//set direction
	DIO_ErrStateSetPinDirection(lcd->rs_g, lcd->rs_p, DIO_Output);
	DIO_ErrStateSetPinDirection(lcd->rw_g, lcd->rw_p, DIO_Output);
	DIO_ErrStateSetPinDirection(lcd->e_g, lcd->e_p, DIO_Output);
	DIO_ErrStateSetGroupDirection(lcd->data_g,0xFF);
	_delay_ms(40);
	//sent fun set
    lcd_voidsendcommand(LCD_Set8Bit2Line5x8,lcd);
	_delay_ms(1);
	//display on/of
	 lcd_voidsendcommand( LCD_DisplayON,lcd);
	_delay_ms(1);
	 lcd_voidsendcommand( LCD_ClearDisplay,lcd);
		_delay_ms(2);


}
