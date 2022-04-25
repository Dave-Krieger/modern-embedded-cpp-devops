#include "spi-logger.hpp"
#include "spi-logger-defs.hpp"

#include "logger.hpp"
#include "spi.hpp"

#include <iostream>

SpiSpiLogger::SpiLogger() {
    using Logger::Logger
}
SpiLogger::~SpiLogger(){

}

uint8_t SpiLogger::write(const std::string & msg) {
    // Insert to queue
    m_queue[m_arrayIndex] = msg;
    m_arrayIndex++;

    // If greater than max queue len. Write to interfaces
    if (m_arrayIndex >= LOG_QUEUE_LEN){
        write_queue_to_interface();
    }
    
}
uint8_t SpiLogger::flush(){
    for(uint8_t i=0;i<LOG_QUEUE_LEN;i++){
        m_queue(m_arrayIndex) = "";
    }
    m_arrayIndex = 0;
}

uint8_t write_queue_to_spi(){
    for(uint8_t i=0;i<LOG_QUEUE_LEN;i++){
        
    }
}

