#include <Encoder.h>
#include <Bounce2.h>

// Define the pins for the encoder
const int encoderPinA = 2;
const int encoderPinB = 3;
const int buttonPin = 4;

// Create encoder and button objects
Encoder myEnc(encoderPinA, encoderPinB);
Bounce2::Button button = Bounce2::Button();

// Timeout duration in milliseconds
const unsigned long TIMEOUT_DURATION = 5000;

// Function prototypes
void testEncoderEffectsStep(void);
void testEncoderMEFKey(void);
void run_tests(void);

void setup() {
    Serial.begin(9600);
    // Initialize the encoder
    pinMode(buttonPin, INPUT_PULLUP);
    button.attach(buttonPin);
    button.interval(5); // Debounce interval
}

void loop() {
    // Run tests
    run_tests();
    while (true);  // Stop the loop after running tests
}

void testEncoderEffectsStep(void) {
    // Test 1: Apply encoder effects step
    unsigned long startTime = millis();
    long newPosition = myEnc.read();
    while (millis() - startTime < TIMEOUT_DURATION) {
        long currentPosition = myEnc.read();
        if (currentPosition != newPosition) {
            Serial.print("Encoder position: ");
            Serial.println(currentPosition);
            delay(1000);  // Wait for 1 second
            return;
        }
    }
    Serial.println("Test failed: No signal received for encoder effects step");
}

void testEncoderMEFKey(void) {
    // Test 2: Run encoder MEF key
    unsigned long startTime = millis();
    while (millis() - startTime < TIMEOUT_DURATION) {
        button.update();
        if (button.pressed()) {
            Serial.println("Button pressed");
            delay(1000);  // Wait for 1 second
            return;
        }
    }
    Serial.println("Test failed: No signal received for encoder MEF key");
}

void run_tests(void) {
    testEncoderEffectsStep();
    delay(1000);  // Wait for 1 second between tests
    testEncoderMEFKey();
}
