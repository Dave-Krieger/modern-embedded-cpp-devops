#include "gpio.hpp"
#include "gpio-defs.hpp"

#include "error-handler.h"
Gpio:: Gpio(const uint8_t gpioChip, const uint8_t line){
    m_gpioChip = gpioChip;
    m_line = line;
}
Gpio:: ~Gpio() {

}

// Implement HW level get
uint8_t Gpio::get() {

}
// Implement HW level set.
uint8_t Gpio::set() {
    uint8_t retval = 0;

    // Set the HW
    
    // Check and log if error
    if (retval, (void *) SpiLogger) {
        
    }
    // 
}

// This could be redesigned into a single func w/ param pass to evaluate
uint8_t Gpio::conf_active_low() {

}
uint8_t Gpio::conf_active_high() {

}
