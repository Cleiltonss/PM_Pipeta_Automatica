#include "mbed.h"
#include "JOG.h"
#include "REFERENCING.h"
#include "AUT_PEPETTING.h"
#include "IHM.h"
#include "EMERGENCY.h"



Serial pc(USBTX, USBRX); // Declara o objeto pc para comunicação serial nativo

// BOTÕES: blue, green and red
InterruptIn button_b(PB_14); // botão de speed: normal e rapida - TA COM PROBLEMA NA COMUNICAÇÃO DE ARQUIVOS
DigitalIn button_g(D14); // botão de confirmação: 0 -> valor pressionado
DigitalIn button_r(PB_15);  // botão de retorno
InterruptIn button_emerg(PB_1); // Botão de EMERGÊNCIA

// LEDS: blue, red and yellow
DigitalOut LED_B(PB_2, 0); // Operação de definição de posições
DigitalOut LED_G(PB_12, 0); // Finalização de cada operação
DigitalOut LED_Y(PC_5, 0); // Referenciamento
DigitalOut LED_R(PC_6, 0); // Processo automático de pipetagem 
DigitalOut LED_R_EMERG(D15); // led vermelho para o estado de emergência


// REFERENCIAMENTO
DigitalIn fdcx1(PA_15); // fim de curso 1 no eixo x 
DigitalIn fdcx2(PA_14); // fim de curso 2 no eixo x 
DigitalIn fdcy1(PC_11); // fim de curso 1 no eixo y 
DigitalIn fdcy2(PC_12); // fim de curso 2 no eixo x 
DigitalIn fdcz1(PC_4); // fim de curso 1 no eixo z 
DigitalIn fdcz2(PB_13); // fim de curso 2 no eixo z 


// // Definindo variáveis de leitura de posicionamento do JOYSTICK
AnalogIn xAxis(D12);
AnalogIn yAxis(D11);


// MOTORES:  MOTOR1 - x , MOTOR2 - y, MOTOR3 - z
PwmOut MOTOR_CLK(PC_8);

DigitalOut MOTOR1_EN(D10, 0);
DigitalOut MOTOR1_CW(PC_9, 0);

DigitalOut MOTOR2_EN(PB_11, 0);
DigitalOut MOTOR2_CW(PC_10, 0);

DigitalOut MOTOR3_EN(PA_11, 0);
DigitalOut MOTOR3_CW(PA_12, 0);



// valor utilizado nas etapas de JOG para coleta de dados de pipetagem
int step_jog = 0; // Define em que passo do processo de coleta ou posicionamento de pipetagem estará

// Definindo lista para o ponto de Coleta e frasco de Pipetagem
int pCollect[4]; 
int pPepet[9][4];

int n_frascos = 0; // Define o número de frascos que serão pipetados


// // Variável de acionamento do relé
// DigitalOut releIN1(PC_2, 0); // 0 : desligado
// DigitalOut releIN2(PC_3, 0);

// // DigitalOut buzzer(PB7, 0);



//********************************************************SPEED DO MOTOR*******************************************
void normal_speed() {
    MOTOR_CLK.period(0.005); // 200 hz: voltar para 0.01
}
void high_speed() {
    MOTOR_CLK.period(0.002); // 1000 hz
}
//********************************************************SPEED DO MOTOR********************************************



int main() {
    // Define periodo dos motores - botão azul pressionado aumenta a velocidade e, ao soltar, retorna a velocidade original
    button_b.fall(&high_speed);
    button_b.rise(&normal_speed);

    // button_emerg.fall(EMERGENCY(LED_B, LED_G, LED_Y, LED_R, LED_R_EMERG,
    //                             MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR1_EN, MOTOR2_EN));

    MOTOR1_EN = 1;
    MOTOR2_EN = 1;
    MOTOR3_EN = 1;

    // variáveis estados iniciais
    LED_B = 0;
    LED_Y = 0;
    LED_R = 0;
    LED_R_EMERG = 0;


    // Motores
    DigitalIn fdc[3][2] = {{fdcx1, fdcx2}, {fdcy1, fdcy2},  {fdcz1, fdcz2}}; // Lista que armazena os valores de cada fdc para cada eixo
    int position[3] = {0, 0, 0};

    MOTOR_CLK.write(0.5); // Duty cicle para 50%
    MOTOR_CLK.period(0.005); // *speed inicial igual a 0.01
 
    
    while (1) {
        // start_ref(button_g, LED_Y);
        // REFERENCING(fdc, position, &speed,
        //             MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN,  
        //             button_g,
        //             LED_Y, LED_G);
        

        JOG(xAxis, yAxis, 
            MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN, 
            position, &step_jog, 
            button_g, 
            LED_B, LED_G,
            pCollect, pPepet,
            &n_frascos
            );
        // // printf("SAI DO JOG!");
        // AUT_PEPETTING(&n_frascos, pCollect, pPepet, position, 
        //               MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR1_EN, MOTOR2_EN,
        //               rele);
        break;
    }
        
}


