
#include "init.h"

// Inicializa el Timer 1 para generar interrupciones periódicas
void Timer1_Init(void) {
    // Configuración del Timer 1
    Chip_TIMER_Init(LPC_TIMER1);
    Chip_TIMER_PrescaleSet(LPC_TIMER1, 1024); // 1024 equivale a aproximadamente 5.04 us

    // Configuración del Match 0 (periodo)
    Chip_TIMER_MatchEnableInt(LPC_TIMER1, 0);
    Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 0);
    Chip_TIMER_StopOnMatchDisable(LPC_TIMER1, 0);
    Chip_TIMER_SetMatch(LPC_TIMER1, 0, 1);

    // Inicialización del Timer 1
    Chip_TIMER_Reset(LPC_TIMER1);
    Chip_TIMER_Enable(LPC_TIMER1);

    // Habilitación de la interrupción del Timer 1
    NVIC_EnableIRQ(TIMER1_IRQn);
}


// inicializa las entradas digitales del encoder
void Encoder_Init(void) {
    // Configuración para la rotación del encoder
    gpioConfig(ENC_A_CLK_PIN, GPIO_INPUT);
    gpioConfig(ENC_B_DT_PIN, GPIO_INPUT);

    // Configuración para cuando el pulsador se presiona
    gpioConfig(BOTON_SW_PIN, GPIO_INPUT);
}

// Inicializa el Neopixel
// configura interrupción del timer0 cada 1.25uS, e inicializa las máscaras
void Neopixel_Init(){
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

	SystemCoreClockUpdate();
	// SysTick_Config(SystemCoreClock / 1000);
	SysTick_Config(255); //Generación de interrupciones periódicas cada 1250ns
		// pre-calcula las máscaras de bit, para tardar siempre el mismo tiempo en alcanzar cualquier bit
	init_mask_bit();

}

//***************************************

// ************ INIT máscaras Neopixel ********
   // Pre-calcula las máscaras de bits para la extracción de todos los "bit" en tiempo constante
   void init_mask_bit(){
      for (int bit = 7; bit >=0 ; bit--) {
         bit_mask[ 7-bit ] = 1 << bit; // ordena las máscaras de mayor a menor
      }
   }

//***************************************


void TouchADC_Init(){
    /* Config ADC0 sample mode */
    ADC_CLOCK_SETUP_T ADCSetup = {
       ADC_MAX_SAMPLE_RATE,   // ADC Sample rate:ADC_MAX_SAMPLE_RATE = 400KHz
       10,                    // ADC resolution: ADC_10BITS = 10
       0                      // ADC Burst Mode: (true or false)
    };


	Chip_ADC_Init(LPC_ADC0, &ADCSetup);
    /* Disable burst mode */
    Chip_ADC_SetBurstCmd( LPC_ADC0, DISABLE );

	Chip_ADC_SetSampleRate(LPC_ADC0, &ADCSetup, 88000);

	Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH3, ENABLE);

	// deshabilita el resto de los canales
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH3, DISABLE );
    Chip_ADC_EnableChannel( LPC_ADC0, ADC_CH2, DISABLE );
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH2, DISABLE );
    Chip_ADC_EnableChannel( LPC_ADC0, ADC_CH1, DISABLE );
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH1, DISABLE );
    Chip_ADC_EnableChannel( LPC_ADC0, ADC_CH4, DISABLE );
    Chip_ADC_Int_SetChannelCmd( LPC_ADC0, ADC_CH4, DISABLE );

}

// Inicializa configuraciones del DAC y variables
void Sounds_Init() {
    // Configuración del DAC
    dacConfig(DAC_ENABLE);
}


void Gyroscope_Init() {
    mpu9250Init(MPU9250_ADDRESS_0);
}