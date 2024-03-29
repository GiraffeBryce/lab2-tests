#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <comp421/yalnix.h>
#include <comp421/hardware.h>

char line[NUM_TERMINALS][TERMINAL_MAX_LINE];

int
main()
{

    Fork();
    Fork();

    int pid = GetPid() - 1;
    

    while(1) {
        char * p = "> ";
        TtyWrite(pid, p, strlen(p));
        int len = TtyRead(pid, line[pid], sizeof(line[pid]));
        TtyWrite(pid, line[pid], len);

        if(strncmp("exit", line[pid], len) == 0) {
            Exit(0);
        }
    }
}
