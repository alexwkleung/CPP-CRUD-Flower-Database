#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

struct miscOpts {
    static inline std::string goBack = "_back";
    
    std::string optionsInvalidStr{};
};

class option1 {
    private:
        std::string addEntryStr{};
        std::string inputGl{};

    public:
        void opt1();

        /*
        void opt2();

        void opt3();

        void opt3();

        void opt5();
        */
};

#endif