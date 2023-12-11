#include "AUT_PEPETTING.h"
#include "IHM.h"


// Função que realiza a subida da pipeta
void UP(int *z, 
       DigitalOut MOTOR_CLK, 
       DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
       DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
       float *speed) {

    


    // movimento para cima de volta - eixo z - até o ponto da posição de coleta
    MOTOR3_EN = 0;
    MOTOR_CLK = 0;
    wait(*speed);
    MOTOR_CLK = 1;
    wait(*speed);

    MOTOR3_CW = 0;

    *z = (*z+1);
    // printf("\rValor de Z na subida: %i\n", *z);
}

// Função que realiza a descida da pipeta
void DOWN(int *z,
             DigitalOut MOTOR_CLK, 
             DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
             DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
             float *speed) {


    // movimento para baixo de descida - eixo z
    MOTOR3_EN = 0;
    MOTOR_CLK = 0;
    wait(*speed);
    MOTOR_CLK = 1;
    wait(*speed);

    MOTOR3_CW = 1;
    *z = (*z-1);
}



// Função que realiza o retorno do ponto de um frasco até o ponto de coleta
//********************************************************INÍCIO DO RETORNO***********************************************************
void RETURN(int *x, int *y, int xCollect, int yCollect, 
             DigitalOut MOTOR_CLK, 
             DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
             DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
             float *speed) {
    
 


    // movimento para esquerda - eixo x - até o ponto de coleta
    if (*x > xCollect) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 1;
        *x = (*x-1);
    }


    if (*x > xCollect && xCollect < 0) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 1;
        *x = (*x-1);
    }
        
    // movimento para direita - eixo x - até o ponto de coleta
    if (*x < xCollect && xCollect >= 0) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 0;
        *x = (*x+1);
    }

    // movimento para direita - eixo x - até o ponto de coleta
    if (*x < xCollect && xCollect < 0) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 0;
        *x = (*x+1);
    }

    // movimento para baixo - eixo y - até o ponto de coleta
    if (*y > yCollect) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR1_CW = 0;
        *y = (*y-1);
    }

    // movimento para cima - eixo y - até o ponto de coleta
    if (*y > yCollect && yCollect < 0) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);
        MOTOR1_CW = 0;
        
        *y = (*y-1);
    }

    // movimento para cima - eixo y - até o ponto de coleta
    if (*y < yCollect && yCollect >= 0) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);
        MOTOR1_CW = 1;
        
        *y = (*y+1);
    }

    // movimento para cima - eixo y - até o ponto de coleta
    if (*y < yCollect && yCollect < 0) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);
        MOTOR1_CW = 1;
        
        *y = (*y+1);
    }

}
//********************************************************TERMINO DO RETORNO**********************************************************



// Função que realiza a ida do ponto de coleta até o ponto de um frasco
//********************************************************INÍCIO DA VOLTA***********************************************************
void TAKE(int xPepet, int yPepet, int *x, int *y, 
             DigitalOut MOTOR_CLK, 
             DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR3_CW, 
             DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN, DigitalOut MOTOR3_EN,
             float *speed) {
    
    

    // movimento para esquerda - eixo x - até o ponto de coleta
    if (*x > xPepet) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 1;
        *x = (*x-1);
    }

        
    // movimento para direita - eixo x - até o ponto de coleta
    if (*x < xPepet && xPepet >= 0) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 0;
        *x = (*x+1);
    }

    // movimento para direita - eixo x - até o ponto de coleta
    if (*x < xPepet && xPepet < 0) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 0;
        *x = (*x+1);
    }

    // movimento para direita - eixo x - até o ponto de coleta
    if (*x > xPepet && xPepet < 0) {
        MOTOR2_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR2_CW = 1;
        *x = (*x-1);
    }

    // movimento para baixo - eixo y - até o ponto de coleta
    if (*y > yPepet) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);

        MOTOR1_CW = 0;
        *y = (*y-1);
    }

    // movimento para cima - eixo y - até o ponto de coleta
    if (*y < yPepet && yPepet >= 0) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);
        MOTOR1_CW = 1;
        
        *y = (*y+1);
    }

    // movimento para cima - eixo y - até o ponto de coleta
    if (*y < yPepet && yPepet < 0) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);
        MOTOR1_CW = 1;
        
        *y = (*y+1);
    }

    // movimento para cima - eixo y - até o ponto de coleta
    if (*y > yPepet && yPepet < 0) {
        MOTOR1_EN = 0; 
        MOTOR_CLK = 0;
        wait(*speed);
        MOTOR_CLK = 1;
        wait(*speed);
        MOTOR1_CW = 0;
        
        *y = (*y-1);
    }
        

        
}
//********************************************************TERMINO DA VOLTA**********************************************************




