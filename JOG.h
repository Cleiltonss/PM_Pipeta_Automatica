#ifndef JOG_H
#define JOG_h
#include "mbed.h"


void normal_velocity();
void speed_velocity();


void JOG(AnalogIn xAxis, AnalogIn yAxis,
        PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, BusOut MOTOR3,
        int position[3], int *step_jog, float *speed,
        InterruptIn button_b, DigitalOut button_g, DigitalOut button_r,
        int pCollect[4], int pPepet[][4],
        int *n_frascos);

#endif

