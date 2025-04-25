#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>
class MyException {

    public:
        MyException(std::string message): message{message}{}
        std::string getMessage() const {return message; }


    private:
        std::string message;
};

#endif // MYEXCEPTION_H
