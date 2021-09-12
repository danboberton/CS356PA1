// Exception.cpp

#include "exception.h"

void CipherException::printExecption(std::string context){
    if(this->valueInt != NULL){
        this->value = std::to_string(valueInt);
    };
    printf("[Exception]\n%s\n%s\nPassed value was: %s\nAbort", context, value);
}