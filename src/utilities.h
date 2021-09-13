// utilities.h

#pragma once
#include <cstdio> //FILE
#include <string> //string
#include "exception.h" //CipherException
#include <sys/stat.h> //stat

class Utilities{
    public:
        static FILE* openFile(char* filePath);
        static void closeFile(FILE* fileToClose);
        static FILE* prepFileForWrite(char* filePath);
        static int getFileSizeInBytes(FILE* file);
        static char* createCharArraySizeBytes(int size);
        static void allocateBufferSizeOfFilePadded(FILE* file, char* outputBuffer, int pad);
};

