#ifndef TERMINALFORMATTING_H
#define TERMINALFORMATTING_H

#include <string>

namespace terminalformatting {
    struct FormTypes {
        public:
            static inline const std::string clear = "\033c";
            static inline const std::string defaultColour = "\e[39m";
            static inline const std::string lightRed = "\e[91m";
            static inline const std::string lightGreen = "\e[92m";
            static inline const std::string lightYellow = "\e[93m";
            static inline const std::string lightMagenta = "\e[95m";
            static inline const std::string lightCyan = "\e[96m";
    };
}

#endif