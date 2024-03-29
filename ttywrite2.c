#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

#define	TTY_WRITE_STR(term, str) TtyWrite(term, str, strlen(str))

int
main()
{
    int i, t;
    
    for (i = 0; i < 10; i++)
    for (t = 0; t < 4; t++) {
	TTY_WRITE_STR(t, "Hello world\n");
    }

    Exit(0);
}
