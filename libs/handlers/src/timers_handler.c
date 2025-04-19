#include "chip.h"
#include "Sounds.h"

// Definiciones de configuración
#define TIMER1_MATCH_CHANNEL 0 // Canal de coincidencia del Timer 1
#define TIMER1_INTERVAL_US   5 // Intervalo de interrupción en microsegundos


// Inicializa el Timer 1 para generar interrupciones periódicas
void Timer1_Init(void) {
    // Configuración del Timer 1
    Chip_TIMER_Init(LPC_TIMER1);
    Chip_TIMER_PrescaleSet(LPC_TIMER1, 1024); // 1024 equivale a aproximadamente 5.04 us

    // Configuración del Match 0 (periodo)
    Chip_TIMER_MatchEnableInt(LPC_TIMER1, 0);
    Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 0);
    Chip_TIMER_StopOnMatchDisable(LPC_TIMER1, 0);
    Chip_TIMER_SetMatch(LPC_TIMER1, 0, 1);

    // Inicialización del Timer 1
    Chip_TIMER_Reset(LPC_TIMER1);
    Chip_TIMER_Enable(LPC_TIMER1);

    // Habilitación de la interrupción del Timer 1
    NVIC_EnableIRQ(TIMER1_IRQn);
}

// Rutina de atención de interrupciones (cada 5.04 us)
void SOUNDS_TIMER1_IRQHandler(void) {
    if (Chip_TIMER_MatchPending(LPC_TIMER1, TIMER1_MATCH_CHANNEL)) {
        Chip_TIMER_ClearMatch(LPC_TIMER1, TIMER1_MATCH_CHANNEL); // Limpiar la bandera de coincidencia
        Sound_Service_DAC(); // Llamar al servicio de sonido
    }
}