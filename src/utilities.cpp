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
void Utilities::allocateBufferSizeOfFilePadded(FILE* file, char* outputBuffer, int padBytes){

    int originFileSizeBytes = Utilities::getFileSizeInBytes(file);
    int amountToPad = padBytes - (originFileSizeBytes % padBytes);

    outputBuffer = (char*)malloc(sizeof(char) * (originFileSizeBytes + amountToPad));
    
}


void Utilities::closeFile(FILE* fileToClose){
    fclose(fileToClose);
}

void Utilities::printArgs(int argc, char** argv){
    printf("%d arguments.\n", argc);
    for (int i = 0; i < (argc); i++){
        printf("Arg %d: %s\n",i , argv[i]);
    };
}

std::bitset<8> Utilities::getBinaryByteArrayFromInt(int byte){
    return std::bitset<8>(byte);
}

std::bitset<128> Utilities::getBitsetFromChars(char* string, int blockSize){

    std::bitset<8> bitsetBuffer;
    std::bitset<128> resultBuffer;

    for(size_t i = 0; i < blockSize; i++){
        bitsetBuffer = getBinaryByteArrayFromInt((int)*(string + i));

        for (size_t k = 0; k < 8; k++){
            resultBuffer[(i*8)+k] = bitsetBuffer[k];
        }
    }

    return resultBuffer;
}

char Utilities::getCharFromBinaryByte(std::bitset<8> binary){
    ulong longInt = binary.to_ulong();
    int regInt = (int)longInt;
    return (char)regInt;
}