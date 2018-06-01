#pragma once
#include <stdbool.h>

struct AMessage
{
    char ucMessageID;
    char ucData[20];
} xMessage;



extern void uart_createObj(void);
extern bool uart_isInitialized(void);

extern BaseType_t uart_send(const void* buffer);
extern void uart_byteReceived(void* buffer);
