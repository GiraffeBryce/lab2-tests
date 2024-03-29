#include <comp421/hardware.h>
#include <comp421/yalnix.h>
#include <stdio.h>

#include "../trace.h"

int main(int argc, char **argv) {
        (void) argc;
        (void) argv;
        TracePrintf(4, "Switch test Start\n");
        Delay(5);

        int i = 0;
        while (i < 10) {
                i++;
                TracePrintf(kTrace, "ADDING i\n");
        }

        Delay(3);
        i = 0;
        while (i < 10) {
                i++;
                TracePrintf(kTrace, "ADDING j\n");
        }

        Delay(7);
        i = 0;
        while (i < 10) {
                i++;
                TracePrintf(kTrace, "ADDING j\n");
        }
        Delay(2);
        i = 0;
        while (i < 10) {
                i++;
                TracePrintf(kTrace, "ADDING j\n");
        }
        Delay(1);
        i = 0;
        while (i < 10) {
                i++;
                TracePrintf(kTrace, "ADDING j\n");
        }
        Exit(0);
}