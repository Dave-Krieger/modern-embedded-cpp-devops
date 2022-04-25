#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "logger-defs.hpp"

#include <iostream>
#include <array>
#include <mutex>

/**
 * @brief HOW TO USE
 * 
 * @details Implements queue and dumps when size > 8
 * @details Assumes RTOS/Multithreading 
 */
class Logger
{
public:
    Logger(const uint8_t m_prio);
    ~Logger();

    // Use pure virtual voids and force users to use the child classes
    virtual uint8_t write(const std::string & msg) = 0;
    virtual uint8_t clear() = 0;

private:
    uint8_t m_prio=0;
    uint8_
};

#endif  // LOGGER_HPP