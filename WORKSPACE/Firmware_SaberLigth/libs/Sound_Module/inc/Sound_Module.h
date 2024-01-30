#ifndef _SOUNDS_MODULE_H_
#define _SOUNDS_MODULE_H_

#include "Sounds.h"


void print_vector(uint8_t *v,uint16_t limit); // prototipos
void modular(float vt);
void amplificar(float ganancia);
uint8_t interpol(uint8_t y1 ,uint8_t y2, float dx );

#endif /* #ifndef _NEOPIXEL_EFECTS_H_*/
