/*
 * ADC_program.c
 *
 *  Created on: Apr 15, 2023
 *      Author: ranah
 */
#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include "../../Comman/STD_types.h"
#include "ADC_reg.h"
#include "ADC_interface.h"
void adc_init()
{
	Set_Bit(ADMUX,6);
	Clr_Bit(ADMUX,7);
	Set_Bit(ADMUX,5);
	Set_Bit(ADCSRA,7);
}
u8 adc_readingchannel(u8 copy_channel)
{

}

