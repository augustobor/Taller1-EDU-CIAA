#include "Gyroscope.h"

//MPU control structure
static MPU60X0_control_t current_control;

void GYRO_mpuRead( void )
{
    current_control = mpu60X0Read_returned();
}

// Retorna la medición del giroscopio en la dirección x, rad/s
uint8_t GYRO_mpu6050GetGyroX_rads( void )
{
    return (uint8_t)(current_control._gx);
}
// Retorna la medición del giroscopio en la dirección z, rad/s
uint8_t GYRO_mpu6050GetGyroZ_rads( void )
{
	return (uint8_t)(current_control._gz);
}

uint8_t filter_gyro(uint8_t GyX, uint8_t GyZ) {
    uint8_t filtered_value_x = alpha * GyX + (1 - alpha) * last_value_x;
    uint8_t filtered_value_z = alpha * GyZ + (1 - alpha) * last_value_z;
    last_value_x = filtered_value_x;
    last_value_z = filtered_value_z;
    return filtered_value_x + filtered_value_z;
}