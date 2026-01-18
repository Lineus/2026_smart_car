//
// Created by sixPigs on 2026/1/17.
//

#ifndef CHARIOT_GATE_H
#define CHARIOT_GATE_H

#include "stdint.h"

//定义舵机初始位置与180°位置所对应的pwm占空比（以比较寄存器数值表示）
#define Servo2_LOW 245
#define Servo2_MAX 105

#define Servo1_LOW 88
#define Servo1_MAX 228

//定义初始的开门角度
#define Open_angle 135

//定义全局变量，用于中断计
typedef struct {
    //定义门的状态，0为关闭，1为打开
    int door_status;
} Gate_t;
extern Gate_t gate_data;

void gate_init();

void gate_setAngle(uint16_t GPIO_Pin,double angle);

void gate_open();
void gate_close();
void gate_openToAngle(int angle);

#endif //CHARIOT_GATE_H