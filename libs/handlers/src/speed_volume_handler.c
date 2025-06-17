#include "speed_volume_handler.h"

void SpeedVolume_Handler() {
    VolumeHandler_Update(getGyroscopeValue()); // Actualiza el volumen basado en el estado del giroscopio
}
