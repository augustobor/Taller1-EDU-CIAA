#include "Encoder.h"
#include <stdio.h>
#include <unistd.h>

// Function prototypes
void testEncoderInit(void);
void testEncoderEffectsStepStarting(void);
void testEncoderEffectsStepStopping(void);
void testEncoderMEFKey(void);
void run_tests(void);

/*
Used functions:
- Encoder_Init
- Encoder_Efects_Step
- Encoder_MEF_Key
- getButtonState
- setButtonState
*/

void testEncoderInit(void) {
    // Test 1: Initialize the encoder
    Encoder_Init();
    printf("Encoder initialized\n");
    sleep(1);  // Wait for 1 second
}

void testEncoderEffectsStepStarting(void) {
    // Test 2: Apply encoder effects step with Button_state STARTING
    Button_init();
    setButtonState(STARTING);
    Encoder_Efects_Step();
    printf("Encoder effects step applied with STARTING\n");
    sleep(1);  // Wait for 1 second
}

void testEncoderEffectsStepStopping(void) {
    // Test 3: Apply encoder effects step with Button_state STOPPING
    Button_init(); 
    setButtonState(STOPPING);
    Encoder_Efects_Step();
    printf("Encoder effects step applied with STOPPING\n");
    sleep(1);  // Wait for 1 second
}

void testEncoderMEFKey(void) {
    // Test 4: Run encoder MEF key
    Encoder_MEF_Key();
    printf("Encoder MEF key processed\n");
    sleep(1);  // Wait for 1 second
}

void run_tests(void) {
    testEncoderInit();
    sleep(1);  // Wait for 1 second between tests
    testEncoderEffectsStepStarting();
    sleep(1);  // Wait for 1 second between tests
    testEncoderEffectsStepStopping();
    sleep(1);  // Wait for 1 second between tests
    testEncoderMEFKey();
}

int main(void) {
    // Run tests
    run_tests();

    return 0;
}
