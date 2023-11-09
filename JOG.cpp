#include "JOG.h"
#include "mbed.h"


// movimentação do joystick com o armazenamento de variáveis para o processo de pipetagem


void JOG(AnalogIn xAxis, AnalogIn yAxis,
         DigitalOut MOTOR[][2], 
         int *xcount, int *ycount, int *zcount,
         DigitalOut button_b, DigitalOut button_g, DigitalOut button_r,
         int pCollect[4], int pPepet[][4],
         int *vp, int *n_frascos, float *velocity, int *hc) 
         {
            int joystick[3]; // lista com as posições x,y,z do joystick
            int switchz = 0; // variável que muda posição joystick xy para z
            int step_jog = 0; // Define em que passo do processo de coleta ou posicionamento de pipetagem estará
            bool leave_cp = true; // Define quebra do looping total de saída
            int incre_loop = 5; // Auxilia para index do looping de registro de valores de pipetagem
            int index = step_jog - incre_loop;

            while (leave_cp == true) {     
                if (switchz == 0) {
                    joystick[0] = xAxis.read() * 1000; // float (0->1) to int (0->1000)
                    joystick[1] = yAxis.read() * 1000;
                    printf("\rX=%4d\nY=%4d", joystick[0], joystick[1]);

                    if (button_b == 1) {
                        *velocity = *velocity / 5; // configura a velocidade para ser 5 vezes mais rápida
                    }

                    if (470 < joystick[0] && joystick[0] < 530 || 470 < joystick[1] && joystick[1] < 530) {
                        MOTOR[3][0] = 1; // ENABLE MOTORES: 1 -> NÃO MOVIMENTA, 0 -> MOVIMENTA 
                    }


                    // Movimentação do JOYSTICK

                    if (joystick[0] > 550) {
                        // Deslocamento do MOTOR - x direita
                        MOTOR[3][0] = 0; // ENABLE
                        MOTOR[0][0] = 1; // bobinas
                        MOTOR[0][1] = 0; // direção: 0
                        wait(*velocity); 
                        MOTOR[0][0] = 0;
                        wait(*velocity); // intervalo de 10ms
                        *xcount = *xcount + 1;
                    }

                    if (joystick[0] < 450) {
                        // Deslocamento do MOTOR - x esquerda
                        MOTOR[3][0] = 0; // ENABLE
                        MOTOR[0][0] = 1; // bobinas
                        MOTOR[0][1] = 1; // direção
                        wait(*velocity); // intervalo de 10ms
                        MOTOR[0][0] = 0;
                        wait(*velocity); // intervalo de 10ms
                        *xcount = *xcount - 1;
                    }

                    if (joystick[1] > 550) {
                    // Deslocamento do MOTOR - y direita
                        MOTOR[3][0] = 0;
                        MOTOR[1][0] = 1; // bobinas
                        MOTOR[1][1] = 0; // direção
                        wait(*velocity); 
                        MOTOR[1][0] = 0;
                        wait(*velocity); // intervalo de 10ms
                        *ycount = *ycount + 1;
                    }

                    if (joystick[1] < 450) {
                    // Deslocamento do MOTOR - y esquerda
                        MOTOR[3][0] = 0;
                        MOTOR[1][0] = 1; // bobinas
                        MOTOR[1][1] = 1; // direção
                        wait(*velocity); // intervalo de 10ms
                        MOTOR[1][0] = 0;
                        wait(*velocity); // intervalo de 10ms
                        *ycount = *ycount - 1;
                    }
                }
                
                // Eixo Z - cima e baixo
                if (switchz == 1) {
                    joystick[0] = 0;
                    joystick[2] = yAxis.read() * 1000;
                    
                    if (470 < joystick[2] && joystick[2] < 530) {
                        MOTOR[3][0] = 1;
                    }

                    if (joystick[2] > 550) {
                        // Deslocamento do MOTOR - z cima
                        MOTOR[3][0] = 0;
                        MOTOR[2][0] = 1; // bobinas
                        MOTOR[2][1] = 0; // direção
                        wait(*velocity); 
                        MOTOR[2][0] = 0;
                        wait(*velocity); // intervalo de 10ms
                        *zcount = *zcount + 1;
                    }

                    if (joystick[2] < 450) {
                        // Deslocamento do MOTOR - z baixo
                        MOTOR[3][0] = 0;
                        MOTOR[2][0] = 1; // bobinas
                        MOTOR[2][1] = 1; // direção
                        wait(*velocity); // intervalo de 10ms
                        MOTOR[2][0] = 0;
                        wait(*velocity); // intervalo de 10ms
                        *zcount = *zcount - 1;
                    }

                    if (step_jog == 2) {
                        pCollect[2] = *zcount;

                        // É necessário zerar a contagem para as novas medidas dos frascos
                        *xcount = 0;
                        *ycount = 0;
                        *zcount = 0;

                        switchz = 0; // para de movimentar z 

                        step_jog++; // necessário para  a próxima passada de etapa
                    }

                    if ((step_jog-5) < 32) {
                        pPepet[index][2] = *zcount;

                        switchz = 0;
                        step_jog++;
                    }
                }

                // Salvar posição de coleta e altura do frascos de coleta para pipetagem 
                if (button_g == 1) {
                    if (step_jog == 0) {
                        // EMITIR MENSAGEM NO PAINEL PARA SALVAR XYZ e hc da COLETA
                    }

                    if (step_jog == 1) {
                        pCollect[0] = *xcount;
                        pCollect[1] = *ycount;

                        switchz = 1;
                    }

                    if (step_jog == 3) {
                        *hc = 4;  // Altura total do frasco de coleta, precisa ser modificado p/ o usuário definir seu valor
                        pCollect[3] = *hc; // armazenou aqui o valor final para ter tudo de posição da COLETA
                    }

                    // Salva quantidade de frascos para pipetagem
                    if (step_jog == 4) {
                        // MENSAGEM: Defina o número de frascos para pipetar. 
                        // Esse valor é definido pelo usuário apertando o botão
                        *n_frascos = 3; // Valor fictício que vai de 1 à 9

                    }
                    
                    
                    // looping de pegar valores para pipetagem
                    if (index < *n_frascos) {
                        // Salva a quantidade de volume do frasco n (variável vp)
                        if ((step_jog-5)== 0 || (step_jog-5) == 3 || (step_jog-5) == 6 || (step_jog-5) == 9 || (step_jog-5) == 12 || (step_jog-5) == 15 || (step_jog-5) == 18 || (step_jog-5) == 21 || (step_jog-5) == 24) {
                            // MENSAGEM: DEFINIR VALOR DE VOLUME: variável vp
                            *vp = 10; // valor fictício que será sempre alterado pelo usuário

                            pPepet[index][3] = *vp;
                            incre_loop++;
                        }

                        if ((step_jog-5) == 1 || (step_jog-5) == 4 || (step_jog-5) == 7 || (step_jog-5) == 10 || (step_jog-5) == 13 || (step_jog-5) == 16 || (step_jog-5) == 19 || (step_jog-5) == 22 || (step_jog-5) == 25) {
                            while (switchz == 0) {
                            // step_jog-5 começa com valor 0 e vai aumentando de 1 em 1
                            pPepet[index][0] = *xcount;
                            pPepet[index][1] = *ycount;
                            switchz = 1;
                            incre_loop++;
                            }
                        }
                    }

                    step_jog++; 
                }
  

                // quebra do looping
                if (step_jog-5 == *n_frascos) {
                    leave_cp = false;
                } 
            }
      
            
         }


  
