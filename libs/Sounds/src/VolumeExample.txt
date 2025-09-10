#include "sapi_board.h"
#include "sounds_handler.h"
#include "timers_handler.h"
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
    Sounds_Init();
    Timer1_Init();        // Inicializa el Timer 1 para interrupciones periódicas

    // Variables para el control del volumen
    float currentVolume = 0.1f; // Volumen inicial (50%)

    
    while (1) {
        currentVolume += 0.5f;
        if (currentVolume > 3.0f) {
            currentVolume = 0.0f; // Reinicia el volumen al llegar al máximo
        }
        VolumeHandler_Update(currentVolume);
        uint16_t printCurrentVolume = 100*currentVolume;
        printf("Volumen actual: %d\n", printCurrentVolume);
        dddd(2000); // 2s de delay
    }

    return 0;
}