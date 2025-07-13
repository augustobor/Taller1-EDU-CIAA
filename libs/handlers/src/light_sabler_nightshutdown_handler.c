#include "light_sabler_nightshutdown_handler.h"
void LightSabler_NightShutdown_Handler() {
    static float brightnessLevel = 0; // Nivel de brillo actual
    static const float porcentual_step = 0.02; // Paso de brillo al iniciar o apagar

    // Verificar el estado del botón del encoder
    eButton_State currentState = getButtonState();
    
    Encoder_SW_Key();
    switch (currentState) { // Para manejar los eventos del encoder
        case STARTING:
            //printf("Estado: ENCENDIENDO\n");
            setButtonState(PRENDIDO);
            setPorcentualState(0.9);
            break;
            
        case STOPPING:   
            //printf("Estado: APAGANDO\n");
            setButtonState(APAGADO);
            setPorcentualState(0.0);
            break;

        default:
            break;
    }
}