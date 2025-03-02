#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "Neopixel.h"
#include "board.h"
#include <stdint.h>

#define PIXELS_LENGTH 111
#define ENC_A_CLK 35 // Update this line to define the correct pin number
#define ENC_B_DT 37  // Update this line to define the correct pin number
#define BOTON_SW 33 // Update this line to define the correct pin number

typedef enum {APAGADO, STARTING, PRENDIDO, STOPPING} eButton_State;
/* Vector de colores para el sable láser
   - 0: Rojo intenso
   - 1: Naranja fuerte
   - 2: Amarillo brillante
   - 3: Amarillo pálido
   - 4: Verde lima
   - 5: Verde brillante
   - 6: Turquesa
   - 7: Cyan claro
   - 8: Azul claro
   - 9: Azul cian
   - 10: Azul oscuro
   - 11: Violeta
   - 12: Morado intenso
   - 13: Magenta brillante
   - 14: Rosa vibrante
   - 15: Blanco brillante
*/
#define CANT_COLORES 16
static struct color colorSableLazer[CANT_COLORES] = {
        (struct color){255, 0, 0},        // Rojo intenso
        (struct color){255, 165, 0},      // Naranja fuerte
        (struct color){255, 255, 0},      // Amarillo brillante
        (struct color){255, 255, 153},    // Amarillo pálido
        (struct color){204, 255, 102},    // Verde lima
        (struct color){0, 255, 0},        // Verde brillante
        (struct color){0, 206, 209},      // Turquesa
        (struct color){0, 255, 255},      // Cyan claro
        (struct color){102, 204, 255},    // Azul claro
        (struct color){0, 255, 255},      // Azul cian
        (struct color){0, 0, 139},        // Azul oscuro
        (struct color){138, 43, 226},     // Violeta
        (struct color){128, 0, 128},      // Morado intenso
        (struct color){255, 0, 255},      // Magenta brillante
        (struct color){255, 20, 147},     // Rosa vibrante
        (struct color){255, 255, 255}     // Blanco brillante
};

void Encoder_Init();
void Button_init();
void Encoder_MEF_Key();	// verifica el estado de los botones, actualiza el estado y los colores de los efectos
void Encoder_Efects_Step();
float getProcentualState();
uint8_t Encoder_IS_Enable(); // retorna TRUE si el sable está prendido, funcionamiento normal
uint8_t Encoder_IS_Disable();
uint8_t Encoder_IS_Transicion();

#endif /* #ifndef _ENCODER_H_ */
