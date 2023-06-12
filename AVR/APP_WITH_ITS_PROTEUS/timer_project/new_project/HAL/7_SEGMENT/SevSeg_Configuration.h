/*
 * SevSeg_Configuration.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#define HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#include "SevSeg_Private.h"
#include "../../MCAL/DIO/DIO_Private.h"
typedef struct
{
	SevSeg_Type SevSeg_Type1;
	DIO_GroupNumber SevSeg_Group;

}SevSeg_info;


#endif /* HAL_SEVSEG_SEVSEG_CONFIGURATION_H_ */
