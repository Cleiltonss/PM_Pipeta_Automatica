#include "REFERENCING.h"
#include "IHM.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], float *speed,
                 PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, 
                 DigitalIn button_g,
                 DigitalOut LED_Y, DigitalOut LED_G) {

                    
                    start_ref(button_g, LED_Y); 

                    
                    MOTOR_CLK.write(0.5); // Duty cicle para 50%
                    MOTOR_CLK.period(*speed); // *speed inicial igual a 0.01
                    
                    dur_ref();
                    if (button_g == 0) {
                        printf("\rVERDE PRESSIONADO!\n");
                        for (int i = 0; i < 3; i++) {

                            // Eixo xyz - Sentido 1
                            while(fdc[i][0] == 1 or fdc[i][1] == 1) {
                                if (i == 0) {
                                    MOTOR1_EN = 0;
                                    MOTOR1_CW = 0; // direção do motor

                                    MOTOR2_EN = 1;
                                } 

                                if (i == 1) {
                                    MOTOR1_EN = 1;
        
                                    MOTOR2_EN = 0;
                                    MOTOR2_CW = 0; // direção do motor
                                }

                                if (i == 2) { // deve ser alterado para testar o Z
                                    // for (int j = 0; j < 4; j++) {
                                    //     MOTOR3 = 1 << j;
                                    //     wait(0.01);
                                    // }
                                    // MOTOR3 = 0x0000; // conferir se esse é o valor correto
                                }
                            }

                            // desliga os motores
                            MOTOR1_EN = 1;
                            MOTOR2_EN = 1;


                            // Eixo xyz - Sentido 2
                            while(fdc[i][0] == 0 or fdc[i][1] == 0) {
                                if (i == 0) {
                                    MOTOR1_EN = 0;
                                    MOTOR1_CW = 1; // direção do motor

                                    MOTOR2_EN = 1;
                                }  

                                if (i == 1) {
                                    MOTOR1_EN = 1;
        
                                    MOTOR2_EN = 0;
                                    MOTOR2_CW = 1; // direção do motor
                                } 
                                
                                if (i == 2) {
                                    // for (int j = 0; j < 4; j++) {
                                    //     MOTOR3 = 1 << j;
                                    //     wait(0.01);
                                    // }
                                    // MOTOR3 = 0x0000; // conferir se esse é o valor correto 
                                } 
                            }
                        }
                    }
                    
                    end_ref(LED_Y, LED_G);
                    
                    // zeramento de variáveis no referenciamento

                    MOTOR_CLK.write(0);
                    MOTOR1_EN = 1; // Desligando o MOTOR1
                    MOTOR2_EN = 1; // Desligando o MOTOR2

                    position[0] = 1; // posição x
                    position[1] = 2; // posição y
                    position[2] = 3; // posição z
                }

