#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

void
foo(int depth)
{
    fprintf(stderr, "foo %d\n", depth);
    char array[PAGESIZE * 10];
    // char * array2 = malloc(PAGESIZE);
    fprintf(stderr,"array %lx\n", (uintptr_t)array);
    // if(!array2) {
    // fprintf(stderr,"no heap mem\n");
    //     exit(1);
    // }
    TracePrintf(5, "before i\n");
    unsigned int i = 0;
    TracePrintf(5, "after i\n");

    TracePrintf(0, "blowstack foo: depth %d\n", depth);

    fprintf(stderr,"%d\n",depth);
    fflush(stderr);

    TracePrintf(5, "before force\n");
    for (i = 0; i < sizeof(array); i++) {
        // if(!(i % 1000))
        // TracePrintf(0, "blowstack foo: depth %d i: %d\n", depth, i);
        array[i] = 'a';
        
        // array2[i] = 'a';
    }
    TracePrintf(5, "after force\n");

TracePrintf(5, "before check\n");
    if (depth == 1) return;
TracePrintf(5, "after check\n");
TracePrintf(5, "before call foo %p\n", foo);
    foo(depth-1);
}

int
main(int argc, char **argv)
{
    (void)argc;
    int num = atoi(argv[1]);

    TracePrintf(0, "blowstack initially calling foo depth %d", num);
    foo(num);

    Exit(0);
}
