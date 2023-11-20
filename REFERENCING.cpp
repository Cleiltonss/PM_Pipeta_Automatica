#include "REFERENCING.h"
#include "IHM.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], float *speed,
                 DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, 
                 DigitalIn button_g,
                 DigitalOut LED_Y, DigitalOut LED_G) {
                    
                    // eixo x
                    while(1) {
                        if (fdc[0][0] == 1 || fdc[0][1] == 1) {
                                // printf("\rTA MOVENDO!\n");
                                MOTOR1_EN = 0;
                                MOTOR1_CW = 1;
                            } 

                        if (fdc[0][0] == 0 || fdc[0][1] == 0) {
                            // printf("\rENTROU RETORNO!!\n");
                            while(1) {
                                if (fdc[0][0] == 0 || fdc[0][1] == 0) {
                                    // printf("\rTA RETORNANDO!\n");
                                    MOTOR1_EN = 0;
                                    MOTOR1_CW = 0;
                                } else if (fdc[0][0] == 1 || fdc[0][1] == 1) {
                                    // printf("\rSAIU DO RETORNO, ACABOU!\n");
                                    MOTOR1_EN = 1;
                                    break;
                                } 
                                
                            }
                            break;
                        }
                    
                    
                        
                    }

                    


                    // // volta
                    // while(1) {
                    //     if (fdc[0][0] == 1 || fdc[0][1] == 1) {
                    //             printf("\rENTROU NO WHILE CERTO!\n");
                    //             MOTOR1_EN = 0;
                    //             MOTOR1_CW = 1;
                    //         } 
                        
                    //     if (fdc[1][0] == 1 || fdc[1][1] == 1) {
                    //             printf("\rENTROU NO WHILE CERTO!\n");
                    //             MOTOR1_EN = 0;
                    //             MOTOR1_CW = 1;
                    //         } 

                    //     if (fdc[2][0] == 1 || fdc[2][1] == 1) {
                    //             printf("\rENTROU NO WHILE CERTO!\n");
                    //             MOTOR1_EN = 1;
                    //             MOTOR1_CW = 0;
                    //         } 
                            
                        // if (fdc[0][0] == 0 || fdc[0][1] == 0) {
                        //     printf("\rENTROU NO ERRADO!!\n");
                        //     MOTOR1_EN = 1;
                        //     break;
                        // }

                        // if (fdc[1][0] == 0 || fdc[1][1] == 0) {
                        //     printf("\rENTROU NO ERRADO!!\n");
                        //     MOTOR1_EN = 1;
                        //     break;
                        // }

                        // if (fdc[2][0] == 0 || fdc[2][1] == 0) {
                        //     printf("\rENTROU NO ERRADO!!\n");
                        //     MOTOR1_EN = 1;
                        //     break;
                        // }
                        
                    }
                                                // }



                        // printf("\rVERDE PRESSIONADO!\n");
                        // for (int i = 0; i < 3; i++) {
                        //     if (fdc[i][0] == 1 || fdc[i][1] == 1) {
                        //             MOTOR2_EN = 1;

                        //             MOTOR1_EN = 0;
                        //             MOTOR1_CW = 0; // direção do motor
                        //         } else {
                        //             MOTOR1_EN = 1;
                        //             break;
                        //     }

                            // // desliga os motores
                            // MOTOR1_EN = 1;
                            // MOTOR2_EN = 1;


                            // // Eixo xyz - Sentido 2
                            // while(fdc[i][0] == 0 or fdc[i][1] == 0) {
                            //     if (i == 0) {
                            //         MOTOR1_EN = 0;
                            //         MOTOR1_CW = 1; // direção do motor

                            //         MOTOR2_EN = 1;
                            //     }  

                            //     if (i == 1) {
                            //         MOTOR1_EN = 1;
        
                            //         MOTOR2_EN = 0;
                            //         MOTOR2_CW = 1; // direção do motor
                            //     } 
                                
                            //     if (i == 2) {
                            //         // for (int j = 0; j < 4; j++) {
                            //         //     MOTOR3 = 1 << j;
                            //         //     wait(0.01);
                            //         // }
                            //         // MOTOR3 = 0x0000; // conferir se esse é o valor correto 
                            //     } 
                            // }
                 
                    
                    // end_ref(LED_Y, LED_G);
                    
                    // zeramento de variáveis no referenciamento

                    // MOTOR_CLK.write(0);
                    // MOTOR1_EN = 1; // Desligando o MOTOR1
                    // MOTOR2_EN = 1; // Desligando o MOTOR2

                    // position[0] = 1; // posição x
                    // position[1] = 2; // posição y
                    // position[2] = 3; // posição z
                // }

