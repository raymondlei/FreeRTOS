#pragma once

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* The values sent to the queue receive task from the queue send task and the
queue send software timer respectively. */
#define mainVALUE_SENT_FROM_TASK			( 100UL )
#define mainVALUE_SENT_FROM_TIMER			( 200UL )

/* The queue used by both tasks. */
extern QueueHandle_t xQueue;

/* A software timer that is started from the tick hook. */
extern TimerHandle_t xTimer;


extern void taskReceive_create(void);
extern void prvQueueReceiveTask(void *pvParameters);

extern void taskSend_create(void);
extern void prvQueueSendTask(void *pvParameters);

extern void timerTask_create(void);
extern void timerTask_start(void);
extern void prvQueueSendTimerCallback(TimerHandle_t xTimerHandle);