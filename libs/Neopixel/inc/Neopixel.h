#ifndef _NEOPIXEL_H_
#define _NEOPIXEL_H_

#include <stdint.h> // Include for uint8_t type
//#include "sapi.h" // Ensure the correct path to sapi.h

// ************** Parametros de la tira led *****************
#define PIXELS_LENGTH 111  // cantidad de leds

//************ Estructura de datos de color
   struct color {
      uint8_t g;
      uint8_t r;
      uint8_t b;
   };

//********************

void Neopixel_Init(); // inicializa libreria
void Neopixel_Update();// actualiza el estado de la tira led
void Neopixel_Wait(); // espera a que se termine de actualizar los colores de la tira

void SysTick_Handler(void); // rutina de atencion de interrupciones

struct color getColor(uint8_t number_pixel); // retorna el color del pixel
void setColor(uint8_t number_pixel, struct color c); // asigna el color c al pixel
void setColor_i(uint8_t number_pixel ,float intensity); // asigna una el color "c" al pixel "n" con la "intencidad" espesificada (entre 0 a 1)
void setColor_fade(uint8_t number_pixel, struct color c1, struct color c2, float proportion); //asigna una mescla lineal de los colores "c1" y "c2" al pixel "n", con una "proporcion" espesificada (entre 0 a 1)
void mirror(uint8_t number_pixel); //copia el color del pixel "n" al pixel "PIXELS_LENGTH-n"
void mirror_all(); // copia espejada de todos los pixeles de la tira led
void pixel_off(uint8_t number_pixel);// apaga el pixel con numero @number_pixel
void setCurrentColor(struct color );
struct color getCurrentColor();

#endif /* #ifndef _NEOPIXEL_H_ */

