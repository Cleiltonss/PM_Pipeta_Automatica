#include "REFERENCING.h"


void REFERENCING(DigitalIn fdc[][2],
                 PwmOut MOTOR1_CLK, PwmOut MOTOR2_CLK, PwmOut MOTOR3_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, DigitalOut MOTOR_EN,
                 int position[3]) {

                    // Setando a velocidade dos motores
                    MOTOR1_CLK.period(0.01);
                    MOTOR2_CLK.period(0.01);
                    MOTOR3_CLK.period(0.01);

                    for (int i = 0; i < 3; i++) {

                        // Eixo xyz - Sentido 1
                        while(fdc[i][0] == 1 or fdc[i][1] == 1) {
                            MOTOR_EN = 0;
                            if (i == 0) {
                                MOTOR1_CW = 0; // direção do motor
                                MOTOR1_CLK.write(0.5); // Duty cicle para 50%
                            } 

                            if (i == 1) {
                                MOTOR2_CW = 0; // direção do motor
                                MOTOR2_CLK.write(0.5); 
                            }

                            if (i == 2) {
                                MOTOR3_CW = 0; // direção do motor
                                MOTOR3_CLK.write(0.5);
                            }
                        }

                        MOTOR_EN = 1;

                        // Eixo xyz - Sentido 2
                        while(fdc[i][0] == 0 or fdc[i][1] == 0) {
                            MOTOR_EN = 0;
                            if (i == 0) {
                                MOTOR1_CW = 1; // direção do motor
                                MOTOR1_CLK.write(0.5); // Duty cicle para 50%
                            }  

                            if (i == 1) {
                                MOTOR2_CW = 1; // direção do motor
                                MOTOR2_CLK.write(0.5); // Duty cicle para 50%
                            }  

                            if (i == 2) {
                                MOTOR3_CW = 1; // direção do motor
                                MOTOR3_CLK.write(0.5); // Duty cicle para 50%
                            }   
                        }
                    }
                    
                    // zeramento de variáveis no referenciamento

                    MOTOR1_CLK.write(0); // Duty cicle para 0%
                    MOTOR2_CLK.write(0); // Duty cicle para 0%
                    MOTOR3_CLK.write(0); // Duty cicle para 0%
                    MOTOR_EN = 1; // Desligando o Enable

                    position[0] = 0; // posição x
                    position[1] = 0; // posição y
                    position[2] = 0; // posição z
                }

