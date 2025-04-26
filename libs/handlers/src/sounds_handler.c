#include "sounds_handler.h"


// Actualiza el volumen en función del estado del encoder
// EncoderState: es un parametro que deberia recibir el value de los pines de lectura del encoder o de un potencionemtro?
void VolumeHandler_Update(float currentVolume) {
    setGain(currentVolume);
}

uint16_t generador_onda_cuadrada() {
    static float count_push = 0;  // Cambiado a static para mantener el estado entre llamadas
    static uint8_t direction = 1; // Dirección de la onda cuadrada
    float velocity_push = 50;     // Velocidad de cambio
    float amp = 350;              // Amplitud de la onda

    count_push += velocity_push;  // Incremento un paso de audio
    if (count_push >= 100) {      // Si el contador rebalsa
        count_push -= 100;        // Reseteo
        direction = !direction;   // Cambio la dirección
    }
    return amp * direction; // Retorna la onda cuadrada centrada en 0
}
