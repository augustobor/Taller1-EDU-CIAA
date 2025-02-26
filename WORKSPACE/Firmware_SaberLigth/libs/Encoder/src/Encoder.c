/*==================[inclusions]=============================================*/

#include "Encoder.h"

/*==================[variables]=================================*/

static uint8_t select_color = 12; // número de color seleccionado por defecto
static float porcentual_init = 0; // estado de encendido (0 apagado; 1 encendido; ...)
static float porcentual_step = 0.02; // velocidad de encendido
static eButton_State Button_state;

/*==================[funciones]=================================*/

void Button_init() {
    Button_state = APAGADO;
}

void Encoder_Efects_Step() {
    if ((Button_state == STARTING) || (Button_state == STOPPING)) { // ESTO PUEDE SER UN SWITCH
        if (Button_state == STARTING) { // incremento el porcentaje de inicio
            porcentual_init = porcentual_init + porcentual_step;
            if (porcentual_init >= 1) {
                Button_state = PRENDIDO;
                porcentual_init = 1;
            }
        }
        if (Button_state == STOPPING) { // decremento el porcentaje de encendido
            porcentual_init = porcentual_init - porcentual_step;
            if (porcentual_init <= 0) {
                Button_state = APAGADO;
                porcentual_init = 0;
            }
        }
    }
}

// MEF verifica el estado del encoder, con el pulsador en flanco descendente enciende y apaga
// con el giro del encoder cambia el color del sistema
void Encoder_MEF_Key() {
    static bool_t CLK_ANT, DT_ANT;
    static bool_t B_CLK, B_DT;
    CLK_ANT = B_CLK; // guardo los valores anteriores de las señales de entrada
    DT_ANT = B_DT;

    // leo los valores nuevos de las señales
    B_DT = gpioRead(ENC_B_DT);
    B_CLK = gpioRead(ENC_A_CLK);

    static uint16_t timedelay = 0;
    if (!gpioRead(BOTON_SW)) { // si se mantiene presionado el botón encendido, acumula
        timedelay++;
    } else {
        timedelay = 0;
    }
    if (timedelay == 100) { // si acumula 100 veces con el botón presionado
        if (Button_state == APAGADO) Button_state = STARTING; // cambio de estado
        if (Button_state == PRENDIDO) Button_state = STOPPING;
    }
    if (!CLK_ANT && B_CLK) { // si hay un flanco ascendente del CLK, se verifica dirección con DT
        if (B_DT) {
            select_color = (++select_color) % CANT_COLORES;
        } else {
            select_color = (--select_color + CANT_COLORES) % CANT_COLORES;
        }
        setCurrentColor(colorSableLazer[select_color]);
    }
}

// inicializa las entradas digitales del encoder
void Encoder_Init() {
    // Configuración para la rotación del encoder
    gpioConfig(ENC_A_CLK, GPIO_INPUT);
    gpioConfig(ENC_B_DT, GPIO_INPUT);

    // Configuración para cuando el pulsador se presiona
    gpioConfig(BOTON_SW, GPIO_INPUT);
}

// retorna si el sable está totalmente encendido
// retorna FALSE cuando el sable está apagado, o haciendo transición de estado
bool_t Encoder_IS_Enable() {
    return (Button_state == PRENDIDO);
}

bool_t Encoder_IS_Disable() {
    return (Button_state == APAGADO);
}
bool_t Encoder_IS_Transicion() {
    return (Button_state == STARTING) || (Button_state == STOPPING);
}
float getPorcentualState() {
    return porcentual_init;
}

// Getter y Setter de Button_state
eButton_State getButtonState() {
    return Button_state;
}

void setButtonState(eButton_State state) {
    Button_state = state;
}
