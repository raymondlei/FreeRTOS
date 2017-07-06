
#include "PIC24F_CPU.h"

void System_initialize(void)
{
    ConfigureOscillator();
    SOSC_Configuration();
}

int __attribute__((__section__(".libc.write"))) write(int handle, void *buffer, unsigned int len)
{
    int i;
    
    switch (handle)
    {
        case 0:		// stdin
        case 1:		// stdout
        case 2:		// stderr
            
            for (i = len; i; --i)
            {
                //vPutCharU1( *(BYTE*)buffer++ );
            }
            break;
        default:
            break;
    }
    
    return(len);
}
