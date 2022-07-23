#include "welcome.h"
#include "select.h"
#include "terminalformatting.h"
#include <iostream> 

int main() {
    std::cout << terminalformatting::FormTypes::clear << '\n'; 

    WelcomeScr welcScr;

    welcScr.welcome();

    return 0;
}