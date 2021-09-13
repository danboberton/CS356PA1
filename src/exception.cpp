// Exception.cpp

#include "exception.h"

void CipherException::printExecption(std::string context){
    
    printf("[Exception]\n%s\nPassed value was: %s%d\nAbort", context.c_str(), value.c_str(), valueInt);

}