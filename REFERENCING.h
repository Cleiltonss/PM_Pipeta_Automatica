#ifndef REFERENCING_H
#define REFERENCING_h
#include "mbed.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], float *speed, 
                 PwmOut MOTOR1_CLK, PwmOut MOTOR2_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR_EN, BusOut MOTOR3,
                 DigitalOut button_g,
                 DigitalOut LED_Y); // movimenta no sentido horário e antihorário

#endif
