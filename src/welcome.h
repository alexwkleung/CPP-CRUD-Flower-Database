#ifndef WELCOME_H
#define WELCOME_H

#include <string>

struct miscWelcome {
    public:
        std::string welcomeInvalidStr{};
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