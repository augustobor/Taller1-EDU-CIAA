#include "sapi_board.h"
#include "light_sabler_nightshutdown_handler.h"
#include "init.h"

#define INACCURATE_TO_MS       20400

// Delay apropiativo inexacto copia SAPI
void dddd(uint32_t delay_ms){
    volatile uint32_t i;
    volatile uint32_t delay;
    delay = INACCURATE_TO_MS * delay_ms;
    for( i=delay; i>0; i-- );
 }

int main(void) {
    // Inicialización del sistema
    boardInit();
    Encoder_Init();       // Inicializa el encoder y el botón

    
    while (1) {
        LightSabler_NightShutdown_Handler(); // Llama al handler para controlar el sable de luz
    }

    return 0;
}