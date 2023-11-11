#include "mbed.h"
#include "EMERGENCY.h"
#include "IHM.h"

void flip() {
    
}


void EMERGENCY(InterruptIn button_emerg){
    button_emerg.fall(&flip);
    while(1) {
        
    }
}
