/*
 * software_timer.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag;
extern int timer_counter;

extern int timer1_flag;
extern int timer1_counter;

extern int timer2_flag;
extern int timer2_counter;

extern int timer3_flag;
extern int timer3_counter;

extern int timer4_flag;
extern int timer4_counter;

extern int timer5_flag;
extern int timer5_counter;

extern int TIMER_CYCLE;
void setTimer(int time);
void setTimer1(int time);
void setTimer2(int time);
void setTimer3(int time);
void setTimer4(int time);
void setTimer5(int time);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
