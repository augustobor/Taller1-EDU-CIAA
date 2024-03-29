
/*
 * 24-01-2024 revision Nico v1 - porteo de workspace, firmware, modulos
 *
 * */


/*==================[inclusions]=============================================*/
#include "sapi.h"

#include "app.h"
#include "board.h"
#include <stdint.h>

#include "Neopixel.h"
#include "Neopixel_Efects.h"
#include "Touch_ADC.h"
#include "Encoder.h"
#include "Sounds.h"

/*==================[macros and definitions]=================================*/

#define OUTPUT   1
#define INPUT    0

#define ON       1
#define OFF      0
#define INACCURATE_TO_MS       20400


// Delay apropiativo inexacto copia SAPI
void dddd(uint32_t delay_ms){
   volatile uint32_t i;
   volatile uint32_t delay;
   delay = INACCURATE_TO_MS * delay_ms;
   for( i=delay; i>0; i-- );
}

void Blink_Led(); // prototipo

//********* main ************
int main(void)
{
   Board_Init();
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

   uartConfig( UART_USB, 115200 );
   Neopixel_Init();
   //Sounds_Init();
   //TouchADC_Init();
   Encoder_Init();
   Button_init();
   //mpu60X0Init( MPU60X0_ADDRESS_0 );

	// setea la ganancia al inicio en 2.0X
	// setea la ganancia al final del prendido en 0.0X
   // ZAR: Seteamos la ganancia antes del while para reducir la cantidad de llamabdas del module sound
	//setGanance(2.0-getProcentualState()*2 ); // +get_gyro_abs_val() );
   
   while (1){  // cada vez que prende el led_integrado, actualiaza los leds
      
		// modula la velocidad de reproduccion del sonido en 0.001X al inicio del sistema
		// 1X cuando esta totalmente prendido
      // Si ya esta al 100% entonces no hago mas llamadas. Al apagarse vuelve a llamar
      
      /*
      if(getProcentualState() < 1.0) {
		   moduleSound( (getProcentualState()+3)/10 );
      }
      */
      printf("prueba");
      
   
      //uartWriteByte( UART_USB, 'h' - 32 );
      // Punto de sincronizacion
		// Neopixel_Wait(); // espera que la tira led termine de actualizar la tira de leds
		
      // efecto onda Neopixel, prende una proporcion del largo del sable
      // TODO: Meter la ejecucion de los leds en un core aparte
      // Efects_porcentual(1); 

      /*
		if(Encoder_IS_Enable() ){ // si el sable esta prendido
			TouchADC_read();  // leo los tactiles
			if( IS_TOUCH() ){// si hay algun tactil presionado
				set_enable_colision_sound(1);
				TouchADC_efects(7); // llamo al efecto colision touch, con radio de colision 7PX
			}else{
				set_enable_colision_sound(0);
			}
		}
      */
      
      
      /*
		Encoder_Efects_Step(); // actualiza el valor de prendido porcentual
		Encoder_MEF_Key();

		Neopixel_Update();   //actualiza TIRA LEDS
      Blink_Led();
		dddd(11); //retardo bloqueante 22ms, opcional
      */
	}

}


void Blink_Led(){
	static bool_t state=0;
    Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, state);
    state=!state;
}
