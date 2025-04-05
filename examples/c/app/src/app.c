#include "NeopixelExample.h"
#include "sapi.h"
#include "sapi_stdio.h"
#include "Board.h"
#include <stdio.h>

int main(void) {
    // Run Neopixel tests
    boardInit();

    // Keep the program running
    while (1) {
       printf("Running Neopixel tests...\n");
       runTests();
       delay(3000);
    }

    return 0;
}

