#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <comp421/yalnix.h>
#include <comp421/hardware.h>

char line[TERMINAL_MAX_LINE];

void
recurse(char *who, int i)
{
    printf("%s %d\n", who, i);
    if (i == 0)
    {
	printf("Done with recursion\n");
	return;
    }
    else
	recurse(who, i - 1);
}

int
main(int argc, char **argv)
{
    int pid;
    int i;
    int ret0;
    int ret1;
    int ret2;
    int ret3;

    setbuf(stdout, NULL);

    printf("FORK2> This program is a test mainly of Fork\n");
    printf("FORK2> BEFORE Fork(): If nothing else is printed, Fork fails \n");
    printf("FORK2> You should see lines from parent and child below:\n");

    
    if ((pid = Fork()) == 0)
    {
        printf("CHILD\n");
        for (i = 0; i < 10; i++) {
            sprintf(line, "Child line %d\n", i);
            ret0 = TtyWrite(0, line, strlen(line));
            fprintf(stdout, "ret0 of TtyWrite: %i\n", ret0);
            ret1 = TtyWrite(1, line, strlen(line));
            fprintf(stdout, "ret1 of TtyWrite: %i\n", ret1);
            ret2 = TtyWrite(2, line, strlen(line));
            fprintf(stdout, "ret2 of TtyWrite: %i\n", ret2);
            ret3 = TtyWrite(3, line, strlen(line));
            fprintf(stdout, "ret3 of TtyWrite: %i\n", ret3);
            fprintf(stdout, "Did Child print for %i.\n", i);
        }
        recurse("child", 10);
    }
    else
    {
        printf("PARENT: child pid = %d\n", pid);
        for (i = 0; i < 10; i++) {
            sprintf(line, "Parent line %d\n", i);
            ret0 = TtyWrite(0, line, strlen(line));
            fprintf(stdout, "ret0 of TtyWrite: %i\n", ret0);
            ret1 = TtyWrite(1, line, strlen(line));
            fprintf(stdout, "ret1 of TtyWrite: %i\n", ret1);
            ret2 = TtyWrite(2, line, strlen(line));
            fprintf(stdout, "ret2 of TtyWrite: %i\n", ret2);
            ret3 = TtyWrite(3, line, strlen(line));
            fprintf(stdout, "ret3 of TtyWrite: %i\n", ret3);
            fprintf(stdout, "Did Parent print for %i.\n", i);
        }
        recurse("parent", 10);
    }

    printf("FORK2 done.\n");
    Exit(0);
}
