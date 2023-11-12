#include "mbed.h"
#include "AUT_PEPETTING.h"
#include "IHM.h"

void AUT_PIPETTING(int *n_frascos, int pCollect[3], int pPepet[][4], int position[3], 
                   PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, 
                   DigitalOut rele) {

    
    // float speed = 0.01;
    // /* 

    // Ajustando a posição da máquina para o ficar sob o ponto de coleta... 
    // para cada valor de j, será analisado os eixos x, y e z respectivamente 

    // */

    // // Sobe Eixo Z para: (position[0], position[1], 0)
    // for (int i = position[2]; i == 0; i--) {
    //     MOTOR_EN = 0;

    //     // Deslocamento do MOTOR - z cima
    //     for (int j = 0; j < 4; j++) {
    //         MOTOR3 = 1 << j;
    //         wait(0.01);
    //     }
    //     position[2] = position[2] - 1;
    //     MOTOR3 = 0x0000; // conferir se esse é o valor correto
    // }


    // for (int j = 0; j < 3; j++) {

    //     // Quando a posição final em xy está a frente do ponto de coleta
    //     if (pPepet[*n_frascos][j] > pCollect[j]) {
    //         int distance = pPepet[*n_frascos][0] - pCollect[0];
    //         for (int i = 0; i < distance; i++) {
    //             if (j == 0) {
    //                 MOTOR_EN = 0; // ENABLE
    //                 MOTOR1_CLK.period(*speed);
    //                 MOTOR1_CLK.write(0.5); // Duty Cicle em 50%
    //                 MOTOR1_CW = 1;  // Direção
    //                 position[0] = position[0] - 1;
    //                 MOTOR1_CLK.write(0);
    //             }

    //             if (j == 1) {
    //                 MOTOR_EN = 0; // ENABLE
    //                 MOTOR2_CLK.period(*speed);
    //                 MOTOR2_CLK.write(0.5); // Duty Cicle em 50%
    //                 MOTOR2_CW = 1;  // Direção
    //                 position[1] = position[1] - 1;
    //                 MOTOR2_CLK.write(0); // Duty Cicle em 0%
    //             }
    //         }
    //     }

    //     // Quando a posição final em xy está atrás do ponto de coleta
    //     if (pPepet[*n_frascos][j] < pCollect[j]) {
    //         int distance = pCollect[0] - pPepet[*n_frascos][0];
    //         for (int i = 0; i < distance; i++) {
    //             if (j == 0) {
    //                 MOTOR_EN = 0; // ENABLE
    //                 MOTOR1_CLK.period(*speed);
    //                 MOTOR1_CLK.write(0.5); // Duty Cicle em 50%
    //                 MOTOR1_CW = 0; 
    //                 position[0] = position[0] + 1;
    //                 MOTOR1_CLK.write(0); // VERIFICAR SE PARAR O CLOCK BEM AQUI É A MELHOR ALTERNATIVA!
    //             }

    //             if (j == 1) {
    //                 MOTOR_EN = 0; // ENABLE
    //                 MOTOR2_CLK.period(*speed);
    //                 MOTOR2_CLK.write(0.5); // Duty Cicle em 50%
    //                 MOTOR2_CW = 0;  // Direção
    //                 position[1] = position[1] + 1;
    //                 MOTOR2_CLK.write(0); // Duty Cicle em 0%
    //             }
    //         }
    //     }
    // }
    

    // // Inicia as etapas de pipetagem para cada um dos frascos 
    // for (int n = 0; n < *n_frascos; n++) {
    //     for (int vp = 0; vp < pPepet[n][3]; vp++) {

    //         // Desce eixo Z para posição de coleta
    //         for (int i = 0; i < pCollect[2]; i++) {
    //             // Deslocamento do MOTOR - z cima
    //             for (int j = 0; j < 4; j++) {
    //                 MOTOR3 = 1 << j;
    //                 wait(0.01);
    //             }
    //             position[2] = position[2] + 1;
    //             MOTOR3 = 0x0000; // conferir se esse é o valor correto
    //         }

    //         // acionamento da pipeta: pega líquido
    //         rele = 1; 

    //         // Sobe Eixo Z para: (xcoleta, ycoleta, 0)
    //         for (int i = position[2]; i == 0; i--) {
    //             // Deslocamento do MOTOR - z baixo - VERIFICAR SE INVERTEU O SENTIDO
    //             for (int j = 4; j > 0; j--) {
    //                 MOTOR3 = 1 << j;
    //                 wait(0.01);
    //             }
    //             position[2] = position[2] - 1;
    //             MOTOR3 = 0x0000; // conferir se esse é o valor correto
    //         }

    //         for (int j = 0; j < 3; j++) {
    //             // desloca xn e yn quando a posição em xy está na frente do ponto de coleta
    //             if (pPepet[n][j] > pCollect[j]) {
    //                 int distance = pPepet[n][0] - pCollect[0];
    //                 for (int i = 0; i < distance; i++) {
    //                     if (j == 0) {
    //                         MOTOR_EN = 0; // ENABLE
    //                         MOTOR1_CLK.period(*speed);
    //                         MOTOR1_CLK.write(0.5); // Duty Cicle em 50%
    //                         MOTOR1_CW = 1;  // Direção
    //                         position[0] = position[0] - 1;
    //                         MOTOR1_CLK.write(0);
    //                     }

    //                     if (j == 1) {
    //                         MOTOR_EN = 0; // ENABLE
    //                         MOTOR2_CLK.period(*speed);
    //                         MOTOR2_CLK.write(0.5); // Duty Cicle em 50%
    //                         MOTOR2_CW = 1;  // Direção
    //                         position[1] = position[1] - 1;
    //                         MOTOR2_CLK.write(0); // Duty Cicle em 0%
    //                     }
    //                 }
    //             }

    //             // desloca xn e yn quando a posição em xy está atrás do ponto de coleta
    //             if (pPepet[n][j] < pCollect[j]) {
    //                 int distance = pCollect[0] - pPepet[n][0];
    //                 for (int i = 0; i < distance; i++) {
    //                     if (j == 0) {
    //                         MOTOR_EN = 0; // ENABLE
    //                         MOTOR1_CLK.period(*speed);
    //                         MOTOR1_CLK.write(0.5); // Duty Cicle em 50%
    //                         MOTOR1_CW = 0; 
    //                         position[0] = position[0] + 1;
    //                         MOTOR1_CLK.write(0); // VERIFICAR SE PARAR O CLOCK BEM AQUI É A MELHOR ALTERNATIVA!
    //                     }

    //                     if (j == 1) {
    //                         MOTOR_EN = 0; // ENABLE
    //                         MOTOR2_CLK.period(*speed);
    //                         MOTOR2_CLK.write(0.5); // Duty Cicle em 50%
    //                         MOTOR2_CW = 0;  // Direção
    //                         position[1] = position[1] + 1;
    //                         MOTOR2_CLK.write(0); // Duty Cicle em 0%
    //                     }
    //                 }
                    
    //                 // Desce eixo Z para posição de zn
    //                 for (int i = 0; i < pPepet[n][3]; i++) {
    //                     for (int j = 0; j < 4; j++) {
    //                         MOTOR3 = 1 << j;
    //                         wait(0.01);
    //                     }
    //                     position[2] = position[2] + 1;
    //                     MOTOR3 = 0x0000; // conferir se esse é o valor correto
    //                 }

    //                 // Desacionar o relé: despeja o líquido
    //                 rele = 0;

    //                 // Sobe Eixo Z para: (xn, yn, 0)
    //                 for (int i = position[2]; i == 0; i--) {
    //                     // Deslocamento do MOTOR - z baixo - VERIFICAR SE INVERTEU O SENTIDO
    //                     for (int j = 4; j > 0; j--) {
    //                         MOTOR3 = 1 << j;
    //                         wait(0.01);
    //                     }
    //                     position[2] = position[2] - 1;
    //                     MOTOR3 = 0x0000; // conferir se esse é o valor correto
    //                 }


    //                 // retorna para a posição de coleta: (xc, yc, 0)
    //                 // Quando a posição final em xy está a frente do ponto de coleta
    //                 for (int j = 0; j < 3; j++) {
    //                     if (pPepet[*n_frascos][j] > pCollect[j]) {
    //                         int distance = pPepet[*n_frascos][0] - pCollect[0];
    //                         for (int i = 0; i < distance; i++) {
    //                             if (j == 0) {
    //                                 MOTOR_EN = 0; // ENABLE
    //                                 MOTOR1_CLK.period(*speed);
    //                                 MOTOR1_CLK.write(0.5); // Duty Cicle em 50%
    //                                 MOTOR1_CW = 1;  // Direção
    //                                 position[0] = position[0] - 1;
    //                                 MOTOR1_CLK.write(0);
    //                             }

    //                             if (j == 1) {
    //                                 MOTOR_EN = 0; // ENABLE
    //                                 MOTOR2_CLK.period(*speed);
    //                                 MOTOR2_CLK.write(0.5); // Duty Cicle em 50%
    //                                 MOTOR2_CW = 1;  // Direção
    //                                 position[1] = position[1] - 1;
    //                                 MOTOR2_CLK.write(0); // Duty Cicle em 0%
    //                             }
    //                         }
    //                     }

    //                     // Quando a posição final em xy está atrás do ponto de coleta
    //                     if (pPepet[*n_frascos][j] < pCollect[j]) {
    //                         int distance = pCollect[0] - pPepet[*n_frascos][0];
    //                         for (int i = 0; i < distance; i++) {
    //                             if (j == 0) {
    //                                 MOTOR_EN = 0; // ENABLE
    //                                 MOTOR1_CLK.period(*speed);
    //                                 MOTOR1_CLK.write(0.5); // Duty Cicle em 50%
    //                                 MOTOR1_CW = 0; 
    //                                 position[0] = position[0] + 1;
    //                                 MOTOR1_CLK.write(0); // VERIFICAR SE PARAR O CLOCK BEM AQUI É A MELHOR ALTERNATIVA!
    //                             }

    //                             if (j == 1) {
    //                                 MOTOR_EN = 0; // ENABLE
    //                                 MOTOR2_CLK.period(*speed);
    //                                 MOTOR2_CLK.write(0.5); // Duty Cicle em 50%
    //                                 MOTOR2_CW = 0;  // Direção
    //                                 position[1] = position[1] + 1;
    //                                 MOTOR2_CLK.write(0); // Duty Cicle em 0%
    //                             }
    //                         }
    //                     }
    //                 }

    //             }
    //         }

            
    //     }
    // }
}
