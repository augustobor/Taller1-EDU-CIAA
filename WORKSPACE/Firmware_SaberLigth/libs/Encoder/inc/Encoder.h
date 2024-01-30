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

bool_t Encoder_IS_Enable(); // retorna TRUE si el sable esta prendido, funcionamiento normal

void updateColor(uint8_t);
void Encoder_Init();
void Button_init();
void Encoder_MEF_Key();	// verifica el estado de los botones, actualiza el estado y los colores de los efectos
void Encoder_Efects_Step();

#endif /* #ifndef _ENCODER_H_*/
