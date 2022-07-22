#include "options.h"
#include "select.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

/*
** implement:

* a filter for unwanted words being present in the db
*/

void option1::opt1() {
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
    while(std::getline(ifdb, inputGl)) {
        vecGl.push_back(inputGl);
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
            option1::opt1();
        } else if(!std::binary_search(vecGl.begin(), vecGl.end(), this->addEntryStr)) {
             if(addEntryStr == miscOptions::goBack) {
                selectScr selScr;

                addEntryStr.clear();

                selScr.select();
            }
            
            //write the input to file
            db << addEntryStr << '\n';

            //close ifstream buffer
            db.close();

            std::cout << '\n' << "Added " << addEntryStr << " to the database!" << '\n';

            addEntryStr.clear();

            option1::opt1(); 
        }
    }
}