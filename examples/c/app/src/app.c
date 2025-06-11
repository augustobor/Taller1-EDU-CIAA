#include "sapi_board.h"
#include "color_handler.h"
#include "light_sabler_nightshutdown_handler.h"
#include "collision_handler.h"
#include "init.h"


#define OUTPUT   1
#define INPUT    0

#define ON       1
#define OFF      0

int main(void) {
    // Configuro LED1 = pin P2_10 = GPIO0[14]
   Chip_SCU_PinMux( 2, 10, SCU_MODE_INACT, SCU_MODE_FUNC0 );
   // Configuro COL1 = pin P0_0 = GPIO3[12]
   Chip_SCU_PinMux( 7, 4, SCU_MODE_INACT, SCU_MODE_FUNC0 );

   // Configuro GPIO0[14] como salida
   Chip_GPIO_SetDir( LPC_GPIO_PORT, 0, (1<<14), OUTPUT );
   // Configuro GPIO0[0] como salida
   Chip_GPIO_SetDir( LPC_GPIO_PORT, 3, (1<<12), OUTPUT );

   // Pongo en estado bajo LED1 el GPIO0[14]
   Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, OFF );

    // Inicialización del sistema
    boardInit();
    Timer1_Init();   
    Neopixel_Init(); 
    Encoder_Init();  
    TouchADC_Init();
    Sounds_Init();

    //VolumeHandler_Update(0.1f);
    
    static uint8_t B_CLK, B_DT, CLK_ANT;
    while (1) {
        //CLK_ANT = B_CLK;
        //B_CLK = (bool_t) gpioRead(ENC_A_CLK_PIN);
        //B_DT = (bool_t) gpioRead(ENC_B_DT_PIN);
        LightSabler_NightShutdown_Handler(); // Neopixel handler

        // Encoder handler
        // if(CLK_ANT != B_CLK) { // Si el encoder ha girado
        //     Switch_Color_Handler(B_DT); // Llama al handler de color
        // }
        Efects_porcentual(0.4); // Sounds handler
        //Collision_Handler(); // TouchADC handler
    }

    return 0;
}