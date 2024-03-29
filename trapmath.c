#include <comp421/yalnix.h>
#include <comp421/hardware.h>

int
main()
{
    int x = 0;
    int y;

    /*
     *  Dividing by zero here should result in a TRAP_MATH trap.
     */
    y = 5/x;
    TracePrintf(2, "value of y: %i", y); // Shouldn't execute.

    Exit(1);
}
