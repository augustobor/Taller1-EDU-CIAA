#include "Gyroscope.h"

//MPU control structure
static MPU60X0_control_t current_control;

MPU60X0_control_t GYRO_mpuRead( void )
{
    current_control = mpu60X0Read_returned();
    printf("Status: %d\n", current_control._status);
	return current_control;
}

// Retorna la medición del giroscopio en la dirección x, rad/s
float GYRO_mpu6050GetGyroX_rads( void )
{
    return current_control._gx;
}
// Retorna la medición del giroscopio en la dirección z, rad/s
float GYRO_mpu6050GetGyroZ_rads( void )
{
	return current_control._gz;
}

float filter_gyro(float GyX, float GyZ) {
    float filtered_value_x = alpha * GyX + (1 - alpha) * last_value_x;
    float filtered_value_z = alpha * GyZ + (1 - alpha) * last_value_z;
    last_value_x = filtered_value_x;
    last_value_z = filtered_value_z;
    return filtered_value_x + filtered_value_z;
}