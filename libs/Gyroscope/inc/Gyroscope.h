#ifndef _GYROSCOPE_H_
#define _GRYROSCOPE_H_

#include "Neopixel.h"
#include "sapi_imu_mpu9250.h"
#include "sapi_imu_mpu60X0.h"

#define GYRO_MAX_VALUE 5	//rad/s

typedef struct {
    // Variables para almacenar los valores del giroscopio
    float gyroX;
    float gyroY;
    float gyroZ;
} gyroscope_coordinates;

// gyroscope_coordinates getGyroscopeValue();
float get_gyro_abs_val();// retorna valor absoluto de movimiento entre [0..1]
float GYRO_mpu9250GetGyroX_rads( void );
float GYRO_mpu9250GetGyroY_rads( void );
float GYRO_mpu9250GetGyroZ_rads( void );

#endif