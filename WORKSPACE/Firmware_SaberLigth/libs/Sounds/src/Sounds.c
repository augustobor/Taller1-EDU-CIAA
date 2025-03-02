// #include "Sounds.h"

// float ganancia = 1;

// float vt = 0; // velocidad de transducción, es que tan rápido lee el sonido
// float state_read = 0; // es el instante actual de lectura de sonido

// uint8_t enable_colision = 0;
// float vtC = 0.97;
// float state_readC = 0; // índice de lectura del sonido colisión

// // Inicializa configuraciones del Timer 1, DAC y variables
// void Sounds_Init() {
//     // Configuración del DAC
//     dacConfig(ENABLE);

//     // Configuración del Timer 1
//     Chip_TIMER_Init(LPC_TIMER1);
//     Chip_TIMER_PrescaleSet(LPC_TIMER1, 1024); // 1024 equivale a aproximadamente 5.04 us

//     // Configuración del Match 0 (periodo)
//     Chip_TIMER_MatchEnableInt(LPC_TIMER1, 0);
//     Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 0);
//     Chip_TIMER_StopOnMatchDisable(LPC_TIMER1, 0);
//     Chip_TIMER_SetMatch(LPC_TIMER1, 0, 1);

//     // Inicialización del Timer 1
//     Chip_TIMER_Reset(LPC_TIMER1);
//     Chip_TIMER_Enable(LPC_TIMER1);

//     // Habilitación de la interrupción del Timer 1
//     NVIC_EnableIRQ(TIMER1_IRQn);
// }

// // Rutina de atención de interrupciones (cada 5.04 us)
// void TIMER1_IRQHandler(void) {
//     if (Chip_TIMER_MatchPending(LPC_TIMER1, 0)) {
//         Chip_TIMER_ClearMatch(LPC_TIMER1, 0);
//         Sound_Service_DAC();
//     }
// }

// // Modifica la velocidad de escritura del DAC para generar una variación de frecuencia
// void moduleSound(float velocidad_transduccion) {
//     vt = velocidad_transduccion;
// }

// // Interpolación lineal, toma 2 valores y el porcentaje de cercanía entre ellos
// float interpol(uint16_t y1, uint16_t y2, float dx) {
//     return (y1 + (y2 - y1) * dx);
// }

// // Servicio de sonido para el DAC
// void Sound_Service_DAC() {
//     if (ganancia != 0) {
//         float sound_point = 0;

//         // Etapa 1: Incremento al siguiente paso de lectura (en base al pase de la velocidad de transducción)
//         state_read += vt;
//         uint16_t index_read = TRUNC(state_read); // Trunco el valor entero del índice

// 		/*
// 		Etapa 2: Interpolación y amplificación
// 		- Interpola los 2 valores más cercanos (el valor anterior de sonido y el siguiente dado 
// 		por el paso) a la lectura, respecto a la velocidad de lectura flotante,
// 		- Luego amplifica ese valor, teniendo en cuenta que el valor medio de la señal 
// 		guardada es de +128;
// 		el valor medio de la señal amplificada es +500
// 		*/
// 		sound_point += amplificarS(interpol(raw_samples[index_read], raw_samples[index_read + 1], (state_read - index_read)));

//         // Etapa 3: Truncado de la señal
//         if (sound_point > 1024) sound_point = 1024;
//         if (sound_point < 0) sound_point = 0;

//         // Etapa 4: Envío del valor al DAC
//         Chip_DAC_UpdateValue(LPC_DAC, sound_point);

//         // Etapa 5: Reinicio de la lectura si se sobrepasa la tabla de valores (control circular)
//         if (state_read >= raw_samples_length) {
//             state_read -= raw_samples_length;
//         }
//     }
// }

// /*
// Si los táctiles están activados
// Retorna valores de señal, onda cuadrada, sin valor medio
// Con amplitud @amp=350
// Con frecuencia normalizada = velocity_push/(2*100) = 0.5 ciclos/escritura
// */
// float generador_onda_cuadrada() {
//     float count_push = 0;
//     float velocity_push = 50;
//     float amp = 350;
//     uint8_t direction = 0;
//     if (enable_colision) {
//         count_push += velocity_push; // Incremento un paso de audio
//         if (count_push > 100) { // Si el contador rebalsa
//             count_push -= 100; // Reseteo
//             direction = !direction; // Cambio la dirección
//         }
//         return direction ? amp : -amp; // Le asigno la onda cuadrada, centrada en 0
//     }
//     return 0;
// }

// /*
// Retorna valores de señal, onda cuadrada, sin valor medio
// Con velocidad de lectura @vtC
// Con ganancia 3.5
// Si los touch están activados, envía 1 de cada 2 valores
// Si los touch están activados, modifica la ganancia del efecto principal @ganancia=1
// */
// float sonido_auxiliar() {
//     static uint8_t trimer = 0;
//     trimer = !trimer; // Para generar un efecto más grotesco, el efecto colisión, solo se aplica 1 de cada 2 puntos, generando una onda cuadrada que deforma la señal
//     if ((enable_colision) && (trimer)) {
//         state_readC += vtC; // Incremento al siguiente paso de lectura
//         uint16_t index_readC = TRUNC(state_readC); // Trunco el valor entero del índice

//         if (state_readC >= raw_samples_length) { // Si sobrepaso la lectura de la tabla de valores, vuelvo al inicio
//             state_readC -= raw_samples_length;
//         }
//         ganancia = 1;
//         return 3.5 * (interpol(raw_samples[index_readC], raw_samples[index_readC + 1], (state_readC - index_readC)) - 128); // Le sumo la señal de colisión, sin el valor medio
//     }
//     return 0;
// }

// // Establece la ganancia
// void setGain(float g) {
//     ganancia = g;
// }

// // Obtiene el valor absoluto del giroscopio
// float get_gyro_abs_val() {
//     static float antiBUG[5]; // Guarda los valores promedio, si detecta 5 veces el mismo valor, RESET
//     static uint8_t indexBUG = 0;

//     // Obtiene la lectura
//     uint8_t lecturaStatus = mpu60X0Read();
//     while (!lecturaStatus); // Si hay lectura errónea, bloqueo el código

//     float value = ((GYRO_X_COMPONENT + GYRO_Y_COMPONENT + GYRO_Z_COMPONENT) / GYRO_MAX_VALUE);
//     antiBUG[indexBUG] = value;
//     indexBUG = ((indexBUG + 1) % 5);
//     if ((antiBUG[0] == antiBUG[1]) && (antiBUG[1] == antiBUG[2]) && (antiBUG[2] == antiBUG[3]) && (antiBUG[3] == antiBUG[4])) {
//         // Si los 5 valores son idénticos, HARD-RESET
//         mpu60X0Init(MPU60X0_ADDRESS_0);
//     }

//     if (value < 1) { // Retorna el porcentaje absoluto de aceleración angular, respecto al máximo posible
//         return value;
//     } else {
//         return 1;
//     }
// }

// // Amplifica la señal
// uint16_t amplificarS(float raw) {
//     raw = (raw - 128) * ganancia; // Saco el valor medio
//     if (raw > 512) {
//         ganancia = 1;
//         struct color cl = { (rand()) % 170, (rand()) % 170, (rand()) % 170 }; // Asigna nuevo color random
//         Efects_colision(25, cl, 22); // Efecto_BUGG();
//         return 1024; // Limito el valor máximo
//     }
//     if (raw < -512) { // Limito el valor mínimo
//         ganancia = 1;
//         struct color cl = { (rand()) % 170, (rand()) % 170, (rand()) % 170 }; // Asigna nuevo color random
//         Efects_colision(25, cl, 22); // Efecto_BUGG();
//         return 0;
//     }
//     return (raw + 512); // Retorna el valor amplificado
// }

// // Habilita o deshabilita el sonido de colisión
// void set_enable_colision_sound(uint8_t enable) {
//     enable_colision = enable;
// }

