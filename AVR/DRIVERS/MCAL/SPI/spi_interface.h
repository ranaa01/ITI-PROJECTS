/*
 * spi_interface.h
 *
 *  Created on: Apr 19, 2023
 *      Author: ranah
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "../../Comman/STD_types.h"
void mstr_init();
void slave_init();
u8 send_recieve(u8 data);
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
