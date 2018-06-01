/* Standard includes. */
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "uart_queue.h"

/* The number of items the queue can hold at once. */
#define MaxQueueSize            ( 2 )
#define MaxElementsPerQueue     (sizeof(uint8_t) * 12)

/* The queue used by both tasks. */
QueueHandle_t xQueue = NULL;

void uart_createObj(void)
{
	/* Create the queue. */
	xQueue = xQueueCreate(MaxQueueSize, MaxElementsPerQueue);
}

bool uart_isInitialized(void)
{
	return (xQueue != NULL);
}

BaseType_t uart_send(const void* buffer)
{
    struct AMessage msgObj;

    strncpy(&msgObj.ucData, (char*)buffer, 10);
    msgObj.ucMessageID = 1;

	/* Send to the queue - causing the queue receive task to unblock and
	write out a message.  This function is called from the timer/daemon task, so
	must not block.  Hence the block time is set to 0. */
	return xQueueSend(xQueue, &msgObj, 10U);
}

void uart_byteReceived(void* buffer)
{
	/* Wait until something arrives in the queue - this task will block
	indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
	FreeRTOSConfig.h.  It will not use any CPU time while it is in the
	Blocked state. */
	xQueueReceive(xQueue, buffer, portMAX_DELAY);
}
