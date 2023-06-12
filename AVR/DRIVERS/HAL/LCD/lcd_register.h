/*
 * lcd_register.h
 *
 *  Created on: Mar 25, 2023
 *      Author: ranah
 */

#ifndef HAL_LCD_LCD_REGISTER_H_
#define HAL_LCD_LCD_REGISTER_H_


#define lcd_firstline 0x00
#define lcd_secondline 0x40

/*Set CG RAM Address*/
#define  LCD_SetAddressCGRAM      0x40
/*---------------------------------------------------------------------------------------------------*/

/*Set DDRAM Address*/
#define  LCD_SetAddressDDRAM      0x80 //command line not address
/*---------------------------------------------------------------------------------------------------*/

#endif /* HAL_LCD_LCD_REGISTER_H_ */
