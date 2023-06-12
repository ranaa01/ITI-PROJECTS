/*
 * TIMER_Reg.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */

#ifndef MCAL_TIMER_TIMER_REG_H_
#define MCAL_TIMER_TIMER_REG_H_


#define Timer_Counter_Control_Register_TCCR0   *((volatile u8*)0x53)
#define Timer_Counter_Register_TCNT0   *((volatile u8*)0x52)
#define Output_Compare_Register_OCR0    *((volatile u8*)0x5C)
#define Timer_Counter_Interrupt_Flag_Register_TIFR    *((volatile u8*)0x58)
#define TIMSK  *((volatile u8*)0x59)
#define EXTI_SREG     (*(volatile u8*)0x5F)


#endif /* MCAL_TIMER_TIMER_REG_H_ */
