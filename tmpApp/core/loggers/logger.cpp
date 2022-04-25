#include "logger.hpp"
#include "logger-defs.hpp"

#include <iostream>

Logger::Logger(LoggerInterface interface) {
    m_interface = interface;
}
Logger::~Logger(){

}

uint8_t Logger::write(const std::string & msg) {
    // Insert to queue
    m_queue[m_arrayIndex] = msg;
    m_arrayIndex++;

    // If greater than max queue len. Write to interfaces
    if (m_arrayIndex >= LOG_QUEUE_LEN){
        write_queue_to_interface();
    }
    
}
uint8_t Logger::flush(){
    for(uint8_t i=0;i<LOG_QUEUE_LEN;i++){
        m_queue(m_arrayIndex) = "";
    }
    m_arrayIndex = 0;
}

uint8_t Logger::write_to_interface(void *){
    switch(interface){
        case UART: {
            
        }
        case SPI: {

        }
        // Default to std:cout for funsies
        case STDOUT:
        default: {

        }
    }
}