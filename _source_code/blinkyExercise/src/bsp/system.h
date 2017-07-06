
#ifndef SYSTEM_H
#define	SYSTEM_H

#include <stdint.h>
#include "FreeRTOSConfig.h"

/*****************************************************************************

    Macro definitions

 *****************************************************************************/
/*!
    The frequency of the software clock interrupt.
*/
#define CLK_FREQ                 configTICK_RATE_HZ

/*!
    Macro that converts clock ticks to milliseconds.
*/
#define System_TicksToMilliseconds(t)    ((uint32_t)(t) / (CLK_FREQ / 1000))

/*!
    Macro that converts clock ticks to seconds.
*/
#define System_TicksToSeconds(t)         ((uint32_t)(t) / CLK_FREQ)

/*!
    Macro that converts milliseconds to clock ticks.
*/
#define System_MillisecondsToTicks(mS)   ((uint32_t)(mS) * (CLK_FREQ / (uint32_t)1000))

/*!
    Macro that converts clock ticks to seconds.
*/
#define System_SecondsToTicks(s)         ((uint32_t)(s) * CLK_FREQ)

/* The number of nano seconds between each processor clock. */
#define System_nsPerTick  (( unsigned short ) (( 1.0 / ( double ) CLK_FREQ ) * 1000000000.0 ))

/*!
    Micro that converts 200 ms to clock ticks.
*/
#define System_200MS_TICKS               (CLK_FREQ / (uint32_t)5)

#ifdef	__cplusplus
extern "C" {
#endif

    extern void System_initialize(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

