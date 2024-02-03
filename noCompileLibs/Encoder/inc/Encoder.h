#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "board.h"
#include "Neopixel.h"
#include "Neopixel_Efects.h"
#include <stdint.h>
#include "sapi.h"

#define PIXELS_LENGTH 111
#define ENC_A_CLK T_FIL3 // 35
#define ENC_B_DT T_FIL2 // 37
#define BOTON_SW T_FIL0 // 33

typedef enum {APAGADO, STARTING, PRENDIDO, STOPPING} eButton_State;
/*Vector de colores
	- 0: rojo
	- 1: violeta
	- 2: rosa
	- 3: azul
	- 4: verde
	- 5: naranja
	- 6: turquesa
	- 7: amarillo
*/
#define CANT_COLORS 8
struct color colorSystem[CANT_COLORS] = {
		(struct color){255,0,0},      // Rojo
		(struct color){148,0,211},    // Violeta
		(struct color){255,182,193},  // Rosa
		(struct color){0,0,255},      // Azul
		(struct color){0,255,0},      // Verde
		(struct color){255,165,0},    // Naranja
		(struct color){0,206,209},    // Turquesa
		(struct color){255,255,0},    // Amarillo
};

bool_t Encoder_IS_Enable(); // retorna TRUE si el sable esta prendido, funcionamiento normal

void updateColor(uint8_t);
void Encoder_Init();
void Button_init();
void Encoder_MEF_Key();	// verifica el estado de los botones, actualiza el estado y los colores de los efectos
void Encoder_Efects_Step();

#endif /* #ifndef _ENCODER_H_*/
