// Exception.cpp

#include "exception.h"
CipherException::CipherException(std::string value, std::string error){

}

CipherException::CipherException(int valueInt, std::string error){
    
}

void CipherException::printExecption(std::string context){
    
    printf("[Exception]\n%s\nPassed value was: %s%d\nAbort", context.c_str(), value.c_str(), valueInt);

}