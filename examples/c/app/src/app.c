#include "sapi_board.h"
#include "color_handler.h"
#include "sounds_handler.h"
#include "light_sabler_nightshutdown_handler.h"
#include "speed_volume_handler.h"
#include "collision_handler.h"
#include "init.h"


int main(void) {
    boardInit();
    Board_Init();
    Timer1_Init();   
    Neopixel_Init();
    Encoder_Init();  
    TouchADC_Init();
    Sounds_Init();
    printf("Sable-EDU-CIAA Firmware v3-r1.3.0\n");
    mpu60X0Init( MPU60X0_ADDRESS_0 );
    printf("MPU60X0 Init: %d\n", mpu60X0Init( MPU60X0_ADDRESS_0 )); // MPU init
    //mpu9250Init(MPU9250_ADDRESS_0); // MPU init
    
    static uint8_t B_CLK, B_DT, CLK_ANT;
    while (1) {
        VolumeHandler_Update(3.5-(1 - getPorcentualState())*2);
        moduleSound((getPorcentualState()+3)/10); // Actualiza el volumen en función del estado del encoder
        Neopixel_Wait(); // Para evitar que ocurran eventos durante la actualizacion de los LEDs es necesario esperar.
        LightSabler_NightShutdown_Handler();
        Efects_porcentual(getPorcentualState()); // Actualiza los efectos de la tira LED según el estado del encoder
        
        //Encoder handler
        CLK_ANT = B_CLK;
        B_DT = (bool_t) gpioRead(ENC_B_DT_PIN);
        B_CLK = (bool_t) gpioRead(ENC_A_CLK_PIN);
        if(!CLK_ANT && B_CLK) {
            Switch_Color_Handler(B_DT); 
        }
        if(getButtonState() == PRENDIDO) {
            Collision_Handler(); // TouchADC handler
            SpeedVolume_Handler();
        }
        Neopixel_Update();
    }

    return 0;
}