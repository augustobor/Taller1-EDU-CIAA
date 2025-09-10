#include "color_handler.h"

static uint8_t select_color = 12; // número de color seleccionado por defecto
static uint8_t delay = 0;

void Switch_Color_Handler(bool_t boton) {
    delay++;
    if (delay < 50) return;
    delay = 0;

    if (!boton) {
        select_color = (++select_color) % CANT_COLORES;
        // printf("Color B: %d\n", select_color);
    }
    setCurrentColor(colorSableLazer[select_color]);
}
