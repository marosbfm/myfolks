#ifndef LOGGER_H
#define LOGGER_H

#include <chrono>
#include <string>
#include <unordered_map>
#include "log_level.h"

class Logger
{
   public:
    static void log(LogLevel level, const std::string& message);
    static void log(const std::string& tag, LogLevel level, const std::string& message);
    static void logOnecePerTime(const std::string& tag, LogLevel level, const std::string& message,
                                int timeIntervalMS = 1000);

   private:
    static bool shouldLogPerTime(LogLevel level, const std::string& tag, int timeIntervalMS);
    static std::unordered_map<std::string, uint64_t> lastLoggedTime;
};

#endif
