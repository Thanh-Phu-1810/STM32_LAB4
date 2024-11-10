/*
 * scheduler.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Thanh Phu
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
//	unsigned char i;
//	for(i = 0; i < SCH_MAX_TASKS; i++)
//	{
//		SCH_Delete(i);
//	}
	current_index_task = 0;

}
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
	if(current_index_task < SCH_MAX_TASKS)
	{
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period = PERIOD / 10;
		SCH_tasks_G[current_index_task].RunMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
	}
}
void SCH_Update(void)
{
//	for(int i = 0; i < current_index_task; i++)
//	{
//		if(SCH_tasks_G[i].Delay > 0)
//		{
//			SCH_tasks_G[i].Delay--;
//		}
//		else
//		{
//			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//			SCH_tasks_G[i].RunMe++;
//		}
//	}

	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].pTask)
		{
			if(SCH_tasks_G[i].Delay == 0)
			{
				SCH_tasks_G[i].RunMe++;
				if(SCH_tasks_G[i].Period > 0) //chu y cho nay
				{
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}
			}
			else
			{
				SCH_tasks_G[i].Delay--;
			}
		}
	}
}
void SCH_Dispatch_Tasks(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].RunMe > 0)
		{
			(*SCH_tasks_G[i].pTask)();
			SCH_tasks_G[i].RunMe--;
			if(SCH_tasks_G[i].Period == 0)
			{
				SCH_Delete(SCH_tasks_G[i].TaskID);
			}

		}
	}
}
void SCH_Delete(uint32_t ID)
{
	 SCH_tasks_G[ID].pTask = 0x0000;
	 SCH_tasks_G[ID]. Delay = 0;
	 SCH_tasks_G[ID]. Period = 0;
	 SCH_tasks_G[ID].RunMe = 0;
}
