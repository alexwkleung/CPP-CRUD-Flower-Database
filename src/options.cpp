#include "options.h"
#include "select.h"
#include "terminalformatting.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

/*
** implement:

* separate checking mechanism from options

* a filter for unwanted words being present in the db
*/

//1. add a new entry to the database 
void Option::opt1() {
    //vector to hold strings from getline
    std::vector<std::string> vecGl = {};

    //input file stream - read from db.txt
    std::ifstream ifdb("src/db.txt");

    //file output stream (open db.txt into buffer)
    //set output to be appended to the end of file (db.txt)
    std::ofstream db("src/db.txt", std::ios::app);

    //use getline to read from ifstream and inputGl holds them as strings
    //push strings to the end of the vector
    //sort the vector (for binary search)
    while(std::getline(ifdb, glStr)) {
        vecGl.push_back(glStr);
        std::sort(vecGl.begin(), vecGl.end());
    }
    
    //while loop, taking input as condition
    //condition: binary search within the range of the vector and comparing it against the input
    //if the input matches a string within the vector, output an error 
    //else, add inputted string to the db
    while(std::cin >> this->addEntryStr) {
        if(std::binary_search(vecGl.begin(), vecGl.end(), this->addEntryStr)) {
            std::cerr << '\n' << addEntryStr << " exists in the datatbase. Try again." << '\n';

            addEntryStr.clear();

            //call opt1() after cin clear
            Option::opt1();
        } else if(!std::binary_search(vecGl.begin(), vecGl.end(), this->addEntryStr)) {
             if(addEntryStr == MiscOptions::goBack) {
                SelectScr selScr;

                addEntryStr.clear();

                std::cout << terminalformatting::FormTypes::clear;

                selScr.select();
            }
            
            //write the input to file
            db << addEntryStr << '\n';

            //close ifstream buffer
            db.close();

            std::cout << '\n' << "Added " << addEntryStr << " to the database!" << '\n';

            addEntryStr.clear();

            Option::opt1(); 
        }
    }
}

//CHECK GUARD: 2. update an entry in the database
void CheckGuard::checkOpt2() {
    std::ifstream ifDb("src/db.txt");

    std::vector<std::string> checkUpdateVec = {};
    
    std::cin >> this->deleteEntryStr;

    while(std::getline(ifDb, this->glStr)) {
        checkUpdateVec.push_back(this->glStr);
        std::sort(checkUpdateVec.begin(), checkUpdateVec.end());
    }

    if(this->deleteEntryStr == MiscOptions::goBack) {
        SelectScr selScr;

        deleteEntryStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(this->deleteEntryStr != MiscOptions::goBack) {
        if(std::binary_search(checkUpdateVec.begin(), checkUpdateVec.end(), this->deleteEntryStr)) {
            Option::opt2();
        } else {
            std::cout << terminalformatting::FormTypes::clear << '\n';

            std::cout << MiscOptions::optionsNotFoundStr << '\n';

            CheckGuard::checkOpt2();
        }
    }
}

//2. update an entry in the database
void Option::opt2() {
    std::ifstream db("src/db.txt");
    std::ofstream dbTemp("src/db-temp.txt");
    
    if(deleteEntryStr == MiscOptions::goBack) {
        SelectScr selScr;

        deleteEntryStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(deleteEntryStr != MiscOptions::goBack) { 
        std::cin >> this->updateEntryStr;
        
        //credit: 
        //https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
        //https://stackoverflow.com/questions/42724694/how-to-copy-a-file-into-another-file-but-replace-a-word-with-a-user-entered-word

        while(std::getline(db, this->glStr)) {
            std::string::size_type szType{};

            //while condition:
            //szType is assigned std::string.find() against deleteEntryStr
            //szType represents the maximum size of deleteEntryStr
            //and that must not equal std::string::npos (size_type of npos is the largest it can handle)
            while((szType = glStr.find(deleteEntryStr) != std::string::npos)) {
                glStr.replace(glStr.find(deleteEntryStr), deleteEntryStr.length(), updateEntryStr);
            }

            //append contents of glStr to dbTemp
            dbTemp << glStr << '\n';
        }

        db.close();
        dbTemp.close();
            
        std::cout << terminalformatting::FormTypes::clear;

        std::cout << '\n' << "Updated entry " << deleteEntryStr << " in the database!" << '\n';
            
        deleteEntryStr.clear();
        updateEntryStr.clear();

        //remove old db.txt with updated db.txt (temp)
        std::remove("src/db.txt");
        std::rename("src/db-temp.txt", "src/db.txt");

        CheckGuard ch;

        ch.checkOpt2();
    }
}