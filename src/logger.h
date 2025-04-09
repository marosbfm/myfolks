#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "log_level.h"

class Logger
{
   public:
    static void log(LogLevel level, const std::string& message);
};

#endif
