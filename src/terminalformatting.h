#ifndef TERMINALFORMATTING_H
#define TERMINALFORMATTING_H

#include <string>

namespace terminalformatting {
    struct FormTypes {
        public:
            static inline const std::string clear = "\033c";
    };
}

#endif