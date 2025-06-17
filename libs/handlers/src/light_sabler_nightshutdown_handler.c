#include "light_sabler_nightshutdown_handler.h"
void LightSabler_NightShutdown_Handler() {
    static float brightnessLevel = 0; // Nivel de brillo actual
    static const float porcentual_step = 0.02; // Paso de brillo al iniciar o apagar

    // Verificar el estado del botón del encoder
    eButton_State currentState = getButtonState();

    Neopixel_Wait(); // Para evitar que ocurran eventos durante la actualizacion de los LEDs es
                     // necesario esperar.
    Encoder_SW_Key();
    switch (currentState) { // Para manejar los eventos del encoder
        case STARTING:
            printf("Estado: ENCENDIENDO\n");
            setButtonState(PRENDIDO);
            setPorcentualState(getPorcentualState() + porcentual_step);
            if (getPorcentualState() >= 1.0) {
                setPorcentualState(1.0);
            }
            for (uint8_t i = 0; i < PIXELS_LENGTH; i++) {
                setColor_i(i, 0);
            }
            break;
            
        case STOPPING:   
            printf("Estado: APAGANDO\n");
            setButtonState(APAGADO);
            setPorcentualState(getPorcentualState() - porcentual_step);
            if (getPorcentualState() <= 0.0) {
                setPorcentualState(0.0);
            }
            for (uint8_t i = 0; i < PIXELS_LENGTH; i++) {
                setColor_i(i, 1);
            }
            break;

        default:
            break;
    }
    Neopixel_Update();
}