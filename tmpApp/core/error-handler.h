#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <stdint.h>

// Copied and pasted from 
typedef enum error{
    error_ok,
    error_error,
    error_timeout,
    error_unknown
} error;

void error_check(uint8_t * errorcode, void* loggerType);

#endif // ERROR_HANDLER_H