#include "REFERENCING.h"
#include "IHM.h"


void REFERENCING(DigitalIn fdc[][2], int position[3], float *speed,
                 PwmOut MOTOR_CLK, 
                 DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
                 DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN, 
                 DigitalIn button_g,
                 DigitalOut LED_Y, DigitalOut LED_G, DigitalIn fdcz1) {
                    
                    dur_ref();

                    
                    // eixo x
                    while(1) {
                        if (fdc[0][0] == 1 || fdc[0][1] == 1) {
                                printf("\rTA MOVENDO X!\n");
                                MOTOR1_EN = 0;
                                MOTOR1_CW = 1;
                            } 

                        if (fdc[0][0] == 0 || fdc[0][1] == 0) {
                            // printf("\rENTROU RETORNO X!\n");
                            while(1) {
                                if (fdc[0][0] == 0 || fdc[0][1] == 0) {
                                    printf("\rTA RETORNANDO X!\n");
                                    MOTOR1_EN = 0;
                                    MOTOR1_CW = 0;
                                } else if (fdc[0][0] == 1 || fdc[0][1] == 1) {
                                    printf("\rSAIU DO RETORNO X!\n");
                                    MOTOR1_EN = 1;
                                    break;
                                } 
                                
                            }
                            break;
                        }   
                    }

                    
                    // eixo y
                    while(1) {
                        // printf("\rENTROU\n");
                        if (fdc[1][0] == 1 || fdc[1][1] == 1) {
                                printf("\rTA MOVENDO Y!\n");
                                MOTOR2_EN = 0;
                                MOTOR2_CW = 1;
                            } 

                        if (fdc[1][0] == 0 || fdc[1][1] == 0) {
                            // printf("\rENTROU NO RETORNO Y!\n");
                            while(1) {
                                if (fdc[1][0] == 0 || fdc[1][1] == 0) {
                                    printf("\rRETORNANDO Y!\n");
                                    MOTOR2_EN = 0;
                                    MOTOR2_CW = 0;
                                } else if (fdc[1][0] == 1 || fdc[1][1] == 1) {
                                    printf("\rSAIU DO RETORNO DE Y!\n");
                                    MOTOR2_EN = 1;
                                    break;
                                } 
                                
                            }
                            break;
                        }   
                    }


                    // eixo z
                    while(1) {
                        // printf("\rENTROU\n");
                        if (fdc[2][0] == 1 /*|| fdc[2][1] == 1*/) {
                                printf("\rMOVENDO Z!\n");
                                MOTOR3_EN = 0;
                                MOTOR3_CW = 1;
                            } 

                        if (fdc[2][0] == 0 /*|| fdc[2][1] == 0*/) {
                            // printf("\rENTROU RETORNO DE Z!!\n");
                            while(1) {
                                if (fdc[2][0] == 0 /*|| fdc[2][1] == 0*/) {
                                    printf("\rRETORNANDO Z!\n");
                                    MOTOR3_EN = 0;
                                    MOTOR3_CW = 0;
                                } else if (fdc[2][0] == 1 /*|| fdc[2][1] == 1*/) {
                                    printf("\rSAIU DO RETORNO DE Z, ACABOU!\n");
                                    MOTOR3_EN = 1;
                                    break;
                                } 
                                
                            }
                            break;
                        }   
                    }
                    
                    // end_ref(LED_Y, LED_G);
                }
                         

