#include "Encoder.h"
#include "Board.h"
#include "sapi.h"
#include <stdio.h>
#include <unistd.h>

// Function prototypes
void testEncoderInit(void);
void testEncoderEffectsStepStarting(void);
void testEncoderEffectsStepStopping(void);
void testEncoderMEFKey(void);
void runTestsEncoder(void);
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
    if (getButtonState() == APAGADO) {
        printf("Encoder initialized successfully\n");
        printf("Test 1 passed: Encoder initialized\n");
    } else {
        printf("Encoder initialization failed\n");
    }
    delay(1000); 
}

void testEncoderEffectsStepStarting(void) {
    // Test 2: Apply encoder effects step with Button_state STARTING
    Button_init();
    setButtonState(STARTING);
    if (getButtonState() == STARTING) {
        printf("Button state is STARTING\n");
        printf("Test 2 passed: Button state is STARTING\n");
    } else {
        printf("Button state is not STARTING\n");
    }
    Encoder_Efects_Step();
    delay(1000);  // Wait for 1 second
}

void testEncoderEffectsStepStopping(void) {
    // Test 3: Apply encoder effects step with Button_state STOPPING
    Button_init(); 
    setButtonState(STOPPING);
    if (getButtonState() == STOPPING) {
        printf("Test 3 passed: Button state is STOPPING\n");
    } else {
        printf("Test 3 failed: Button state is not STOPPING\n");
    }
    Encoder_Efects_Step();
    delay(1000);  // Wait for 1 second
}

void testEncoderMEFKey(void) {
    // Test 4: Run encoder MEF key
    Encoder_MEF_Key();
    printf("Encoder MEF key processed\n");
    delay(1000);  // Wait for 1 second
}

void runTestsEncoder(void) {
    testEncoderInit();
    delay(1000);  // Wait for 1 second between tests
    testEncoderEffectsStepStarting();
    delay(1000);  // Wait for 1 second between tests
    testEncoderEffectsStepStopping();
    delay(1000);  // Wait for 1 second between tests
    testEncoderMEFKey();
}

