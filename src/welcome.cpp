#include "welcome.h"
#include "select.h"
#include "terminalformatting.h"
#include <iostream>
#include <string>
#include <cstdlib>

void WelcomeScr::welcome() {
    this->welcomeStr = "Welcome to the CRUD Flower Database!";
    this->continueStr = "Continue? (y/n):";

    std::cout << '\n' << terminalformatting::FormTypes::lightMagenta << welcomeStr << terminalformatting::FormTypes::defaultColour << '\n';
                        
    std::cout << '\n' << terminalformatting::FormTypes::lightYellow << continueStr << this->continueInput << terminalformatting::FormTypes::defaultColour << " ";

    std::cin >> this->continueInput;
    
    //create selS object from selectScr class
    SelectScr selScr;
    
    //assign truthy bool to input that equals "y" or "n"
    bool y = (continueInput == "y");
    bool n = (continueInput == "n");

    //if bool y is true, call select() from selScr
    //else if bool n is true, exit the program successfully (0 status)
    if(y == true) {
        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(n == true) {
        std::cout << terminalformatting::FormTypes::clear;

        std::exit(0); 
    }

    //clear cin buffer
    continueInput.clear();

    //if bool y or bool n is false (not "y" or "n" as input)
    //output "Invalid input." in the character error stream
    if(y == false || n == false) {
        std::cout << terminalformatting::FormTypes::clear;

        std::cerr << '\n' << terminalformatting::FormTypes::lightRed << MiscWelcome::welcomeInvalidStr << terminalformatting::FormTypes::defaultColour << '\n';

        WelcomeScr::welcome();
    }
}
