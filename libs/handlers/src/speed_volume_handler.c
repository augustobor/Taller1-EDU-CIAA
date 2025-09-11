#include "speed_volume_handler.h"
#include "Encoder.h"

static volatile uint8_t Gyro = 0.1;
static float cambio = 0.2f;

void SpeedVolume_Handler() {
    GYRO_mpuRead();
    GyroX = GYRO_mpu6050GetGyroX_rads();
    GyroZ = GYRO_mpu6050GetGyroZ_rads();
    Gyro = filter_gyro(GyroX, GyroZ);
    setIntensity((uint8_t)GyroX*1000000);
}


void Intensity_encoder_Handler(bool_t direction) {
    
    if (direction) {
        setIntensity(getIntensity() + cambio);
    } else {
        if (getIntensity() > 0) {
            setIntensity(getIntensity() - cambio);
        }
    }
}