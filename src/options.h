#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

struct miscOptions {
    public:
        static inline const std::string goBack = "_back";
    
        static inline const std::string optionsInvalidStr = "Invalid input. Try again.";

        static inline const std::string optionsNotFoundStr = "String not found. Try again.";
};

class option {
    private:
        //add entry
        std::string addEntryStr{};
        
        //getline str
        std::string glStr{};

        //update entry
        std::string updateEntryStr{};
        std::string deleteEntryStr{};

    public:
        void opt1();

        void opt2();

        /*
        void opt3();

        void opt3();

        void opt5();
        */
};

class check : public option {
    private:


    public:
        void checkOpt1();

};

#endif