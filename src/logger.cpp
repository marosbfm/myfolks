#include "logger.h"
#include <iostream>
#include "timer.h"

void Logger::log(LogLevel level, const std::string& message)
{
    switch (level)
    {
        case LogLevel::DEBUG:
            std::cout << Timer::currentDateTime() << " [DEBUG] " << message << std::endl;
            break;

        case LogLevel::INFO:
            std::cout << Timer::currentDateTime() << " [INFO] " << message << std::endl;
            break;

        case LogLevel::WARN:
            std::cout << Timer::currentDateTime() << " [WARN] " << message << std::endl;
            break;

        case LogLevel::ERROR:
            std::cout << Timer::currentDateTime() << " [ERROR] " << message << std::endl;
            break;

        case LogLevel::FATAL:
            std::cout << Timer::currentDateTime() << " [FATAL] " << message << std::endl;
            break;

        default:
            break;
    }
}