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

    // Inicializa o display
    tft.reset();
    tft.begin();
    tft.setRotation(Orientation);
    tft.fillScreen(PINK);  // Fundo do Display


    // mensagem: HELLO!
    tft.setTextColor(MAROON);
    tft.setTextSize(3);      // Tamanho do Texto no Display

    // movimento mensagem: HELLO! 
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
        delay(100);
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


    // LED YELLOW estado pulsante
    bool state = true; 
    while (state == true) {
        if (button_g == 0) {
            LED_Y = 1;
            wait(0.5); // testar se o tempo de piscar está bom
            LED_Y = 0;
            wait(0.5);
        } else {    
            state = false;
        }
    }
}

void during_ref(DigitalOut LED_Y) {
    LED_Y = 1;

    clean();
    tft.setTextColor(GREEN);
    tft.setTextSize(4); 
    tft.setCursor(120, 40);
    tft.println("REFERENCIANDO!");
}

void end_ref() {
    clean();
    tft.setTextColor(GREEN);
    tft.setTextSize(4); 
    tft.setCursor(120, 40);
    tft.println("REFERENCIADO!");
}
//************************************REFERENCING***********************************///







//******************************************JOG***********************************///
// TUDO AQUI TEM QUE SER AJUSTADO
void start_pCollect() {

    // mensagem: DEFINA PONTO DE COLETA
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("DEFINA PONTO");
    tft.setCursor(60, 70);
    tft.println("DE");
    tft.setCursor(40, 90);
    tft.println("COLETA");
    delay(2000);

    clean();
    // mensagem: DEFINA PONTO DE COLETA: XY
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("DEFINA PONTO DE COLETA: XY");
    delay(2000); 

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(75, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE PARA CONTINUAR");
}


void end_pCollectXY() {
    clean();
    // mensagem: PONTO DE COLETA DEFINIDO: XY
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("PONTO DE COLETA DEFINIDA: XY");
    delay(2000);  

    clean();
    // mensagem: DEFINA PONTO DE COLETA: Z
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("DEFINA PONTO DE COLETA: Z");
    delay(2000);  
}

void end_pCollectZ() {
    clean();
    // mensagem: PONTO DE COLETA DEFINIDO: Z
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("PONTO DE COLETA DEFINIDA: Z");

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(75, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE PARA CONTINUAR"); 
}

void start_pCollectH() {
    clean();
    // mensagem: DEFINA ALTURA DE COLETA: {MOSTRAR VALOR AQUI DENTRO} mL
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("DEFINA ALTURA DE COLETA: {MOSTRAR VALOR AQUI DENTRO} mL");
}

void end_pCollectH() {
    clean();
    // mensagem: ALTURA COLETA DEFINIDA
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("ALTURA COLETA DEFINIDA");
    delay(2000);  
    clean();
}

void start_NumFlask() {
    clean();
    // mensagem: DEFINA TOTAL DE FRASCOS: {EMITIR VALOR DE MUDANÇA NO DISPLAY}
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.printf("DEFINA TOTAL DE FRASCOS: %i\n", 12445);
    delay(2000);  
    clean();
}

void start_FlaskH() {
    clean();
    // mensagem: DEFINIR VALOR DE VOLUME: {EMITIR VALOR DO VOLUME} mL
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("DEFINIR VALOR DE VOLUME: {EMITIR VALOR DO VOLUME} mL");
    delay(2000);  
    clean();
}

void start_FlaskPosition() {
    clean();
    // mensagem: DEFINIR POSIÇÃO XY: {EMITIR VALOR DO VOLUME}
    tft.setTextColor(BLACK);
    tft.setTextColor(RED);
    tft.setCursor(110, 40);
    tft.println("DEFINIR POSIÇÃO XY: {EMITIR VALOR DO VOLUME}");
    delay(2000);  
    clean();
}
