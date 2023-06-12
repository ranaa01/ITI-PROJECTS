/*
 * UART_program.c
 *
 *  Created on: Apr 17, 2023
 *      Author: ranah
 */

#include "UART_reg.h"
#include "UART_interface.h"
#include "../../Comman/STD_types.h"
#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"

void uart_init()
{
	u8 ucsrc_value=0;
	Set_Bit(ucsrc_value, 1);
	Set_Bit(ucsrc_value, 7);
	Set_Bit(ucsrc_value, 2);
	UCSRC=ucsrc_value;
	UBRRL=51;
	Set_Bit(UCSRB, 4);
	Set_Bit(UCSRB, 3);

}

void uart_send(u8 data)
{
	while(Get_Bit(UCSRA,5)==0);

		UDR =data;


}
u8 uart_receive(){
	while(Get_Bit(UCSRA,7)==0);
		return UDR;
}
