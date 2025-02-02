#include <stdio.h>
#include <comp421/yalnix.h>

/* exectest progname args... */
/* for fun: exectest exectest exectest exectest exectest progname args... */
int
main(int argc, char **argv)
{
    int i;
    int f;

    for (i = 0; i < argc; i++) {
	fprintf(stderr, "argv[%d] = %p", i, argv[i]);
	fprintf(stderr, " = '%s'\n", argv[i]);
    }

    f = Fork();
    if (f == 0) {
        Exec(argv[1], argv + 1);
        fprintf(stderr, "Exec did not work!!\n");

        Exit(1);
    }
}
