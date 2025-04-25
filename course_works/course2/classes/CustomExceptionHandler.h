#pragma once

#include <stdexcept>

class FileOpeningException : public std::runtime_error {

    using std::runtime_error::runtime_error;

};

class UnknownUserChooseException : public std::runtime_error {

    using std::runtime_error::runtime_error;

};

class IncorrectInputDataException : public std::runtime_error {

    using std::runtime_error::runtime_error;

};
