/*
 * led7_segment.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */
#include "led7_segment.h"

int temp = 0;

void display7SEG1(int temp)
{
	switch(temp)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG_6_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin , RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_2_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG_2_Pin | SEG_5_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_3_Pin | SEG_4_Pin | SEG_6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG_4_Pin | SEG_5_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_2_Pin | SEG_3_Pin | SEG_6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin |SEG_2_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_4_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG_1_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
			break;
		default:
			break;
	}
}

void display7SEG2(int temp)
{
	switch(temp)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG_13_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_8_Pin | SEG_9_Pin | SEG_10_Pin | SEG_11_Pin | SEG_12_Pin , RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_10_Pin | SEG_11_Pin | SEG_12_Pin | SEG_13_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_8_Pin | SEG_9_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG_9_Pin | SEG_12_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_8_Pin |SEG_10_Pin | SEG_11_Pin | SEG_13_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG_11_Pin | SEG_12_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_8_Pin |SEG_9_Pin | SEG_10_Pin | SEG_13_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_10_Pin | SEG_11_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_8_Pin | SEG_9_Pin | SEG_12_Pin | SEG_13_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG_8_Pin | SEG_11_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin |SEG_9_Pin | SEG_10_Pin | SEG_12_Pin | SEG_13_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG_8_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin |SEG_9_Pin | SEG_10_Pin | SEG_11_Pin | SEG_12_Pin | SEG_13_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG_10_Pin | SEG_11_Pin | SEG_12_Pin | SEG_13_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_8_Pin | SEG_2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_8_Pin | SEG_9_Pin | SEG_10_Pin | SEG_11_Pin | SEG_12_Pin | SEG_13_Pin , RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG_11_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, SEG_7_Pin | SEG_8_Pin | SEG_9_Pin | SEG_10_Pin | SEG_12_Pin | SEG_13_Pin , RESET);
			break;
		default:
			break;
	}
}

