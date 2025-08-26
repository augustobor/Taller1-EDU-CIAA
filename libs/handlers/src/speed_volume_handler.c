#include "speed_volume_handler.h"
#include "Encoder.h"

static volatile float Gyro = 0.0f;
void SpeedVolume_Handler() {
    GyroX = GYRO_mpu6050GetGyroX_rads();
    GyroZ = GYRO_mpu6050GetGyroZ_rads();
    Gyro = filter_gyro(GyroX, GyroZ);
    //printf("Test: %f\n", 1.234f);

    if (Gyro > 2) {
        Gyro = 2;
    } else if (Gyro < -2) {
        Gyro = -2;
    }
    VolumeHandler_Update(Gyro*0.05f);
    //setPorcentualState(Gyro*0.015f);
}
