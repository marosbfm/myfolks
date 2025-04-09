#include "logger.h"
#include <iostream>
#include "timer.h"

std::unordered_map<std::string, uint64_t> Logger::lastLoggedTime;

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

void Logger::log(const std::string& tag, LogLevel level, const std::string& message)
{
    log(level, "[" + tag + "] " + message);
}

void Logger::logOnecePerTime(const std::string& tag, LogLevel level, const std::string& message,
                             int timeIntervalMS)
{
    if (shouldLogPerTime(level, tag, timeIntervalMS))
    {
        log(tag, level, message);
    }
}

bool Logger::shouldLogPerTime(LogLevel level, const std::string& tag, int timeIntervalMS)
{
    std::string key = tag + "_" + std::to_string(static_cast<int>(level));
    uint64_t now = Timer::currentTimeMillis();

    if (lastLoggedTime.find(key) == lastLoggedTime.end())
    {
        lastLoggedTime[key] = now;
        return true;
    }
    else if (now - lastLoggedTime[key] > timeIntervalMS)
    {
        lastLoggedTime[key] = now;
        return true;
    }
    return false;
}
