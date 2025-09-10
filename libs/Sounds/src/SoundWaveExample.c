#include "Sounds.h"
#include "SoundWaveExample.h"

// Function prototypes
void testAmplificarS(void);
void testSonidoAuxiliar(void);
bool validateResultWave(float expected, float actual, float tolerance);
void run_tests(void);

/*
Used functions:
- amplificarS
- sonido_auxiliar
*/

void testAmplificarS(void) {
    printf("Test 1: Amplificar S\n");
    float raw = 128.0;
    uint16_t amplifiedVal = amplificarS(raw);
    printf("Amplified Val: %u\n", amplifiedVal);

    // Validate result
    uint16_t expected = 512;
    if (!validateResultWave(expected, amplifiedVal, 10)) {
        printf("Test 1 failed\n");
    } else {
        printf("Test 1 passed\n");
    }	
}

void testSonidoAuxiliar(void) {
    printf("Test 2: Sonido Auxiliar\n");
    float auxSound = sonido_auxiliar();
    printf("Auxiliary Sound: %f\n", auxSound);

    // Validate result
    float expected = 3.5 * (128 - 128);  // Example expected value
    if (!validateResultWave(expected, auxSound, 10.0)) {
        printf("Test 2 failed\n");
    } else {
        printf("Test 2 passed\n");
    }
}

bool validateResultWave(float expected, float actual, float tolerance) {
    return (actual >= expected - tolerance) && (actual <= expected + tolerance);
}

void runTestsSoundWave(void) {
    testAmplificarS();
    testSonidoAuxiliar();
}

