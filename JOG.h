#ifndef JOG_H
#define JOG_h
#include "mbed.h"


void JOG(AnalogIn xAxis, AnalogIn yAxis,
        DigitalOut MOTOR[][2],
        int *xcount, int *ycount, int *zcount,
        DigitalOut button_b, DigitalOut button_g, DigitalOut button_r,
        int pCollect[4], int pPepet[][4],
        int *vp, int *n_frascos, float *velocity, int *hc);

#endif

