#include "color_handler.h"

static uint8_t select_color = 12; // número de color seleccionado por defecto

void Switch_Color_Handler(bool_t direction) {
    
    if (direction) {
        select_color = (++select_color) % CANT_COLORES;
        // printf("Color B: %d\n", select_color);
    } else {
        select_color = (--select_color + CANT_COLORES) % CANT_COLORES;
        // printf("Color A: %d\n", select_color);
    }
    setCurrentColor(colorSableLazer[select_color]);
}

void Intensity_Change_Handler(bool_t B_SW) {
    if (!B_SW && getButtonState() == PRENDIDO) { // Si el botón está presionado
        dddd(500); // Delay para evitar problemas de lectura del botón del encoder
        if (!B_SW && getButtonState() == PRENDIDO) { // Verifica nuevamente si el botón sigue presionado
            setIntensity(getIntensity() + fade_factor);
            printf("Intensidad: %u\n", getIntensity());
            if (getIntensity() >= 1.0) {
                setIntensity(0.0);
            }
        }
    }
}