#ifndef PIC24F_CPU_H
#define	PIC24F_CPU_H

#ifdef	__cplusplus
extern "C" {
#endif

    extern void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
    extern void SOSC_Configuration(void);
    
    extern void CPU_RP_Unlock(void);
    extern void CPU_RP_Lock(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PIC24F_CPU_H */

