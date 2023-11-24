#ifndef AUT_PEPETTING_H
#define AUT_PEPETTING_h
#include "mbed.h"


void AUT_PEPETTING(int *n_frascos, int pCollect[3], int pPepet[][4], int position[3], 
                   PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, 
                   DigitalOut rele); 

#endif