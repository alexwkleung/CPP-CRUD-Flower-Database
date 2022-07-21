#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

struct goBack {
    std::string gb{}; 
};

class option1 {
    private:
        std::string addEntryStr{};

    public:
        void opt1();
};

#endif