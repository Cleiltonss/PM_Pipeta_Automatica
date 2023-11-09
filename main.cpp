#include "mbed.h"
#include "JOG.h"
#include "REFERENCING.h"
#include "AUT_PEPETTING.h"

// BOTÕES: blue, green and red
DigitalOut button_b(D3);
DigitalOut button_g(D3);
DigitalOut button_r(D3); 
InterruptIn button_emerg(D11); // Botão de EMERGÊNCIA


// REFERENCIAMENTO
DigitalIn fdcx1(D3); // fim de curso 1 no eixo x 
DigitalIn fdcx2(D4); // fim de curso 2 no eixo x 
DigitalIn fdcy1(D5); // fim de curso 1 no eixo y 
DigitalIn fdcy2(D6); // fim de curso 2 no eixo x 
DigitalIn fdcz1(D7); // fim de curso 1 no eixo z 
DigitalIn fdcz2(D8); // fim de curso 2 no eixo z 


// Definindo variáveis de leitura de posicionamento do JOYSTICK
AnalogIn xAxis(A0);
AnalogIn yAxis(A1);


// MOTORES:  MOTOR1 - x , MOTOR2 - y , MOTOR3 - z
PwmOut MOTOR1_CLK(D5, 0);
PwmOut MOTOR2_CLK(D9, 0);
PwmOut MOTOR3_CLK(D11, 0);
DigitalOut MOTOR1_CW(D6, 0);
DigitalOut MOTOR2_CW(D9, 0);
DigitalOut MOTOR3_CW(D8, 0);
DigitalOut MOTOR_EN(D7, 1);
// Contadores de posicionamentos para cada eixo
int xcount = 0;
int ycount = 0;
int zcount = 0;
// Velocidade dos motores
float velocity = 0.01;


// Definindo lista para o ponto de Coleta e frasco de Pipetagem
int pCollect[4]; 
int pPepet[9][4];
int hc; // Define altura de coleta
int n_frascos; // Define o número de frascos que serão pipetados
int vp; // Define o total de volume no frasco


// Variáveis para o relé
DigitalOut rele(D11);



int main() {
    
    // Motores
    MOTOR1_CLK.write(0.5); // Duty cicle para 50%
    MOTOR2_CLK.write(0.5); // Duty cicle para 50%
    MOTOR3_CLK.write(0.5); // Duty cicle para 50%
    DigitalIn fdc[3][2] = {{fdcx1, fdcx2}, {fdcy1, fdcy2},  {fdcz1, fdcz2}}; // Lista que armazena os valores de cada fdc para cada eixo
    int position[3] = {xcount, ycount, zcount}; // Alterar no código

    // Botões
    button_b = 0;
    button_g = 0;
    button_r = 0;


    // variável de volume de pipetagem
    vp = 0;
    // Número total de frascos
    n_frascos = 0;


    // Variável de acionamento do relé
    rele = 0; // desligado


    
    while (1) {
        REFERENCING(fdc,
                    MOTOR1_CLK, MOTOR2_CLK, MOTOR3_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR_EN,
                    position);
        
        /*JOG(xAxis, yAxis, 
            MOTOR, 
            &xcount, &ycount, &zcount,
            button_b, button_g, button_r,
            pCollect, pPepet,
            &vp, &n_frascos, &velocity, &hc
            );

        AUT_PEPETTING(&n_frascos, pCollect, pPepet, &velocity, &xcount, &ycount, &zcount,
                      MOTOR1_CLK, MOTOR1_CW, 
                      MOTOR2_CLK, MOTOR2_CW, 
                      MOTOR3_CLK, MOTOR3_CW, 
                      MOTOR_EN,
                      rele);
        */
    }
        
}


