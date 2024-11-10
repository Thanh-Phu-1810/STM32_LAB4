/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "traffic_light.h"

void led_red_and_green()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_6_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin, RESET);
}

void led_red_and_yellow()
{
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_5_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_6_Pin, RESET);
}

void led_green_and_red()
{
	HAL_GPIO_WritePin(GPIOA, LED_3_Pin | LED_4_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_5_Pin | LED_6_Pin, RESET);
}

void led_yellow_and_red()
{
	HAL_GPIO_WritePin(GPIOA, LED_2_Pin | LED_4_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_3_Pin | LED_5_Pin | LED_6_Pin, RESET);
}

