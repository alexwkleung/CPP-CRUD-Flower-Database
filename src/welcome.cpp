#include "welcome.h"
#include "select.h"
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
    
    //if continueInput == "y", call select() from selScr
    //else if continueInput == "n", exit the program successfully (0 status)
    if(continueInput == "y") {
        selScr.select();
    } else if(continueInput == "n") {
        exit(0); 
    }
}
