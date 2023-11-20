#ifndef EMERGENCY_H
#define EMERGENCY_h
#include "mbed.h"

void flip();
void EMERGENCY(DigitalOut LED_B, DigitalOut LED_G, DigitalOut LED_Y, DigitalOut LED_R, DigitalOut LED_R_EMERG,
               PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN); 

#endif
