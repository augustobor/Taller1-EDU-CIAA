#include "Gyroscope.h"

//MPU control structure
//static MPU9250_control_t control;
static MPU60X0_control_t control;

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

// Retorna la medición del giroscopio en la dirección x, rad/s
float GYRO_mpu6050GetGyroX_rads( void )
{
	return control._gx;
}
// Retorna la medición del giroscopio en la dirección z, rad/s
float GYRO_mpu6050GetGyroZ_rads( void )
{
	return control._gz;
}

float filter_gyro(float GyX, float GyZ) {
    float filtered_value_x = alpha * GyX + (1 - alpha) * last_value_x;
    float filtered_value_z = alpha * GyZ + (1 - alpha) * last_value_z;
    last_value_x = filtered_value_x;
    last_value_z = filtered_value_z;
    return filtered_value_x + filtered_value_z;
}