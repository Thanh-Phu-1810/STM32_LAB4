/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Thanh Phu
 */

#include "fsm_manual.h"
int temp_red = 5;
int temp_yellow = 2;
int temp_green = 3;
int led_blinky1 = 0;

int display_led = 5;
int tmp = 1;
void fsm_manual_run()
{
	switch(status)
	{
		case MODE_LED_RED:
			if(timer3_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, LED_1_Pin | LED_4_Pin);

				setTimer3(500);
			}
			if(isButtonPressed2() == 1)
			{
				temp_red++;
				display_led = temp_red;

			}
			if(isButtonPressed3() == 1)
			{
				if(temp_red == temp_green + temp_yellow)
				{
					led7_seg[0] = temp_red;
					led7_seg[1] = temp_yellow;
					led7_seg[2] = temp_green;
				}
			}
			if(timer4_flag == 1)
			{
				display7SEG_MAN();
				setTimer4(250);
			}

			if(timer2_flag == 1)
			{
				status = INIT;
				temp_red = led7_seg[0];
			}
			if(isButtonPressed1() == 1)
			{
				status = MODE_LED_YELLOW;
				clearAllLed();
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
				display_led = temp_yellow;
			}
			break;
		case MODE_LED_YELLOW:
			if(timer3_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, LED_2_Pin | LED_5_Pin);
				setTimer3(500);
			}
			if(isButtonPressed2() == 1)
			{
				temp_yellow++;
				display_led = temp_yellow;
			}
			if(isButtonPressed3() == 1)
			{
				if(temp_red == temp_yellow + temp_green)
				{
					led7_seg[1] = temp_yellow;
					led7_seg[0] = temp_red;
					led7_seg[2] = temp_green;
				}
			}
			if(timer4_flag == 1)
			{
				display7SEG_MAN();
				setTimer4(250);
			}

			if(timer2_flag == 1)
			{
				status = INIT;
				temp_yellow = led7_seg[1];
			}
			if(isButtonPressed1() == 1)
			{
				status = MODE_LED_GREEN;
				clearAllLed();
				setTimer2(10000);
				setTimer3(500);
				setTimer4(250);
				display_led = temp_green;
			}
			break;
		case MODE_LED_GREEN:
			if(timer3_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, LED_3_Pin | LED_6_Pin);
				setTimer3(500);
			}
			if(isButtonPressed2() == 1)
			{
				temp_green++;
				display_led = temp_green;
			}
			if(isButtonPressed3() == 1)
			{
				if(temp_red == temp_yellow + temp_green)
				{
					led7_seg[2] = temp_green;
					led7_seg[0] = temp_red;
					led7_seg[1] = temp_yellow;
				}
			}
			if(timer4_flag == 1)
			{
				display7SEG_MAN();
				setTimer4(250);
			}

			if(timer2_flag == 1)
			{
				status = INIT;
				temp_green = led7_seg[2];
			}
			if(isButtonPressed1() == 1)
			{
				status = INIT;
				setTimer2(10000);
			}
			break;
		default:
			break;
	}
}

void display7SEG_MAN()
{
	if(status == MODE_LED_RED || status == MODE_LED_YELLOW || status == MODE_LED_GREEN)
	{
		switch(led_blinky1)
		{
			case 0:
				HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, SET);
				display7SEG1(display_led / 10);
				display7SEG2(0);
				led_blinky1 = 1;
				break;
			case 1:
				tmp = (status == MODE_LED_RED) ? 2 : (status == MODE_LED_YELLOW) ? 3 : (status == MODE_LED_GREEN) ? 4 : 1;
				HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN3_Pin, RESET);
				display7SEG1(display_led % 10);
				display7SEG2(tmp);
				led_blinky1 = 0;
				break;
		}
	}
}

