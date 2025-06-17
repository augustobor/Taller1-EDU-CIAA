#include "collision_handler.h"

uint8_t radious = 7;

void Collision_Handler(void) {
    TouchADC_read();
    if(!IS_TOUCH()) {
        set_enable_colision_sound(0);
    } else {
        set_enable_colision_sound(1);
        TouchADC_efects(radious); // Cambia el color de los LEDs cercanos
    }
}