#ifndef TERMINALFORMATTING_H
#define TERMINALFORMATTING_H

#include <string>

namespace terminalFormatting {
    struct formTypes {
        public:
            static inline const std::string clear = "\033c";
    };
}

#endif