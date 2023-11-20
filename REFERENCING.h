#ifndef REFERENCING_H
#define REFERENCING_h
#include "mbed.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], float *speed, 
                 DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, 
                 DigitalIn button_g,
                 DigitalOut LED_Y, DigitalOut LED_G); // movimenta no sentido horário e antihorário

#endif
