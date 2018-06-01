/* Standard includes. */
#include <stdio.h>
#include <conio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include "app_tasks.h"
#include "uart_queue.h"

/* The rate at which data is sent to the queue.  The times are converted from
milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define mainTIMER_SEND_FREQUENCY_MS			pdMS_TO_TICKS( 2000UL )

/* A software timer that is started from the tick hook. */
TimerHandle_t xTimer = NULL;


void timerTask_create(void)
{
	const TickType_t xTimerPeriod = mainTIMER_SEND_FREQUENCY_MS;

	xTimer = xTimerCreate("Timer",	/* The text name assigned to the software timer - for debug only as it is not used by the kernel. */
		xTimerPeriod,		/* The period of the software timer in ticks. */
		pdTRUE,			    /* xAutoReload is set to pdFALSE, so this is a one shot timer. */
		NULL,				/* The timer's ID is not used. */
		prvQueueSendTimerCallback);/* The function executed when the timer expires. */
}

void timerTask_start(void)
{
	xTimerStart(xTimer, 0U);
}

void prvQueueSendTimerCallback(TimerHandle_t xTimerHandle)
{
	/* Avoid compiler warnings resulting from the unused parameter. */
	(void)xTimerHandle;

	//const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TIMER;
	uint8_t buffer[12];
	strncpy(&buffer[0], "0123456789", 5);

	/* This is the software timer callback function.  The software timer has a
	period of two seconds and is reset each time a key is pressed.  This
	callback function will execute if the timer expires, which will only happen
	if a key is not pressed for two seconds. */

    if (uart_send(&buffer) == pdTRUE)
    {
        printf("data sent... ");
    }
}
