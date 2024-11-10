/*
 * software_timer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "software_timer.h"

int timer_flag = 0;
int timer_counter = 0;

int timer1_flag = 0;
int timer1_counter = 0;

int timer2_flag = 0;
int timer2_counter = 0;

int timer3_flag = 0;
int timer3_counter = 0;

int timer4_flag = 0;
int timer4_counter = 0;

int timer5_flag = 0;
int timer5_counter = 0;

int TIMER_CYCLE = 10;
void setTimer(int time)
{
	timer_counter =  time / TIMER_CYCLE;
	timer_flag = 0;
}
void setTimer1(int time)
{
	timer1_counter = time / TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int time)
{
	timer2_counter = time / TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer3(int time)
{
	timer3_counter = time / TIMER_CYCLE;
	timer3_flag = 0;
}
void setTimer4(int time)
{
	timer4_counter = time / TIMER_CYCLE;
	timer4_flag = 0;
}
void setTimer5(int time)
{
	timer5_counter = time / TIMER_CYCLE;
	timer5_flag = 0;
}
void timerRun()
{
	if(timer_counter > 0)
	{
		timer_counter--;
		if(timer_counter <= 0)
		{
			timer_flag = 1;
		}
	}

	if(timer1_counter > 0)
		{
			timer1_counter--;
			if(timer1_counter <= 0)
			{
				timer1_flag = 1;
			}
		}

	if(timer2_counter > 0)
		{
			timer2_counter--;
			if(timer2_counter <= 0)
			{
				timer2_flag = 1;
			}
		}

	if(timer3_counter > 0)
		{
			timer3_counter--;
			if(timer3_counter <= 0)
			{
				timer3_flag = 1;
			}
		}

	if(timer4_counter > 0)
		{
			timer4_counter--;
			if(timer4_counter <= 0)
			{
				timer4_flag = 1;
			}
		}

	if(timer5_counter > 0)
	{
		timer5_counter--;
		if(timer5_counter <= 0)
		{
			timer5_counter = 1;
		}
	}
}
