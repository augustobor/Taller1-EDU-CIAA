#include "sapi_board.h"
#include "sounds_handler.h"

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
    //Encoder_Init();       // Inicializa el encoder
    Sounds_Init();

    // Variables para el control del volumen
    float currentVolume = 0.5f; // Volumen inicial (50%)

    while (1) {

        VolumeHandler_Update(currentVolume); // Esto esta en bucle
        Sound_Service_DAC();

        uint16_t printCurrentVolume = 100*currentVolume;
        printf("Volumen actual: %d\n", printCurrentVolume);
        

        dddd(2); // 1s

    }

    return 0;
}