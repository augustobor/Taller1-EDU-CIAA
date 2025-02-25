#include "sounds.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// Function prototypes
void testAmplificarS(void);
void testGeneradorOndaCuadrada(void);
void testSonidoAuxiliar(void);
bool validateResult(float expected, float actual, float tolerance);
void run_tests(void);

/*
Used functions:
- amplificarS
- generador_onda_cuadrada
- sonido_auxiliar
*/

void testAmplificarS(void) {
    printf("Test 1: Amplificar S\n");
    float raw = 128.0;
    uint16_t amplifiedVal = amplificarS(raw);
    printf("Amplified Val: %u\n", amplifiedVal);

    // Validate result
    uint16_t expected = 512;
    if (!validateResult(expected, amplifiedVal, 10)) {
        printf("Test 1 failed\n");
        exit(1);
    }
    printf("Test 1 passed\n");
    sleep(1);  // Wait for 1 second
}

void testGeneradorOndaCuadrada(void) {
    printf("Test 2: Generador Onda Cuadrada\n");
    float squareWave = generador_onda_cuadrada();
    printf("Square Wave: %f\n", squareWave);

    // Validate result
    float expected = 350.0;  // Example expected value
    if (!validateResult(expected, squareWave, 10.0)) {
        printf("Test 2 failed\n");
        exit(1);
    }
    printf("Test 2 passed\n");
    sleep(1);  // Wait for 1 second
}

void testSonidoAuxiliar(void) {
    printf("Test 3: Sonido Auxiliar\n");
    float auxSound = sonido_auxiliar();
    printf("Auxiliary Sound: %f\n", auxSound);

    // Validate result
    float expected = 3.5 * (128 - 128);  // Example expected value
    if (!validateResult(expected, auxSound, 10.0)) {
        printf("Test 3 failed\n");
        exit(1);
    }
    printf("Test 3 passed\n");
    sleep(1);  // Wait for 1 second
}

bool validateResult(float expected, float actual, float tolerance) {
    return (actual >= expected - tolerance) && (actual <= expected + tolerance);
}

void run_tests(void) {
    testAmplificarS();
    testGeneradorOndaCuadrada();
    testSonidoAuxiliar();
}

int main(void) {
    // Initialize the sound system
    Sounds_Init();

    // Run tests
    run_tests();

    return 0;
}
