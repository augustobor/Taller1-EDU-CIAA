/*==================[inclusions]=============================================*/

#include "Encoder.h"

/*==================[variables]=================================*/

static float porcentual_init = 0; // estado de encendido (0 apagado; 1 encendido; ...)
static float porcentual_step = 0.02; // velocidad de encendido
static eButton_State Button_state;

/*==================[funciones]=================================*/


void Button_init() {
    Button_state = APAGADO;
}


// MEF verifica el estado del encoder, con el pulsador en flanco descendente enciende y apaga
// con el giro del encoder cambia el color del sistema
void Encoder_SW_Key() { // Para el handler
    static uint8_t  B_SW;
    static uint16_t timedelay = 0;
    B_SW = (bool_t)gpioRead(BOTON_SW_PIN); // lee el estado del botón encendido
    if (!B_SW) { // si se mantiene presionado el botón encendido, acumula. CLAVE ESTA LINEA
        timedelay++;
    } else {
        timedelay = 0;
    }
    if (timedelay == 10) {
        while (gpioRead(BOTON_SW_PIN) == 0); // REMOVER ESTO
        if (Button_state == APAGADO) Button_state = STARTING; // cambio de estado
        if (Button_state == PRENDIDO) Button_state = STOPPING;
    }
}

// retorna si el sable está totalmente encendido
// retorna FALSE cuando el sable está apagado, o haciendo transición de estado
uint8_t Encoder_IS_Enable() {
    return (Button_state == PRENDIDO);
}

uint8_t Encoder_IS_Disable() {
    return (Button_state == APAGADO);
}
uint8_t Encoder_IS_Transicion() {
    return (Button_state == STARTING) || (Button_state == STOPPING);
}
float getPorcentualState() {
    return porcentual_init;
}

void setPorcentualState(float state) {
    porcentual_init = state;
}

// Getter y Setter de Button_state
eButton_State getButtonState() {
    return Button_state;
}

void setButtonState(eButton_State state) {
    Button_state = state;
}
