#ifndef _GYROSCOPE_H_
#define _GRYROSCOPE_H_

#include "Neopixel.h"
#include "sapi_imu_mpu60X0.h"

#define GYRO_MAX_VALUE 5.0f

static float alpha = 0.25; // Coeficiente de suavizado (entre 0 y 1)
static float last_value_x = 0;
static float last_value_z = 0;  
static float GyroX = 0;
static float GyroZ = 0;

MPU60X0_control_t GYRO_mpuRead( void );
float GYRO_mpu6050GetGyroX_rads( void );
float GYRO_mpu6050GetGyroZ_rads( void );
float filter_gyro(float, float);

#endif