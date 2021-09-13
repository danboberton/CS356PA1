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
        virtual ~Cipher() {};
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        virtual void setMode(char* cipherDirection);
        virtual void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;
        virtual void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;


    private:

    protected:
        mode cipherMode;
        int cipherID;
        char* getKey(int keySizeInBytes, FILE* keyFile);
        void encryptBlock(int* position, const int BLOCK_SIZE, char* key, char* outputArray);
        
};

class BlockCipher:public Cipher{
    public:
        BlockCipher();
        ~BlockCipher();
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    protected:
        
        
    private:
        
        
        
};

class StreamCipher:public Cipher{
    public:
        StreamCipher();
        ~StreamCipher();
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    private:
        

};

