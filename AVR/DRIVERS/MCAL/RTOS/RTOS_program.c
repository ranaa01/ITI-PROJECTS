/*
 * RTOS_program.c
 *
 *  Created on: Apr 30, 2023
 *      Author: ranah
 */

#include "../DIO/DIO_Interface.h"
#include "../TIMER/TIMER_interface.h"
#include "../../Comman/Bit_Math.h"
#include "../../Comman/definition.h"
#include "../../Comman/STD_types.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_conf.h"
#include<stdio.h>

task_t task[task_num]={{NULL}};
//void (*copy_task)(void)= NULL;
void RTOS_voidstart(void)
{
	timer_info t1 = {ctc, pre_64};

	TIMERS_SetCallBack(&voidscheduler);
	set_timer(&t1);
}
void RTOS_voidcreatetask(u8 copy_priority,u16 copy_periodicity, void (*copy_task)(void))
{
	task[copy_priority].periodicity = copy_periodicity;
	task[copy_priority].task = copy_task;


}
static void voidscheduler()
{
	static u16 local_tick_counter=0;
	static u8 task_counter=0;
	local_tick_counter++;
	for(task_counter=0;task_counter<task_num;task_counter++ )
	{
		if((local_tick_counter%task[task_counter].periodicity)==0)
		{
			if((task[task_counter].task)!=NULL)
			{
			task[task_counter].task();
			}

		}
	}
}
