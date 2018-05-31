/* Standard includes. */
#include <stdio.h>
#include <conio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "app_tasks.h"
/* The number of items the queue can hold at once. */
#define mainQUEUE_LENGTH					( 2 )

/* The queue used by both tasks. */
QueueHandle_t xQueue = NULL;

void app_basic(void)
{
	/* Create the queue. */
	xQueue = xQueueCreate(mainQUEUE_LENGTH, sizeof(uint32_t));

	if (xQueue != NULL)
	{
		/* Start the two tasks as described in the comments at the top of this file. */
		taskReceive_create();
		//taskSend_create();

		/* Create the software timer, but don't start it yet. */
		timerTask_create();
		timerTask_start();
		
		/* Start the tasks and timer running. */
		vTaskStartScheduler();
	}

	/* If all is well, the scheduler will now be running, and the following
	line will never be reached.  If the following line does execute, then
	there was insufficient FreeRTOS heap memory available for the idle and/or
	timer tasks	to be created.  See the memory management section on the
	FreeRTOS web site for more details. */
	for ( ;; );
}