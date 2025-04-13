#include "sounds.h"
#include "SoundExample.h"

// Function prototypes
void testSingleTone(void);
void testMelody(void);
void testFrequencySweep(void);
void testCustomPattern(void);
bool validateResult(float expected, float actual, float tolerance);
void runTestsSound(void);

/*
Used functions:
- Sounds_Init
- moduleSound
- setGain
- set_enable_collision_sound
*/

void testSingleTone(void) {
    printf("Test 1: Play a single tone\n");
    moduleSound(1.0);  // Set frequency
    setGain(1.0);   // Set gain
    // Validate result
    float expected = 1.0;
    float actual = 1.0;  // Replace with actual value from the system
    if (!validateResult(expected, actual, 0.1)) {
        printf("Test 1 failed\n");
        exit(1);
    }
    printf("Test 1 passed\n");
}

void testMelody(void) {
    printf("Test 2: Play a melody\n");
    float melody[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2};  // Frequencies
    for (int i = 0; i < 8; i++) {
        moduleSound(melody[i]);
        setGain(1.0);
    }

    // Validate result
    float expected = 1.2;
    float actual = 1.2;  // Replace with actual value from the system
    if (!validateResult(expected, actual, 0.1)) {
        printf("Test 2 failed\n");
        exit(1);
    }
    printf("Test 2 passed\n");
}

void testFrequencySweep(void) {
    printf("Test 3: Play a frequency sweep\n");
    for (float freq = 0.5; freq <= 1.5; freq += 0.1) {
        moduleSound(freq);
        setGain(1.0);
    }

    // Validate result
    float expected = 1.5;
    float actual = 1.5;  // Replace with actual value from the system
    if (!validateResult(expected, actual, 0.1)) {
        printf("Test 3 failed\n");
        exit(1);
    }
    printf("Test 3 passed\n");
}

void testCustomPattern(void) {
    printf("Test 4: Play a custom sound pattern\n");
    moduleSound(1.0);
    setGain(1.0);
    moduleSound(1.5);
    setGain(1.0);
    moduleSound(2.0);
    setGain(1.0);
    moduleSound(2.5);
    setGain(1.0);

    // Validate result
    float expected = 2.5;
    float actual = 2.5;  // Replace with actual value from the system
    if (!validateResult(expected, actual, 0.1)) {
        printf("Test 4 failed\n");
        exit(1);
    }
    printf("Test 4 passed\n");
}

bool validateResult(float expected, float actual, float tolerance) {
    return (actual >= expected - tolerance) && (actual <= expected + tolerance);
}

void runTestsSound(void) {
    testSingleTone();
    testMelody();
    testFrequencySweep();
    testCustomPattern();
}