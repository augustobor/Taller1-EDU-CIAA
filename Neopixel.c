#include "Neopixel.h"


// ************** Parametros de la tira led *****************
static uint32_t PIXEL_BITS_LENGTH = PIXELS_LENGTH*24; // cantidad de bits para administrar la tira led
//**********************************************************


// ************** Variables de la libreria Neopixel *********
      // habilita la actualizacion cuando es !=0
static volatile uint32_t bit_index=0;  // variable global bit recorrido
static volatile uint32_t ret;        // variable auxiliar para contabilizar los retardos
static volatile uint8_t bit_mask[8]; // Mascaras precalculadas para extraccion de los bits
static volatile uint8_t datachain[PIXELS_LENGTH*3]; // [ G R B ]
volatile uint32_t update=0;  



// *********** Parametros internos para generar la onda de datos de la tira led
   static volatile uint8_t WAITSHORT = 2;  // 3 // parametro para el retardo corto
   static volatile uint8_t WAITLONG = 7;   //4 // parametros para el retardo largo


//***********************


// ************** Atencion a Interrupciones Neopixel ******
   // ISR (Systick TIMER)
void SysTick_Handler(void) {
    if(update){       //Actualizar NEOPIXEL
        LPC_GPIO_PORT->SET[0] = (1 << 0); //Pin(higth)
        for( ret=WAITSHORT; ret>0; ret-- ); // delay "300ns"

        if( datachain[bit_index / 8] & bit_mask[bit_index % 8] ){ //si el bit analizado es 1
        for( ret=WAITLONG; ret>0; ret-- ); // delay "500ns"
        }

        LPC_GPIO_PORT->CLR[0] = (1 <<0);  // Pin(Low)

        bit_index= (bit_index+1) % PIXEL_BITS_LENGTH; // analiza el sigueinte bit
        if(bit_index==0){    //si completo toda la tira terminar
        update=OFF;
        }
    }
}

//***************************************


// le asigna el color "c", al "number_pixel", escalado en "level"
// numer_pixel entre "0" a "PIXEL_LENGTH-1"
void asignColor(uint8_t numer_pixel,struct color c,float level) {
    datachain[numer_pixel*3]  = c.g*level;
    datachain[numer_pixel*3+1]= c.r*level;
    datachain[numer_pixel*3+2]= c.b*level;
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
	datachain[((PIXELS_LENGTH)-number_pixel)*3] 	= datachain[number_pixel*3];
	datachain[((PIXELS_LENGTH)-number_pixel)*3+1] = datachain[number_pixel*3+1];
	datachain[((PIXELS_LENGTH)-number_pixel)*3+2] = datachain[number_pixel*3+2];
}

// asigna un color mesclando c1 y c2 en la pisicion indicada
// proporcion va entre 0 y 1, indica que tanto de c1 sera tomado en cuenta para el color final
// el color asignado es proporcion complementaria (porcentaje C1 + porcentaje C2 = 100% )
void asignColor_fade(uint8_t number_pixel, struct color c1, struct color c2, float proportion) {
	if(proportion>1){ // limito para mas del 100%
	  datachain[number_pixel*3]  = c1.g;
	  datachain[number_pixel*3+1]= c1.r;
	  datachain[number_pixel*3+2]= c1.b;
	}else{
		if(proportion<0){//limito para vamor menor al 0%
			  datachain[number_pixel*3]  = c2.g;
			  datachain[number_pixel*3+1]= c2.r;
			  datachain[number_pixel*3+2]= c2.b;
		}else{// calculo estandar
			  datachain[number_pixel*3]  = (proportion*c1.g)+((float)c2.g*(1-proportion));
			  datachain[number_pixel*3+1]= (proportion*c1.r)+((float)c2.r*(1-proportion));
			  datachain[number_pixel*3+2]= (proportion*c1.b)+((float)c2.b*(1-proportion));
		}
	}
}

