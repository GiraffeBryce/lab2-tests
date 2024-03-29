#include <comp421/yalnix.h>

void
force(char *addr)
{
    *addr = 42;
}

int
main()
{
    char big_buffer[20*1024];
    int foo;
    unsigned int i;

    foo = 42;
    (void)foo;
    (void)i;
    for (i = 0; i < sizeof(big_buffer); i++) 
	force(big_buffer + i);

    Exit(0);
}
