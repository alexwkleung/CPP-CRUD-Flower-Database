#include "options.h"
#include <iostream>
#include <fstream>
#include <vector>

/*
** implement:

* add checking to see if strings exist in the database or not 
* string (getline) --> push into vector --> sort vector --> binary search check --> ...
*/

void option1::opt1() {
    //file output stream (open db.txt into buffer)
    //set output to be appended to the end of file (db.txt)
    std::ofstream db("src/db.txt", std::ios::app);
    
    std::cin >> this->addEntryStr;

    //write the input to file
    db << addEntryStr << '\n';

    //close buffer
    db.close(); 
}