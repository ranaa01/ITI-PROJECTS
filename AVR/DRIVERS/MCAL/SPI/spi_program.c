/*
 * spi_program.c
 *
 *  Created on: Apr 19, 2023
 *      Author: ranah
 */
#include "spi_interface.h"
#include "spi_reg.h"
#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
void mstr_init()
{
	Set_Bit(SPCR,4);
	Set_Bit(SPCR,1);
	Clr_Bit(SPCR,0);
	Clr_Bit(SPSR,0);

	Set_Bit(SPCR,6);
}
void slave_init(){
	Clr_Bit(SPCR,4);
	Set_Bit(SPCR,6);
}
u8 send_recieve(u8 data)
{
	SPDR = data;
	while(Get_Bit(SPSR,7)==0);
	return SPDR;

}
