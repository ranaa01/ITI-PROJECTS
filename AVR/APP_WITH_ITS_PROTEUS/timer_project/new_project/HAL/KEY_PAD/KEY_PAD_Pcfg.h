/*
 * KEY_PAD_Pcfg.h
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */

#ifndef HAL_KEY_PAD_KEY_PAD_PCFG_H_
#define HAL_KEY_PAD_KEY_PAD_PCFG_H_

#include"../../Comman/STD_types.h"
#include"../../Comman/Bit_Math.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#define KEY_PAD_ROWSIZE  4
#define KEY_PAD_COLSIZE  4

#define TRUE                       1
#define FALSE                       0



u8 KEY_PAD_values[KEY_PAD_ROWSIZE][KEY_PAD_COLSIZE]={

		                                          //col0 col1 col2 col3
		                                          {'7','4','1','.'},//row0
		                                          {'8','5','2','0'},//row1
		                                          {'9','6','3','='},//row2
		                                          {'/','*','-','+'}//row3   //s for select
};


//in case I dont have a complete port for the KEYPAD
//WE CREATE A 2D ARRAY TO PLACE THE PORT AND PIN FOR EACH SWITCH

#define KEY_PAD_ROW0  {Pin0}
#define KEY_PAD_ROW1  {Pin1}
#define KEY_PAD_ROW2  {Pin2}
#define KEY_PAD_ROW3  {Pin3}
#define KEY_PAD_COL0  {Pin4}
#define KEY_PAD_COL1  {Pin5}
#define KEY_PAD_COL2  {Pin6}
#define KEY_PAD_COL3  {Pin7}


#define KEY_PAD_ARRAY  {KEY_PAD_ROW0,\
	                    KEY_PAD_ROW1,\
                         KEY_PAD_ROW2,\
                         KEY_PAD_ROW3,\
                         KEY_PAD_COL0,\
                          KEY_PAD_COL1,\
                           KEY_PAD_COL2,\
                           KEY_PAD_COL3}\








#endif /* HAL_KEY_PAD_KEY_PAD_PCFG_H_ */
