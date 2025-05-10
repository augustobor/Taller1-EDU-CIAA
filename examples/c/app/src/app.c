#include "sapi_board.h"
#include "color_handler.h"
#include "light_sabler_nightshutdown_handler.h"
#include "collision_handler.h"
#include "init.h"

int main(void) {
    // Inicialización del sistema
    boardInit();
    Timer1_Init();   
    Neopixel_Init(); 
    Encoder_Init();  
    TouchADC_Init();
    Sounds_Init();

    VolumeHandler_Update(0.1f);
    
    static uint8_t B_CLK, B_DT, CLK_ANT;
    while (1) {
        CLK_ANT = B_CLK;
        B_CLK = (bool_t) gpioRead(ENC_A_CLK_PIN);
        B_DT = (bool_t) gpioRead(ENC_B_DT_PIN);
        LightSabler_NightShutdown_Handler(); // Neopixel handler

        // Encoder handler
        if(CLK_ANT != B_CLK) { // Si el encoder ha girado
            Switch_Color_Handler(B_DT); // Llama al handler de color
        }
        generador_onda_cuadrada(); // Sounds handler
        Collision_Handler(); // TouchADC handler
    }

    return 0;
}