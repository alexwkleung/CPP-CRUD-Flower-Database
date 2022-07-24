#include "options.h"
#include "select.h"
#include "terminalformatting.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

/*
** implement:

* separate checking mechanism from options

* a filter for unwanted words being present in the db

* terminal colours
*/

//CHECK GUARD: 1. add a new entry to the database
void CheckGuard::checkOpt1() {
    std::ifstream ifDb("src/db.txt");

    std::vector<std::string> checkAddEntryVec = {};

    addEntryStr.clear();

    std::cout << "Enter an entry to add: " << addEntryStr;

    std::cin >> this->addEntryStr;

    while(std::getline(ifDb, this->glStr)) {
        checkAddEntryVec.push_back(glStr);
        std::sort(checkAddEntryVec.begin(), checkAddEntryVec.end());
    }

    if(addEntryStr == MiscOptions::goBack) {
        SelectScr selScr;

        addEntryStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(this->addEntryStr != MiscOptions::goBack) {
        if(std::binary_search(checkAddEntryVec.begin(), checkAddEntryVec.end(), addEntryStr)) {
            std::cout << terminalformatting::FormTypes::clear; 

            std::cerr << '\n' << addEntryStr << " exists in the database. Try again." << '\n';

            addEntryStr.clear();

            //call checkOpt1() after cin clear
            CheckGuard::checkOpt1();

        } else if(!std::binary_search(checkAddEntryVec.begin(), checkAddEntryVec.end(), addEntryStr)) {
            Option::opt1();
        }
    }
}

//1. add a new entry to the database 
void Option::opt1() {
    //input file stream - read from db.txt
    std::ifstream ifdb("src/db.txt");

    //file output stream (open db.txt into buffer)
    //set output to be appended to the end of file (db.txt)
    std::ofstream db("src/db.txt", std::ios::app);
            
    //write the input to file
    db << addEntryStr << '\n';

    //close ifstream buffer
    db.close();

    std::cout << terminalformatting::FormTypes::clear;

    std::cout << '\n' << "Added " << addEntryStr << " to the database!" << '\n';

    //clear cin input
    addEntryStr.clear();

    CheckGuard cg;

    cg.checkOpt1(); 
}

//CHECK GUARD: 2. update an entry in the database
void CheckGuard::checkOpt2() {
    std::ifstream ifDb("src/db.txt");

    std::vector<std::string> checkUpdateVec = {};
    
    std::cout << "Enter the entry to update: " << entryForUpdateStr;

    //take input for string to be deleted in db
    std::cin >> this->entryForUpdateStr;

    //use getline to store strings
    //push into vector and sort
    while(std::getline(ifDb, this->glStr)) {
        checkUpdateVec.push_back(this->glStr);
        std::sort(checkUpdateVec.begin(), checkUpdateVec.end());
    }

    //checking input:
    //check to see if the input contains goback str
    //then checks input against the sorted vector using binary search (truthy checking)
    //when input is found within the sorted vector, it will update the entry given a second input
    //when the binary search fails (falsy checking) then it restarts option 2 (via function call)
    if(this->entryForUpdateStr == MiscOptions::goBack) {
        SelectScr selScr;

        ifDb.close();

        entryForUpdateStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(this->entryForUpdateStr != MiscOptions::goBack) {
        if(std::binary_search(checkUpdateVec.begin(), checkUpdateVec.end(), this->entryForUpdateStr)) {
            Option::opt2();
        } else if(!std::binary_search(checkUpdateVec.begin(), checkUpdateVec.end(), this->entryForUpdateStr)) {
            std::cout << terminalformatting::FormTypes::clear << '\n';

            std::cerr << entryForUpdateStr << MiscOptions::optionsNotFoundStr << '\n';

            ifDb.close();

            entryForUpdateStr.clear();

            CheckGuard::checkOpt2();
        }
    }
}

//2. update an entry in the database
void Option::opt2() {
    std::ifstream db("src/db.txt");
    std::ofstream dbTemp("src/db-temp.txt");
    
    if(entryForUpdateStr == MiscOptions::goBack) {
        SelectScr selScr;

        entryForUpdateStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(entryForUpdateStr != MiscOptions::goBack) { 
        std::cout << "Enter the updated entry: " << updatedEntryStr;

        std::cin >> this->updatedEntryStr;
        
        //credit: 
        //https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
        //https://stackoverflow.com/questions/42724694/how-to-copy-a-file-into-another-file-but-replace-a-word-with-a-user-entered-word

        while(std::getline(db, this->glStr)) {
            std::string::size_type szType{};

            //while condition:
            //szType is assigned std::string.find() against entryForUpdateStr
            //szType represents the maximum size of entryForUpdateStr
            //and that must not equal std::string::npos (size_type of npos is the largest it can handle)
            while((szType = glStr.find(entryForUpdateStr) != std::string::npos)) {
                glStr.replace(glStr.find(entryForUpdateStr), entryForUpdateStr.length(), updatedEntryStr);
            }

            //append contents of glStr to dbTemp
            dbTemp << glStr << '\n';
        }

        db.close();
        dbTemp.close();

        //remove old db.txt with updated db.txt (temp)
        std::remove("src/db.txt");
        std::rename("src/db-temp.txt", "src/db.txt");

        std::cout << terminalformatting::FormTypes::clear;

        std::cout << '\n' << "Updated entry " << entryForUpdateStr << " in the database!" << " (" << entryForUpdateStr << " --> " << updatedEntryStr << ")" << '\n';

        entryForUpdateStr.clear();
        updatedEntryStr.clear();

        CheckGuard cg;

        cg.checkOpt2();
    }
}

//CHECK GUARD: 3. delete an entry in the database
void CheckGuard::checkOpt3() {
    std::ifstream ifDb("src/db.txt");

    std::vector<std::string> deleteEntryVec = {};

    std::cout << "Enter string to delete: " << this->deleteEntryStr;
    
    std::cin >> this->deleteEntryStr;

    while(std::getline(ifDb, glStr)) {
        deleteEntryVec.push_back(glStr);
        std::sort(deleteEntryVec.begin(), deleteEntryVec.end());
    }

    if(deleteEntryStr == MiscOptions::goBack) {
        SelectScr selScr;

        deleteEntryStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(deleteEntryStr != MiscOptions::goBack) {
        if(std::binary_search(deleteEntryVec.begin(), deleteEntryVec.end(), this->deleteEntryStr)) {
            Option::opt3();
        } else if(!std::binary_search(deleteEntryVec.begin(), deleteEntryVec.end(), this->deleteEntryStr)) {
            std::cout << terminalformatting::FormTypes::clear;

            std::cerr << deleteEntryStr << MiscOptions::optionsNotFoundStr << '\n';

            deleteEntryStr.clear();

            CheckGuard::checkOpt3();
        }
    }
}

//3. delete an entry in the database
void Option::opt3() {
    std::ifstream ifDb("src/db.txt");
    std::ofstream ofDb("src/db-temp.txt");
    
    //store input file stream (ifDb) as strings in glStr
    //append all strings to output file stream (ofDb) except the one for deletion (input - deleteEntryStr)
    while(std::getline(ifDb, glStr)) {
        if(glStr != deleteEntryStr) {
            ofDb << glStr << '\n';
        }
    }

    ifDb.close();
    ofDb.close();

    std::remove("src/db.txt");
    std::rename("src/db-temp.txt", "src/db.txt");

    std::cout << terminalformatting::FormTypes::clear;
    
    std::cout << "Deleted " << deleteEntryStr << " from the database!" << '\n';

    deleteEntryStr.clear();

    CheckGuard cg;
    
    cg.checkOpt3();
}

//CHECK GUARD: 4. search the database
void CheckGuard::checkOpt4() {
    std::cout << "Search for an entry: " << searchEntryStr;

    std::cin >> searchEntryStr;

    if(searchEntryStr == MiscOptions::goBack) {
        SelectScr selScr;

        searchEntryStr.clear();

        std::cout << terminalformatting::FormTypes::clear;

        selScr.select();
    } else if(searchEntryStr != MiscOptions::goBack) {
        Option::opt4();
    }
}

//4. search the database
void Option::opt4() {
    std::ifstream ifDb("src/db.txt");

    std::vector<std::string> searchVec = {};

    while(std::getline(ifDb, glStr)) {
        searchVec.push_back(glStr);
        std::sort(searchVec.begin(), searchVec.end());
    }

    if(std::binary_search(searchVec.begin(), searchVec.end(), this->searchEntryStr)) {
        std::cout << terminalformatting::FormTypes::clear; 

        std::cout << "Entry found: " << searchEntryStr << '\n';

        //check if element at index of vector is equal to input
        //then output the index of the input within the sorted vector
        for(std::vector<std::string>::size_type i = 0; i < searchVec.size(); i++) {
            if(searchVec[i] == searchEntryStr) {
                std::cout << "At index (sorted vector): " << i << '\n';
            }
        }
    } else if(!std::binary_search(searchVec.begin(), searchVec.end(), this->searchEntryStr)) {
        std::cout << terminalformatting::FormTypes::clear;

        std::cout << searchEntryStr << MiscOptions::optionsNotFoundStr << '\n';

        CheckGuard cg;
        
        cg.checkOpt4();
    }

    ifDb.close();

    deleteEntryStr.clear();

    CheckGuard cg;

    cg.checkOpt4();
}

//7. exit the database
void Option::opt7() {
    std::cout << terminalformatting::FormTypes::clear;

    exit(0);
}