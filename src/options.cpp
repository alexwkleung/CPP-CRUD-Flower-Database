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
void option::opt1() {
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
            option::opt1();
        } else if(!std::binary_search(vecGl.begin(), vecGl.end(), this->addEntryStr)) {
             if(addEntryStr == miscOptions::goBack) {
                selectScr selScr;

                addEntryStr.clear();

                std::cout << terminalFormatting::formTypes::clear;

                selScr.select();
            }
            
            //write the input to file
            db << addEntryStr << '\n';

            //close ifstream buffer
            db.close();

            std::cout << '\n' << "Added " << addEntryStr << " to the database!" << '\n';

            addEntryStr.clear();

            option::opt1(); 
        }
    }
}

//2. update an entry in the database
void option::opt2() {
    std::ifstream db("src/db.txt");
    std::ofstream dbTemp("src/db-temp.txt");

    std::cin >> this->deleteEntryStr;
    
    if(deleteEntryStr == miscOptions::goBack) {
        selectScr selScr;

        deleteEntryStr.clear();

        std::cout << terminalFormatting::formTypes::clear;

        selScr.select();
    } else { 
        std::cin >> this->updateEntryStr;
        
        //credit: 
        //https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
        //https://stackoverflow.com/questions/42724694/how-to-copy-a-file-into-another-file-but-replace-a-word-with-a-user-entered-word

        while(std::getline(db, glStr)) {
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
            
        std::cout << terminalFormatting::formTypes::clear;

        std::cout << '\n' << "Updated entry " << deleteEntryStr << " from the database!" << '\n';
            
        deleteEntryStr.clear();
        updateEntryStr.clear();

        //remove old db.txt with updated db.txt (temp)
        std::remove("src/db.txt");
        std::rename("src/db-temp.txt", "src/db.txt");

        option::opt2();
    }
}