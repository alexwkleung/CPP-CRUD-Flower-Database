#include "select.h"
#include "options.h"
#include <iostream>
#include <cstdlib>
#include <string>

void selectScr::select() {
    this->selectTitle = ">> Database options <<";
    this->breakLine = "======================================";
    this->addAnEntry = "1. Add a new entry to the database.";
    this->updateAnEntry = "2. Update an entry in the database.";
    this->deleteAnEntry = "3. Delete an entry in the database";
    this->searchTheDB = "4. Search the database.";
    this->showAllEntries = "5. Show all entries in the database.";
    this->exitDB = "6. Exit the database.";
    this->selectFooStr = "Select an option:";

    std::cout << '\n' << '\t' << selectTitle << '\n';
    std::cout << breakLine << '\n';
    std::cout << addAnEntry << '\n';
    std::cout << updateAnEntry << '\n';
    std::cout << deleteAnEntry << '\n';
    std::cout << searchTheDB << '\n';
    std::cout << showAllEntries << '\n';
    std::cout << exitDB << '\n';

    std::cout << '\n' << selectFooStr << inputSelectStr << " ";

    std::cin >> this->inputSelectStr;
    
    //create opt1 object from option1 class 
    option1 opt1;

    //convert string to int via std::stoi
    int inputSelectStrStoi = std::stoi(inputSelectStr);

    if(inputSelectStrStoi == 1) {
        opt1.opt1();    
    }
}
