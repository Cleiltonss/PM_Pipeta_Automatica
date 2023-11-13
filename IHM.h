#ifndef IHM_H
#define IHM_h
#include "mbed.h"

//funções para limpeza de tela
void clean();
void clean_start_NumFlask();

// mensagens de referenciamento
void start_ref(DigitalIn button_g, DigitalOut LED_Y);
void dur_ref();
void end_ref(DigitalOut LED_Y, DigitalOut LED_G);


// mensagens de ponto de coleta
void start_pCollect(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G);
void end_pCollectXY(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G);
void end_pCollectZ(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G);

void start_pCollectH(int position[3], DigitalIn button_g, DigitalOut LED_B);
void end_pCollectH();


// mensagens de dados para pipetagem
void start_NumFlask(DigitalOut button_g, int *n_frascos);
void start_FlaskH();
void start_FlaskPosition();



void IHM(DigitalOut button_g, DigitalOut LED_Y); // movimenta no sentido horário e antihorário
    
#endif
