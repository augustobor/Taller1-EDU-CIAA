#ifndef COLOR_HANDLER_H_HANDLER_H
#define COLOR_HANDLER_H

#include "Encoder.h"
#include "Neopixel.h"
#include "Utils.h"
#include "Sounds.h"
#include <stdint.h>
#include <stdio.h>


static uint8_t fade_factor = 0.00002;
// Prototipo de la función del handler
void Switch_Color_Handler(bool_t B_DT);
void Intensity_Change_Handler(bool_t B_SW);
#endif // COLOR_HANDLER_H