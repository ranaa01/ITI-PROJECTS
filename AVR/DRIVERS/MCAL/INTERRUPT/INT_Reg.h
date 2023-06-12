/*
 * INT_Reg.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */

#ifndef MCAL_INTERRUPT_INT_REG_H_
#define MCAL_INTERRUPT_INT_REG_H_

#define EXTI_GICR       (*(volatile u8*)0x5B)
#define EXTI_GIFR       (*(volatile u8*)0x5A)
#define EXTI_MCUCR		(*(volatile u8*)0x55)
#define EXTI_MCUCSR    	(*(volatile u8*)0x54)
#define EXTI_SREG       (*(volatile u8*)0x5F)

#endif /* MCAL_INTERRUPT_INT_REG_H_ */
