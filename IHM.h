#ifndef IHM_H
#define IHM_h
#include "mbed.h"


// mensagens de referenciamento
void start_ref(DigitalOut button_g, DigitalOut LED_Y);
// void during_ref(DigitalOut LED_Y);
void end_ref(DigitalOut LED_G);


// mensagens de ponto de coleta
void start_pCollect();


void end_pCollectXY();
void end_pCollectZ();
void start_pCollectH();
void end_pCollectH();


// mensagens de dados para pipetagem
void start_NumFlask();
void start_FlaskH();
void start_FlaskPosition();



void IHM(DigitalOut button_g, DigitalOut LED_Y); // movimenta no sentido horário e antihorário
    
#endif
