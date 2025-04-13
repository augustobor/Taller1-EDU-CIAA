#include "TouchExample.h"
#include "sapi.h"
#include "sapi_stdio.h"
#include "board.h"
#include <stdio.h>


int main(void) {
    // Run Neopixel tests
    boardInit();

    // Keep the program running
    while (1) {
       printf("Running Encoder tests...\n");
       runTestsADC();
       delay(3000);
    }

    return 0;
}

