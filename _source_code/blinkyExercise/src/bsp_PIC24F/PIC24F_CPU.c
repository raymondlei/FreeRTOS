
// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************

#include <xc.h>

/* Setting up configuration bits */
#if defined(__PIC24HJ64GP502__) || defined(__dsPIC33FJ64MC802__) || defined(__PIC24HJ128GP502__) || defined(__dsPIC33FJ128MC802__)

#pragma config FNOSC = FRC              // Use internal oscillator  (FOSC ~ 8 Mhz)
#pragma config FCKSM = CSECMD
#pragma config OSCIOFNC = ON
#pragma config POSCMD = NONE            // RA3 pin is output
#pragma config FWDTEN = OFF             // Watchdog timer is disabled
#pragma config JTAGEN = OFF             // JTAG Port is disabled

#elif defined(__PIC24FJ256GB110__)
// CONFIG3
#pragma config WPFP = WPFP511           // Write Protection Flash Page Segment Boundary (Highest Page (same as page 170))
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable bit (Segmented code protection disabled)
#pragma config WPCFG = WPCFGDIS         // Configuration Word Code Page Protection Select bit (Last page(at the top of program memory) and Flash configuration words are not protected)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select bit (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMOD = HS             // Primary Oscillator Select (HS oscillator mode selected)
#pragma config DISUVREG = OFF           // Internal USB 3.3V Regulator Disable bit (Regulator is disabled)
#pragma config IOL1WAY = ON             // IOLOCK One-Way Set Enable bit (Write RP Registers Once)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSCO functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-safe Clock Monitor are disabled)
#pragma config FNOSC = PRIPLL           // Oscillator Select (Primary oscillator (XT, HS, EC) with PLL module (XTPLL,HSPLL, ECPLL))
#pragma config PLL_96MHZ = ON           // 96MHz PLL Disable (Enabled)
#pragma config PLLDIV = DIV2            // USB 96 MHz PLL Prescaler Select bits (Oscillator input divided by 2 (8MHz input))
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-speed start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config ICS = PGx2               // Comm Channel Select (Emulator functions are shared with PGEC2/PGED2)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG port is disabled)  
#else
  #error "The config bits aren't configured! Please, configure it!"
#endif

void ConfigureOscillator(void)
{
#if 0
    // CF no clock failure; NOSC FRC; SOSCEN disabled; POSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active; 
    __builtin_write_OSCCONL((uint8_t) (0x0000 & 0x00FF));
    // CPDIV 1:1; PLLEN enabled; RCDIV FRC/2; DOZE 1:8; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3120;
    // TUN Center frequency; 
    OSCTUN = 0x0000;

    // WDTO disabled; TRAPR disabled; SLEEP disabled; BOR disabled; DPSLP disabled; CM disabled; SWR disabled; SWDTEN disabled; EXTR disabled; POR disabled; IDLE disabled; IOPUWR disabled; VREGS disabled; 
    RCON = 0x0000;
#endif
}

void SOSC_Configuration(void)
{
    char a, b, c, *p;

    a = 2;
    b = 0x46;
    c = 0x57;
    p = (char *) &OSCCON;

    asm volatile ("mov.b %1,[%0] \n"
            "mov.b %2,[%0] \n"
            "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
            "r"(a));
}

//Unlock for I/O remapping
void CPU_RP_Unlock(void)
{
    /*
        Unlock sequence for input/output mapping.
    */
    asm volatile (  "MOV    #OSCCON, w1 \n"
                    "MOV    #0x46, w2   \n"
                    "MOV    #0x57, w3   \n"
                    "MOV.b  w2, [w1]    \n"
                    "MOV.b  w3, [w1]    \n"
                    "BCLR   OSCCON, #6  ");
}

//Lock I/O remapping
void CPU_RP_Lock(void)
{
   /*
        Lock sequence for input/output mapping.
    */
    asm volatile (  "MOV    #OSCCON, w1 \n"
                    "MOV    #0x46, w2   \n"
                    "MOV    #0x57, w3   \n"
                    "MOV.b  w2, [w1]    \n"
                    "MOV.b  w3, [w1]    \n"
                    "BSET   OSCCON, #6  ");
}
