
#include "FreeRTOS.h"
#include <xc.h>
#include "Board_MicrostickII.h"

static void vInitU1 ( void );

void Board_initialize(void)
{
    //LCD_Initialize();
    
    //in order of led's placement on the board (left to right)
    //SET_OUTPUT(LED_D10_TRIS);  //Overlaps with S5
    SET_OUTPUT(LED_RB15_TRIS);
    SET_OUTPUT(LED_RB14_TRIS);
    SET_OUTPUT(LED_RB13_TRIS);
    SET_OUTPUT(LED_RB12_TRIS);

    //in order of button's placement on the board (left to right)
    SET_INPUT(BTN_RA2_TRIS);
}

void Board_peripheralInit(void)
{
    vInitU1();
}

/*---------------------------------------------------------------------
  Function name: vInitU1
  Description: Initialization of UART1 module
  Input parameters: -
  Output parameters: -
-----------------------------------------------------------------------*/
static void vInitU1 ( void )
{
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    _RP10R = 0b00011;   // U1TX output -> RP10 pin
    _U1RXR = 11;        // U1RX input  <- RP11 pin
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
}

/*****************************************************************************
 *
 * RS-485
 *
 *****************************************************************************/
void inline BOARD_RS485_TxEnable(void)
{
    portENTER_CRITICAL();
    //RS485IC_ON();
    //IO_RC7_SetHigh();  //switch to transmit mode
    portEXIT_CRITICAL();
}

void inline BOARD_RS485_TxDisable(void)
{
    portENTER_CRITICAL();
    //RS485IC_OFF();
    //IO_RC7_SetLow();  //switch to receive mode
    portEXIT_CRITICAL();
}