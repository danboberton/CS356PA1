// encrypt.h

#pragma once
#include "exception.h"
#include "utilities.h"
#include <cstdio> //FILE
#include <string> //string

enum mode{encrypt, decrypt};

class Cipher{
    public:
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;
        virtual void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;
        virtual void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        virtual void setMode(char* cipherDirection);

    private:
        mode cipherMode;

    protected:
        char* getKey(int keySizeInBytes, FILE* keyFile);
};

class BlockCipher:public Cipher{
    public:
        BlockCipher();
        void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    private:
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        
        
};

class StreamCipher:public Cipher{
    public:
        StreamCipher();
        void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    private:
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);

};

