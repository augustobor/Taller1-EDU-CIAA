#ifndef _SOUNDS_H_
#define _SOUNDS_H_

//#include "Neopixel_Efects.h"
#include "sapi_dac.h" // Se puede dejar
#include <stdlib.h> // Se deja por el rand
#include "sapi_imu_mpu60X0.h"


#define TRUNC(n) ((uint16_t)(n))

//Devuelven el valor absoluto de la entrada
#define GYRO_X_COMPONENT ((mpu60X0GetGyroX_rads() < 0) ? -mpu60X0GetGyroX_rads() : mpu60X0GetGyroX_rads())
#define GYRO_Y_COMPONENT ((mpu60X0GetGyroY_rads() < 0) ? -mpu60X0GetGyroY_rads() : mpu60X0GetGyroY_rads())
#define GYRO_Z_COMPONENT ((mpu60X0GetGyroZ_rads() < 0) ? -mpu60X0GetGyroZ_rads() : mpu60X0GetGyroZ_rads())

void Sounds_Init();

void Sound_Service_DAC();	// servicio de ejecucion continua para enviar muestras al DAC
uint16_t amplificarS(float);
float interpol(uint16_t y1 ,uint16_t y2, float dx );
void moduleSound(float velocidad_transduccion);
void set_enable_colision_sound(uint8_t enable);
void setGain(float g);
float sonido_auxiliar();

#define raw_samples_length 5324


#endif /* #ifndef _SOUNDS_H_ */

