#ifndef WELCOME_H
#define WELCOME_H

#include <string>

struct MiscWelcome {
    public:
        static inline const std::string welcomeInvalidStr = "Invalid input. Try again.";
};

class WelcomeScr {
    protected:
        std::string welcomeStr{};
        std::string continueStr{};
        std::string continueInput{};
    
    public:
        void welcome();
};

#endif