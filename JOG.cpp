#include "JOG.h"
#include "mbed.h"
#include "IHM.h"



// joystick + coleta de dados para pipetagem
void JOG(AnalogIn xAxis, AnalogIn yAxis,
         PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, BusOut MOTOR3, 
         int position[3], int *step_jog, float *speed,
         InterruptIn button_b, DigitalOut button_g, DigitalOut button_r,
         int pCollect[4], int pPepet[][4],
         int *n_frascos) 
         {
            
            
            int joystick[3]; // lista com as posições x,y,z do joystick
            int switchz = 0; // variável que muda posição joystick xy para z
            bool leave_cp = true; // Define quebra do looping total de saída
            int incre_loop = 5; // Auxilia para index do looping de registro de valores de pipetagem
            int index = *step_jog - incre_loop; 

            MOTOR_CLK.write(0.5); // Duty Cicle em 50%
            MOTOR_CLK.period(0.01); // MOTOR_CLK.period(*speed); NÃO FUNCIONA
            while (leave_cp == true) {     
                if (switchz == 0) {
                    joystick[0] = xAxis.read() * 1000; // float (0->1) to int (0->1000)
                    joystick[1] = yAxis.read() * 1000;
                    joystick[2] = 0;
                    printf("\rX=%4d\nY=%4d", joystick[0], joystick[1]);

                    if (joystick[0] < 700 && joystick[0] > 300 && joystick[1] < 700 && joystick[1] > 300) {
                        MOTOR1_EN = 1;
                        MOTOR2_EN = 1;
                    }


                    // Movimentação do JOYSTICK

                    // Deslocamento do MOTOR - x direita
                    if (joystick[0] > 700 && joystick[1] < 700 && joystick[1] > 300) {
                        MOTOR1_EN = 0; 
                        MOTOR1_CW = 1;
                        MOTOR2_EN = 1;
                    }

                    // Deslocamento do MOTOR - x esquerda
                    if (joystick[0] < 450) {
                        MOTOR1_EN = 0; // ENABLE
                        MOTOR2_EN = 1;
                        MOTOR1_CW = 1; 
                        position[0] = position[0] - 1;
                    }

                    // Deslocamento do MOTOR - y direita
                    if (joystick[1] > 550) {
                        MOTOR2_EN = 0; // ENABLE
                        MOTOR2_CW = 0; 
                        position[0] = position[0] + 1;
                    }

                    // Deslocamento do MOTOR - y esquerda
                    if (joystick[1] < 450) {
                        MOTOR2_EN = 0; // ENABLE
                        MOTOR2_CW = 1; 
                        position[0] = position[0] - 1;
                    }
                }

                
                // // Eixo Z - cima e baixo
                // if (switchz == 1) {
                //     joystick[0] = 0;
                //     joystick[1] = 0;
                //     joystick[2] = yAxis.read() * 1000;
                    
                //     if (470 < joystick[2] && joystick[2] < 530) {
                //         MOTOR3 = 0x0000; 
                //     }

                //     if (joystick[2] > 550) {
                //         // Deslocamento do MOTOR - z cima
                //         for (int j = 0; j < 4; j++) {
                //             MOTOR3 = 1 << j;
                //             wait(0.01);
                //         }
                //         position[2] = position[2] + 1;
                //         MOTOR3 = 0x0000; // conferir se esse é o valor correto
                //     }

                //     if (joystick[2] < 450) {
                //         // Deslocamento do MOTOR - z baixo - VERIFICAR SE INVERTEU O SENTIDO
                //         for (int j = 4; j > 0; j--) {
                //             MOTOR3 = 1 << j;
                //             wait(0.01);
                //         }
                //         position[2] = position[2] - 1;
                //         MOTOR3 = 0x0000; // conferir se esse é o valor correto
                //     }

                //     if (*step_jog == 2) {
                //         end_pCollectZ();
                //         pCollect[2] = position[2];

                //         // É necessário zerar a contagem para as novas medidas dos frascos
                //         position[0] = 0;
                //         position[1] = 0;
                //         position[2] = 0;

                //         switchz = 0; // para de movimentar z 

                //         *step_jog = *step_jog + 1; // necessário para  a próxima passada de etapa
                //     }

                //     if ((*step_jog-5) < 32) {
                //         pPepet[index][2] = position[2];

                //         switchz = 0;
                //         *step_jog = *step_jog + 1;
                //     }
                // }

                // // Salvar posição de coleta e altura do frascos de coleta para pipetagem 
                // if (button_g == 1) {
                //     if (*step_jog == 0) {
                //         start_pCollect();
                //     }

                //     if (*step_jog == 1) {
                //         end_pCollectXY();
                //         pCollect[0] = position[0];
                //         pCollect[1] = position[1];

                //         switchz = 1;
                //     }

                //     if (*step_jog == 3) {

                //         start_pCollectH();
                //         joystick[0] = 0;
                //         joystick[1] = yAxis.read() * 1000;
                //         joystick[2] = 0; 

                //         // Deslocamento - y cima
                //         if (joystick[1] > 550) {
                //             position[1] = position[1] + 1;
                //         }

                //         // Deslocamento - y baixo
                //         if (joystick[1] < 450 && position[1] > 0) {
                //             position[1] = position[1] - 1;
                //         }
                //     }

                //     if (*step_jog == 4) {
                //         pCollect[3] = position[1]; // armazenou aqui o valor final para ter tudo de posição da COLETA
                //         void end_pCollectH();
                //         position[1] = 0;
                //     }


                //     // Salva quantidade de frascos para pipetagem
                //     if (*step_jog == 5) {
                //         start_NumFlask();
                //         joystick[0] = 0;
                //         joystick[1] = yAxis.read() * 1000;
                //         joystick[2] = 0; 

                //         // Deslocamento - y cima
                //         if (joystick[1] > 550 && position[1] < 10) {
                //             *n_frascos = *n_frascos + 1;
                //         }

                //         // Deslocamento - y baixo
                //         if (joystick[1] < 450 && position[1] > 0) {
                //             *n_frascos = *n_frascos - 1;
                //         }
                //     }

                //     // looping para pegar valores para pipetagem
                //     if (index < *n_frascos) {
                //         // Salva a quantidade de volume do frasco n 
                //         if ((*step_jog-5) == 0 || (*step_jog-5) == 3 || (*step_jog-5) == 6 || (*step_jog-5) == 9 || (*step_jog-5) == 12 || (*step_jog-5) == 15 || (*step_jog-5) == 18 || (*step_jog-5) == 21 || (*step_jog-5) == 24) {
                //             start_FlaskH();
                //             joystick[0] = 0;
                //             joystick[1] = yAxis.read() * 1000;
                //             joystick[2] = 0; 

                //             // Deslocamento - y cima
                //             if (joystick[1] > 550) {
                //                 pPepet[index][3] = pPepet[index][3] + 1; 
                //             }

                //             // Deslocamento - y baixo
                //             if (joystick[1] < 450 && position[1] > 0) {
                //                 pPepet[index][3] = pPepet[index][3] - 1;
                //             }

                //             incre_loop++;
                //         }

                //         if ((*step_jog-5) == 1 || (*step_jog-5) == 4 || (*step_jog-5) == 7 || (*step_jog-5) == 10 || (*step_jog-5) == 13 || (*step_jog-5) == 16 || (*step_jog-5) == 19 || (*step_jog-5) == 22 || (*step_jog-5) == 25) {
                //             start_FlaskPosition();
                //             while (switchz == 0) {
                //                 // *step_jog-5 começa com valor 0 e vai aumentando de 1 em 1
                //                 pPepet[index][0] = position[0];
                //                 pPepet[index][1] = position[1];
                //                 switchz = 1;
                //                 incre_loop++;
                //             }
                //         }
                //     }

                //     *step_jog = *step_jog + 1; 
                // }
  

                // quebra do looping
                if (*step_jog-5 == *n_frascos) {
                    leave_cp = false;
                } 
            }
      
            
         }


  
