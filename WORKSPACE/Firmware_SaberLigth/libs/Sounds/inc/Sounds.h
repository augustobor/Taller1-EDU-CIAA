
#ifndef _SOUNDS_H_
#define _SOUNDS_H_

#include "sapi.h"
#include "board.h"
#define TRUNC(n) ((uint16_t)(n))

#define GYRO_MAX_VALUE 5	//rad/s

//Devuelven el valor absoluto de la entrada
#define GYRO_X_COMPONENT ((mpu60X0GetGyroX_rads() < 0) ? -mpu60X0GetGyroX_rads() : mpu60X0GetGyroX_rads())
#define GYRO_Y_COMPONENT ((mpu60X0GetGyroY_rads() < 0) ? -mpu60X0GetGyroY_rads() : mpu60X0GetGyroY_rads())
#define GYRO_Z_COMPONENT ((mpu60X0GetGyroZ_rads() < 0) ? -mpu60X0GetGyroZ_rads() : mpu60X0GetGyroZ_rads())

float get_gyro_abs_val();// retorna valor absoluto de movimiento entre [0..1]

void Sounds_Init();   // Inicializa configuraciones del Timer 1 , DAC y variables
void Sound_Service_DAC();	// servicio de ejecucion continua para enviar muestras al DAC
void setGanance(float g);
void moduleSound(float porcentual);
uint16_t amplificarS(float);
float interpol(uint16_t y1 ,uint16_t y2, float dx );
void moduleSound(float velocidad_transduccion);
void set_enable_colision_sound(bool_t enable);

#endif /* #ifndef _SOUNDS_H_*/
