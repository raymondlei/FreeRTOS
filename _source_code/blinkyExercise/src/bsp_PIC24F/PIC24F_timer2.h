
#ifndef PIC24F_TIMER2_H
#define	PIC24F_TIMER2_H

#include <stdint.h>

#define T2_ON    0x8000 /* Timer2 ON */
#define T2_OFF   0x0000 /* Timer2 OFF */

#define T2_IDLE_CON        0x0000 /* stop operation during sleep */
#define T2_GATE_OFF        0x0000 /* Timer Gate time accumulation disabled */
#define T2_PS_1_256        0x0030 /* Prescaler     1:256 */
#define T2_32BIT_MODE_OFF  0x0000 /* Timer 32 bit mode disalbed */
#define T2_SOURCE_INT      0x0000 /* Internal clock source */

#define T2_millisecondToTicks(x)     ((x) * ((configCPU_CLOCK_HZ / 1000) / 256 ))

#ifdef	__cplusplus
extern "C" {
#endif

    extern void Timer2_Init(uint32_t unit50us);
    extern void Timer2_Enable(void);
    extern void Timer2_Disable(void);
    
    extern uint32_t Timer2_getTicks(void);
    extern uint32_t Timer2_getPeriod(void);
    
    extern void Timer2_resetTicks(void);
    extern void Timer2_setEventTick(uint32_t value);

#ifdef	__cplusplus
}
#endif

#endif	/* PIC24F_TIMER2_H */

