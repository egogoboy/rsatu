#include "TPerson.h"


class TStudent : public TPerson {
    
    public:

        TStudent(std::string n, std::string f, std::string o, std::string g, std::string c): TPerson{f, n, o} {
            group = g;
            course = c;
        }

        std::string getFullData() override {
            return TPerson::getFullData() + " " + group + " " + course;
        }
    
    private:
        std::string group, course;
};
