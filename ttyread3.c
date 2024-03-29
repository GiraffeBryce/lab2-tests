#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

char line[5];
char line2[5];

int
main()
{
    int len;
    int len2;
    Delay(10); // Delay so you can type something in.

    fprintf(stderr, "Doing TtyRead...\n");
    len = TtyRead(0, line, sizeof(line));
    len2 = TtyRead(0, line2, sizeof(line2));
    fprintf(stderr, "Done with TtyRead: len %d\n", len);
    fprintf(stderr, "line '");
    fwrite(line, len, 1, stderr);
    fprintf(stderr, "'\n");

    fprintf(stderr, "Done with TtyRead: len2 %d\n", len2);
    fprintf(stderr, "line2 '");
    fwrite(line2, len2, 1, stderr);
    fprintf(stderr, "'\n");

    Exit(0);
}
