#ifndef IHM_H
#define IHM_h
#include "mbed.h"

//funções para limpeza de tela
void clean();
void clean_start_NumFlask();
void clean_start_pCollectH();
void clean_start_FlaskH();
void clean_start_FlaskPositionUpdate();

// mensagens de referenciamento
void start_ref(DigitalIn button_g, DigitalOut LED_Y);
void dur_ref();
void end_ref(DigitalOut LED_Y, DigitalOut LED_G);


// mensagens de Ponto de Coleta
void start_pCollect(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G);
void end_pCollectXY(DigitalIn button_g, DigitalOut LED_B);
void dur_pCollectZ();
// void end_pCollectZ(DigitalIn button_g, DigitalOut LED_B);
void start_pCollectH(int position[3], DigitalIn button_g, DigitalOut LED_B, InterruptIn button_emerg);
void end_pCollectH(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G);


// mensagens de dados para pipetagem
void start_NumFlask(DigitalIn button_g, int *n_frascos, DigitalOut LED_B, DigitalOut LED_G, InterruptIn button_emerg);
int start_FlaskH(int value, DigitalIn button_g, DigitalOut LED_B, int *index, InterruptIn button_emerg);
void start_FlaskPosition(int index, int x, int y);
void start_FlaskPositionUpdate(int x, int y);
void start_FlaskPositionZ(int index);
void start_FlaskPositionUpdateZ(int y);


void IHM(DigitalOut button_g, DigitalOut LED_Y); // movimenta no sentido horário e antihorário
    
#endif
