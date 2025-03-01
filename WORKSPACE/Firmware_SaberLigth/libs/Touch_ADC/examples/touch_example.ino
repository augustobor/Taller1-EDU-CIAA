#include <CapacitiveSensor.h>

// Define the pins for the capacitive sensors
CapacitiveSensor cs0 = CapacitiveSensor(4, 2);
CapacitiveSensor cs1 = CapacitiveSensor(4, 6);
CapacitiveSensor cs2 = CapacitiveSensor(4, 8);
CapacitiveSensor cs3 = CapacitiveSensor(4, 10);

// Function prototypes
void testReadTouchValue(void);
void testApplyTouchEffects(void);
void run_tests(void);

void setup() {
    Serial.begin(9600);
    // Set the timeout for the capacitive sensors
    cs0.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs2.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs3.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
    // Run tests
    run_tests();
    while (true);  // Stop the loop after running tests
}

void testReadTouchValue(void) {
    // Test 1: Read touch value from sensor 0
    Serial.println("Waiting for touch...");
    long touchValue = 0;
    while (touchValue < 1000) {  // Adjust threshold as needed
        touchValue = cs0.capacitiveSensor(30);
        delay(100);  // Wait for 100ms
    }
    Serial.println("Touch value read");
    delay(1000);  // Wait for 1 second
}

void testApplyTouchEffects(void) {
    // Test 3: Apply touch effects (simulated)
    Serial.println("Touch effects applied");
    delay(1000);  // Wait for 1 second
}

void run_tests(void) {
    testReadTouchValue();
    delay(1000);  // Wait for 1 second between tests
    testApplyTouchEffects();
}
