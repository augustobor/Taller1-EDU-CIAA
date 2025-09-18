#ifndef _NEOPIXEL_H_
#define _NEOPIXEL_H_

#include <stdint.h> // Include for uint8_t type
#include <stdio.h>
#include "Sounds.h" 

// ************** Parametros de la tira led *****************
#define PIXELS_LENGTH 111  // cantidad de leds

//************ Estructura de datos de color
   struct color {
      uint8_t g;
      uint8_t r;
      uint8_t b;
   };

//********************
static volatile uint32_t ret;
static uint32_t PIXEL_BITS_LENGTH = PIXELS_LENGTH*24; // cantidad de bits para administrar la tira LED
volatile uint8_t datachain[PIXELS_LENGTH*3]; // [ G R B ]
volatile uint8_t bit_mask[8];  // Máscaras precalculadas para extracción de los bits
static volatile uint32_t bit_index=0; // variable global bit recorrido
static volatile uint8_t WAITSHORT = 2;  // 3 // parámetro para el retardo corto
static volatile uint8_t WAITLONG = 7;   //4 // parámetros para el retardo largo

void Neopixel_Wait(); // espera a que se termine de actualizar los colores de la tira

struct color getColor(uint8_t number_pixel); // retorna el color del pixel
void setColor(uint8_t number_pixel, struct color c); // asigna el color c al pixel
void setColor_i(uint8_t number_pixel ,float intensity); // asigna una el color "c" al pixel "n" con la "intencidad" espesificada (entre 0 y 1)
void setColor_fade(uint8_t number_pixel, struct color c1, struct color c2, float proportion); //asigna una mescla lineal de los colores "c1" y "c2" al pixel "n", con una "proporcion" espesificada (entre 0 a 1)
void setIntensity(float intensity);
float getIntensity(void);
void mirror(uint8_t number_pixel); //copia el color del pixel "n" al pixel "PIXELS_LENGTH-n"
void mirror_all(); // copia espejada de todos los pixeles de la tira led
void pixel_off(uint8_t number_pixel);// apaga el pixel con numero @number_pixel
void setCurrentColor(struct color );
struct color getCurrentColor();

#endif /* #ifndef _NEOPIXEL_H_ */

