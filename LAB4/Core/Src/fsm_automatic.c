/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "fsm_automatic.h"

int led7_seg[3] = {5, 2, 3}; //5s là đỏ, 2s là vàng, 3s là xanh
int led_blinky = 0;
int temp_led1 = 0;
int temp_led2 = 0;

int x = 0, y = 0, z = 0;
void fsm_automatic_run()
{

	switch(status)
	{
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, RESET);
			x = led7_seg[0];
		    y = led7_seg[1];
			z = led7_seg[2];
			status = AUTO_RED_GREEN;
			setTimer(1000);
			setTimer1(250);
			isButtonPressed1();
			isButtonPressed2();
			isButtonPressed3();
			break;
		case AUTO_RED_GREEN:
			led_red_and_green();

			if(isButtonPressed1() == 1) // chuyển sang manual
			{
				status = MODE_LED_RED;
				clearAllLed();
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			if(timer1_flag == 1)
			{
				display7SEG_AUTO();
				setTimer1(250);
			}

            if(timer_flag == 1)
			{
            	x--;
            	z--;
				setTimer(1000);
				if(z == 0)
				{
					status = AUTO_RED_YELLOW;
					z = led7_seg[2];
				}
			}
			break;
		case AUTO_RED_YELLOW:
			led_red_and_yellow();
			if(isButtonPressed1() == 1) // chuyển sang manual
			{
				status = MODE_LED_RED;
				clearAllLed();
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			if(timer1_flag == 1)
			{
				display7SEG_AUTO();
				setTimer1(250);
			}
			if(timer_flag == 1)
			{
				x--;
				y--;
				setTimer(1000);
				if(x == 0)
				{
					status = AUTO_GREEN_RED;
					x = led7_seg[0];
					y = led7_seg[1];
				}

			}
			break;
		case AUTO_GREEN_RED:
			led_green_and_red();
			if(isButtonPressed1() == 1) // chuyển sang manual
			{
				status = MODE_LED_RED;
				clearAllLed();
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			if(timer1_flag == 1)
			{
				display7SEG_AUTO();
				setTimer1(250);
			}
			if(timer_flag == 1)
			{
				x--;
				z--;
				setTimer(1000);
				if(z == 0)
				{
					status = AUTO_YELLOW_RED;
					z = led7_seg[2];
				}
			}
			break;
		case AUTO_YELLOW_RED:
			led_yellow_and_red();
			if(isButtonPressed1() == 1) // chuyển sang manual
			{
				status = MODE_LED_RED;
				clearAllLed();
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
			}
			if(timer1_flag == 1)
			{
				display7SEG_AUTO();
				setTimer1(250);
			}
			if(timer_flag == 1)
			{
				x--;
				y--;
				setTimer(1000);
				if(x == 0)
				{
					status = AUTO_RED_GREEN;
					x = led7_seg[0];
					y = led7_seg[1];
				}
			}
			break;
		default:
			break;

	}
}
void display7SEG_AUTO()
{
	if(status == AUTO_RED_GREEN || status == AUTO_RED_YELLOW || status == AUTO_GREEN_RED || status == AUTO_YELLOW_RED)
		{
			temp_led1 = (status == AUTO_RED_GREEN || status == AUTO_RED_YELLOW) ? x : (status == AUTO_GREEN_RED) ? z : (status == AUTO_YELLOW_RED) ? y : 0;
			temp_led2 = (status == AUTO_RED_GREEN) ? z : (status == AUTO_RED_YELLOW) ? y : (status == AUTO_GREEN_RED || status == AUTO_YELLOW_RED) ? x : 0;
			switch(led_blinky)
			{
				case 0:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, RESET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, SET);
					display7SEG1(temp_led1 / 10);
					display7SEG2(temp_led2 / 10);
					led_blinky = 1;
					break;
				case 1:
					HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, SET);
					HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, RESET);
					display7SEG1(temp_led1 % 10);
					display7SEG2(temp_led2 % 10);
					led_blinky = 0;
					break;
			}
		}
}
void clearAllLed()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin, RESET);
}
