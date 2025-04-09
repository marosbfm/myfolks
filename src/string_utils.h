#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <sstream>
#include <string>

namespace strutil {

    template <typename... Args>
    std::string to_string(Args&&... args) {
        std::ostringstream oss;
        (oss << ... << args);  
        return oss.str();
    }

}

#endif
