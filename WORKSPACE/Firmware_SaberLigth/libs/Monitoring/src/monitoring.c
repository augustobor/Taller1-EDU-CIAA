#include "monitoring.h"

clock_t init, end;
double tiempo;

void monitoring_set_time_count() {
    init = clock();
}

void monitoring_get_time_count() {
    end = clock();
    tiempo = (double)(end - init) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %.6f segundos\n", tiempo);
}