#include "speed_volume_handler.h"
#include "Encoder.h"

static volatile float Gyro = 0.0f;
void SpeedVolume_Handler() {
    GYRO_mpuRead();
    GyroX = GYRO_mpu6050GetGyroX_rads();
    GyroZ = GYRO_mpu6050GetGyroZ_rads();
    Gyro = filter_gyro(GyroX, GyroZ);    
    if (Gyro > 2) {
        Gyro = 2;
    } else if (Gyro < -2) {
        Gyro = -2;
    }
    setIntensity((Gyro/2)*50.0f);
    VolumeHandler_Update(Gyro*0.05f);
}
