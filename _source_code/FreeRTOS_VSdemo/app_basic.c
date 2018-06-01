/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"  //for vTaskStartScheduler();

#include "app_tasks.h"
#include "uart_queue.h"

void app_basic(void)
{
	uart_createObj();  /* Create the queue. */

	if (uart_isInitialized())
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