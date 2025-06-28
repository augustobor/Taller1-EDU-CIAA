#include "Gyroscope.h"

float getGyroscopeValue() {
    mpu60X0Read();
    float gyroX = mpu60X0GetGyroX_rads();
    float gyroY = mpu60X0GetGyroY_rads();
    float gyroZ = mpu60X0GetGyroZ_rads();

    return (gyroX + gyroY + gyroZ) / 3.0;
}
