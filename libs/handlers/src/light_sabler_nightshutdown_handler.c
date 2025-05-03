#include "light_sabler_nightshutdown_handler.h"
void LightSabler_NightShutdown_Handler() {
    static float brightnessLevel = 0; // Nivel de brillo actual

    // Verificar el estado del botón del encoder
    eButton_State currentState = getButtonState();

    Encoder_SW_Key();
    switch (currentState) {
        case STARTING:
            printf("Estado: ENCENDIENDO\n");
            for (uint8_t i = 0; i < PIXELS_LENGTH; i++) {
                setColor_i(i, 0);
            }
            setButtonState(PRENDIDO);
            break;
            
        case STOPPING:   
            printf("Estado: APAGANDO\n");
            for (uint8_t i = 0; i < PIXELS_LENGTH; i++) {
                setColor_i(i, 1);
            }
            setButtonState(APAGADO);
            break;

        default:
            break;
    }
}