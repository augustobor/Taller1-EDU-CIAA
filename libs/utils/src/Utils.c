#include "utils.h"

// Delay apropiativo inexacto copia SAPI
void dddd(uint32_t delay_ms){
    volatile uint32_t i;
    volatile uint32_t delay;
    delay = INACCURATE_TO_MS * delay_ms;
    for( i=delay; i>0; i-- );
 }
