/*
 * UART_reg.h
 *
 *  Created on: Apr 17, 2023
 *      Author: ranah
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_


#define UDR     (*(volatile u8*)0x2C)
#define UCSRA    (*(volatile u8*)0x2B)
#define UCSRB      (*(volatile u8*)0x2A)
#define UBRRL      (*(volatile u8*)0x29)
#define UCSRC      (*(volatile u8*)0x40)
#define UBRRH      (*(volatile u8*)0x40)


#endif /* MCAL_UART_UART_REG_H_ */
