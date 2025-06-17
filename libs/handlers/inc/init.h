#include "chip.h"
#include "Sounds.h"
#include "Encoder.h"
#include "Neopixel_Efects.h"
#include "Neopixel.h"
#include "Gyroscope.h"

#ifndef INIT_H
#define INIT_H

#define OUTPUT   1
#define INPUT    0

#define ON       1
#define OFF      0

void Timer1_Init(void);
void Encoder_Init(void);
void Neopixel_Init(void);
void init_mask_bit(void);
void TouchADC_Init(void);
void Sounds_Init(void);
void Gyroscope_Init(void);

#endif /* #ifndef _INIT_H_ */
