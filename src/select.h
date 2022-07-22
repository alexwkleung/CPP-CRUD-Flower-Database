#ifndef SELECT_H
#define SELECT_H

#include <string>

struct miscSelect {
    public:
        static inline const std::string goBack = "_back";
    
        static inline const std::string selectInvalidStr = "Invalid input. Try again.";
};

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
        std::string selectErrorStr{};

    protected: 
        std::string breakLine{};
        
    public:
        void select();
};

#endif 