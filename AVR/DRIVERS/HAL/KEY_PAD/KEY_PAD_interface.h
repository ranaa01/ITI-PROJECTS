/*
 * KEY_PAD_interface.h
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */

#ifndef HAL_KEY_PAD_KEY_PAD_INTERFACE_H_
#define HAL_KEY_PAD_KEY_PAD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include"../../Comman/STD_types.h"
#include"../../Comman/Bit_Math.h"


#define TRUE  1
#define FLASE 0

void KEY_pad_voidinit(void);
void Key_Pad_u8GetButtonPressed(u8 *result);









#endif /* HAL_KEY_PAD_KEY_PAD_INTERFACE_H_ */
