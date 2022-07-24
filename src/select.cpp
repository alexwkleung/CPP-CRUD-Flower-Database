#include "select.h"
#include "options.h"
#include "terminalformatting.h"
#include <iostream>
#include <cstdlib>
#include <string>

void SelectScr::select() {
    this->selectTitle = ">> Database options <<";
    this->breakLine = "======================================";
    this->addAnEntry = "1. Add a new entry to the database.";
    this->updateAnEntry = "2. Update an entry in the database.";
    this->deleteAnEntry = "3. Delete an entry in the database";
    this->searchTheDB = "4. Search the database.";
    this->showAllEntries = "5. Show all entries in the database.";
    this->showCommands = "6. Show help commmands.";
    this->exitDB = "7. Exit the database.";
    this->selectFooStr = "Select an option:";

    std::cout << '\n' << '\t' << selectTitle << '\n';
    std::cout << breakLine << '\n';
    std::cout << addAnEntry << '\n';
    std::cout << updateAnEntry << '\n';
    std::cout << deleteAnEntry << '\n';
    std::cout << searchTheDB << '\n';
    std::cout << showAllEntries << '\n';
    std::cout << showCommands << '\n';
    std::cout << exitDB << '\n';

    std::cout << '\n' << selectFooStr << inputSelectStr << " ";

    std::cin >> this->inputSelectStr;
    
    //create object opt from option class 
    Option opt;

    CheckGuard ch;

    //need try... catch statements to handle std::stoi exceptions when it cannot convert to int
    try {
        //convert string to int via std::stoi
        int inputSelectStrStoi = std::stoi(inputSelectStr);
    
        if(inputSelectStrStoi == 1) {
            inputSelectStr.clear();

            std::cout << terminalformatting::FormTypes::clear;

            ch.checkOpt1();    
        }

        if(inputSelectStrStoi == 2) {
            inputSelectStr.clear();

            std::cout << terminalformatting::FormTypes::clear;

            ch.checkOpt2();
        }

        if(inputSelectStrStoi == 3) {
            inputSelectStr.clear();

            std::cout << terminalformatting::FormTypes::clear;

            ch.checkOpt3();
        }

        if(inputSelectStrStoi == 4) {
            inputSelectStr.clear();

            std::cout << terminalformatting::FormTypes::clear;

            ch.checkOpt4();
        }

        if(inputSelectStrStoi == 5) {
            inputSelectStr.clear();

            std::cout << terminalformatting::FormTypes::clear;

            opt.opt5();
        }

        if(inputSelectStrStoi == 6) {
            inputSelectStr.clear();

            std::cout << terminalformatting::FormTypes::clear;

            opt.opt6();
        }

        if(inputSelectStrStoi == 7) {
            inputSelectStr.clear();

            opt.opt7();
        }
    }

    catch(std::invalid_argument &e) {
        std::cout << terminalformatting::FormTypes::clear;

        std::cout << MiscSelect::selectInvalidStr << '\n';

        inputSelectStr.clear();

        SelectScr::select();
    }
}
