// exception.h

#pragma once
#include <string>
#include <exception>


class CipherException:public std::exception{
    public:
        CipherException(std::string value, std::string error);
        CipherException(int valueInt, std::string error);
        void printExecption(std::string context);

    private:
        std::string value;
        int valueInt;
        std::string error;
};
