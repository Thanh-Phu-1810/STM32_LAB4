/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Thanh Phu
 */

#include "button.h"

int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int button_flag[NUM_BUTTONS] = {0, 0, 0};
int timer_counter_button[NUM_BUTTONS] = {0, 0, 0};

uint16_t ButtonPin[NUM_BUTTONS] = {Button1_Pin, Button2_Pin, Button3_Pin};

void subKeyProcess(int button_id)
{
    button_flag[button_id] = 1;
}

int isButtonPressed1()
{
    if(button_flag[0] == 1)
    {
        button_flag[0] = 0;
        return 1;
    }
    return 0;
}

int isButtonPressed2()
{
    if(button_flag[1] == 1)
    {
        button_flag[1] = 0;
        return 1;
    }
    return 0;
}

int isButtonPressed3()
{
    if(button_flag[2] == 1)
    {
        button_flag[2] = 0;
        return 1;
    }
    return 0;
}

void getKeyInput()
{
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];
        KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, ButtonPin[i]);

        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i]))
        {
            if (KeyReg3[i] != KeyReg2[i])
            {
                KeyReg3[i] = KeyReg2[i];
                if (KeyReg2[i] == PRESSED_STATE)
                {
                    subKeyProcess(i);
                    timer_counter_button[i] = 200;
                }
            }
            else
            {
                timer_counter_button[i]--;
                if (timer_counter_button[i] <= 0)
                {
                    if (KeyReg2[i] == PRESSED_STATE)
                        subKeyProcess(i);
                    timer_counter_button[i] = 50;
                }
            }
        }
    }
}
