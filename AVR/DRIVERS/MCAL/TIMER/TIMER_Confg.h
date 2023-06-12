/*
 * TIMER_Confg.h
 *
 *  Created on: Apr 2, 2023
 *      Author: ranah
 */

#ifndef MCAL_TIMER_TIMER_CONFG_H_
#define MCAL_TIMER_TIMER_CONFG_H_
#include "TIMER_Private.h"
typedef struct
{
timer_type    t_type;
prescaler_type pre_type;
}timer_info;
typedef struct
{
PWM_Type    PWM_type;
PWM_inv_Type    PWM_inv_type;
prescaler_type pre_type;
}PWM_info;


#endif /* MCAL_TIMER_TIMER_CONFG_H_ */
