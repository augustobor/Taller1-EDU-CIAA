
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



/*==================[inclusions]=============================================*/

#include "app.h"
#include "board.h"
#include "arm_math.h"

/*==================[macros and definitions]=================================*/

#define OUTPUT   1
#define INPUT    0

#define ON       1
#define OFF      0
#define INACCURATE_TO_MS       20400



// ************** Parametros de la tira led *****************
   #define MAX_VALUE 160      // valor maximo que puede tener un color, sin sobrecargar la bateria
//**********************************************************







// ************ INIT del sistema ********
   static void initHardware(void) {
      Board_Init();
      SystemCoreClockUpdate();
      // SysTick_Config(SystemCoreClock / 1000);
      SysTick_Config(255); //Generacion de interrupciones periodicas casa 1250ns
   }

// ************ INIT mascaras Neopixel ********
   // Pre-calcula las mascaras de bits para la extraccion de todos los "bit" en tiempo constante
   void init_mask_bit(){
      for (int bit = 7; bit >=0 ; bit--) {
         bit_mask[ 7-bit ] = 1 << bit; // ordena las mascaras de mayor a menor
      }
   }

//***************************************


// ************** Variables glovales de los Efectos Neopixel *******
#define DESC 1
#define ASC 0

volatile int16_t value_rampa;
volatile uint8_t rising_cicle=ASC;
volatile float velocity = 3; // valor positivo o negativo

volatile float value_cicle;
volatile float value_sin;
volatile float value_medio;
volatile uint8_t value_pixel;

volatile uint16_t delay_time=16;

// ************ EFECTOS NEOPIXEL **********


    // efecto respiro, sube y baja el valor del color de todos los leds al mismo tiempo
void efect_breath_cian(){
	float local_velocity; // velocidad auxiliar siempre positiva
	if(velocity>0)
		local_velocity=velocity;
	else
		local_velocity=-velocity;

	for(uint16_t u=0;u<PIXELS_LENGTH;u++){ // actualiza todos los Pixeles
		datachain[u*3]=value_rampa;        // G = value
		datachain[u*3+2]=value_rampa;      // B = value
	}


   // velocity tiene signo
	if(rising_cicle==ASC){ // si el ciclo es ascendente
      value_rampa+=local_velocity;   // incremento
	}else{
      value_rampa-=local_velocity;  // decremento
	}

   if( value_rampa >= MAX_VALUE) { // si me pase
      value_rampa=MAX_VALUE;  // seteo maximo
      rising_cicle=DESC;      // cambio el sentido del ciclo
   }
   if( value_rampa <= 0) { // si me pase
      value_rampa=0;       // establesco minimo
      rising_cicle=ASC;    // cambio el sentido del ciclo
   }

}

// efecto onda senoidal,
   float longitud_de_onda = 40;
   float desfazaje_by_pixel;
   float corrimiento_angular;
   float corrimiento_angular_alineal;
   float angulo_temporal;

void efect_sinoidal_breath_c(struct color c){
   desfazaje_by_pixel=6.2831853/ longitud_de_onda;
   angulo_temporal=((6.2831853*value_cicle) / 255); // angulo que varia con el tiempo para todos los pixeles (entre 2PI y 0)

	for(int pix_i=0; pix_i<PIXELS_LENGTH ;pix_i++){ // recorro todos los pixeles
         corrimiento_angular=pix_i*desfazaje_by_pixel;
                     // calculo el seno de { 2PI (valor/255) + desfazaje_alineal_del_pixel }
			value_sin = arm_sin_f32( angulo_temporal +corrimiento_angular);
			value_sin+=1; // valor entre 0 y 2

         asignColor(pix_i,c,value_sin/2); // le asigno al pixel i el color seteado escalado en seno
	}
	value_cicle=fmod( (value_cicle+velocity+255), 255) ; // revalsa automaticamente , limitado a 8bits

}

// similar al anterior, pero recorre la mitad de la tira led, y la mitad espejada le asigna el mismo valor
void efect_sinoidal_breath_c_mirror(struct color c){
   angulo_temporal=((6.2831853*((uint8_t)value_cicle))/255); // angulo que varia con el tiempo para todos los pixeles (entre 2PI y 0)
   desfazaje_by_pixel=6.2831853/ longitud_de_onda;

   for(int pix_i=0; pix_i< (PIXELS_LENGTH/2) ;pix_i++){ // recorro la mitad de los pixeles
         corrimiento_angular=pix_i*desfazaje_by_pixel;
         //corrimiento_angular_alineal=0.02*corrimiento_angular*value_cicle;
                     // calculo el seno de { 2PI (valor/255) + desfazaje_alineal_del_pixel }
			value_sin = arm_sin_f32( angulo_temporal +corrimiento_angular);
			value_sin+=1; // valor entre 0 y 2
			value_sin= value_sin*0.85 + 0.15*(2); // offset del 15% siempre prendido

         asignColor(pix_i,c,value_sin/2); // le asigno al pixel i el color seteado escalado en seno
         asignColor( (PIXELS_LENGTH-1-pix_i) ,c ,value_sin/2); // le asigna al pixel espejado el mismo valor
	}
	value_cicle=value_cicle+velocity; // revalsa automaticamente , limitado a 8bits
}

//***************************************


// Delay apropiativo inexacto copia SAPI
void delayInaccurateMs(uint32_t delay_ms){
   volatile uint32_t i;
   volatile uint32_t delay;
   delay = INACCURATE_TO_MS * delay_ms;
   for( i=delay; i>0; i-- );
}


static uint16_t lectura_adc = 0;	// variable interna para lectura del ADC
static uint8_t flag_touch_1 = 0; //  vanderas de touch presionado
static uint8_t flag_touch_2 = 0;
static uint8_t flag_touch_3 = 0;
static uint8_t flag_touch_4 = 0;

static uint16_t triger_value_t1 = 432; // defino el triger en la mitad del valor maximo
static uint16_t triger_value_t2 = 210; // triger en la mitad del valor anterior
static uint16_t triger_value_t3 = 105;
static uint16_t triger_value_t4 = 55; // ?

// ********* lectura_Touch *******
void read_touch_ADC(){

	  // Start conversion
	Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);

	// Wait for conversion complete
	while(
	  (Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1, ADC_DR_DONE_STAT) != SET)
	);

	Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &lectura_adc);

	if(lectura_adc>= triger_value_t1){ // si el valor supera el 50%
		lectura_adc-=triger_value_t1; //guardo el valor de las siguientes muestras
		flag_touch_1=ON; // habilito el flag
	}
	if(lectura_adc>= triger_value_t2){ // si lo que le queda supera el triger 2, entoncres esta prendido
		lectura_adc-=triger_value_t2; //guardo el valor de las siguientes muestras
		flag_touch_2=ON; // habilito el flag
	}
	if(lectura_adc>= triger_value_t3){ // si lo que le queda suera el triger 2, entonces habilito el 3er prendido
		lectura_adc-=triger_value_t3; //guardo el valor de las siguientes muestras
		flag_touch_3=ON; // habilito el flag
	}
	if(lectura_adc>= triger_value_t4){ // si lo que le queda suera el triger 2, entonces habilito el 3er prendido
		lectura_adc-=triger_value_t4; //guardo el valor de las siguientes muestras
		flag_touch_4=ON; // habilito el flag
	}
}

void init_touch_ADC(){
    /* Config ADC0 sample mode */
    ADC_CLOCK_SETUP_T ADCSetup = {
       ADC_MAX_SAMPLE_RATE,   // ADC Sample rate:ADC_MAX_SAMPLE_RATE = 400KHz
       10,                    // ADC resolution: ADC_10BITS = 10
       0                      // ADC Burst Mode: (true or false)
    };

	lectura_adc=0;
	flag_touch_1 = 0; //  reset de vanderas
	flag_touch_2 = 0;
	flag_touch_3 = 0;

	Chip_ADC_Init(LPC_ADC0, &ADCSetup);
    /* Disable burst mode */
    Chip_ADC_SetBurstCmd( LPC_ADC0, DISABLE );

	Chip_ADC_SetSampleRate(LPC_ADC0, &ADCSetup, 88000);

	Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH1, ENABLE);


	// deshabilita el resto de los canales
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH1, DISABLE );
    Chip_ADC_EnableChannel( LPC_ADC0, ADC_CH2, DISABLE );
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH2, DISABLE );
    Chip_ADC_EnableChannel( LPC_ADC0, ADC_CH3, DISABLE );
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH3, DISABLE );
    Chip_ADC_EnableChannel( LPC_ADC0, ADC_CH4, DISABLE );
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH4, DISABLE );

}



// efecto para colision
void efect_colision(uint8_t pixel_center,struct color cl, uint8_t radius){
	asignColor( pixel_center, cl, 1);
	mirror(pixel_center);
	for(int i=1;i<radius;i++){
		asignColor_fade(pixel_center-i,cl,getColor((PIXELS_LENGTH/6)-i),(((float)radius-i)/radius)); // asigno el color al pixel anterior
		asignColor_fade(pixel_center+i,cl,getColor((PIXELS_LENGTH/6)-i),(((float)radius-i)/radius)); // asigno el color del pixel siguiente
		// mirrorles
		mirror(pixel_center-i);
		mirror(pixel_center+i);
	}
}

// *******************
// verifica los flags de touch, y aumenta el brillo correspondiente a los leds cercanos
void efects_touch_colision(struct color cl, uint8_t radius){
	if(radius > (PIXELS_LENGTH/6)-1 ){
		radius=(PIXELS_LENGTH/6)-1;
	}
	if(radius<1){
		radius=1;
	}
	if(flag_touch_1){
		efect_colision(PIXELS_LENGTH/16,cl,radius);
		flag_touch_1=OFF;
	}
	if(flag_touch_2){
		efect_colision(PIXELS_LENGTH*3/16,cl,radius);
		flag_touch_2=OFF;
	}
	if(flag_touch_3){
		efect_colision(PIXELS_LENGTH*5/16,cl,radius);
		flag_touch_3=OFF;
	}
	if(flag_touch_4){
		efect_colision(PIXELS_LENGTH*7/16,cl,radius);
		flag_touch_4=OFF;
	}
}



// ************* variales del main
struct color cl = {0,MAX_VALUE/2, MAX_VALUE/2}; // color principal

// ****************** MAIN ******************

int main(void)
{
   uint32_t state=OFF;

	initHardware();
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

   // pre-calcula las mascaras de bit, para tardar siempre el mismo tiempo en alcanzar cualquier bit
   init_mask_bit();

   init_touch_ADC();

   struct color c2 = {255,5,5}; // color de contraste - verde intenso

	while (1){  // cada vez que prende el led_integrado, actualiaza los leds

		while(update!=OFF); // espero que aya terminado de enviar los datos
		efect_sinoidal_breath_c_mirror(cl); // actualizo el color de toda la tira

		read_touch_ADC();
		efects_touch_colision(c2,3);
		//efect_breath_cian();

		if(state==ON){ //prende LED1
			 state=OFF;
			 Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, OFF );
         }
		else{          //apaga LED1
			 state=ON;
			 Chip_GPIO_SetPinState( LPC_GPIO_PORT, 0, 14, ON );
		}

		update=ON;   //actualiza TIRA LEDS

		delayInaccurateMs(delay_time); //retardo bloqueante 22ms, opcional
	}// end WHILE(TRUE)

}
