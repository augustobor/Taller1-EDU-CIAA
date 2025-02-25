#include "Neopixel.h"
#include "sapi.h" // Ensure the correct path to sapi.h

#define NUM_PIXELS 111

/*
Used functions:
- Neopixel_Init()
- setCurrentColor()
- setColor()
- getColor()
- setColor_fade()
- setColor_i()
- pixel_off()
*/

/*
Tests:
1. Set the current color to red: In this test case, the current color is set to red using setCurrentColor().
2. Set all pixels to red: In this test case, all pixels are set to red using for and setColor().
3. Get the color of the first pixel: In this test case, the color of the first pixel is retrieved.
4. Set the first pixel to a faded color between red and green: In this test case, the first pixel is set to a faded color between red and green.
5. Set the second pixel to a scaled color of the current color: In this test case, the second pixel is set to a scaled color of the current color.
6. Turn off all pixels: In this test case, all pixels are turned off.
*/

void testSetCurrentColorToRed() {
    struct color red = {0, 255, 0};
    setCurrentColor(red); // Assign the color red to the current color
    printf("Test 1: Set the current color to red\n");
    printf("Expected: Current color is red (R: 0, G: 255, B: 0)\n");
    if (getCurrentColor().r != 0 || getCurrentColor().g != 255 || getCurrentColor().b != 0) {
        printf("Test 1 failed\n");
        exit(1);
    }
}

void testSetAllPixelsToRed() {
    struct color red = {0, 255, 0};
    for (uint8_t i = 0; i < NUM_PIXELS; i++) { // Set all pixels to red
        setColor(i, red);
    }
    printf("Test 2: Set all pixels to red\n");
    printf("Expected: All pixels are red (R: 0, G: 255, B: 0)\n");
    for (uint8_t i = 0; i < NUM_PIXELS; i++) {
        struct color c = getColor(i);
        if (c.r != 0 || c.g != 255 || c.b != 0) {
            printf("Test 2 failed at pixel %d\n", i);
            exit(1);
        }
    }
}

void testGetColorOfFirstPixel() {
    struct color firstPixelColor = getColor(0);
    printf("Test 3: Get the color of the first pixel - R: %d, G: %d, B: %d\n", firstPixelColor.r, firstPixelColor.g, firstPixelColor.b);
    printf("Expected: First pixel color is red (R: 0, G: 255, B: 0)\n");
    if (firstPixelColor.r != 0 || firstPixelColor.g != 255 || firstPixelColor.b != 0) {
        printf("Test 3 failed\n");
        exit(1);
    }
}

void testSetFirstPixelToFadedColor() {
    struct color red = {0, 255, 0};
    struct color green = {255, 0, 0};
    setColor_fade(0, red, green, 0.5);
    struct color fadedColor = getColor(0);
    printf("Test 4: Set the first pixel to a faded color between red and green\n");
    printf("Expected: First pixel color is a mix of red and green\n");
    if (fadedColor.r != 127 || fadedColor.g != 127 || fadedColor.b != 0) {
        printf("Test 4 failed\n");
        exit(1);
    }
}

void testSetSecondPixelToScaledColor() {
    setColor_i(1, 128);
    struct color scaledColor = getColor(1);
    printf("Test 5: Set the second pixel to a scaled color of the current color\n");
    printf("Expected: Second pixel color is a scaled version of the current color\n");
    if (scaledColor.r != 0 || scaledColor.g != 128 || scaledColor.b != 0) {
        printf("Test 5 failed\n");
        exit(1);
    }
}

void testTurnOffAllPixels() {
    for (uint8_t i = 0; i < NUM_PIXELS; i++) {
        pixel_off(i);
    }
    printf("Test 6: Turn off all pixels\n");
    printf("Expected: All pixels are turned off\n");
    for (uint8_t i = 0; i < NUM_PIXELS; i++) {
        struct color c = getColor(i);
        if (c.r != 0 || c.g != 0 || c.b != 0) {
            printf("Test 6 failed at pixel %d\n", i);
            exit(1);
        }
    }
}

void runTests() {
    testSetCurrentColorToRed();
    testSetAllPixelsToRed();
    delay(3000);
    testGetColorOfFirstPixel();
    testSetFirstPixelToFadedColor();
    testSetSecondPixelToScaledColor();
    delay(3000);
    testTurnOffAllPixels();
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
