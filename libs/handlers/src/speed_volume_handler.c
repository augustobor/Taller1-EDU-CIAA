#include "speed_volume_handler.h"
#include "Encoder.h"

static volatile float Gyro = 0.0f;


void SpeedVolume_Handler() {
    GYRO_mpuRead();
    GyroX = GYRO_mpu6050GetGyroX_rads();
    GyroZ = GYRO_mpu6050GetGyroZ_rads();
    
    if(GyroX > 3.0f) GyroX = 3.0f;
    Gyro = filter_gyro(GyroX, GyroZ);
    if (Gyro > 2) {
        Gyro = 2;
    } else if (Gyro < -2) {
        Gyro = -2;
    }
    printf("Gyro: %d\n", (int)(Gyro*10000));
    setIntensity(Gyro);
    //VolumeHandler_Update(Gyro*0.05f);
}
