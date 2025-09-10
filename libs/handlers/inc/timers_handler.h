#ifndef TIMERS_HANDLER_H
#define TIMERS_HANDLER_H

#include "chip.h"
#include "Sounds.h"
#include "Neopixel.h"
#include "Encoder.h"
#include "Utils.h"
#include "init.h"

// Definiciones de configuración
#define TIMER1_MATCH_CHANNEL 0 // Canal de coincidencia del Timer 1
#define TIMER1_INTERVAL_US   5 // Intervalo de interrupción en microsegundos

static volatile uint32_t update;    // habilita la actualización cuando es !=0


void TIMER1_IRQHandler(void);
void SysTick_Handler(void);
void Neopixel_Update(void);
void Neopixel_Wait(void);
#endif /* #ifndef _TIMERS_HANDLER_H_ */