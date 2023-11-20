#include "mbed.h"
#include "IHM.h"
#include "Arduino.h"
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft; 
#include "TouchScreen_kbv_mbed.h"

// //para o carregamento
// #include <iostream>
// #include <cmath>

//******************************Configuração do Display***********************//
const PinName XP = D8, YP = A3, XM = A2, YM = D9; 
const int TS_LEFT=121,TS_RT=922,TS_TOP=82,TS_BOT=890;
DigitalInOut YPout(YP);
DigitalInOut XMout(XM);
TouchScreen_kbv ts = TouchScreen_kbv(XP, YP, XM, YM);
TSPoint_kbv tp;

// Valores para detectar a pressão do toque 
#define MINPRESSURE 10
#define MAXPRESSURE 1000

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

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
//***********************Tabela de Cores**************************************//





// Função para limpar as telas de referenciamentos
void clean() {
    tft.fillScreen(PINK);
}


// Função para limpar a tela
void clean_start_NumFlask() {
    
    // BOTÕES DE + e -
    tft.fillCircle(60,180,40,GREEN); // X, Y, Raio, COR
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(50, 167); // Orientação X,Y
    tft.println("+");

    tft.fillCircle(230,180,40,RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(220, 167); // Orientação X,Y
    tft.println("-");

    // retângulo mensagem: PRESSIONE VERDE
    tft.fillRoundRect(18, 50, 281, 60, 1, BLUE); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(60, 60); // Orientação X,Y
    tft.println("VALUE: ");
}



// Função para fazer a limpeza de tela da start_pCollectH
void clean_start_pCollectH() {
    // BOTÕES DE + e -
    tft.fillCircle(190,180,40, GREEN); // X, Y, Raio, COR
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(180, 167); // Orientação X,Y
    tft.println("-");

    tft.fillCircle(70,180,40,RED);
    tft.setTextSize(4);
    tft.setCursor(60, 167); // Orientação X,Y
    tft.println("+");    

    tft.fillRoundRect(18, 20, 230, 100, 1, BLACK); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(40, 60); // Orientação X,Y
    tft.println("VALUE: ");
}


// Função para limpar a tela
void clean_start_FlaskH() {

    tft.fillScreen(PINK);
    
    // BOTÕES DE + e -
    tft.fillCircle(60,180,40,GREEN); // X, Y, Raio, COR
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(50, 167); // Orientação X,Y
    tft.println("+");

    tft.fillCircle(230,180,40,RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(220, 167); // Orientação X,Y
    tft.println("-");

    // retângulo mensagem: PRESSIONE VERDE
    tft.fillRoundRect(18, 50, 281, 60, 1, BLUE); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(60, 60); // Orientação X,Y
    tft.println("VALUE: ");
}

void clean_start_FlaskPosition() {
    tft.setTextColor(PINK);
    // retângulo mensagem: PRESSIONE VERDE
    tft.fillRoundRect(15, 57, 287, 72, 3, RED); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 67, 281, 86, 1, BLACK); // (x,y,x1,y1,s)
}


//**********************************************************REFERENCING******************************************************///
void start_ref(DigitalIn button_g, DigitalOut LED_Y){

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

    
    // Led amarelo pulsando até que, ao pressionar o botão verde, se torna contínuo
    while (1) {
        if (button_g == 0) {
            LED_Y = 0;
            
        } else {
            LED_Y = 1;
            break;
        }

        wait(0.1);

        if (button_g == 0) {
            LED_Y = 1;
            
        } else {
            LED_Y = 1;
            break;
        }

        wait(0.1);
    }

}

void dur_ref() {
    clean();
    tft.fillRoundRect(40, 40, 235, 50, 1, BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(3);
    tft.setCursor(45, 50); // Orientação X,Y
    tft.println("REFERENCIANDO!");

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(70, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");
}

void end_ref(DigitalOut LED_Y, DigitalOut LED_G) {
    LED_Y = 0;
    LED_G = 1;

    tft.fillRoundRect(40, 40, 235, 50, 1, BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(3);
    tft.setCursor(45, 50); // Orientação X,Y
    tft.println("REFERENCIADO!");

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(70, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");
}
//**********************************************************REFERENCING******************************************************///







//**************************************************************JOG**********************************************************///

// Função para pisca o led azul
void flasher(DigitalIn button_g, DigitalOut LED_B){
    // Led azul pulsando até que, ao pressionar o botão verde, se torna contínuo
    while (1) {
        if (button_g == 0) {
            LED_B = 0;
            
        } else {
            LED_B = 1;
            break;
        }

        wait(0.1);

        if (button_g == 0) {
            LED_B = 1;
            
        } else {
            LED_B = 1;
            break;
        }

        wait(0.1);
    }
}



void start_pCollect(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G) {
    LED_G = 0;
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

    flasher(button_g, LED_B);
}



void end_pCollectXY(DigitalIn button_g, DigitalOut LED_B) {
    clean();      

    tft.fillRoundRect(10, 40, 300, 50, 1, BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(3);
    tft.setCursor(15, 50); // Orientação X,Y
    tft.println("COLETA XY");

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(70, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");
    flasher(button_g, LED_B);

}

void end_pCollectZ(DigitalIn button_g, DigitalOut LED_B) {
    clean();

    // mensagem: DEFINIDO PONTO Z
    tft.fillRoundRect(10, 40, 300, 50, 1, BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(3);
    tft.setCursor(15, 50); // Orientação X,Y
    tft.println("DEFINA COLETA PONTO Z");

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(70, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");

    flasher(button_g, LED_B);

}


void start_pCollectH(int position[3], DigitalIn button_g, DigitalOut LED_B) {
    // Primeira parte - Tela 1
    //mensagem: DEFINIR ALTURA DE COLETA 
    tft.fillRoundRect(10, 20, 300, 200, 1, BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.setCursor(60, 55); // Orientação X,Y
    tft.println("DEFINIR ALTURA DE");
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.setCursor(110, 150); // Orientação X,Y
    tft.println("COLETA");
    // Primeira parte - Tela 1


    delay(2000);

    clean_start_pCollectH();

    // BOTÕES DE + e -
    tft.fillCircle(190,180,40, GREEN); // X, Y, Raio, COR
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(180, 167); // Orientação X,Y
    tft.println("-");

    tft.fillCircle(70,180,40,RED);
    tft.setTextSize(4);
    tft.setCursor(60, 167); // Orientação X,Y
    tft.println("+");

    tft.fillRoundRect(18, 20, 230, 100, 1, BLACK); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(40, 60); // Orientação X,Y
    tft.println("VALUE: ");

    tft.setTextColor(RED);
    tft.setCursor(170, 60); // Orientação X,Y
    tft.printf("\r%i", position[1]);
    

    while (1) {

        tp = ts.getPoint();
        YPout.output();
        XMout.output(); 
        // tft.setTextSize(2);
        // tft.setTextColor(MAGENTA,BLACK);
        // tft.setCursor(0, 0);
        // tft.printf("tp.x=%d tp.y=%d   ", tp.x, tp.y); // Faz leitura dos valores de xy quando se pressiona o touchscreen
        // printf("\rtp.x=%d tp.y=%d\n   ", tp.x, tp.y);
        
        
        if (tp.x < 350 && tp.x > 320 && tp.y > 220 && tp.y < 240) { 
            clean_start_pCollectH();
            printf("\rTA EM +\n");
            position[1]++;

            tft.setCursor(170, 60);
            tft.setTextColor(RED);
            tft.setTextSize(3);
            tft.printf("\r%i", position[1]);
        }

        if (tp.x < 320 && tp.x > 310 && tp.y > 540 && tp.y < 560) {
            clean_start_pCollectH();
            printf("\rTA EM -\n");
            if (position[1] > 0) {
                position[1]--;
            }

            tft.setCursor(170, 60);
            tft.setTextColor(RED);
            tft.setTextSize(3);
            tft.printf("\r%i", position[1]);
        }


        // LED AZUL PISCANDO - Não pode chamar a funçaõ flasher, pois necessitaria de um novo pressionar VERDE para pultar etapa
        if (button_g == 0) {
            LED_B = 0;
        } else {
            LED_B = 1;
            break;
        }
        wait(0.1);

        if (button_g == 0) {
            LED_B = 1;
            
        } else {
            LED_B = 1;
            break;
        }
        wait(0.1);
    }
}


void end_pCollectH(DigitalIn button_g, DigitalOut LED_B, DigitalOut LED_G) {
    clean();

    //mensagem: ALTURA DEFINIDA
    tft.fillRoundRect(10, 40, 300, 50, 1, BLACK);
    tft.setTextColor(RED);
    tft.setTextSize(3);
    tft.setCursor(25, 55); // Orientação X,Y
    tft.println("ALTURA DEFINIDA");

    // retângulo mensagem: PRESSIONE VERDE PARA CONTINUAR
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(70, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE");

    flasher(button_g, LED_B);

    LED_B = 0;
    LED_G = 1;
}



// Selecionar o número total de frascos para pipetagem - TELA TOUCHSCREEN - FEITO - A LÓGICA COM O *n_frascos PODE ESTAR ERRADA! VERIFICAR!
void start_NumFlask(DigitalIn button_g, int *n_frascos, DigitalOut LED_B, DigitalOut LED_G) {
    LED_G = 0;

    // BOTÕES DE + e -
    tft.fillCircle(60,180,40,GREEN); // X, Y, Raio, COR
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(50, 167); // Orientação X,Y
    tft.println("+");

    tft.fillCircle(230,180,40,RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(220, 167); // Orientação X,Y
    tft.println("-");
    

    tft.fillRoundRect(18, 50, 260, 60, 1, BLUE); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(60, 60); // Orientação X,Y
    tft.println("VALUE: ");


    tft.setCursor(200, 60);
    tft.setTextColor(MAGENTA);
    tft.setTextSize(3);
    tft.printf("\r%i", *n_frascos);


    while (1) {

         // numero total de frascos
        tp = ts.getPoint();
        YPout.output();
        XMout.output(); 
        
        // tft.setTextSize(2);
        // tft.setTextColor(MAGENTA,BLACK);
        // tft.setCursor(0, 0);
        // tft.printf("tp.x=%d tp.y=%d   ", tp.x, tp.y); // Faz leitura dos valores de xy quando se pressiona o touchscreen
        // printf("\rtp.x=%d tp.y=%d\n   ", tp.x, tp.y);
        
        // botão vermelho no display: subtrair
        if(tp.x < 320 && tp.x > 300 && tp.y > 610 && tp.y < 650) {
            clean_start_NumFlask();
            if (*n_frascos > 0) {
                *n_frascos = *n_frascos - 1;
            }

            tft.setCursor(200, 60);
            tft.setTextColor(MAGENTA);
            tft.setTextSize(3);
            tft.printf("\r%i", *n_frascos);
        }

        // botão verde no display: adicionar
        if(tp.x < 345 && tp.x > 335 && tp.y > 200 && tp.y < 220) {
            clean_start_NumFlask();
            if (*n_frascos < 9 && *n_frascos >= 0) {
                *n_frascos = *n_frascos + 1;
            }

            tft.setCursor(200, 60);
            tft.setTextColor(MAGENTA);
            tft.setTextSize(3);
            tft.printf("\r%i", *n_frascos);
        }


        // pisca-pisca LED AZUL
        if (button_g == 0) {
            LED_B = 1;
        } else {
            LED_B = 1;
            break;
        }
        wait(0.1);

        if (button_g == 0) {
            LED_B = 0;
        } else {
            LED_B = 1;
            break;
        }
        wait(0.1);
    }
}
// Selecionar o número total de frascos para pipetagem - TELA TOUCHSCREEN - FEITO - verifica lógica com o *n_frascos




int start_FlaskH(int value, DigitalIn button_g, DigitalOut LED_B) {

    // mensagem: Salvar XY para Frascos
    tft.setTextSize(3);
    tft.setTextColor(PINK);
    tft.setTextColor(DARKCYAN);
    tft.setCursor(80, 20);
    tft.println("Salvar H");
    tft.setCursor(130, 50);
    tft.println("para");
    tft.setCursor(100, 75);
    tft.setTextColor(RED);
    tft.println("Frascos");
    wait(1);

    // retângulo mensagem: PRESSIONE VERDE
    tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
    tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(75, 155); // Orientação X,Y
    tft.println("PRESSIONE VERDE"); 
    
    wait(3);
    clean_start_FlaskH();


    // BOTÕES DE + e -
    tft.fillCircle(60,180,40,GREEN); // X, Y, Raio, COR
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(50, 167); // Orientação X,Y
    tft.println("+");

    tft.fillCircle(230,180,40,RED);
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(220, 167); // Orientação X,Y
    tft.println("-");
    

    tft.fillRoundRect(18, 50, 260, 60, 1, BLUE); // (x,y,x1,y1,s)
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(60, 60); // Orientação X,Y
    tft.println("VALUE: ");

    tft.setCursor(200, 60);
    tft.setTextColor(MAGENTA);
    tft.setTextSize(3);
    tft.printf("\r%i", value);


    while (1) {

         // numero total de frascos
        tp = ts.getPoint();
        YPout.output();
        XMout.output(); 
        
        // tft.setTextSize(2);
        // tft.setTextColor(MAGENTA,BLACK);
        // tft.setCursor(0, 0);
        // tft.printf("tp.x=%d tp.y=%d   ", tp.x, tp.y); // Faz leitura dos valores de xy quando se pressiona o touchscreen
        // printf("\rtp.x=%d tp.y=%d\n   ", tp.x, tp.y);
        
        // botão vermelho no display: subtrair
        if(tp.x < 320 && tp.x > 300 && tp.y > 610 && tp.y < 650) {
            clean_start_FlaskH();
            if (value > 0) {
                value--;
            }

            tft.setCursor(200, 60);
            tft.setTextColor(MAGENTA);
            tft.setTextSize(3);
            tft.printf("\r%i", value);
        }

        // botão verde no display: adicionar
        if(tp.x < 345 && tp.x > 335 && tp.y > 200 && tp.y < 220) {
            clean_start_FlaskH();
            value++;

            tft.setCursor(200, 60);
            tft.setTextColor(MAGENTA);
            tft.setTextSize(3);
            tft.printf("\r%i", value);
        }

        // pisca-pisca LED AZUL
        if (button_g == 0) {
            LED_B = 1;
        } else {
            LED_B = 1;
            break;
        }
        wait(0.1);

        if (button_g == 0) {
            LED_B = 0;
        } else {
            LED_B = 1;
            break;
        }
        wait(0.1);

    }

    return value;
}


//////// TO AQUI!!! 
void start_FlaskPosition(float X, float Y) {
    int pass = 0;
    if (pass == 0) {
        // mensagem: Salvar XY para Frascos
        tft.setTextSize(3);
        tft.setTextColor(PINK);
        tft.setTextColor(DARKCYAN);
        tft.setCursor(80, 20);
        tft.println("Salvar XY");
        tft.setCursor(130, 50);
        tft.println("para");
        tft.setCursor(100, 75);
        tft.setTextColor(RED);
        tft.println("Frascos");
        wait(1);

        // retângulo mensagem: PRESSIONE VERDE
        tft.fillRoundRect(15, 107, 287, 122, 3, GREEN); // (x,y,x1,y1,s) : EFEITO DE BORDA
        tft.fillRoundRect(18, 110, 281, 116, 1, DARKGREEN); // (x,y,x1,y1,s)
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.setCursor(75, 155); // Orientação X,Y
        tft.println("PRESSIONE VERDE"); 
        
        wait(3);
        pass++;
    } else {
        clean_start_FlaskPosition();
        // retângulo mensagem: PRESSIONE VERDE
        tft.fillRoundRect(15, 57, 287, 72, 3, RED); // (x,y,x1,y1,s) : EFEITO DE BORDA
        tft.fillRoundRect(18, 67, 281, 86, 1, BLACK); // (x,y,x1,y1,s)
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.setCursor(75, 65); // Orientação X,Y
        tft.printf("DESLOCAMENTO X: %1.3f", X);
        tft.setCursor(75, 75); // Orientação X,Y
        tft.printf("DESLOCAMENTO Y: %1.3f", Y); 
    }
}












// void clean_start_LOAD() {
//     tft.fillScreen(PINK);  // Fundo do Display - Fundo da tela
//     tft.drawCircle(150,110,80,WHITE);
//     //tft.fillCircle(150,110,80,WHITE);

    
// }



// void start_LOAD() {
    



//     tft.drawCircle(150,110,80,WHITE);
//     //tft.fillCircle(150,110,80,WHITE);
//     tft.setTextColor(RED);
//     tft.setTextSize(3);
//     tft.setCursor(95, 98); // Orientação X,Y
//     tft.println("CIRCLE");


    



//     float x, y = 0;
//     int R = 80;
//     int n = 1; // número de voltas 
//     int T = 3; // controla a velocidade do ponto
//     for (int i = 0; i < 360 * n; i++) {
//         clean_start_LOAD();

//         // incremento por passada em radianos
//         double angulo = T * (i * 3.141593 / 180); // em radianos

//         // coordenadas
//         x = R * cos(angulo);
//         y = R * sin(angulo);


//         tft.fillCircle(150+x,110+y,1,BLACK);
//         tft.fillCircle(150+x,111+y,1,BLACK);

//         tft.fillCircle(151+x,110+y,1,BLACK);
//         tft.fillCircle(151+x,111+y,1,BLACK);

//         if (i == 120) {
//             break;
//         }
//     }

//     tft.setTextColor(RED);
//     tft.setTextSize(3);
//     tft.setCursor(95, 98); // Orientação X,Y
//     tft.println("CIRCLE");

    
// }


