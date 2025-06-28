#include "color_handler.h"

static uint8_t select_color = 12; // número de color seleccionado por defecto

void Switch_Color_Handler(bool_t direction) {
    
    if (direction) {
        select_color = (++select_color) % CANT_COLORES;
        printf("Color B: %d\n", select_color);
    } else {
        select_color = (--select_color + CANT_COLORES) % CANT_COLORES;
        printf("Color A: %d\n", select_color);
    }
    setCurrentColor(colorSableLazer[select_color]);
}
