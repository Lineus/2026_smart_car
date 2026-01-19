//
// Created by sixPigs on 2026/1/17.
//

#include "gate.h"

#include <stdio.h>

#include "main.h"
#include "tim.h"


//舵机初始化
void gate_init() {

}

//舵机移动至对应角度
void gate_setAngle(uint16_t GPIO_Pin,double angle) {
    int type;
    if (GPIO_Pin==Servo1_Pin) {
        type=Servo1_LOW+angle/180*(Servo1_MAX-Servo1_LOW);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, type);
    }
    else if (GPIO_Pin==Servo2_Pin) {
        type=Servo2_LOW+angle/180*(Servo2_MAX-Servo2_LOW);
        __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, type);
    }
}

//开门开到默认角度
void gate_open() {
    door_status=0;
    gate_setAngle(Servo1_Pin,135);
    HAL_TIM_Base_Stop_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim2);
}

//更改回调函数，控制开门时间

//开门开到设定角度
void gate_openToAngle(int angle) {

}

void gate_close() {
    door_status=1;
    gate_setAngle(Servo2_Pin,0);
    HAL_TIM_Base_Stop_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim2);
}