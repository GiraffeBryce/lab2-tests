#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int
main()
{
    void *currbreak;
    char *new;

    currbreak = sbrk(0);

    fprintf(stderr, "sbrk(0) = %p\n", currbreak);

    // BRK is above curr brk --> expand valid pages for heap.

    currbreak = (void *)UP_TO_PAGE(currbreak);
    currbreak++;
    currbreak = (void *)UP_TO_PAGE(currbreak);

    if (Brk(currbreak)) {
	fprintf(stderr, "Brk %p returned error\n", currbreak);
	Exit(1);
    }

    // Brk is below curr brk --> deallocate heap pages.
    currbreak = (void *)UP_TO_PAGE(currbreak);
    currbreak--;
    currbreak = (void *)DOWN_TO_PAGE(currbreak);

    if (Brk(currbreak)) {
	fprintf(stderr, "Brk %p returned error\n", currbreak);
	Exit(1);
    }

    fprintf(stderr, "MALLOC\n");
    new = malloc(1024*50);
    fprintf(stderr, "DONE\n");

    Exit(0);
}
