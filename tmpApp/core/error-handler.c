#include "error-handler.h"

uint8_t error_check(uint8_t * errorcode, void* loggerType) {
    if (* errorcode > error_ok){
        // Do safe state here
    }
}
