/* Standard includes. */
#include <stdio.h>
#include <conio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "app_tasks.h"

/* Priorities at which the tasks are created. */
#define mainQUEUE_RECEIVE_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )


void taskReceive_create(void)
{
	xTaskCreate(prvQueueReceiveTask,	/* The function that implements the task. */
		"Rx", 							/* The text name assigned to the task - for debug only as it is not used by the kernel. */
		configMINIMAL_STACK_SIZE, 		/* The size of the stack to allocate to the task. */
		NULL, 							/* The parameter passed to the task - not used in this simple case. */
		mainQUEUE_RECEIVE_TASK_PRIORITY,/* The priority assigned to the task. */
		NULL);							/* The task handle is not required, so NULL is passed. */
}

void prvQueueReceiveTask(void *pvParameters)
{
	/* Prevent the compiler warning about the unused parameter. */
	(void)pvParameters;

	uint32_t ulReceivedValue;

	for (;; )
	{
		/* Wait until something arrives in the queue - this task will block
		indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
		FreeRTOSConfig.h.  It will not use any CPU time while it is in the
		Blocked state. */
		xQueueReceive(xQueue, &ulReceivedValue, portMAX_DELAY);

		/*  To get here something must have been received from the queue, but
		is it an expected value?  Normally calling printf() from a task is not
		a good idea.  Here there is lots of stack space and only one task is
		using console IO so it is ok.  However, note the comments at the top of
		this file about the risks of making Windows system calls (such as
		console output) from a FreeRTOS task. */
		if (ulReceivedValue == mainVALUE_SENT_FROM_TASK)
		{
			printf("Message received from task\r\n");
		}
		else if (ulReceivedValue == mainVALUE_SENT_FROM_TIMER)
		{
			printf("Message received from software timer\r\n");
		}
		else
		{
			printf("Unexpected message\r\n");
		}

		/* Reset the timer if a key has been pressed.  The timer will write
		mainVALUE_SENT_FROM_TIMER to the queue when it expires. */
		if (_kbhit() != 0)
		{
			/* Remove the key from the input buffer. */
			(void)_getch();

			/* Reset the software timer. */
			xTimerReset(xTimer, portMAX_DELAY);
		}
	}
}