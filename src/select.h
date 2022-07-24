#ifndef SELECT_H
#define SELECT_H

#include <string>

struct MiscSelect {
    public:
        static inline const std::string goBack = "_back";
    
        static inline const std::string selectInvalidStr = "Invalid input. Try again.";
};

class SelectScr {
    private:
        std::string selectTitle{};
        std::string inputSelectStr{};
        std::string addAnEntry{};
        std::string updateAnEntry{};
        std::string deleteAnEntry{};
        std::string searchTheDB{};
        std::string showAllEntries{};
        std::string showCommands{};
        std::string exitDB{};
        std::string selectErrorStr{};
        std::string breakLine{};
        
    public:
        void select();
};

#endif 