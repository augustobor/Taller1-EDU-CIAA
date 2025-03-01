#include "Touch_ADC.h"
#include <stdio.h>
#include <unistd.h>

// Function prototypes
void testReadTouchValue(void);
// void testCheckTouchDetected(void);
void testApplyTouchEffects(void);
void run_tests(void);

/*
Used functions:
- TouchADC_Init
- TouchADC_read
- TouchADC_efects
- IS_TOUCH
*/

void testReadTouchValue(void) {
    // Test 1: Read touch value
    printf("Waiting for touch...\n");
    while (IS_TOUCH() == 0) {
        TouchADC_read();
        usleep(100000);  // Wait for 100ms
    }
    printf("Touch value read\n");
    sleep(1);  // Wait for 1 second
}

void testApplyTouchEffects(void) {
    // Test 2: Apply touch effects
    TouchADC_efects(5);
    printf("Touch effects applied\n");
    sleep(1);  // Wait for 1 second
}

void run_tests(void) {
    testReadTouchValue();
    sleep(1);  // Wait for 1 second between tests
    testApplyTouchEffects();
}

int main(void) {
    // Initialize the touch ADC module
    TouchADC_Init();

    // Run tests
    run_tests();

    return 0;
}
