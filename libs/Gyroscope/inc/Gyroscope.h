#ifndef _GYROSCOPE_H_
#define _GYROSCOPE_H_

#include "sapi_imu_mpu9250.h"

typedef struct {
    // Variables para almacenar los valores del giroscopio
    float gyroX;
    float gyroY;
    float gyroZ;
} gyroscope_coordinates;

gyroscope_coordinates getGyroscopeValue();
float GYRO_mpu9250GetGyroX_rads( void );
float GYRO_mpu9250GetGyroY_rads( void );
float GYRO_mpu9250GetGyroZ_rads( void );

#endif