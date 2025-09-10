#include "speed_volume_handler.h"
#include "Encoder.h"

static float Gyro = 0.0f;
static float cambio = 0.2f;

void SpeedVolume_Handler() {
    GYRO_mpuRead();
    GyroX = GYRO_mpu6050GetGyroX_rads();
    GyroZ = GYRO_mpu6050GetGyroZ_rads();
    
    Gyro = filter_gyro(GyroX, GyroZ);
    printf("Gyro: %d\n", (uint8_t)(GyroX*10000));
    //setIntensity((uint8_t)(Gyro*10000));
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