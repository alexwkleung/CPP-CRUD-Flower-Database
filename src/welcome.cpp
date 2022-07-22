#include "welcome.h"
#include "select.h"
#include "terminalformatting.h"
#include <iostream>
#include <string>

void welcomeScr::welcome() {
    this->welcomeStr = "Welcome to the CRUD Flower Database!";
    this->continueStr = "Continue? (y/n):";

    std::cout << '\n' << welcomeStr << '\n';
                        
    std::cout << '\n' << continueStr << this->continueInput << " ";

    std::cin >> this->continueInput;
    
    //create selS object from selectScr class
    selectScr selScr;
    
    //assign truthy bool to input that equals "y" or "n"
    bool y = (continueInput == "y");
    bool n = (continueInput == "n");

    //if bool y is true, call select() from selScr
    //else if bool n is true, exit the program successfully (0 status)
    if(y == true) {
        std::cout << terminalFormatting::formTypes::clear;

        selScr.select();
    } else if(n == true) {
        exit(0); 
    }

    //clear cin buffer
    continueInput.clear();

    //if bool y or bool n is false (not "y" or "n" as input)
    //output "Invalid input." in the character error stream
    if(y == false || n == false) {
        std::cout << terminalFormatting::formTypes::clear;

        std::cerr << '\n' << miscWelcome::welcomeInvalidStr << '\n';

        welcomeScr::welcome();
    }
}
