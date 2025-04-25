#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

class MyException {
    public:
        MyException(std::string message) {
            message_ = message;
        }
        
        std::string getMessage() {
            return message_;
        }

    private:
        std::string message_;
};

#endif // MYEXCEPTION_H
