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
void lcd_voidsendnum(float copy_num,lcd_info *lcd)
{
	int i =0;
	int number_of_digits =3;
	//float number = (float)copy_num;
			//	u16 z = copy_num;
				 int ipart = (int)copy_num;
				 int ipart_for_digits = (int)copy_num;
				 float fpart = (float)copy_num - (float)ipart;
			// float fpart_for_digits = copy_num - (float)ipart;
			/* fpart_for_digits = fpart_for_digits *100.0;
				 //getting the number of digits after the point
			while (fpart_for_digits) {
					number_of_digits++;
				        fpart_for_digits /= 10;
				    }*/
				while (ipart_for_digits) {
				    i++;
				    ipart_for_digits /= 10;
			    }
				u16 arr_of_ipart[i+ number_of_digits+1];
				u16 arr_of_fpart[i+ number_of_digits+1];
				u16 arr1[i+ number_of_digits+1];
				int r =0;
							while (ipart)
							{
								arr_of_ipart[++r] = ipart % 10 + '0';
								ipart /= 10;
							    }
							u16 j;
							for ( j = 0; j < i; j++) {
							        arr1[j] = arr_of_ipart[i - j];
							    }
							 arr1[i]= '\0';

int n =number_of_digits+1;
long double result=1.0;
				 if ((number_of_digits+1) != 0) {
				        arr1[i] = '.';
				        while (n != 0) {
				        	result = result * 10;
				                --n;
				            }
				        fpart = fpart * result;
				     r =0;
				     int z = (int)fpart;
				        while (z)
							{
								arr_of_fpart[++r] = z % 10 + '0';
								//++r;
								z /= 10;
							    }
							int s;
							int a=0;
							int d=0;
							for ( s = i+1; s < (i+number_of_digits+1); s++) {
							        arr1[s] = arr_of_fpart[(number_of_digits+1)-a];
							        a=a+1;

							    }
							 arr1[i+number_of_digits+1]= '\0';
				    }

				int l_c=0;
					while(arr1[l_c]!='\0')
					{
						lcd_voidsendchar(arr1[l_c],lcd);
						l_c++;
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
