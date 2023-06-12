/*
 * RTOS_interface.h
 *
 *  Created on: Apr 30, 2023
 *      Author: ranah
 */

#ifndef MCAL_RTOS_RTOS_INTERFACE_H_
#define MCAL_RTOS_RTOS_INTERFACE_H_

#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include "../../Comman/STD_types.h"
void RTOS_voidstart(void);
void RTOS_voidcreatetask(u8 copy_priority,u16 copy_periodicity, void (*copy_task)(void));

#endif /* MCAL_RTOS_RTOS_INTERFACE_H_ */
