#include "speed_volume_handler.h"

void SpeedVolume_Handler() {
    printf("%f\n", get_gyro_abs_val());
    VolumeHandler_Update(1- get_gyro_abs_val()); // Actualiza el volumen basado en el estado del giroscopio
    setPorcentualState(1 - get_gyro_abs_val()); // Actualiza el estado porcentual basado en el giroscopio
}
