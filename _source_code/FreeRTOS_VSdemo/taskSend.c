
/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "app_tasks.h"

/* Priorities at which the tasks are created. */
#define	mainQUEUE_SEND_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )

/* The rate at which data is sent to the queue.  The times are converted from
milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define mainTASK_SEND_FREQUENCY_MS			pdMS_TO_TICKS( 200UL )

void taskSend_create(void)
{
	xTaskCreate(prvQueueSendTask,
		"TX",
		configMINIMAL_STACK_SIZE,
		NULL,
		mainQUEUE_SEND_TASK_PRIORITY,
		NULL);
}

void prvQueueSendTask(void *pvParameters)
{
	/* Prevent the compiler warning about the unused parameter. */
	(void)pvParameters;

	TickType_t xNextWakeTime;
	const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
	const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TASK;

	/* Initialise xNextWakeTime - this only needs to be done once. */
	xNextWakeTime = xTaskGetTickCount();

	for (;; )
	{
		/* Place this task in the blocked state until it is time to run again.
		The block time is specified in ticks, pdMS_TO_TICKS() was used to
		convert a time specified in milliseconds into a time specified in ticks.
		While in the Blocked state this task will not consume any CPU time. */
		vTaskDelayUntil(&xNextWakeTime, xBlockTime);

		/* Send to the queue - causing the queue receive task to unblock and
		write to the console.  0 is used as the block time so the send operation
		will not block - it shouldn't need to block as the queue should always
		have at least one space at this point in the code. */
		xQueueSend(xQueue, &ulValueToSend, 0U);
	}
}