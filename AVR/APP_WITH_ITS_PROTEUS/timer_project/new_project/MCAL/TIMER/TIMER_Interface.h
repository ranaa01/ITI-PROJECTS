/*
 * TIMER_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_
#include "TIMER_Confg.h"
#include "../../Comman/STD_types.h"
#include "TIMER_Private.h"

void set_timer(timer_info *t);
void __vector_10(void)__attribute__((signal));
void __vector_11(void)__attribute__((signal));
void  TIMERS_SetCallBack(void(*Copy_pf)(void));

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
