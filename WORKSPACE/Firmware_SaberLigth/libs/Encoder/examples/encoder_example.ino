#include <Encoder.h>

// Define the pins for the encoder
const int encoderPinA = 2;
const int encoderPinB = 3;
const int buttonPin = 4;

// Function prototypes
void testEncoderInit(void);
void testEncoderEffectsStep(void);
void testEncoderMEFKey(void);
void run_tests(void);

void setup() {
    Serial.begin(9600);
    // Initialize the encoder
    pinMode(encoderPinA, INPUT);
    pinMode(encoderPinB, INPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // Run tests
    run_tests();
    while (true);  // Stop the loop after running tests
}

void testEncoderInit(void) {
    // Test 1: Initialize the encoder
    Serial.println("Encoder initialized");
    delay(1000);  // Wait for 1 second
}

void testEncoderEffectsStep(void) {
    // Test 2: Apply encoder effects step
    Serial.println("Encoder effects step applied");
    delay(1000);  // Wait for 1 second
}

void testEncoderMEFKey(void) {
    // Test 3: Run encoder MEF key
    Serial.println("Encoder MEF key processed");
    delay(1000);  // Wait for 1 second
}

void run_tests(void) {
    testEncoderInit();
    delay(1000);  // Wait for 1 second between tests
    testEncoderEffectsStep();
    delay(1000);  // Wait for 1 second between tests
    testEncoderMEFKey();
}
