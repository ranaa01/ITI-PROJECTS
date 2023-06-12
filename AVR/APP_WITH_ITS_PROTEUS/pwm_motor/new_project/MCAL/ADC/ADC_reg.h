/*
 * ADC_reg.h
 *
 *  Created on: Apr 15, 2023
 *      Author: ranah
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

#define ADMUX     (*(volatile u8*)0x27)
#define ADCSRA    (*(volatile u8*)0x26)
#define ADCH      (*(volatile u8*)0x25)
#define ADCL      (*(volatile u8*)0x24)

#endif /* MCAL_ADC_ADC_REG_H_ */
