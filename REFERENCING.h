#ifndef REFERENCING_H
#define REFERENCING_h
#include "mbed.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], 
                 PwmOut MOTOR_CLK, 
                 DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
                 DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN, 
                 DigitalIn button_g,
                 DigitalOut LED_Y, DigitalOut LED_G, float *speed, InterruptIn button_emerg); // movimenta no sentido horário e antihorário

#endif
