/*
 * RTOS_private.h
 *
 *  Created on: Apr 30, 2023
 *      Author: ranah
 */

#ifndef MCAL_RTOS_RTOS_PRIVATE_H_
#define MCAL_RTOS_RTOS_PRIVATE_H_
#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include "../../Comman/STD_types.h"
typedef struct
{
	u16 periodicity;
	void (*task)(void);
}task_t;
static void voidscheduler();

#endif /* MCAL_RTOS_RTOS_PRIVATE_H_ */
