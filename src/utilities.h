// utilities.h

#pragma once
#include <cstdio> //FILE
#include <string> //string

class Utilities{
    public:
        static FILE* openFile(char* filePath);
        static void closeFile(FILE* fileToClose);
};

class UtilityException{
    public:
        UtilityException(std::string value, std::string error);
        
};