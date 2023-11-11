#include "REFERENCING.h"
#include "IHM.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], float *speed,
                 PwmOut MOTOR1_CLK, PwmOut MOTOR2_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR_EN, BusOut MOTOR3,
                 DigitalOut button_g,
                 DigitalOut LED_Y) {

                    start_ref(button_g, LED_Y);
            
                    for (int i = 0; i < 3; i++) {
                        // during_ref(DigitalOut LED_Y);

                        // Eixo xyz - Sentido 1
                        while(fdc[i][0] == 1 or fdc[i][1] == 1) {
                            MOTOR_EN = 0;
                            if (i == 0) {
                                MOTOR1_CLK.period(*speed);
                                MOTOR1_CW = 0; // direção do motor
                                MOTOR1_CLK.write(0.5); // Duty cicle para 50%
                            } 

                            if (i == 1) {
                                MOTOR2_CLK.period(*speed);
                                MOTOR2_CW = 0; // direção do motor
                                MOTOR2_CLK.write(0.5); 
                            }

                            if (i == 2) { // deve ser alterado para testar o Z
                                for (int j = 0; j < 4; j++) {
                                    MOTOR3 = 1 << j;
                                    wait(0.01);
                                }
                                MOTOR3 = 0x0000; // conferir se esse é o valor correto
                            }
                        }

                        MOTOR_EN = 1;

                        // Eixo xyz - Sentido 2
                        while(fdc[i][0] == 0 or fdc[i][1] == 0) {
                            MOTOR_EN = 0;
                            if (i == 0) {
                                MOTOR1_CLK.period(*speed);
                                MOTOR1_CW = 1; // direção do motor
                                MOTOR1_CLK.write(0.5); // Duty cicle para 50%
                            }  

                            if (i == 1) {
                                MOTOR2_CLK.period(*speed);
                                MOTOR2_CW = 1; // direção do motor
                                MOTOR2_CLK.write(0.5); // Duty cicle para 50%
                            }  

                            for (int j = 0; j < 4; j++) {
                                    MOTOR3 = 1 << j;
                                    wait(0.01);
                                }
                                MOTOR3 = 0x0000; // conferir se esse é o valor correto 
                        }
                    }
                    
                    // zeramento de variáveis no referenciamento

                    MOTOR1_CLK.write(0); // Duty cicle para 0%
                    MOTOR2_CLK.write(0); // Duty cicle para 0%
                    MOTOR_EN = 1; // Desligando o Enable

                    position[0] = 0; // posição x
                    position[1] = 0; // posição y
                    position[2] = 0; // posição z

                    end_ref();
                }

