#ifndef SPI_LOGGER_HPP
#define SPI_LOGGER_HPP

#include "spi-logger-defs.hpp"

#include <iostream>
#include <array>
#include <mutex>

/**
 * @brief HOW TO USE
 * 
 * @details Implements queue and dumps when size > 8
 * @details Assumes RTOS/Multithreading 
 */
class SpiLogger : public Logger
{
public:
    SpiLogger(SpiLines);
    ~SpiLogger();

    uint8_t write(const std::string & msg);
    uint8_t clear();

private:
    std::array<std::string,LOG_QUEUE_LEN> m_queue;
    uint8_t m_arrayIndex=0;

    uint8_t write_queue_to_interface();
    uint8_t write_to_spi();
    uint8_t write_to_uart();

    static std::mutex m_uartMutex;

};

#endif  // SPI_LOGGER_HPP