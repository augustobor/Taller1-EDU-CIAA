/*==================[inclusions]=============================================*/

#include "Encoder.h"

/*==================[macros and definitions]=================================*/


static volatile uint8_t datachain[PIXELS_LENGTH*3]; // [ G R B ]
static uint8_t index = 0;


/*Matriz de colores*/
/*
 Cada columna es el rgb de un color del sable
 1era fila: tonalidad red
 2da fila: tonalidad green
 3era fila: tonalidad blue

- 0: rojo
- 1: violeta
- 2: rosa
- 3: azul
- 4: verde
- 5: naranja
- 6: turquesa
- 7: amarillo
*/

volatile uint8_t colors[3][CANT_COLORS] = {
    {255,   148,    255,    0,      0,      255,    255},
    {0,     0,      20,     0,      255,    140,    215},
    {0,     211,    147,    255,    0,      0,      0}
};

static eButton_State Button_state;

struct color currentColor;

void Button_init() {
	Button_state = OFF;
}


/*
Esta funcion recorre la hoja led de forma simetrica. Va hasta la mitad encendiendo
para cada iteracion 2 leds que se encuentran en cada extremo. Para cada iteracion
todos los leds que se encuentren entre los leds iluminados con el color se ponen negros

Se pasa el indice de la matriz para seleccionar el color
*/
void updateColor(uint8_t index) {

    currentColor = {colors[0][index], colors[1][index], colors[2][index]};
    for(uint16_t i=0; i <= PIXELS_LENGTH/2; i++) {

    	/* Asigno el color a los leds extremos. El seteo del color va desde
    	los leds mas extremos hasta el centro */
        setColor(i, currentColor);
        setColor(PIXELS_LENGTH - i, currentColor);

        for(uint16_t u=(i+1); u <= PIXELS_LENGTH/2; u++) {

            setColor(u, {0, 0, 0});
            setColor(PIXELS_LENGTH - u, {0, 0, 0});

        }
        delay(1); //10 milisegundos para que no sea instantaneo el efecto
    }
}

/* Incrementar o decrementar el contador seg�n la direcci�n de rotaci�n
    sentido horario -> index++
    sentido antihorario -> index--
*/
void Encoder_Handler() {
    if (gpioRead(ENC_A_CLK) > gpioRead(ENC_B_DT)) {
        index++;
    } else {
        index--;
    }

    updateColor(index);
}

// MEF basada en la implementacion de Adrian
void Key_pressed() {

    switch(Button_state) {
        case OFF:
            Button_state = STARTING;
            return;
        break;
        case STARTING:
            if (gpioRead(BOTON_SW)) {
                Button_state = ON;
            } else {
                Button_state = OFF;
            }
            return;
        break;
        case ON:
            Button_state = STOPPING;
            return;
        break;
        case STOPPING:
            if (gpioRead(BOTON_SW)) {
                Button_state = OFF;
            } else {
                Button_state = ON;
            }
            return;
        break;
    }
    return;
}

void Encoder_Init() {

    Chip_GPIO_SetDir( LPC_GPIO_PORT, 0, (1<<ENC_A_CLK), INPUT );
    Chip_GPIO_SetDir( LPC_GPIO_PORT, 0, (1<<ENC_B_DT), INPUT );
    Chip_GPIO_SetDir( LPC_GPIO_PORT, 0, (1<<BOTON_SW), INPUT );

    
    //Configuracion para la rotacion del encoder
    gpioConfig(ENC_A_CLK, GPIO_INPUT_PULLUP | GPIO_IRQ_BOTH_EDGES, Encoder_Handler());
    gpioConfig(ENC_B_DT, GPIO_INPUT_PULLUP | GPIO_IRQ_BOTH_EDGES, Encoder_Handler());

    //Configuracion para cuando el pulsador se presiona
    gpioConfig(BOTON_SW, GPIO_INPUT_PULLUP, Key_Pressed());
}