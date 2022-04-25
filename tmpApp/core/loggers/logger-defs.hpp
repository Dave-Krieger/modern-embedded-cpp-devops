
#ifndef LOGGER_DEFS_HPP
#define LOGGER_DEFS_HPP

const uint8_t LOG_QUEUE_LEN 8 
/**
 * @brief Set the interface type which the log will use
 * 
 */
enum LoggerInterface {
    UART,
    SPI,
};

/**
 * @brief Severity logging. Lower values are less prio
 * 
 */
enum Severity {
    DEBUG,
    WARN,
    ERROR,
    CRITICAL
};
#endif  // LOGGER_DEFS_HPP