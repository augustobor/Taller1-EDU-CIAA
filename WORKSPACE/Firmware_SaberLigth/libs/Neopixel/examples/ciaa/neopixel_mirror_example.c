#include "Neopixel.h"
#include "sapi.h" // Include for delay function

#define NUM_PIXELS 111

/*
Used functions:
- Neopixel_Init()
- setCurrentColor()
- setColor()
- mirror()
- mirror_all()
- pixel_off()
*/

void testSetCurrentColorToBlue() {
    struct color blue = {0, 0, 255};
    setCurrentColor(blue); // Assign the color blue to the current color
    printf("Test 1: Set the current color to blue\n");
    printf("Expected: Current color is blue (R: 0, G: 0, B: 255)\n");
    if (getCurrentColor().r != 0 || getCurrentColor().g != 0 || getCurrentColor().b != 255) {
        printf("Test 1 failed\n");
        exit(1);
    }
}

void testSetFirstHalfPixelsToBlue() {
    struct color blue = {0, 0, 255};
    for (uint8_t i = 0; i < NUM_PIXELS / 2; i++) {
        setColor(i, blue);
    }
    printf("Test 2: Set the first half of the pixels to blue\n");
    printf("Expected: First half of the pixels are blue (R: 0, G: 0, B: 255)\n");
    for (uint8_t i = 0; i < NUM_PIXELS / 2; i++) {
        struct color c = getColor(i);
        if (c.r != 0 || c.g != 0 || c.b != 255) {
            printf("Test 2 failed at pixel %d\n", i);
            exit(1);
        }
    }
}

void testMirrorFirstHalfToSecondHalf() {
    mirror_all();
    printf("Test 3: Mirror the first half to the second half\n");
    printf("Expected: Second half of the pixels are mirrored from the first half\n");
    for (uint8_t i = NUM_PIXELS / 2; i < NUM_PIXELS; i++) {
        struct color c = getColor(i);
        if (c.r != 0 || c.g != 0 || c.b != 255) {
            printf("Test 3 failed at pixel %d\n", i);
            exit(1);
        }
    }
}

void testTurnOffAllPixels() {
    for (uint8_t i = 0; i < NUM_PIXELS; i++) {
        pixel_off(i);
    }
    printf("Test 4: Turn off all pixels\n");
    printf("Expected: All pixels are turned off\n");
    for (uint8_t i = 0; i < NUM_PIXELS; i++) {
        struct color c = getColor(i);
        if (c.r != 0 || c.g != 0 || c.b != 0) {
            printf("Test 4 failed at pixel %d\n", i);
            exit(1);
        }
    }
}

void testSetCurrentColorToGreen() {
    struct color green = {255, 0, 0};
    setCurrentColor(green);
    printf("Test 5: Set the current color to green\n");
    printf("Expected: Current color is green (R: 255, G: 0, B: 0)\n");
    if (getCurrentColor().r != 255 || getCurrentColor().g != 0 || getCurrentColor().b != 0) {
        printf("Test 5 failed\n");
        exit(1);
    }
}

void testSetFirstPixelToGreen() {
    struct color green = {255, 0, 0};
    setColor(0, green);
    printf("Test 6: Set the first pixel to green\n");
    printf("Expected: First pixel is green (R: 255, G: 0, B: 0)\n");
    struct color firstPixelColor = getColor(0);
    if (firstPixelColor.r != 255 || firstPixelColor.g != 0 || firstPixelColor.b != 0) {
        printf("Test 6 failed\n");
        exit(1);
    }
}

void testMirrorFirstPixelToLastPixel() {
    mirror(0);
    printf("Test 7: Mirror the first pixel to the last pixel\n");
    printf("Expected: Last pixel is mirrored from the first pixel\n");
    struct color lastPixelColor = getColor(NUM_PIXELS - 1);
    if (lastPixelColor.r != 255 || lastPixelColor.g != 0 || lastPixelColor.b != 0) {
        printf("Test 7 failed\n");
        exit(1);
    }
}

void runTests() {
    testSetCurrentColorToBlue();
    testSetFirstHalfPixelsToBlue();
    testMirrorFirstHalfToSecondHalf();
    delay(3000);
    testTurnOffAllPixels();
    delay(3000);
    testSetCurrentColorToGreen();
    testSetFirstPixelToGreen();
    testMirrorFirstPixelToLastPixel();
}

int main(void) {
    // Initialize the Neopixel
    Neopixel_Init();

    // Run tests
    runTests();

    // Keep the program running
    while (1) {
        // ...existing code...
    }

    return 0;
}
