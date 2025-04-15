#include "SoundExample.h"
#include "sapi_board.h"


int main(void) {
    // Run Neopixel tests
    boardInit();

    // Keep the program running
    while (1) {
       printf("Running Encoder tests...\n");
       runTestsSoundWave();
    }

    return 0;
}

