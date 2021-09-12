// utilities.h

#pragma once
#include <cstdio> //FILE
#include <string> //string

class UtililityException{
    public:
        UtililityException(std::string key, std::string value);

};

class Utilities{
    public:
        static FILE* openFile(char* fileName);
        static void closeFile(FILE* file);

    private:
};
