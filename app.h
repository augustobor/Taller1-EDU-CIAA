/*==================[inclusions]=============================================*/

#ifndef NEOPIXEL_INCLUDED // optimizacion ante una ejecucio concurrente de archivos
    #define NEOPIXEL_INCLUDED 1
    #include "../Modules/Neopixel.h"

    #include "../Modules/Neopixel_Efects.h"
    #include "../Modules/Touch_ADC.h"
    /*==================[macros and definitions]=================================*/

    #define OUTPUT   1
    #define INPUT    0

    #define ON       1
    #define OFF      0
    #define INACCURATE_TO_MS       20400
#endif