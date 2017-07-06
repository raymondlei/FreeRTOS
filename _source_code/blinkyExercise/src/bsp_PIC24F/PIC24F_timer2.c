#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE

#include <xc.h>

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "timers.h"

#include "PIC24F_timer2.h"

/*****************************************************************************

    Private variables

 *****************************************************************************/
static uint32_t _period, _interval;

static uint32_t _current_ticks, _event_ticks;
/*****************************************************************************

    Private functions prototype

 *****************************************************************************/
static uint16_t UseTimer2(void);
static void DefaultConfig_T2(void);

/*****************************************************************************

 Public functions implementation

 *****************************************************************************/
/*!
    Function to initialize the clock timer. This is used to track the time of
    various activities within the firmware.
*/
void Timer2_Init(uint32_t milliseconds)
{
    _interval = milliseconds;
    _period = T2_millisecondToTicks(milliseconds);

    _current_ticks = 0;
    UseTimer2();
}

void Timer2_Enable(void)
{
    T2CONbits.TON = 1;
}

void Timer2_Disable(void)
{
    T2CONbits.TON = 0;
}

uint32_t Timer2_getTicks(void)
{
    return _current_ticks;
}

uint32_t Timer2_getPeriod(void)
{
    return _interval;
}

void Timer2_resetTicks(void)
{
    _current_ticks = 0;
}
void Timer2_setEventTick(uint32_t value)
{
    _event_ticks = value;
}
/*****************************************************************************

    Private functions implementation

 *****************************************************************************/
static uint16_t UseTimer2(void)
{
    DefaultConfig_T2();

    /* Configuration of Timer23 */
    TMR2 = 0x00;
    PR2 = (_period & 0x0000FFFF);
    
    IPC1bits.T2IP = 1;  //interrupt priority
    IFS0bits.T2IF = 0;  //interrupt flag
    IEC0bits.T2IE = 1;  //enable interrupt
    
    return 1;
}

static void DefaultConfig_T2(void)
{
    T2CONbits.TON = 0;
    T2CONbits.TSIDL = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0b11;
    T2CONbits.T32 = 0;
}

/*****************************************************************************

 Interrupt Service Routine

 *****************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt()
{
    IFS0bits.T2IF = 0;  //clear interrupt flag
    
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;
    
    _current_ticks++;
    //LED_RB15_LAT ^= 1;  //Toggle signal
    
    /* If xHigherPriorityTaskWoken is now set to pdTRUE then a context
    switch should be requested.  The macro used is port specific and will
    be either portYIELD_FROM_ISR() or portEND_SWITCHING_ISR() - refer to
    the documentation page for the port being used. */
    if( xHigherPriorityTaskWoken != pdFALSE )
    {
        taskYIELD();
    }
}