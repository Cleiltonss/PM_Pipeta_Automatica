#ifndef REFERENCING_H
#define REFERENCING_h
#include "mbed.h"


void REFERENCING(DigitalIn fdc[][2],
                 PwmOut MOTOR1_CLK, PwmOut MOTOR2_CLK, PwmOut MOTOR3_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, DigitalOut MOTOR_EN,
                 int position[3]); // movimenta no sentido horário e antihorário

#endif
