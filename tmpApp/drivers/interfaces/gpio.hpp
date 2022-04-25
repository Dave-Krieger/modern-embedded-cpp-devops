#ifndef GPIO_HPP
#define GPIO_HPP

/**
 * @brief Implements a standard linux GPIO interface using chardev interface
 * 
 * @details Uses libgpiod. A core linux library for GPIO
 * 
 * Resources: 
 * - https://embeddedbits.org/new-linux-kernel-gpio-user-space-interface/
 * - https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/
 */

#include "spi-logger.hpp"

class Gpio
{
private:
    /* data */
    uint8_t m_gpioChip    = 0;
    uint8_t m_line        = 0;

    // Let user assign a specific spi logger. Else use default
    SpiLogger * = NULL;

public:
    Gpio(const uint8_t gpioChip, const uint8_t line, Spilogger* = NULL);
    ~Gpio();

    uint8_t get();
    uint8_t set();

    // This could be redesigned into a single func w/ param pass to evaluate
    uint8_t conf_active_low();
    uint8_t conf_active_high();
};

#endif  // GPIO_HPP