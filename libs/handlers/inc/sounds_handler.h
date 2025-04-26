#ifndef SOUNDS_HANDLER_H
#define SOUNDS_HANDLER_H

#include "Encoder.h"
#include "Sounds.h"

// Definición de los límites del volumen
#define VOLUME_MIN 0.0f
#define VOLUME_MAX 1.0f
#define VOLUME_STEP 0.05f // Incremento o decremento del volumen

// Prototipos de funciones
void VolumeHandler_Update(float);    // Actualiza el volumen en función del encoder
uint16_t generador_onda_cuadrada_handler(void);

#endif // SOUNDS_HANDLER_H