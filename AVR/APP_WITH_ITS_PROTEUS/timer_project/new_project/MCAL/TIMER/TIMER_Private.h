/*
 * TIMER_Private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ranah
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_


typedef enum
{
	normal,
	ctc,
	PWM_PHASE_CORRECT,
	PWM_FAST

}timer_type;
typedef enum
{
	PWM_inverting_mode,
	PWM_nin_inverting_mode

}PWM_Type;

typedef enum
{
	pre_8,
	pre_64,
	pre_256,
	pre_1024
}prescaler_type;

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
