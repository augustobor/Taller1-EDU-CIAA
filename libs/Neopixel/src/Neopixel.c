#include "Neopixel.h"
#include "chip.h" // Include for Chip_TIMER_Enable, Chip_TIMER_Disable, LPC_TIMER1

#define ON       1
#define OFF      0


struct color currentColor = {170, 0, 170}; // si el color es negro: el sistema deja de enviar colores
static uint8_t currentIntensity = 0;

/**
 * @brief Setea el color actual que se muestra en la tira LED. El color se aplica
 *        a todos los pixeles de la tira LED.
 *
 * @param[in] cl: Estructura que contiene el color RGB a setear.
 */
void setCurrentColor(struct color cl){
	currentColor=cl;
}

struct color getCurrentColor(){
	return currentColor;
}



// le asigna una proporción del color del sistema, al "number_pixel", escalado en "level" entre 0 y 1
// number_pixel entre "0" a "PIXEL_LENGTH-1"
void setColor_i(uint8_t number_pixel, float level) {
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
// Si proporción es 0, el color asignado es c2
// Si proporción es 1, el color asignado es c1
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

void setIntensity(uint8_t intensity) {
    currentIntensity = intensity;
}

uint8_t getIntensity(void) {
    return currentIntensity;
}