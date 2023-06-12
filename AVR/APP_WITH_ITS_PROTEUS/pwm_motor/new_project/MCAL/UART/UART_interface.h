/*
 * UART_interface.c
 *
 *  Created on: Apr 17, 2023
 *      Author: ranah
 */

#ifndef MCAL_UART_UART_INTERFACE_C_
#define MCAL_UART_UART_INTERFACE_C_
#include "../../Comman/STD_types.h"
#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
void uart_init();
void uart_send();
u8 uart_receive();

#endif /* MCAL_UART_UART_INTERFACE_C_ */
