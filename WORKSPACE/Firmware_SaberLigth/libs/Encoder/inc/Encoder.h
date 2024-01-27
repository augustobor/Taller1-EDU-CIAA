#include "board.h"
#include "Neopixel.h"

#define PIXELS_LENGTH 111
#define CANT_COLORS 3
#define ENC_A_CLK 35 // CHECKED
#define ENC_B_DT 37 // CHECKED
#define BOTON_SW 33 // CHECKED

typedef enum {OFF, STARTING, ON, STOPPING} eButton_State;

void updateColor(uint8_t);
void Encoder_Handler(void);
void Button_init();
void Key_pressed();
