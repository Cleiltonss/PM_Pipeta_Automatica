#ifndef AUT_PEPETTING_H
#define AUT_PEPETTING_h
#include "mbed.h"


void AUT_PEPETTING(int *n_frascos, int pCollect[3], int pPepet[][4], float *velocity, 
                   int *xcount, int *ycount, int *zcount, 
                   DigitalOut MOTOR1_CLK, DigitalOut MOTOR1_CW, 
                   DigitalOut MOTOR2_CLK, DigitalOut MOTOR2_CW,
                   DigitalOut MOTOR3_CLK, DigitalOut MOTOR3_CW,
                   DigitalOut MOTOR_EN,
                   DigitalOut rele); 

#endif
