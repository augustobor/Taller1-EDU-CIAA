#include "timers_handler.h"


//***********************


// Rutina de atención de interrupciones (cada 5.04 us)
void TIMER1_IRQHandler(void) {
    if (Chip_TIMER_MatchPending(LPC_TIMER1, TIMER1_MATCH_CHANNEL)) {
        Chip_TIMER_ClearMatch(LPC_TIMER1, TIMER1_MATCH_CHANNEL); // Limpiar la bandera de coincidencia
        Sound_Service_DAC(); // Llamar al servicio de sonido
    }
}


// ************** Atención a Interrupciones Neopixel ******
   // ISR (Systick TIMER)
   // [USE-NEOPIXEL_UPDATE FUNCION HERE]
   // [MIGRATE-FUNCTION-TO-LOWER-MODULE]
   /*
   Systick_Handler logical strucure should be:
   if (neopixel_update){
	   send bytes to neopixel
   } else {
		timer_sound_counter++;
		if (timer_sound_counter > sound_timeout){
			send bytes to DAC
		}	
   }
*/
// ISR (Systick TIMER)
void SysTick_Handler(void){
    if(update==ON) {       //Actualizar NEOPIXEL
        LPC_GPIO_PORT->B[3][12] = 1; //Pin(higth) GPIO3[12]
        
        for( ret=WAITSHORT; ret>0; ret-- ); // delay "300ns"
        
        if( datachain[bit_index / 8] & bit_mask[bit_index % 8] ){ //si el bit analizado es 1
            for( ret=WAITLONG; ret>0; ret-- ); // delay "500ns"
        }
        LPC_GPIO_PORT->B[3][12] = 0;  // Pin(Low)
        
        bit_index= (bit_index+1) % PIXEL_BITS_LENGTH; // analiza el sigueinte bit
        if(bit_index==0) {    //si completo toda la tira terminar
            update=OFF;
            if(!Encoder_IS_Disable()) {
                // habilita lo que  deshabilito
                dacConfig( DAC_ENABLE );
                Chip_TIMER_Enable(LPC_TIMER1);
            }
        }
    }
}

void Neopixel_Update() {
    update=ON;
	printf("Update: %d\n", update);
    // deshabilita todo lo que genera interrupciones
    dacConfig( DAC_DISABLE );
    Chip_TIMER_Disable(LPC_TIMER1);
}

void Neopixel_Wait() {
    while(update!=OFF); // espero que haya terminado de enviar los datos
}