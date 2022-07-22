#ifndef WELCOME_H
#define WELCOME_H

#include <string>

struct miscWelcome {
    public:
        static inline const std::string welcomeInvalidStr = "Invalid input. Try again.";
};

class welcomeScr {
    protected:
        std::string welcomeStr{};
        std::string continueStr{};
        std::string continueInput{};
    
    public:
        void welcome();
};

#endif