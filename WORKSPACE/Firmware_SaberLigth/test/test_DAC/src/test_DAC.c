
#include "sapi.h"         /* <= sAPI header */

#define raw_samples_length 100
static uint16_t raw_samples[] =	// onda senoidal 100 samples, valor medio 128, amplitud [0..255]
{
	128, 130, 132, 134, 136, 139, 141, 143, 145, 147, 150, 152, 154, 156, 158, 160, 163, 165, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 187, 189, 191, 193, 195, 197, 199, 201, 202, 204, 206, 208, 209, 211, 213, 214, 216, 218, 219, 221, 222, 224, 225, 227, 228, 229, 231, 232, 233, 234, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 247, 248, 249, 249, 250, 251, 251, 252, 252, 253, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 253,
};

void dddd(uint32_t delay_ms){
   volatile uint32_t i;
   volatile uint32_t delay;
   delay = INACCURATE_TO_MS * delay_ms;
   for( i=delay; i>0; i-- );
}

int main(){
   boardConfig();

   dacConfig( DAC_ENABLE );

   uint8_t i=0;
   while(TRUE){
	   i= i++ % raw_samples_length ;
       dacWrite( DAC, raw_samples[i] );

       ledState1 = !ledState1;
       gpioWrite( LED1, ledState1 );

       dddd(20); // delay de aproximadamente 20ms

   }
}

