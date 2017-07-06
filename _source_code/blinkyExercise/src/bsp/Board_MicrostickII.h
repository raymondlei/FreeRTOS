#ifndef BOARD_MICROSTICKII_H
#define	BOARD_MICROSTICKII_H

#ifdef	__cplusplus

#else

/*** Microcontroller MIPs (FCY) *********************8**************/
#define FOSC        8000000L    /* On-board Crystal frequency */
#define FCY         (FOSC / 2)  /* Instruction Cycle Frequency */


#define PIN_INPUT    1
#define PIN_OUTPUT   0

#define SET_OUTPUT(tris)   { tris = PIN_OUTPUT; }
#define SET_INPUT(tris)    { tris = PIN_INPUT; }

/*** Button Definitions ********************************************/
//      S1  is MCLR button
#define BTN_RA2          PORTAbits.RA2

#define BTN_RA2_TRIS     TRISAbits.TRISA2

/*** LED pins definition *******************************************/
#define LED_COUNT    4

#define LED_RB15_LAT      LATBbits.LATB15
#define LED_RB14_LAT      LATBbits.LATB14
#define LED_RB13_LAT      LATBbits.LATB13
#define LED_RB12_LAT      LATBbits.LATB12

#define LED_RB15_TRIS     TRISBbits.TRISB15
#define LED_RB14_TRIS     TRISBbits.TRISB14
#define LED_RB13_TRIS     TRISBbits.TRISB13
#define LED_RB12_TRIS     TRISBbits.TRISB12

#define LED_ON(x)       { x = 1; }
#define LED_OFF(x)      { x = 0; }
#define LED_TOGGLE(x)   { x ^= 1; }
#define LED_READ(x)     ((x == 1) ? true : false)

/*** UART pins definition *******************************************/


#endif

#ifdef	__cplusplus
extern "C" {
#endif

    extern void Board_initialize(void);
    extern void Board_peripheralInit(void);
    
    extern void inline BOARD_RS485_TxEnable(void);
    extern void inline BOARD_RS485_TxDisable(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_MICROSTICKII_H */

