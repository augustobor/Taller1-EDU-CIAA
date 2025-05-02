
#include "init.h"

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


// inicializa las entradas digitales del encoder
void Encoder_Init(void) {
    // Configuración para la rotación del encoder
    gpioConfig(ENC_A_CLK_PIN, GPIO_INPUT);
    gpioConfig(ENC_B_DT_PIN, GPIO_INPUT);

    // Configuración para cuando el pulsador se presiona
    gpioConfig(BOTON_SW_PIN, GPIO_INPUT);
}