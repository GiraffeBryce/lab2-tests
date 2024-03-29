#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

char line[5];
char line2[5];
char line3[5];
char line4[5];
char line5[5];

int
main()
{
    int len;
    int len2;
    int len3;
    int len4;
    int len5;
    Delay(10); // Delay so you can type something in.

    fprintf(stderr, "Doing TtyRead...\n");
    len = TtyRead(0, line, sizeof(line));
    len2 = TtyRead(1, line2, sizeof(line2));
    len3 = TtyRead(2, line3, sizeof(line3));
    len4 = TtyRead(3, line4, sizeof(line4));
    len5 = TtyRead(3, line5, sizeof(line5));
    fprintf(stderr, "Done with TtyRead: len %d\n", len);
    fprintf(stderr, "line '");
    fwrite(line, len, 1, stderr);
    fprintf(stderr, "'\n");

    fprintf(stderr, "Done with TtyRead: len2 %d\n", len2);
    fprintf(stderr, "line2 '");
    fwrite(line2, len2, 1, stderr);
    fprintf(stderr, "'\n");

    fprintf(stderr, "Done with TtyRead: len3 %d\n", len3);
    fprintf(stderr, "line3 '");
    fwrite(line3, len3, 1, stderr);
    fprintf(stderr, "'\n");

    fprintf(stderr, "Done with TtyRead: len4 %d\n", len4);
    fprintf(stderr, "line4 '");
    fwrite(line4, len4, 1, stderr);
    fprintf(stderr, "'\n");

    fprintf(stderr, "Done with TtyRead: len5 %d\n", len5);
    fprintf(stderr, "line5 '");
    fwrite(line5, len5, 1, stderr);
    fprintf(stderr, "'\n");

    Exit(0);
}
