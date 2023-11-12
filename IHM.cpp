#include "mbed.h"
#include "IHM.h"
#include "Arduino.h"
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft; // VER DEPOIS PQ TA DANDO ERRO

uint8_t Orientation = 1; 

//***********************Tabela de Cores**************************************//
#define BLACK        0x0000
#define BLUE         0x001F
#define RED          0xF800
#define GREEN        0x07E0
#define DARKGREEN    0x03E0
#define CYAN         0x07FF
#define DARKCYAN     0x03EF
#define MAGENTA      0xF81F
#define YELLOW       0xFFE0
#define WHITE        0xFFFF
#define PINK         0xFC9F
#define NAVY         0x000F
#define MAROON       0x7800
#define PURPLE       0x780F
#define OLIVE        0x7BE0
#define LIGHTGREY    0xC618
#define DARKGREY     0x7BEF
//****************************************************************************//


// Função para limpar a tela
void clean() {
    tft.fillScreen(PINK);
}



//************************************REFERENCING***********************************///
void start_ref(DigitalOut button_g, DigitalOut LED_Y){

    // Inicializando o display
    tft.reset(); // reseta tudo do display
    tft.begin(); // inicializa o display
    tft.setRotation(Orientation); // Seta a direção da tela na horizontal: Orientation = 1
    tft.fillScreen(PINK);  // Fundo do Display - Fundo da tela


    // mensagem: HELLO!
    tft.setTextColor(MAROON); // Seta a cor do texto
    tft.setTextSize(3);      // Tamanho do Texto no Display

    // movimento da mensagem: HELLO! 
    for (int i = 0; i < 10; i++) {
        if (i == 0 or i == 5) {
            tft.setCursor(110, 90);
        }

        if (i == 1 or i == 6) {
            tft.setCursor(100, 80);
        } 

        if (i == 2 or i == 7) {
            tft.setCursor(120, 80);
        } 

        if (i == 3 or i == 8) {
            tft.setCursor(110, 100);
        } 

        if (i == 4 or i == 9) {
            tft.setCursor(125, 110);
        } 

        tft.println("Hello!");
        delay(70);
        clean();
    }

    tft.setCursor(110, 100); //  Orientação do texto X,Y
    tft.println("Hello!");
    delay(1000);

    clean(); 

    // mensagem: Deseja Referenciar?
    tft.setTextColor(PINK);
    tft.setTextColor(DARKCYAN);
    tft.setCursor(110, 40);
    tft.println("Deseja");
    tft.setCursor(60, 70);
    tft.println("Referenciar?");


    // retângulo mensagem: PRESSIONE VERDE
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(75, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");
    

    // // NÃO CONSIGO DESLIGAR O LED NO FINAL!!!
    // bool state = true;
    // while (state == true) {
    //     LED_Y = 1;
    //     wait(0.5);
    //     LED_Y = 0;
    //     wait(0.5);

    //     if (button_g == 0) {
            
    //         state = false;
    //     }
    // }
}

void end_ref(DigitalOut LED_Y, DigitalOut LED_G) {
    // // LED NÃO ACENDE!!
    // printf("\rDENTRO DO END_REF\n");
    // clean();
    // tft.setTextColor(GREEN);
    // tft.setTextSize(4); 
    // tft.setCursor(120, 40);
    // tft.println("REFERENCIADO!");
}
//************************************REFERENCING***********************************///







//**************************************************************JOG***********************************///


//*************************************************************FEITO***************************************************

void start_pCollect() {

    //mensagem: DEFINA PONTO DE COLETA
    tft.setTextSize(3);    
    tft.setTextColor(DARKCYAN);
    char coleta[7] = {"COLETA"};

    for (int i = 0; i < 116; i = i+2) {
        clean();
        tft.setCursor(i, 180);
        for (int j = 0; j < 7; j++) {
            tft.printf("%c", coleta[j]);
        }
        delay(1);
    }
    tft.setTextColor(PURPLE);
    tft.setCursor(55, 30);
    tft.println("DEFINA PONTO");
    tft.setCursor(155, 110);
    tft.println("DE");
    tft.setTextColor(PURPLE);
    delay(2000);

    clean();
    // mensagem: DEFINA PONTO DE COLETA: XY
    tft.setTextSize(3);
    for (int i = 0; i < 10; i++) {
        clean();
        if (i == 0) {
            tft.setTextColor(YELLOW);
        }
        if (i == 1) {
            tft.setTextColor(BLUE);
        }
        if (i == 2) {
            tft.setTextColor(GREEN);
        }
        if (i == 3) {
            tft.setTextColor(PURPLE);
        }
        if (i == 4) {
            tft.setTextColor(BLACK);
        }
        if (i == 5) {
            tft.setTextColor(OLIVE);
        }
        if (i == 6) {
            tft.setTextColor(NAVY);
        }
        if (i == 7) {
            tft.setTextColor(DARKGREEN);
        }
        if (i == 8) {
            tft.setTextColor(MAGENTA);
        }
        if (i == 9) {
            tft.setTextColor(DARKCYAN);
        }
        tft.setCursor(50, 50);
        tft.println("DEFINA X e Y");
        delay(50);
    }
    
    delay(200); 

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(70, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");
}
//*************************************************************FEITO***************************************************



void end_pCollectXY() {
    // clean();
    // // mensagem: PONTO DE COLETA DEFINIDO: XY
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("PONTO DE COLETA DEFINIDA: XY");
    // delay(2000);  

    // clean();
    // // mensagem: DEFINA PONTO DE COLETA: Z
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("DEFINA PONTO DE COLETA: Z");
    // delay(2000);  
}

void end_pCollectZ() {
    // clean();
    // // mensagem: PONTO DE COLETA DEFINIDO: Z
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("PONTO DE COLETA DEFINIDA: Z");

    // // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    // tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    // tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    // tft.setTextColor(WHITE);
    // tft.setTextSize(2);
    // tft.setCursor(75, 155); // Orientação X,Y
    // tft.println("PRESSIONE VERDE PARA CONTINUAR"); 
}

void start_pCollectH() {
    // clean();
    // // mensagem: DEFINA ALTURA DE COLETA: {MOSTRAR VALOR AQUI DENTRO} mL
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("DEFINA ALTURA DE COLETA: {MOSTRAR VALOR AQUI DENTRO} mL");
}

void end_pCollectH() {
    // clean();
    // // mensagem: ALTURA COLETA DEFINIDA
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("ALTURA COLETA DEFINIDA");
    // delay(2000);  
    // clean();
}

void start_NumFlask() {
//     clean();
//     // mensagem: DEFINA TOTAL DE FRASCOS: {EMITIR VALOR DE MUDANÇA NO DISPLAY}
//     tft.setTextColor(BLACK);
//     tft.setTextColor(RED);
//     tft.setCursor(110, 40);
//     tft.printf("DEFINA TOTAL DE FRASCOS: %i\n", 12445);
//     delay(2000);  
//     clean();
}

void start_FlaskH() {
    // clean();
    // // mensagem: DEFINIR VALOR DE VOLUME: {EMITIR VALOR DO VOLUME} mL
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("DEFINIR VALOR DE VOLUME: {EMITIR VALOR DO VOLUME} mL");
    // delay(2000);  
    // clean();
}

void start_FlaskPosition() {
    // clean();
    // // mensagem: DEFINIR POSIÇÃO XY: {EMITIR VALOR DO VOLUME}
    // tft.setTextColor(BLACK);
    // tft.setTextColor(RED);
    // tft.setCursor(110, 40);
    // tft.println("DEFINIR POSIÇÃO XY: {EMITIR VALOR DO VOLUME}");
    // delay(2000);  
    // clean();
}









// // BOTÕES DE + e -
//     tft.fillCircle(60,180,40,GREEN); // X, Y, Raio, COR
//     tft.setTextColor(WHITE);
//     tft.setTextSize(4);
//     tft.setCursor(50, 167); // Orientação X,Y
//     tft.println("+");

//     tft.fillCircle(260,180,40,RED);
//     //tft.fillCircle(150,110,80,WHITE);
//     tft.setTextColor(WHITE);
//     tft.setTextSize(4);
//     tft.setCursor(250, 167); // Orientação X,Y
//     tft.println("-");