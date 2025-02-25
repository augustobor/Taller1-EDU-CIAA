#include "Neopixel.h"
#include "chip.h" // Include for Chip_TIMER_Enable, Chip_TIMER_Disable, LPC_TIMER1

#define ON       1
#define OFF      0

// ************** Parámetros de la tira LED *****************
static uint32_t PIXEL_BITS_LENGTH = PIXELS_LENGTH*24; // cantidad de bits para administrar la tira LED
//**********************************************************


// ************** Variables de la librería Neopixel *********

static volatile uint32_t bit_index=0; // variable global bit recorrido
static volatile uint32_t ret;         // variable auxiliar para contabilizar los retardos
static volatile uint8_t bit_mask[8];  // Máscaras precalculadas para extracción de los bits
static volatile uint8_t datachain[PIXELS_LENGTH*3]; // [ G R B ]
static volatile uint32_t update=0;    // habilita la actualización cuando es !=0

struct color currentColor = {170, 0, 170}; // si el color es negro: el sistema deja de enviar colores

void setCurrentColor(struct color cl){
	currentColor=cl;
}

struct color getCurrentColor(){
	return currentColor;
}


// *********** Parámetros internos para generar la onda de datos de la tira LED
   static volatile uint8_t WAITSHORT = 2;  // 3 // parámetro para el retardo corto
   static volatile uint8_t WAITLONG = 7;   //4 // parámetros para el retardo largo
//***********************


// ************** Atención a Interrupciones Neopixel ******
   // ISR (Systick TIMER)
   // [MIGRATE-FUNCTION-TO-LOWER-MODULE]
//    void SysTick_Handler(void){
// 		 if(update){       //Actualizar NEOPIXEL
// 			LPC_GPIO_PORT->B[3][12] = 1; //Pin(high) GPIO3[12]
// 			for( ret=WAITSHORT; ret>0; ret-- ); // delay "300ns"

// 			if( datachain[bit_index / 8] & bit_mask[bit_index % 8] ){ //si el bit analizado es 1
// 			   for( ret=WAITLONG; ret>0; ret-- ); // delay "500ns"
// 			}

// 			LPC_GPIO_PORT->B[3][12] = 0;  // Pin(Low)

// 			bit_index= (bit_index+1) % PIXEL_BITS_LENGTH; // analiza el siguiente bit
// 			if(bit_index==0){    //si completó toda la tira terminar
// 			   update=OFF;
// 			   if(!Encoder_IS_Disable()){
// 					// habilita lo que deshabilitó
// 				   //dacConfig( DAC_ENABLE );
// 				   Chip_TIMER_Enable(LPC_TIMER1);
// 			   }
// 			}
// 		 }
//    }
//***************************************

// ************ INIT máscaras Neopixel ********
   // Pre-calcula las máscaras de bits para la extracción de todos los "bit" en tiempo constante
   void init_mask_bit(){
      for (int bit = 7; bit >=0 ; bit--) {
         bit_mask[ 7-bit ] = 1 << bit; // ordena las máscaras de mayor a menor
      }
   }

//***************************************

// configura interrupción del timer0 cada 1.25uS, e inicializa las máscaras
void Neopixel_Init(){
	SystemCoreClockUpdate();
	// SysTick_Config(SystemCoreClock / 1000);
	SysTick_Config(255); //Generación de interrupciones periódicas cada 1250ns
		// pre-calcula las máscaras de bit, para tardar siempre el mismo tiempo en alcanzar cualquier bit
	init_mask_bit();

}


// le asigna una proporción del color del sistema, al "number_pixel", escalado en "level" entre 0 a 255
// number_pixel entre "0" a "PIXEL_LENGTH-1"
void setColor_i(uint8_t number_pixel, float level) {
	level=level/255;
    datachain[number_pixel*3]  = level*currentColor.g;
    datachain[number_pixel*3+1]= level*currentColor.r;
    datachain[number_pixel*3+2]= level*currentColor.b;
}

// apaga el pixel con número @number_pixel
void pixel_off(uint8_t number_pixel){
    datachain[number_pixel*3]  = 0;
    datachain[number_pixel*3+1]= 0;
    datachain[number_pixel*3+2]= 0;
}

// int @number_pixel válido 0,(PIXELS_LENGTH-1)
// color @c ( uint8_t, uint8_t, uint8_t )
void setColor(uint8_t number_pixel, struct color c){
	datachain[number_pixel*3]=c.g;
	datachain[number_pixel*3+1]=c.r;
	datachain[number_pixel*3+2]=c.b;
}
struct color getColor(uint8_t number_pixel){
	struct color c1;
	c1.g=datachain[number_pixel*3];
	c1.r=datachain[number_pixel*3+1];
	c1.b=datachain[number_pixel*3+2];
	return c1;
}

// copia el color del pixel, a su relativo en la parte superior de la tira
// number_pixel >0 && number_pixel < (PIXELS_LENGTH-1)/2
void mirror(uint8_t number_pixel) {
	datachain[((PIXELS_LENGTH)-number_pixel)*3]   = datachain[number_pixel*3];
	datachain[((PIXELS_LENGTH)-number_pixel)*3+1] = datachain[number_pixel*3+1];
	datachain[((PIXELS_LENGTH)-number_pixel)*3+2] = datachain[number_pixel*3+2];
}

// copia espejada de los colores de la tira LED, respecto a PIXELS_LENGTH/2
void mirror_all(){
	for(uint8_t i=0 ; i<(PIXELS_LENGTH-1)/2 ; i++){
		mirror(i);
	}
}

// asigna un color mezclando c1 y c2 en la posición indicada
// proporción va entre 0 y 1, indica que tanto de c1 será tomado en cuenta para el color final
// el color asignado es proporción complementaria (porcentaje C1 + porcentaje C2 = 100% )
void setColor_fade(uint8_t number_pixel, struct color c1, struct color c2, float proportion) {
	if(proportion>1){ // limito para más del 100%
	  datachain[number_pixel*3]  = c1.g;
	  datachain[number_pixel*3+1]= c1.r;
	  datachain[number_pixel*3+2]= c1.b;
	}else{
		if(proportion<0){//limito para valor menor al 0%
			  datachain[number_pixel*3]  = c2.g;
			  datachain[number_pixel*3+1]= c2.r;
			  datachain[number_pixel*3+2]= c2.b;
		}else{// cálculo estándar
			  datachain[number_pixel*3]  = (proportion*c1.g)+((float)c2.g*(1-proportion));
			  datachain[number_pixel*3+1]= (proportion*c1.r)+((float)c2.r*(1-proportion));
			  datachain[number_pixel*3+2]= (proportion*c1.b)+((float)c2.b*(1-proportion));
		}
	}
}

// [DEPRECATED-FUNCTION-CANDIDATE]
// void Neopixel_Update() {
//     update=ON;
//     // deshabilita todo lo que genera interrupciones
//     dacConfig( DAC_DISABLE );
//     Chip_TIMER_Disable(LPC_TIMER1);
// }

// [DEPRECATED-FUNCTION-CANDIDATE]
// void Neopixel_Wait() {
//     while(update!=OFF); // espero que haya terminado de enviar los datos
// }
