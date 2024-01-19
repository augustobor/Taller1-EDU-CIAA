
/* ################# Resumen del Programa ################### :: conclusiones Nico
   #) el programa cada vez que prende el led integrado refrezca la tira de leds,
      con los colores preestablecidos al maximo (Azul,Rojo,Verde,Azul,Rojo,Verde,Azul,Rojo)

   1) la variable "datachain" tiene el vector de datos de salida
      se almacena 1byte por cada bit a transmitir.
   2a) controla los la tira de LEDS bajo una interrupcion periodica del timer cada 1200ns
      el manejador de interrupciones que escribe cada bit es "SysTick_Handler"
   2b) si esta habilitado la variable "update" en controlador de interrupciones
      respeta la rutina del protocolo, flanco ascendente, esperar 400ns siempre,
      si el bit a esperar es 1, espera otros 400ns, y luego siempre hace el flaco descendente
      Solo hace falta modifar update, ya que el indice se reestablece siempre a 0 gracias a la operacion %

   nota: la rutina de interrupciones bloquea la ejecucion mientras genera
         la parte alta de la onda de salida, en este tiempo tiene retardos bloqueantes,
         y puede estar entre 400ns y 900ns bloqueado generando el ciclo alto


   Update 29-10-2023 :
         Se cambio la forma de almacenar data_chain, ahora cada byte almacenado
         corresponde a los 8bits de cada color de cada bit GRB; tomando en cuenta que
         la operacion desplazamiento de bits puede tener un tiempo de ejecucion variable
         se decidio estandarizar este tiempo, pre-calculando las mascaras.
         El acceso a las mascaras y al color de cada led, se hace a travez de 1 sola variale
         la division entera corresponde al color analizado, y el resto de la division a la mascara que hay que utilizar

   nota2: se debe calcular Empiricamente las siguientes variables
      WAITSHORT (para que el buble de retardo corto, con la comparacion de bit, alcance el retardo de 400ns)
      WAITLONG (que bucle genere el retardo suficiente para compensar los 900ns de tiempo demorado de ciclo alto)
      bit_mask ( la forma de crear las mascaras de menor a mayor, o mayor a menor )
      PIXELS_LENGTH (cantidad de pixeles)
      datachain (cantidad y orden de los datos correctos)
*/
#include "app.h"
#include "board.h"

// Delay apropiativo inexacto copia SAPI
void delayInaccurateMs(uint32_t delay_ms){
   volatile uint32_t i;
   volatile uint32_t delay;
   delay = INACCURATE_TO_MS * delay_ms;
   for( i=delay; i>0; i-- );
}

void Blink_Led(); // prototipo

//********* variables main ************

struct color cl = {0,MAX_VALUE/2, MAX_VALUE/2}; // color principal - violeta
struct color c2 = {255,5,5}; // color de contraste - verde intenso

//********* main ************
int main(void)
{
   uint32_t state=OFF;
   Board_Init();
   Neopixel_Init();
   // Configuro LED1 = pin P2_10 = GPIO0[14]
   Chip_SCU_PinMux( 2, 10, SCU_MODE_INACT, SCU_MODE_FUNC0 );
   // Configuro RXD1 = pin P0_0 = GPIO0[0]
   Chip_SCU_PinMux( 0, 0, SCU_MODE_INACT, SCU_MODE_FUNC0 );
   // Configuro GPIO0[14] como salida
   Chip_GPIO_SetDir( LPC_GPIO_PORT, 0, (1<<14), OUTPUT );
   // Configuro GPIO0[0] como salida
   Chip_GPIO_SetDir( LPC_GPIO_PORT, 0, (1<<0), OUTPUT );
   // Pongo en estado bajo el GPIO0[14]
   Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, OFF );
   TouchADC_Init();
	while (1){  // cada vez que prende el led_integrado, actualiaza los leds
		Neopixel_Wait(); // espera que la tira led termine de actualizar la tira de leds
		Efects_sinoidal_breath_c_mirror(cl); // actualizo el color de toda la tira
		TouchADC_read();  // leo los tactiles
		TouchADC_efects(c2,3); // llamo al efecto color c2, con radio de colision 3
		Neopixel_Update();   //actualiza TIRA LEDS
      Blink_Led();
		delayInaccurateMs(delay_time); //retardo bloqueante 22ms, opcional
	}

}

void Blink_Led(){
      if(state==ON){ //prende LED1
         state=OFF;
         Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, OFF );
      }
		else{          //apaga LED1
			 state=ON;
			 Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, ON );
		}
}