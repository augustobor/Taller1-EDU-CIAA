
#ifndef _SOUNDS_H_
#define _SOUNDS_H_

#include "sapi.h"
#include "board.h"

void Sounds_Init();   // Inicializa configuraciones del Timer 1 , DAC y variables
void Sound_Service_DAC();	// servicio de ejecucion continua para enviar muestras al DAC

#endif /* #ifndef _NEOPIXEL_EFECTS_H_*/
