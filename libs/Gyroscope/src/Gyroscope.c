#include "Gyroscope.h"

//MPU control structure
static MPU9250_control_t control;

gyroscope_coordinates getGyroscopeValue() {
    control = mpu9250Read(); // Lectura general de los datos del MPU9250
    gyroscope_coordinates coord;
    coord.gyroX = control._gx;
    coord.gyroY = control._gy;
    coord.gyroZ = control._gz;
    return coord;
}

// Retorna la medición del giroscopio en la dirección x, rad/s
float GYRO_mpu9250GetGyroX_rads( void )
{
	return control._gx;
}

// Retorna la medición del giroscopio en la dirección y, rad/s
float GYRO_mpu9250GetGyroY_rads( void )
{
	return control._gy;
}

// Retorna la medición del giroscopio en la dirección z, rad/s
float GYRO_mpu9250GetGyroZ_rads( void )
{
	return control._gz;
}