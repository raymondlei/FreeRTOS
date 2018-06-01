/* Standard includes. */
#include <stdio.h>
#include <conio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "app_tasks.h"
#include "uart_queue.h"

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

    struct AMessage msgObj;

	for (;; )
	{
		/* Blocking call until something arrives in the queue */
		uart_byteReceived(&msgObj);

		/*  To get here something must have been received from the queue */
		printf("%s\r\n", msgObj.ucData);

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