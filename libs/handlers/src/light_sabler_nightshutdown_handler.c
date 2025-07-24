#include "light_sabler_nightshutdown_handler.h"
void LightSabler_NightShutdown_Handler() {
    static volatile float brightnessLevel = 0; // Nivel de brillo actual
    static const float porcentual_step = 0.02; // Paso de brillo al iniciar o apagar

    // Verificar el estado del botón del encoder
    eButton_State currentState = getButtonState();
    
    Encoder_SW_Key();
    switch (currentState) { // Para manejar los eventos del encoder
        case STARTING:
            if (brightnessLevel < 1.0) {
                brightnessLevel += porcentual_step;
                setPorcentualState(brightnessLevel);
                dddd(10); 
            } else {
                setButtonState(PRENDIDO); 
                setPorcentualState(1.0);
            }
            break;
        case STOPPING:
            if (brightnessLevel > 0.0) {
                brightnessLevel -= porcentual_step;
                setPorcentualState(brightnessLevel);
                dddd(10);
            } else {
                setButtonState(APAGADO);
                setPorcentualState(0);
            }
            break;

        default:
            break;
    }
}