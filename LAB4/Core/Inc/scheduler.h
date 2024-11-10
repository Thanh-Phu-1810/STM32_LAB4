/*
 * scheduler.h
 *
 *  Created on: Nov 10, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;    //software_timer
	uint32_t Period;   //software_timer
	uint8_t RunMe;     //timer_flag

	uint32_t TaskID;
}sTasks;

#define SCH_MAX_TASKS  40   //so task toi da ho tro tren he thong nay


void SCH_Init(void);

void SCH_Add_Task( void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD); //setTimer

void SCH_Update(void);   //timerRun()

void SCH_Dispatch_Tasks(void);  //kiem tra cai timer_flag nen duoc kiem tra trong while(1)

void SCH_Delete(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
