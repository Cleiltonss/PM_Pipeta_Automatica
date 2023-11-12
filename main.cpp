#include "mbed.h"
#include "JOG.h"
#include "REFERENCING.h"
#include "AUT_PEPETTING.h"
#include "IHM.h"


Serial pc(USBTX, USBRX); // Declara o objeto pc para comunicação serial nativo

// BOTÕES: blue, green and red
InterruptIn button_b(D4); // botão de speed: normal e rapida - TA COM PROBLEMA NA COMUNICAÇÃO DE ARQUIVOS
DigitalOut button_g(D3, 0); // botão de confirmação: 0 -> valor pressionado
DigitalOut button_r(D10, 0);  // botão de retorno
InterruptIn button_emerg(D11); // Botão de EMERGÊNCIA

// LEDS: blue, red and yellow
DigitalOut LED_B(D10, 0); // Operação de definição de posições
DigitalOut LED_G(D6, 0); // Finalização de cada operação
DigitalOut LED_Y(D5, 0); // Referenciamento
DigitalOut LED_R(D11, 0); // Processo automático de pipetagem 
DigitalOut LED_R_EMERG(D3); // led vermelho para o estado de emergência



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


// MOTORES:  MOTOR1 - x , MOTOR2 - y, MOTOR3 - z
PwmOut MOTOR_CLK(D6);
DigitalOut MOTOR1_CW(D7, 0);
DigitalOut MOTOR2_CW(D8, 0);
DigitalOut MOTOR1_EN(D4, 1);
DigitalOut MOTOR2_EN(D5, 1);
// BusOut MOTOR3(D3, D4, D5, D6);  - ESTÁ COM ALGUM PROBLEMA!



// valor utilizado nas etapas de JOG para coleta de dados de pipetagem
int step_jog = 0; // Define em que passo do processo de coleta ou posicionamento de pipetagem estará

// Definindo lista para o ponto de Coleta e frasco de Pipetagem
int pCollect[4]; 
int pPepet[9][4];

int n_frascos = 0; // Define o número de frascos que serão pipetados


// Variável de acionamento do relé
DigitalOut rele(D11, 0); // 0 : desligado

//********************************************************BOTÃO DE SPEED*******************************************

// Define velocidade do motor
float speed = 0.01;

void normal_speed() {
    speed = 0.01;
}

void high_speed() {
    speed = 0.02;
}
//********************************************************BOTÃO DE SPEED********************************************



int main() {

    // Define period dos motores - botão azul pressionado aumenta a velocidade e, ao soltar, retorna a velocidade original
    button_b.fall(&high_speed);
    button_b.rise(&normal_speed);

    // variáveis estados iniciais
    LED_B = 0;
    LED_Y = 0;
    LED_R = 0;
    LED_R_EMERG = 0;


    // Motores
    DigitalIn fdc[3][2] = {{fdcx1, fdcx2}, {fdcy1, fdcy2},  {fdcz1, fdcz2}}; // Lista que armazena os valores de cada fdc para cada eixo
    int position[3] = {0, 0, 0}; 
    int i = 0;
    while (i < 1) {
        
        // REFERENCING(fdc, position, &speed,
        //             MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR1_EN, MOTOR2_EN, 
        //             button_g,
        //             LED_Y, LED_G);
        
        // JOG(xAxis, yAxis, 
        //     MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR1_EN, MOTOR2_EN,  
        //     position, &step_jog, &speed,
        //     button_g, 
        //     pCollect, pPepet,
        //     &n_frascos
        //     );
        i++;
        // // printf("SAI DO JOG!");
        // AUT_PEPETTING(&n_frascos, pCollect, pPepet, position, 
        //               MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR1_EN, MOTOR2_EN,
        //               rele);
        
    }
        
}


