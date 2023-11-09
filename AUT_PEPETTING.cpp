#include "mbed.h"
#include "AUT_PEPETTING.h"

void AUT_PIPETTING(int *n_frascos, int pCollect[3], int pPepet[][4], float *velocity, 
                   int *xcount, int *ycount, int *zcount, 
                   DigitalOut MOTOR1_CLK, DigitalOut MOTOR1_CW, 
                   DigitalOut MOTOR2_CLK, DigitalOut MOTOR2_CW,
                   DigitalOut MOTOR3_CLK, DigitalOut MOTOR3_CW,
                   DigitalOut MOTOR_EN,
                   Digitalout rele) {

    
    
    /* 

    Ajustando a posição da máquina para o ficar sob o ponto de coleta... 
    para cada valor de j, será analisado os eixos x, y e z respectivamente 

    */

    *velocity = 5 * (*velocity);

    // Sobe Eixo Z para: (*xcount, *ycount, 0)
    for (int i = *zcount; i == 0; i--) {
        MOTOR_EN = 0;
        MOTOR3_CW = 1;
        MOTOR3_CLK = 1;
        wait(*velocity); // intervalo de 10ms
        MOTOR3_CLK = 0;
        wait(*velocity); // intervalo de 10ms
        *zcount = *zcount - 1;
    }


    for (int j = 0; j < 3; j++) {
        // Quando a posição final em xy está a frente do ponto de coleta
        if (pPepet[*n_frascos][j] > pCollect[j]) {
            int distance = pPepet[*n_frascos][0] - pCollect[0];
            for (int i = 0; i < distance; i++) {
                if (j == 0) {
                    MOTOR_EN = 0;
                    MOTOR1_CW = 1;
                    MOTOR1_CLK = 1;
                    wait(*velocity); // intervalo de 10ms
                    MOTOR1_CLK = 0;
                    wait(*velocity); // intervalo de 10ms
                    *xcount = *xcount - 1;
                }

                if (j == 1) {
                    MOTOR_EN = 0;
                    MOTOR2_CW = 1;
                    MOTOR2_CLK = 1;
                    wait(*velocity); // intervalo de 10ms
                    MOTOR1_CLK = 0;
                    wait(*velocity); // intervalo de 10ms
                    *ycount = *ycount - 1;
                }
            }
        }

        // Quando a posição final em xy está atrás do ponto de coleta
        if (pPepet[*n_frascos][j] < pCollect[j]) {
            int distance = pCollect[0] - pPepet[*n_frascos][0];
            for (int i = 0; i < distance; i++) {
                if (j == 0) {
                    MOTOR_EN = 0;
                    MOTOR1_CW = 1;
                    MOTOR1_CLK = 1;
                    wait(*velocity); // intervalo de 10ms
                    MOTOR1_CLK = 0;
                    wait(*velocity); // intervalo de 10ms
                    *xcount = *xcount + 1;
                }

                if (j == 1) {
                    MOTOR_EN = 0;
                    MOTOR2_CW = 1;
                    MOTOR2_CLK = 1;
                    wait(*velocity); // intervalo de 10ms
                    MOTOR1_CLK = 0;
                    wait(*velocity); // intervalo de 10ms
                    *ycount = *ycount + 1;
                }
            }
        }
    }
    

    // Inicia as etapas de pipetagem para cada um dos frascos 
    for (int n = 0; n < *n_frascos; n++) {
        for (int vp = 0; vp < pPepet[n][3]; vp++) {

            // Desce eixo Z para posição de coleta
            for (int i = 0; i < pCollect[2]; i++) {
                MOTOR_EN = 0;
                MOTOR3_CW = 0;
                MOTOR3_CLK = 1;
                wait(*velocity); // intervalo de 10ms
                MOTOR3_CLK = 0;
                wait(*velocity); // intervalo de 10ms
                *zcount = *zcount + 1;
            }

            // acionamento da pipeta: pega líquido
            rele = 1; 

            // Sobe Eixo Z para: (xcoleta, ycoleta, 0)
            for (int i = *zcount; i == 0; i--) {
                MOTOR_EN = 0;
                MOTOR3_CW = 1;
                MOTOR3_CLK = 1;
                wait(*velocity); // intervalo de 10ms
                MOTOR3_CLK = 0;
                wait(*velocity); // intervalo de 10ms
                *zcount = *zcount - 1;
            }

            for (int j = 0; j < 3; j++) {
                // desloca xn e yn quando a posição em xy está na frente do ponto de coleta
                if (pPepet[n][j] > pCollect[j]) {
                    int distance = pPepet[n][0] - pCollect[0];
                    for (int i = 0; i < distance; i++) {
                        if (j == 0) {
                            MOTOR_EN = 0;
                            MOTOR1_CW = 1;
                            MOTOR1_CLK = 1;
                            wait(*velocity); // intervalo de 10ms
                            MOTOR1_CLK = 0;
                            wait(*velocity); // intervalo de 10ms
                            *xcount = *xcount - 1;
                        }

                        if (j == 1) {
                            MOTOR_EN = 0;
                            MOTOR2_CW = 1;
                            MOTOR2_CLK = 1;
                            wait(*velocity); // intervalo de 10ms
                            MOTOR1_CLK = 0;
                            wait(*velocity); // intervalo de 10ms
                            *ycount = *ycount - 1;
                        }
                    }
                }

                // desloca xn e yn quando a posição em xy está atrás do ponto de coleta
                if (pPepet[n][j] < pCollect[j]) {
                    int distance = pCollect[0] - pPepet[n][0];
                    for (int i = 0; i < distance; i++) {
                        if (j == 0) {
                            MOTOR_EN = 0;
                            MOTOR1_CW = 1;
                            MOTOR1_CLK = 1;
                            wait(*velocity); // intervalo de 10ms
                            MOTOR1_CLK = 0;
                            wait(*velocity); // intervalo de 10ms
                            *xcount = *xcount + 1;
                        }

                        if (j == 1) {
                            MOTOR_EN = 0;
                            MOTOR2_CW = 1;
                            MOTOR2_CLK = 1;
                            wait(*velocity); // intervalo de 10ms
                            MOTOR1_CLK = 0;
                            wait(*velocity); // intervalo de 10ms
                            *ycount = *ycount + 1;
                        }
                    }
                    
                    // Desce eixo Z para posição de zn
                    for (int i = 0; i < pPepet[n][3]; i++) {
                        MOTOR_EN = 0;
                        MOTOR3_CW = 0;
                        MOTOR3_CLK = 1;
                        wait(*velocity); // intervalo de 10ms
                        MOTOR3_CLK = 0;
                        wait(*velocity); // intervalo de 10ms
                        *zcount = *zcount + 1;
                    }

                    // Desacionar o relé: despeja o líquido
                    rele = 0;

                    // Sobe Eixo Z para: (xn, yn, 0)
                    for (int i = *zcount; i == 0; i--) {
                        MOTOR_EN = 0;
                        MOTOR3_CW = 1;
                        MOTOR3_CLK = 1;
                        wait(*velocity); // intervalo de 10ms
                        MOTOR3_CLK = 0;
                        wait(*velocity); // intervalo de 10ms
                        *zcount = *zcount - 1;
                    }


                    // retorna para a posição de coleta: (xc, yc, 0)
                    // Quando a posição final em xy está a frente do ponto de coleta
                    for (int j = 0; j < 3; j++) {
                        if (pPepet[*n_frascos][j] > pCollect[j]) {
                            int distance = pPepet[*n_frascos][0] - pCollect[0];
                            for (int i = 0; i < distance; i++) {
                                if (j == 0) {
                                    MOTOR_EN = 0;
                                    MOTOR1_CW = 1;
                                    MOTOR1_CLK = 1;
                                    wait(*velocity); // intervalo de 10ms
                                    MOTOR1_CLK = 0;
                                    wait(*velocity); // intervalo de 10ms
                                    *xcount = *xcount - 1;
                                }

                                if (j == 1) {
                                    MOTOR_EN = 0;
                                    MOTOR2_CW = 1;
                                    MOTOR2_CLK = 1;
                                    wait(*velocity); // intervalo de 10ms
                                    MOTOR1_CLK = 0;
                                    wait(*velocity); // intervalo de 10ms
                                    *ycount = *ycount - 1;
                                }
                            }
                        }

                        // Quando a posição final em xy está atrás do ponto de coleta
                        if (pPepet[*n_frascos][j] < pCollect[j]) {
                            int distance = pCollect[0] - pPepet[*n_frascos][0];
                            for (int i = 0; i < distance; i++) {
                                if (j == 0) {
                                    MOTOR_EN = 0;
                                    MOTOR1_CW = 1;
                                    MOTOR1_CLK = 1;
                                    wait(*velocity); // intervalo de 10ms
                                    MOTOR1_CLK = 0;
                                    wait(*velocity); // intervalo de 10ms
                                    *xcount = *xcount + 1;
                                }

                                if (j == 1) {
                                    MOTOR_EN = 0;
                                    MOTOR2_CW = 1;
                                    MOTOR2_CLK = 1;
                                    wait(*velocity); // intervalo de 10ms
                                    MOTOR1_CLK = 0;
                                    wait(*velocity); // intervalo de 10ms
                                    *ycount = *ycount + 1;
                                }
                            }
                        }
                    }

                }
            }

            
        }
    }
}
