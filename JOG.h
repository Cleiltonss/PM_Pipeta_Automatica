#ifndef JOG_H
#define JOG_h
#include "mbed.h"


// void normal_velocity();
// void speed_velocity();


void JOG(AnalogIn xAxis, AnalogIn yAxis,
        PwmOut MOTOR_CLK, 
        DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
        DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN, 
        int position[3], int *step_jog, 
        DigitalIn button_g,
        DigitalOut LED_B, DigitalOut LED_G,
        int pCollect[4], int pPepet[][4],
        int *n_frascos);

#endif

