#ifndef SELECT_H
#define SELECT_H

#include <string>

class selectScr {
    private:
        std::string selectTitle{};
        std::string inputSelectStr{};
        std::string selectFooStr{};
        std::string addAnEntry{};
        std::string updateAnEntry{};
        std::string deleteAnEntry{};
        std::string searchTheDB{};
        std::string showAllEntries{};
        std::string exitDB{};

    protected: 
        std::string breakLine{};
        
    public:
        void select();
};

#endif 