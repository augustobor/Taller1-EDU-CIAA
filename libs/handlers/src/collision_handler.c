#include "collision_handler.h"

uint8_t radious = 1;

void Collision_Handler(void) {
    TouchADC_read();
    if(!IS_TOUCH()) {
        return;
    } else {
        TouchADC_efects(radious); // Cambia el color de los LEDs cercanos
    }
}