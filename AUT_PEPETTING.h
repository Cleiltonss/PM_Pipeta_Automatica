#ifndef AUT_PEPETTING_H
#define AUT_PEPETTING_h
#include "mbed.h"


void UP(int *z, 
       DigitalOut MOTOR_CLK, 
       DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
       DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
       float *speed);

void DOWN(int *z, 
             DigitalOut MOTOR_CLK, 
             DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
             DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
             float *speed);

void RETURN(int *x, int *y, int xCollect, int yCollect,
             DigitalOut MOTOR_CLK, 
             DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
             DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
             float *speed);

void TAKE(int xPeppet, int yPeppet, int *x, int *y, 
             DigitalOut MOTOR_CLK, 
             DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
             DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
             float *speed);


#endif

