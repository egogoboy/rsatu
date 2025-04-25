#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>

class ProcessUserAction {

    public:
        static std::string getInputFile();
        static std::string getUserAction();
        
        static inline const std::string PRINT_ALL_ANAGRAMS = "print all anagrams";
        static inline const std::string PRINT_NON_ANAGRAMS = "print non anagrams";
        static inline const std::string FIND_ANAGRAMS = "find anagrams";
        static inline const std::string GET_NEW_TEXT = "get new text";
        static inline const std::string CLOSE_PROGRAM = "close program";

    private:

        static inline const std::string FROM_DEFAULT_FILE = "from default file";
        static inline const std::string FROM_CUSTOM_FILE = "from custom file";
        static inline const std::string FROM_CONSOLE = "from console";
        static inline const std::string FROM_TESTS = "from tests";

        static inline const std::string DEFAULT_FILE_NAME = "input_files/default.txt";
        static inline const std::string TESTS_FILE_NAME = "input_files/tests.txt";
        static inline const std::string CONSOLE_FILE_NAME = "input_files/console.txt";
        
        static inline const std::string CUSTOM_FILE_NAME = "custom filename";
        static inline const std::string UNKNOWN_CHOOSE = "unknown choose";
        
        static std::string processUserActionChoose(const std::string& choose);

        static std::string getUserChooseOfInputStream();
        static std::string processUserInputStreamChoose(const std::string& choose);

        static std::string getDataFromConsole();
        static std::string getCustomFileName();
};
