#include "timers_handler.h"

// Definiciones de configuración
#define TIMER1_MATCH_CHANNEL 0 // Canal de coincidencia del Timer 1
#define TIMER1_INTERVAL_US   5 // Intervalo de interrupción en microsegundos

// Rutina de atención de interrupciones (cada 5.04 us)
void TIMER1_IRQHandler(void) {
    if (Chip_TIMER_MatchPending(LPC_TIMER1, TIMER1_MATCH_CHANNEL)) {
        Chip_TIMER_ClearMatch(LPC_TIMER1, TIMER1_MATCH_CHANNEL); // Limpiar la bandera de coincidencia
        Sound_Service_DAC(); // Llamar al servicio de sonido
    }
}