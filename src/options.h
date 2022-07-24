#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

struct MiscOptions {
    public:
        static inline const std::string goBack = "_back";
    
        static inline const std::string optionsInvalidStr = "Invalid input. Try again.";

        static inline const std::string optionsNotFoundStr = " not found in the database. Try again.";
};

class Option {
    protected:
        //add entry
        std::string addEntryStr{};
        
        //getline str
        std::string glStr{};

        //update entry
        std::string entryForUpdateStr{};
        std::string updatedEntryStr{};

        //delete entry
        std::string deleteEntryStr{};
        
        //search entry
        std::string searchEntryStr{};

        //show all entries
        std::string showAllEntriesStr{};

        //help commands
        std::string helpCommandsStr{};

    public:
        void opt1();

        void opt2();

        void opt3();

        void opt4();

        void opt5();

        void opt6();

        void opt7();
};

class CheckGuard : public Option {
    private:
        //getline str
        std::string glStr{};

    public:
        void checkOpt1();

        void checkOpt2();

        void checkOpt3();

        void checkOpt4();

        void checkOpt5();
};

#endif