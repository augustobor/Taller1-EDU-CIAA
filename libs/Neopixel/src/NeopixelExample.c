#include "Neopixel.h"
#include "NeopixelExample.h"
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
    printf("Expected: Current color is red (G: 0, R: 255, B: 0)\n");
    getCurrentColor(); // Get the current color
    if (getCurrentColor().r != 255 || getCurrentColor().g != 0 || getCurrentColor().b != 0) {
        printf("Current color - R: %d, G: %d, B: %d\n", getCurrentColor().r, getCurrentColor().g, getCurrentColor().b);
        printf("Test 1 failed\n");
        return;
    } else {
        printf("Test 1 passed\n");
        return;
    }
}


void testSetAllPixelsToRed() {
    struct color red = {0, 255, 0};
    for (uint8_t i = 0; i < NUM_PIXELS; i++) { // Set all pixels to red
        setColor(i, red);
    }
    printf("Test 2: Set all pixels to red\n");
    printf("Expected: All pixels are red (G: 0, R: 255, B: 0)\n");
    for (uint8_t i = 0; i < NUM_PIXELS; i++) {
        struct color c = getColor(i);
        if (c.g != 0 || c.r != 255 || c.b != 0) {
            printf("Test 2 failed at pixel %d\n", i);
            return;
        }
    }
    printf("Test 2 passed\n");
}

void testGetColorOfFirstPixel() {
    struct color red = {0, 255, 0};
    setColor(0, red);
    struct color firstPixelColor = getColor(0);
    printf("Test 3: Get the color of the first pixel - R: %d, G: %d, B: %d\n", firstPixelColor.r, firstPixelColor.g, firstPixelColor.b);
    if (firstPixelColor.g != 0 || firstPixelColor.r != 255 || firstPixelColor.b != 0) {
        printf("Expected: First pixel color should be red (G: 0, R: 255, B: 0)\n");
        printf("Test 3 failed\n");
        return;
    } else {
        printf("Test 3 passed\n");
        return;
    }
}

void testSetFirstPixelToFadedColor() {
    struct color red = {0, 254, 0};
    struct color green = {254, 0, 0};
    setColor_fade(0, red, green, 0.5);
    struct color fadedColor = getColor(0);
    printf("Test 4: Set the first pixel to a faded color between red and green\n");
    printf("Expected: First pixel color is a mix of red and green\n");
    if (fadedColor.r != 127 || fadedColor.g != 127 || fadedColor.b != 0) {
        printf("Faded color - R: %d, G: %d, B: %d\n", fadedColor.r, fadedColor.g, fadedColor.b);
        printf("Test 4 failed\n");
        return;
    } else {
        printf("Test 4 passed\n");
        return;
    }
}

void testSetSecondPixelToScaledColor() {
    struct color red = {0, 200, 0};
    setCurrentColor(red); // Set current color to green
    setColor_i(1, 0.5); // 50% intensity
    struct color scaledColor = getColor(1);
    printf("Test 5: Set the second pixel to a scaled color of the current color\n");
    if (scaledColor.g != 0 || scaledColor.r != 100 || scaledColor.b != 0) {
        printf("Expected: Second pixel color is a scaled version of the current color: R: 100, G: 0, B: 0\n");
        printf("Scaled color - R: %d, G: %d, B: %d\n", scaledColor.r, scaledColor.g, scaledColor.b);
        printf("Test 5 failed\n");
        return;
    } else {
        printf("Test 5 passed\n");
        return;
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
            return;
        }
    }
    printf("Test 6 passed\n");
    return;
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
