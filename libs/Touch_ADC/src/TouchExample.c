#include "Touch_ADC.h"
#include "TouchExample.h"
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


/**
 * @brief Tests the reading of touch values
 *
 * This function waits for a touch event and then reads the touch value using
 * TouchADC_read().
 */
void testReadTouchValue(void) {
    // Test 1: Read touch value
    printf("Waiting for touch...\n");
    while (IS_TOUCH() == 0) {
        TouchADC_read();
    }
    printf("Touch value read\n");

}

void testApplyTouchEffects(void) {
    // Test 2: Apply touch effects
    TouchADC_efects(5);
    printf("Touch effects applied\n");

}

void runTestsADC(void) {
    testReadTouchValue();
    testApplyTouchEffects();
}
