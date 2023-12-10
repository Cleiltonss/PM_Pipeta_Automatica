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
DigitalOut MOTOR_CLK(PC_8);

DigitalOut MOTOR1_EN(D10, 0);
DigitalOut MOTOR1_CW(PC_9, 0);

DigitalOut MOTOR2_EN(PB_11, 0);
DigitalOut MOTOR2_CW(PC_10, 0);

DigitalOut MOTOR3_EN(PA_11, 0);
DigitalOut MOTOR3_CW(PA_12, 0);



// valor utilizado nas etapas de JOG para coleta de dados de pipetagem
int step_jog = 0; // Define em que passo do processo de coleta ou posicionamento de pipetagem estará
int index = 0; // Valor para setar em qual frascos estará sendo colado os valores

// Definindo lista para o ponto de Coleta e frasco de Pipetagem
int pCollect[4]; 
int pPepet[9][4];

int n_frascos = 1; // Define o número de frascos que serão pipetados

int loop = 0;

// // Variável de acionamento do relé
DigitalOut rele1(PC_2, 0); // 0 : desligado
DigitalOut rele2(PC_3, 0);

// // DigitalOut buzzer(PB7, 0);

float speed = 0.002;

//********************************************************SPEED DO MOTOR*******************************************
void normal_speed() {
    speed = 0.002; // 200 hz: voltar para 0.01
}
void high_speed() {
    speed = 0.001; // 1000 hz
    // printf("\rENTROU\n");
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
<<<<<<< HEAD
    MOTOR3_EN = 1; // enable do eixo z. Aciona em 1
=======
    MOTOR3_EN = 0; // enable do eixo z. Aciona em 1
>>>>>>> 5c0de22dde1c8f602ac3fb9b68b8ca580c8faa38

    // variáveis estados iniciais
    LED_B = 0;
    LED_Y = 0;
    LED_R = 0;
    LED_R_EMERG = 0;


    // Motores
    DigitalIn fdc[3][2] = {{fdcx1, fdcx2}, {fdcy1, fdcy2},  {fdcz1, fdcz2}}; // Lista que armazena os valores de cada fdc para cada eixo
    int position[3] = {0, 0, 0};
<<<<<<< HEAD
    int pPeppet[9][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 
                        {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}};

    



    //**********************************************************REFERENCIAMENTO************************************************************
    while(1) {
        // start_ref(button_g, LED_Y);
        // REFERENCING(fdc, position,
        //             MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN,  
        //             button_g,
        //             LED_Y, LED_G);
=======
    int pPeppet[9][4] ={{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 
                        {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}};

    MOTOR_CLK.write(0.5); // Duty cicle para 50%
    MOTOR_CLK.period(0.005); // *speed inicial igual a 0.01
 
    int i = 0;
    while (i < 1) {
        // start_ref(button_g, LED_Y);
        // REFERENCING(fdc, position,
        //             MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN,  
        //             button_g,
        //             LED_Y, LED_G);
        

        JOG(xAxis, yAxis, 
            MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN, 
            position, &step_jog, 
            button_g, 
            LED_B, LED_G,
            pCollect, pPepet,
            &n_frascos, &index, &loop
            );
        i++;
        // // printf("SAI DO JOG!");
        // AUT_PEPETTING(&n_frascos, pCollect, pPepet, position, 
        //               MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR1_EN, MOTOR2_EN,
        //               rele);
>>>>>>> 5c0de22dde1c8f602ac3fb9b68b8ca580c8faa38
        break;
    }
    //**********************************************************REFERENCIAMENTO************************************************************





    //***************************************************************JOG*******************************************************************
    int switchz = 0; // variável que muda posição joystick xy para z
    int joystick[3]; // lista com as posições x,y,z do joystick
    bool leave_cp = true; // Define quebra do looping total de saída
    // IHM(LED_R, button_g);
    start_pCollect(button_g, LED_B, LED_G); // DESCOMENTAR DEPOIS!
    while (1) {

        // printf("\rswitchz: %i!\n", switchz);
        if (switchz == 0) {
            // Valores do joystick
            joystick[0] = xAxis.read() * 1000; // float (0->1) to int (0->1000)
            joystick[1] = yAxis.read() * 1000;
            joystick[2] = 0;

            // printf("\nX= %i, Y= %i\n", joystick[0], joystick[1]);
            // Movimentação do JOYSTICK com interpolação de eixos
        
            // sem movimento
            if (joystick[0] < 550 && joystick[0] > 450 && joystick[1] < 550 && joystick[1] > 450) {
                MOTOR1_EN = 1;
                MOTOR2_EN = 1;
                // printf("\rX e Y PARADOS!\n");
            }
            
            // movimento leste
            if (joystick[0] > 600 && joystick[1] < 550 && joystick[1] > 450) {
                MOTOR1_EN = 1;

                MOTOR2_EN = 0;
                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR2_CW = 0;
                position[0]++;
                // printf("\rposition[0]: %i\n", position[0]);
                // printf("\nX DIREITA!\n");
            }

            // movimento oeste
            if (joystick[0] < 400 && joystick[1] < 550 && joystick[1] > 450) {
                MOTOR1_EN = 1;

                MOTOR2_EN = 0; 
                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR2_CW = 1;
                position[0]--;
                // printf("\rX ESQUERDA!\n\n");
            }

            // movimento norte
            if (joystick[1] > 600 && joystick[0] < 550 && joystick[0] > 450) {
                MOTOR2_EN = 1;

                MOTOR1_EN = 0;
                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR1_CW = 1; 
                position[1]++;
                // printf("\rY CIMA!\n\n");
            }

            // movimento sul
            if (joystick[1] < 400 && joystick[0] < 550 && joystick[0] > 450) {
                MOTOR2_EN = 1; // ENABLE

                MOTOR1_EN = 0;
                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR1_CW = 0; 
                position[1]--;
                // printf("\rY BAIXO!\n\n");
            }

            // movimento nordeste
            if (joystick[0] > 600 && joystick[1] > 600) {
                MOTOR1_EN = 0; // ENABLE
                MOTOR2_EN = 0; // ENABLE

                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);


                MOTOR1_CW = 1; 
                MOTOR2_CW = 0; 
                position[0]++;
                position[1]++;
                // printf("\rNORDESTE!\n\n");
            }
            
            // movimento noroeste
            if (joystick[0] < 400 && joystick[1] > 600) {
                MOTOR1_EN = 0; // ENABLE
                MOTOR2_EN = 0; // ENABLE

                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);


                MOTOR1_CW = 1; 
                MOTOR2_CW = 1; 
                position[0]--;
                position[1]++;
                // printf("\rNOROESTE\n\n");
            }

            // movimento sudoeste
            if (joystick[0] < 400 && joystick[1] < 400) {
                MOTOR1_EN = 0; // ENABLE
                MOTOR2_EN = 0; // ENABLE

                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR1_CW = 0; 
                MOTOR2_CW = 1; 
                position[0]--;
                position[1]--;
                // printf("\rSUDOESTE!\n\n");
            }

            // movimento sudeste
            if (joystick[0] > 600 && joystick[1] < 400) {
                MOTOR1_EN = 0; // ENABLE
                MOTOR2_EN = 0; // ENABLE

                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR1_CW = 0; 
                MOTOR2_CW = 0; 
                position[0]++;
                position[1]--;
                // printf("\rSUDESTE!\n\n");
            }
        }

        
        // Eixo Z - movimento norte e sul
        if (switchz == 1) {
            joystick[0] = 0;
            joystick[1] = 0;
            joystick[2] = yAxis.read() * 1000;
            
            if (450 < joystick[2] && joystick[2] < 550) {
                // printf("\rEIXO Z PARADO!\n");
                MOTOR3_EN = 0; 
            }
            
            // Deslocamento do MOTOR - z norte
            if (joystick[2] > 600) {
                MOTOR3_EN = 0;

                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);

                MOTOR3_CW = 0;
                position[2]++;
                // printf("\rEIXO Z NORTE!\n\n");
            }

            // Deslocamento do MOTOR - z sul
            if (joystick[2] < 400) {
                MOTOR3_EN = 0;
                
                MOTOR_CLK = 0;
                wait(speed);
                MOTOR_CLK = 1;
                wait(speed);
                
                MOTOR3_CW = 1;
                position[2]--;
                // printf("\rEIXO Z SUL!\n\n");
            }


            if (step_jog == 3) {
                // printf("\rPASSO 3!\n");
                pCollect[2] = position[2];
                // printf("\rZ: %i\n", pCollect[2]);
                // É necessário zerar a contagem para as novas medidas dos frascos
                position[0] = 0;
                position[1] = 0;
                position[2] = 0;

                switchz = 0; // para de movimentar z 
                step_jog = step_jog + 1; // necessário para  a próxima passada de etapa
                // printf("\rFINALIZOU O PASSO 3!\n");
            }

            // printf("\rValor de Z: %i\n", position[2]);
            if (step_jog == 9 || step_jog == 14 || step_jog == 18 || step_jog == 22 || step_jog == 26 || step_jog == 30 || step_jog == 34 || step_jog == 38 || step_jog == 42) {
                // printf("\rVALOR DE ENTRADA DO step_jog: %i\n", step_jog);
                pPepet[index][2] = position[2];
                step_jog = step_jog + 1; // primeiro ciclo aqui vai pra step_jog = 10
                // printf("\rFINALIZOU O PASSO %i!\n", step_jog);
                index = index + 1;
                step_jog = step_jog+1; // step_jog == 30
                switchz = 0;
                // printf("\rindex: %i\n", index);
                // printf("\r*position[2]: %i\n", position[2]);
                // if (index < *n_frascos) {
                //     start_FlaskPosition(index, position[0], position[1]);
                // }
                wait(1);
            }
        }


        // Entrada dos passos de coleta e altura do frascos de coleta para pipetagem 
        if (button_g == 0) {
            if (step_jog == 0) {
                // printf("\rPASSO 0!\n");
                // printf("\rFINALIZOU O PASSO 0!\n");
            }

            // Salva posições xy de coleta
            if (step_jog == 1) {
                // printf("\rPASSO 1!\n");
                end_pCollectXY(button_g, LED_B);
                pCollect[0] = position[0];
                pCollect[1] = position[1];
                // printf("\rX: %i\n\rY: %i\n", pCollect[0], pCollect[1]);
                switchz = 1;
                // printf("\rFINALIZOU O PASSO 1!\n");
                dur_pCollectZ();
            }

            // Salva a altura do ponto de coleta
            if (step_jog == 4) {
                // printf("\rPASSO 4!\n");
                start_pCollectH(position, button_g, LED_B); // verificar se salvou realmente a posição!
                pCollect[3] = position[1]; // armazenou aqui o valor final para ter tudo de posição da COLETA
                // printf("\rValor do Volume de Coleta: %i\n", pCollect[3]);
                // printf("\rValor do step_jog: %i\n", step_jog);
                position[1] = 0;
                end_pCollectH(button_g, LED_B, LED_G);
                // printf("\rFINALIZOU O PASSO 4!\n");
            }

            // Salva quantidade de frascos para pipetagem - será substituido por tela touchscreen
            if (step_jog == 5) {
                // printf("\rPASSO 5!\n");
                start_NumFlask(button_g, &n_frascos, LED_B, LED_G); // verificar se salvou os frascos
                // printf("\rFINALIZOU O PASSO 5!\n");
            }


            if (index < n_frascos) {
                // Salva a quantidade de volume do frasco n 
                // printf("\rENTRANDO NA COLETA DOS FRASCOS\n");
                // printf("\rstep_jog NA COLETA DE ALTURA DE FRASCOS: %i\n", step_jog);

                if (step_jog == 6 || step_jog == 11 || step_jog == 14 || step_jog == 18 || step_jog == 22 || step_jog == 26 || step_jog == 30 || step_jog == 34 || step_jog == 38) {
                    pPepet[index][3] = start_FlaskH(pPepet[index][3], button_g, LED_B, &index); // ele está salvando! está correto!
                    // printf("\rValor de altura do frasco %i: %i\n", index+1, pPepet[index][3]);
                    // printf("\rTerminou a coleta com um total de %i frasco(s)\n", index+1);
                    // colocar led azul pulsante 

                    start_FlaskPosition(index, position[0], position[1]);
                }

                if (step_jog == 7 || step_jog == 12 || step_jog == 17 || step_jog == 22 || step_jog == 28 || step_jog == 33 || step_jog == 38 || step_jog == 43 || step_jog == 48) {
                    // printf("ENTROU NO PASSO QUE EU QUERIA!");
                    pPepet[index][0] = position[0];
                    pPepet[index][1] = position[1];
                    switchz = 1;
                    wait(0.5);
                    start_FlaskPositionZ(index);
                }
            }                    
            step_jog = step_jog + 1; 
            wait(1); // Controll Time to each time that the green button is press
        }


        // printf("\rValor step_jog: %i\n", step_jog);
        if (step_jog == 7 || step_jog == 12 || step_jog == 16 || step_jog == 20 || step_jog == 24 || step_jog == 28 || step_jog == 32 || step_jog == 36 || step_jog == 40) {
            // printf("\rDENTRO\n");
            start_FlaskPositionUpdate(position[0], position[1]);
        }

        if (step_jog == 8 || step_jog == 13 || step_jog == 18 || step_jog == 23 || step_jog == 28 || step_jog == 33 || step_jog == 38 || step_jog == 43 || step_jog == 48) {
            start_FlaskPositionUpdateZ(position[2]);
        }  

        if (index == n_frascos) {
            break;
        }
    }
    //***************************************************************JOG*******************************************************************






    //***********************************************************PIPETAGEM*******************************************************************
    
    // Volta do ponto do último frasco com parâmetros digitados para o ponto de coleta
    printf("\rPpeppet[0]: %i\n", pPeppet[(n_frascos-1)][0]);
    printf("\rPpeppet[1]: %i\n", pPeppet[(n_frascos-1)][1]);
    printf("\rPpeppet[2]: %i\n", pPeppet[(n_frascos-1)][2]);
    printf("\rPpeppet[3]: %i\n", pPeppet[(n_frascos-1)][3]);

    printf("\rpCollect[0]: %i\n", pCollect[0]);
    printf("\rpCollect[1]: %i\n", pCollect[1]);
    printf("\rpCollect[2]: %i\n", pCollect[2]);
    printf("\rpCollect[3]: %i\n", pCollect[3]);

    // retorno do ultimo frasco para posição de coleta
    int x = pPeppet[(n_frascos-1)][0];
    int y = pPeppet[(n_frascos-1)][1];
    int z = pPeppet[(n_frascos-1)][2];
    
    int xCollect = pCollect[0];
    int yCollect = pCollect[1];
    int zCollect = pCollect[2];

    // foi colado o valor de (zCollect-2) para se ter a segurança que a pipeta ficará 3 passos do motor acima do frasco de coleta
    while(z != (zCollect-2)) {
        UP(&z, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN, &speed);
    }
    MOTOR3_EN = 1;



    while(1) {
        RETURN(&x, &y, xCollect, yCollect, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN, &speed);

        // Critérios de parada de motores  
        if (x > y && y == yCollect) {
            MOTOR1_EN = 1;
            if (x == xCollect) {
                MOTOR2_EN = 1;
                break;
            }
        }
        if (x < y && x == xCollect) {
            MOTOR2_EN = 1;
            if (y == yCollect) {
                MOTOR1_EN = 1;
                break;
            }
        }
    }




    // INÍCIO DA PIPETAGEM
    /*for (int i = 0; i < n_frascos; i++) {
        int xPeppet = pPeppet[i][0];
        int yPeppet = pPeppet[i][1];
        int zPeppet = pPeppet[i][2];
        int hPeppet = pPeppet[i][3];

        // LOOPING DA PIPETAGEM PARA CADA FRASCO
        for (int j = 0; j < hPeppet; j++) {


            // descida para pegar o líquido descendo 4 passos, ficando 2 passos abaixo do z de coleta: (zCollect+2)
            for (int a = 0; a < 3; a++) {
                DOWN(&z, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN,  MOTOR3_EN, &speed);
            }
            // aciona o relé para coletar o líquido
            rele1 = 1; 
            wait(10);


            // subida, ficando 2 passos acima do z de coleta: (zCollect-2)
            for (int a = 0; a < 3; a++) {
                UP(&z, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN,  MOTOR3_EN, &speed);
            }


            // movimentação até o ponto xy do enésimo frasco
            while (1) {
                TAKE(xPeppet, yPeppet, &x, &y, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN, &speed);

                // Critérios de parada de motores  
                if (x > y && y == yPeppet) {
                    MOTOR1_EN = 1;
                    if (x == xPeppet) {
                        MOTOR2_EN = 1;
                        break;
                    }
                }
                if (x < y && x == xPeppet) {
                    MOTOR2_EN = 1;
                    if (y == yPeppet) {
                        MOTOR1_EN = 1;
                        break;
                    }
                }
            }


            // descida para despejar o líquido no enésimo frasco, ficando 2 passos abaixo do z de pipetagem: (zPeppet+2)
            for (int a = 0; a < (zPeppet+2); a++) {
                DOWN(&z, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN,  MOTOR3_EN, &speed);
            }
            // aciona o relé para coletar o líquido
            rele1 = 0; 
            wait(10);


            // subida para retornar para o ponto de coleta, ficando 2 passos acima do z de coleta: (zCollect-2)
            for (int a = 0; a < (zCollect-2); a++) {
                DOWN(&z, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN,  MOTOR3_EN, &speed);
            }


            
            // movimentação até o ponto xy do ponto de coleta
            while(1) {
                RETURN(&x, &y, xCollect, yCollect, MOTOR_CLK, MOTOR1_CW, MOTOR2_CW, MOTOR3_CW, MOTOR1_EN, MOTOR2_EN, MOTOR3_EN, &speed);

                // Critérios de parada de motores  
                if (x > y && y == yCollect) {
                    MOTOR1_EN = 1;
                    if (x == xCollect) {
                        MOTOR2_EN = 1;
                        break;
                    }
                }
                if (x < y && x == xCollect) {
                    MOTOR2_EN = 1;
                    if (y == yCollect) {
                        MOTOR1_EN = 1;
                        break;
                    }
                }
            }

     
        }
    }*/


}
    


    
    

    

    





