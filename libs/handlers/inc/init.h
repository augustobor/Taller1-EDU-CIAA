#include "chip.h"
#include "Sounds.h"
#include "Encoder.h"
#include "Neopixel.h"

#ifndef INIT_H
#define INIT_H 

void Timer1_Init(void);
void Encoder_Init(void);
void Neopixel_Init(void);
void init_mask_bit(void);
void TouchADC_Init(void);
void Sounds_Init(void);

#endif /* #ifndef _INIT_H_ */
