#ifndef AUT_PEPETTING_H
#define AUT_PEPETTING_h
#include "mbed.h"


void AUT_PEPETTING(int *n_frascos, int pCollect[3], int pPepet[][4], int position[3], float *speed,
                   PwmOut MOTOR1_CLK, PwmOut MOTOR2_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR_EN, BusOut MOTOR3,
                   DigitalOut rele); 

#endif
