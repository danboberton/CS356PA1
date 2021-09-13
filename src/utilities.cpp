// utilities.cpp

#include "utilities.h"

FILE* Utilities::openFile(char* filePath){
    FILE* fileStream;
    try{
        fileStream = fopen(filePath, "r");
    } catch (...){
        throw new CipherException(filePath, "Unable to open file.");
    }

    return fileStream;
}

FILE* Utilities::prepFileForWrite(char* filePath){

    FILE* fileStream;
    try{
        fileStream = fopen(filePath, "w");
    } catch (...){
        throw new CipherException(filePath, "Unable to prep file for write.");
    }

    return fileStream;
}

int Utilities::getFileSizeInBytes(FILE* file){
    struct stat st;
    int fileDescriptor = fileno(file);
    fstat(fileDescriptor, &st);
    return st.st_size;
}

// Creates a block of memory in the heap that is the size of the inputfile
// padded with extra space on the end
void allocateBufferSizeOfFilePadded(FILE* file, char* outputBuffer, int padBytes){

    int originFileSizeBytes = Utilities::getFileSizeInBytes(file);
    int amountToPad = padBytes - (originFileSizeBytes % padBytes);

    outputBuffer = (char*)malloc(sizeof(char) * (originFileSizeBytes + amountToPad));
    
}