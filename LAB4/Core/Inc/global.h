/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"

extern int status;
extern int led7_seg[3];
extern int led_blinky;
extern int led_blinky1;

extern int temp_red;
extern int temp_yellow;
extern int temp_green;

extern int display_led;

extern int tmp;
extern int temp_led1;
extern int temp_led2;

extern int x;
extern int y;
extern int z;

#define INIT       1
#define AUTO_RED_GREEN      2
#define AUTO_RED_YELLOW     3
#define AUTO_GREEN_RED 		4
#define AUTO_YELLOW_RED 	5

#define NORMAL_MODE             12
#define MODE_LED_RED            13
#define MODE_LED_YELLOW         14
#define MODE_LED_GREEN          15
void display7SEG_AUTO();
void display7SEG_MAN();
void clearAllLed();
#endif /* INC_GLOBAL_H_ */
