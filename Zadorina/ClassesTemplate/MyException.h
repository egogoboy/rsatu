#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <stdexcept>
class MyException : public std::runtime_error {

    using std::runtime_error::runtime_error;

};

#endif
