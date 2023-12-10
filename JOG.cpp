// #include "JOG.h"
// #include "IHM.h"


// // joystick + coleta de dados para pipetagem
// int JOG(AnalogIn xAxis, AnalogIn yAxis,
//          DigitalOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
//          DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,  
//          int position[3], int *step_jog,
//          DigitalIn button_g, 
//          DigitalOut LED_G, DigitalOut LED_B,
//          int pCollect[4], int pPepet[][4],
//          int *n_frascos, int *index, float *speed)
//          int *n_frascos, int *index, int *loop) 
//          {

//             // IHM(LED_R, button_g);
//             int joystick[3]; // lista com as posições x,y,z do joystick
//             int switchz = 0; // variável que muda posição joystick xy para z
//             bool leave_cp = true; // Define quebra do looping total de saída
            
            
//             // start_pCollect(button_g, LED_B, LED_G);
//             // while (leave_cp == true) {    
//             //     // printf("\nTA DENTRO!\n");
//             //     if (switchz == 0) {
//             //         // Valores do joystick
//             //         joystick[0] = xAxis.read() * 1000; // float (0->1) to int (0->1000)
//             //         joystick[1] = yAxis.read() * 1000;
//             //         joystick[2] = 0;

//             //         // printf("\nX= %i, Y= %i\n", joystick[0], joystick[1]);
//             //         // Movimentação do JOYSTICK com interpolação de eixos
                
//             //         // sem movimento
//             //         if (joystick[0] < 550 && joystick[0] > 450 && joystick[1] < 550 && joystick[1] > 450) {
//             //             MOTOR1_EN = 1;
//             //             MOTOR2_EN = 1;
//             //             // printf("\rX e Y PARADOS!\n");
//             //         }
                    
//             //         // movimento leste
//             //         if (joystick[0] > 600 && joystick[1] < 550 && joystick[1] > 450) {
//             //             MOTOR1_EN = 1;

//             //             MOTOR2_EN = 0;
//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);

//             //             MOTOR2_CW = 0;
//             //             position[0]++;
//             //             // printf("\rposition[0]: %i\n", position[0]);
//             //             // printf("\nX DIREITA!\n");
//             //         }

//             //         // movimento oeste
//             //         if (joystick[0] < 400 && joystick[1] < 550 && joystick[1] > 450) {
//             //             MOTOR1_EN = 1;

//             //             MOTOR2_EN = 0; 
//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);

//             //             MOTOR2_CW = 1;
//             //             position[0]--;
//             //             // printf("\rX ESQUERDA!\n\n");
//             //         }

//             //         // movimento norte
//             //         if (joystick[1] > 600 && joystick[0] < 550 && joystick[0] > 450) {
//             //             MOTOR2_EN = 1;

//             //             MOTOR1_EN = 0;
//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);

//             //             MOTOR1_CW = 1; 
//             //             position[1]++;
//             //             // printf("\rY CIMA!\n\n");
//             //         }

//             //         // movimento sul
//             //         if (joystick[1] < 400 && joystick[0] < 550 && joystick[0] > 450) {
//             //             MOTOR2_EN = 1; // ENABLE

//             //             MOTOR1_EN = 0;
//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);

//             //             MOTOR1_CW = 0; 
//             //             position[1]--;
//             //             // printf("\rY BAIXO!\n\n");
//             //         }

//             //         // movimento nordeste
//             //         if (joystick[0] > 600 && joystick[1] > 600) {
//             //             MOTOR1_EN = 0; // ENABLE
//             //             MOTOR2_EN = 0; // ENABLE

//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);


//             //             MOTOR1_CW = 1; 
//             //             MOTOR2_CW = 0; 
//             //             position[0]++;
//             //             position[1]++;
//             //             // printf("\rNORDESTE!\n\n");
//             //         }
                    
//             //         // movimento noroeste
//             //         if (joystick[0] < 400 && joystick[1] > 600) {
//             //             MOTOR1_EN = 0; // ENABLE
//             //             MOTOR2_EN = 0; // ENABLE

//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);


//             //             MOTOR1_CW = 1; 
//             //             MOTOR2_CW = 1; 
//             //             position[0]--;
//             //             position[1]++;
//             //             // printf("\rNOROESTE\n\n");
//             //         }

//             //         // movimento sudoeste
//             //         if (joystick[0] < 400 && joystick[1] < 400) {
//             //             MOTOR1_EN = 0; // ENABLE
//             //             MOTOR2_EN = 0; // ENABLE

//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);

//             //             MOTOR1_CW = 0; 
//             //             MOTOR2_CW = 1; 
//             //             position[0]--;
//             //             position[1]--;
//             //             // printf("\rSUDOESTE!\n\n");
//             //         }

//             //         // movimento sudeste
//             //         if (joystick[0] > 600 && joystick[1] < 400) {
//             //             MOTOR1_EN = 0; // ENABLE
//             //             MOTOR2_EN = 0; // ENABLE

//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);

//             //             MOTOR1_CW = 0; 
//             //             MOTOR2_CW = 0; 
//             //             position[0]++;
//             //             position[1]--;
//             //             // printf("\rSUDESTE!\n\n");
//             //         }
//             //     }

                
//             //     // Eixo Z - movimento norte e sul
//             //     if (switchz == 1) {
//             //         joystick[0] = 0;
//             //         joystick[1] = 0;
//             //         joystick[2] = yAxis.read() * 1000;
                    
//             //         if (450 < joystick[2] && joystick[2] < 550) {
//             //             // printf("\rEIXO Z PARADO!\n");
//             //             MOTOR3_EN = 0; 
//             //         }
                    
//             //         // Deslocamento do MOTOR - z norte
//             //         if (joystick[2] > 600) {
//             //             MOTOR3_EN = 1;

//             //             MOTOR_CLK = 1;
//             //             wait(*speed);
//             //             MOTOR_CLK = 0;
//             //             wait(*speed);

//             //             MOTOR3_CW = 0;
//             //             position[2]++;
//             //             // printf("\rEIXO Z NORTE!\n\n");
//             //         }

//             //         // Deslocamento do MOTOR - z sul
//             //         if (joystick[2] < 400) {
//             //             MOTOR3_EN = 1;
                        
//             //             MOTOR_CLK = 1;
//             //             wait(*speed);
//             //             MOTOR_CLK = 0;
//             //             wait(*speed);
                        
//             //             MOTOR3_CW = 1;
//             //             position[2]--;
//             //             // printf("\rEIXO Z SUL!\n\n");
//             //         }


//             //         if (*step_jog == 3) {
//             //             // printf("\rPASSO 3!\n");
//             //             pCollect[2] = position[2];
//             //             // printf("\rZ: %i\n", pCollect[2]);
//             //             // É necessário zerar a contagem para as novas medidas dos frascos
//             //             position[0] = 0;
//             //             position[1] = 0;
//             //             position[2] = 0;

//             //             switchz = 0; // para de movimentar z 
//             //             *step_jog = *step_jog + 1; // necessário para  a próxima passada de etapa
//             //             // printf("\rFINALIZOU O PASSO 3!\n");
//             //         }

//             //         printf("\rValor de Z: %i\n", position[2]);
//             //         if (*step_jog == 9 || *step_jog == 14 || *step_jog == 18 || *step_jog == 22 || *step_jog == 26 || *step_jog == 30 || *step_jog == 34 || *step_jog == 38 || *step_jog == 42) {
//             //             // printf("\rVALOR DE ENTRADA DO *step_jog: %i\n", *step_jog);
//             //             pPepet[*index][2] = position[2];
//             //             *step_jog = *step_jog + 1; // primeiro ciclo aqui vai pra *step_jog = 10
//             //             // printf("\rFINALIZOU O PASSO %i!\n", *step_jog);
//             //             *index = *index + 1;
//             //             *step_jog = *step_jog+1; // *step_jog == 30
//             //             switchz = 0;
//             //             // printf("\r*index: %i\n", *index);
//             //             // printf("\r*position[2]: %i\n", position[2]);
//             //             // if (*index < *n_frascos) {
//             //             //     start_FlaskPosition(*index, position[0], position[1]);
//             //             // }
//             //             wait(1);
//             //         }
//             //     }


//             //     // Entrada dos passos de coleta e altura do frascos de coleta para pipetagem 
//             //     if (button_g == 0) {
//             //         if (*step_jog == 0) {
//             //             // printf("\rPASSO 0!\n");
//             //             // printf("\rFINALIZOU O PASSO 0!\n");
//             //         }

//             //         // Salva posições xy de coleta
//             //         if (*step_jog == 1) {
//             //             // printf("\rPASSO 1!\n");
//             //             end_pCollectXY(button_g, LED_B);
//             //             pCollect[0] = position[0];
//             //             pCollect[1] = position[1];
//             //             // printf("\rX: %i\n\rY: %i\n", pCollect[0], pCollect[1]);
//             //             switchz = 1;
//             //             // printf("\rFINALIZOU O PASSO 1!\n");
//             //             dur_pCollectZ();
//             //         }

//             //         // Salva a altura do ponto de coleta
//             //         if (*step_jog == 4) {
//             //             // printf("\rPASSO 4!\n");
//             //             start_pCollectH(position, button_g, LED_B); // verificar se salvou realmente a posição!
//             //             pCollect[3] = position[1]; // armazenou aqui o valor final para ter tudo de posição da COLETA
//             //             // printf("\rValor do Volume de Coleta: %i\n", pCollect[3]);
//             //             // printf("\rValor do step_jog: %i\n", *step_jog);
//             //             position[1] = 0;
//             //             end_pCollectH(button_g, LED_B, LED_G);
//             //             // printf("\rFINALIZOU O PASSO 4!\n");
//             //         }

//             //         // Salva quantidade de frascos para pipetagem - será substituido por tela touchscreen
//             //         if (*step_jog == 5) {
//             //             // printf("\rPASSO 5!\n");
//             //             start_NumFlask(button_g, n_frascos, LED_B, LED_G); // verificar se salvou os frascos
//             //             // printf("\rFINALIZOU O PASSO 5!\n");
//             //         }

            
//             //         if (*index < *n_frascos) {
//             //             // Salva a quantidade de volume do frasco n 
//             //             // printf("\rENTRANDO NA COLETA DOS FRASCOS\n");
//             //             // printf("\r*step_jog NA COLETA DE ALTURA DE FRASCOS: %i\n", *step_jog);

//             //             if (*step_jog == 6 || *step_jog == 11 || *step_jog == 14 || *step_jog == 18 || *step_jog == 22 || *step_jog == 26 || *step_jog == 30 || *step_jog == 34 || *step_jog == 38) {
//             //                 pPepet[*index][3] = start_FlaskH(pPepet[*index][3], button_g, LED_B, index); // ele está salvando! está correto!
//             //                 // printf("\rValor de altura do frasco %i: %i\n", *index+1, pPepet[*index][3]);
//             //                 // printf("\rTerminou a coleta com um total de %i frasco(s)\n", *index+1);
//             //                 // colocar led azul pulsante 

//             //                 start_FlaskPosition(*index, position[0], position[1]);
//             //             }

//             //             if (*step_jog == 7 || *step_jog == 12 || *step_jog == 17 || *step_jog == 22 || *step_jog == 28 || *step_jog == 33 || *step_jog == 38 || *step_jog == 43 || *step_jog == 48) {
//             //                 // printf("ENTROU NO PASSO QUE EU QUERIA!");
//             //                 pPepet[*index][0] = position[0];
//             //                 pPepet[*index][1] = position[1];
//             //                 switchz = 1;
//             //                 wait(0.5);
//             //                 start_FlaskPositionZ(*index);
//             //             }
//             //         }                    
//             //         *step_jog = *step_jog + 1; 
//             //         wait(1); // Controll Time to each time that the green button is press
//             //     }


//             //     // printf("\rValor step_jog: %i\n", *step_jog);
//             //     if (*step_jog == 7 || *step_jog == 12 || *step_jog == 16 || *step_jog == 20 || *step_jog == 24 || *step_jog == 28 || *step_jog == 32 || *step_jog == 36 || *step_jog == 40) {
//             //         // printf("\rDENTRO\n");
//             //         start_FlaskPositionUpdate(position[0], position[1]);
//             //     }

//             //     if (*step_jog == 8 || *step_jog == 13 || *step_jog == 18 || *step_jog == 23 || *step_jog == 28 || *step_jog == 33 || *step_jog == 38 || *step_jog == 43 || *step_jog == 48) {
//             //         start_FlaskPositionUpdateZ(position[2]);
//             //     }  
//                 // Eixo Z - movimento norte e sul
//                 if (switchz == 1) {
//                     joystick[0] = 0;
//                     joystick[1] = 0;
//                     joystick[2] = yAxis.read() * 1000;
                    
//                     if (450 < joystick[2] && joystick[2] < 550) {
//                         // printf("\rEIXO Z PARADO!\n");
//                         MOTOR3_EN = 0; 
//                     }
                    
//                     // Deslocamento do MOTOR - z norte
//                     if (joystick[2] > 600) {
//                         MOTOR3_EN = 1;
//                         MOTOR3_CW = 0;
//                         position[2]++;
//                         // printf("\rEIXO Z NORTE!\n\n");
//                     }

//                     // Deslocamento do MOTOR - z sul
//                     if (joystick[2] < 400) {
//                         MOTOR3_EN = 1;
//                         MOTOR3_CW = 1;
//                         position[2]--;
//                         // printf("\rEIXO Z SUL!\n\n");
//                     }


//                     if (*step_jog == 3) {
//                         printf("\rPASSO 3!\n");
//                         pCollect[2] = position[2];
//                         printf("\rZ: %i\n", pCollect[2]);
//                         // É necessário zerar a contagem para as novas medidas dos frascos
//                         position[0] = 0;
//                         position[1] = 0;
//                         position[2] = 0;

//                         switchz = 0; // para de movimentar z 
//                         *step_jog = *step_jog + 1; // necessário para  a próxima passada de etapa
//                         printf("\rFINALIZOU O PASSO 3!\n");
//                     }

//                     if (*step_jog == 9 || *step_jog == 13 || *step_jog == 17 || *step_jog == 21 || *step_jog == 25 || *step_jog == 29 || *step_jog == 33 || *step_jog == 37 || *step_jog == 41) {
//                         printf("\rPASSO %i!\n", *step_jog);
//                         pPepet[*index][2] = position[2];
//                         *step_jog = *step_jog + 1; // primeiro ciclo aqui vai pra *step_jog = 10
//                         printf("\rFINALIZOU O PASSO %i!\n", *step_jog);
//                         *index = *index+1;
//                         *step_jog = *step_jog+1; // *step_jog == 30
//                         switchz = 0;

//                         if (*index < *n_frascos) {
//                             start_FlaskPosition(*index, position[0], position[1]);
//                         }
//                     }
//                 }


//                 // Entrada dos passos de coleta e altura do frascos de coleta para pipetagem 
//                 if (button_g == 0) {
//                     if (*step_jog == 0) {
//                         printf("\rPASSO 0!\n");
//                         printf("\rFINALIZOU O PASSO 0!\n");
//                     }

//                     // Salva posições xy de coleta
//                     if (*step_jog == 1) {
//                         printf("\rPASSO 1!\n");
//                         end_pCollectXY(button_g, LED_B);
//                         pCollect[0] = position[0];
//                         pCollect[1] = position[1];
//                         // printf("\rX: %i\n\rY: %i\n", pCollect[0], pCollect[1]);
//                         switchz = 1;
//                         printf("\rFINALIZOU O PASSO 1!\n");
//                         dur_pCollectZ();
//                     }

//                     // Salva a altura do ponto de coleta
//                     if (*step_jog == 4) {
//                         printf("\rPASSO 4!\n");
//                         start_pCollectH(position, button_g, LED_B); // verificar se salvou realmente a posição!
//                         pCollect[3] = position[1]; // armazenou aqui o valor final para ter tudo de posição da COLETA
//                         printf("\rValor do Volume de Coleta: %i\n", pCollect[3]);
//                         // printf("\rValor do step_jog: %i\n", *step_jog);
//                         position[1] = 0;
//                         end_pCollectH(button_g, LED_B, LED_G);
//                         printf("\rFINALIZOU O PASSO 4!\n");
//                     }

//                     // Salva quantidade de frascos para pipetagem - será substituido por tela touchscreen
//                     if (*step_jog == 5) {
//                         printf("\rPASSO 5!\n");
//                         start_NumFlask(button_g, n_frascos, LED_B, LED_G); // verificar se salvou os frascos
//                         printf("\rFINALIZOU O PASSO 5!\n");
//                     }

            
//                     if (*index < *n_frascos) {
//                         // Salva a quantidade de volume do frasco n 
//                         // printf("\rENTRANDO NA COLETA DOS FRASCOS\n");
//                         if (*step_jog == 6 || *step_jog == 10 || *step_jog == 14 || *step_jog == 18 || *step_jog == 22 || *step_jog == 26 || *step_jog == 30 || *step_jog == 34 || *step_jog == 38) {
//                             // printf("\rValor de pPete[index][3]: %i\n", index);
//                             pPepet[*index][3] = start_FlaskH(pPepet[*index][3], button_g, LED_B, index); // ele está salvando! está correto!
//                             printf("\rValor de altura do frasco %i: %i\n", *index+1, pPepet[*index][3]);
//                             // printf("\rTerminou a coleta com um total de %i frasco(s)\n", *index+1);
//                             // colocar led azul pulsante 

//                             start_FlaskPosition(*index, position[0], position[1]);
//                         }

//                         if (*step_jog == 7 || *step_jog == 11 || *step_jog == 15 || *step_jog == 19 || *step_jog == 23 || *step_jog == 27 || *step_jog == 31 || *step_jog == 35 || *step_jog == 39) {
//                             // printf("ENTROU NO PASSO QUE EU QUERIA!");
//                             pPepet[*index][0] = position[0];
//                             pPepet[*index][1] = position[1];
//                             switchz = 1;
//                             wait(0.5);
//                             start_FlaskPositionZ(*index);
//                         }
//                     }                    
//                     *step_jog = *step_jog + 1; 
//                     wait(1); // Controll Time to each time that the green button is press
//                 }


//                 // printf("\rValor step_jog: %i\n", *step_jog);
//                 if (*step_jog == 7 || *step_jog == 11 || *step_jog == 15 || *step_jog == 19 || *step_jog == 23 || *step_jog == 27 || *step_jog == 31 || *step_jog == 35 || *step_jog == 39) {
//                     // printf("\rDENTRO\n");
//                     start_FlaskPositionUpdate(position[0], position[1]);
//                 }

//                 if (*step_jog == 8 || *step_jog == 12 || *step_jog == 16 || *step_jog == 20 || *step_jog == 24 || *step_jog == 28 || *step_jog == 32 || *step_jog == 36 || *step_jog == 40) {
//                     start_FlaskPositionUpdateZ(position[2]);
//                 }
    

//                 // quebra do looping - sai do while no passo 5
//                 if (*index == *n_frascos) {
//                     LED_G = 1;
//                     leave_cp = false;
//                 } 
                
//             // }
//          }


  

