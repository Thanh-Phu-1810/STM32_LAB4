/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NUM_BUTTONS 3

extern int keyReg0[NUM_BUTTONS];
extern int keyReg1[NUM_BUTTONS];
extern int keyReg2[NUM_BUTTONS];
extern int keyReg3[NUM_BUTTONS];
extern int button_flag[NUM_BUTTONS];
extern int timer_counter_button[NUM_BUTTONS];
extern uint16_t ButtonPin[NUM_BUTTONS];

void getKeyInput();
int isButtonPressed1();
int isButtonPressed2();
int isButtonPressed3();
void subKeyProcess1();
void subKeyProcess2();
void subKeyProcess3();
void subKeyProcess();

#endif /* INC_BUTTON_H_ */
