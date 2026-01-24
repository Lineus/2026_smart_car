//
// Created by sixPigs on 2026/1/24.
//

#include "control.h"

void control_move() {
    Emm_V5_Pos_Control(0, 0, 400, 100, 6400, 0, 0);
    HAL_Delay(6000);
    Emm_V5_Global_Pos(0, 300, 60, 3400, 0, 0);
    HAL_Delay(4000);
    Emm_V5_Pos_Control(0, 0, 400, 100, 19200, 0, 0);
    HAL_Delay(8000);
    Emm_V5_Global_Pos(1, 300, 60, 3400, 0, 0);
    HAL_Delay(4000);
    Emm_V5_Pos_Control(0, 0, 400, 100, 16000*4/3, 0, 0);
    HAL_Delay(8000);
    Emm_V5_Pos_Control(0, 1, 60, 100, 9600*4/3, 0, 0);
    HAL_Delay(8000);
}
