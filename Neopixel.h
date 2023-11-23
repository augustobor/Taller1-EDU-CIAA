
// ************** Parametros de la tira led *****************
#define PIXELS_LENGTH 111  // cantidad de leds

//************ Estructura de datos de color
   struct color {
      uint8_t g;
      uint8_t r;
      uint8_t b;
   };

//********************

void SysTick_Handler(void);
void asignColor(uint8_t ,struct color ,float);
void mirror(uint8_t);
void asignColor_fade(uint8_t, struct color, struct color, float);
void Neopixel_Wait();
void Neopixel_Update();
