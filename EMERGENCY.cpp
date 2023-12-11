#include "mbed.h"
#include "EMERGENCY.h"
#include "IHM.h"


void flash() {

}

void EMERGENCY(DigitalOut LED_B, DigitalOut LED_G, DigitalOut LED_Y, DigitalOut LED_R, DigitalOut LED_R_EMERG,
               PwmOut MOTOR_CLK, DigitalOut MOTOR1_CW, DigitalOut MOTOR2_CW, DigitalOut MOTOR1_EN, DigitalOut MOTOR2_EN){
    
    // COOMO QUEBRO ESSE LOOPING?
    while(1) {
        LED_B = 0;
        LED_G = 0;
        LED_Y = 0;
        LED_R = 0;

        printf("\rENTROU NA EMERGENCIA\n");
        LED_R_EMERG = !LED_R_EMERG;
        wait(0.25);
    }
    
}
