// encrypt.h

#pragma once
#include "exception.h"
#include "utilities.h"
#include <cstdio> //FILE
#include <string> //string

enum mode{modeEncrypt, modeDecrypt};

class Cipher{
    public:
        Cipher();
        virtual ~Cipher();
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;
        virtual void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;
        virtual void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        virtual void setMode(char* cipherDirection);

    private:

    protected:
        mode cipherMode;
        int cipherID;
        char* getKey(int keySizeInBytes, FILE* keyFile);
        void encryptBlock(int* position, const int BLOCK_SIZE, char* key, char* outputArray);

};

class BlockCipher:public Cipher::Cipher{
    public:
        BlockCipher();
        virtual ~BlockCipher();
        void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    private:
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        
        
};

class StreamCipher:public Cipher::Cipher{
    public:
        StreamCipher();
        ~StreamCipher();
        void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    private:
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);

};

