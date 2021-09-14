// encrypt.h

#pragma once
#include "exception.h"
#include "utilities.h"
#include <cstdio> //FILE
#include <string> //string
#include <bitset> //bitset class

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
        
};

class BlockCipher:public Cipher{
    public:
        BlockCipher();
        ~BlockCipher();
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    protected:
        
        
    private:
        void getBlockWithPadding(FILE* inputFile, const int &BLOCK_SIZE_BYTES, char* workBlock, bool &endOfFile);
        void encryptBlock(char* workBlock, const int BLOCK_SIZE, char* key);
        void swapBytes(char* workBlock, int const &BLOCK_SIZE_BYTES, char* key);
        void unswapBytes(char* workBlock, int const &BLOCK_SIZE_BYTES, char * key)
        void saveBlock(char* workBlock, int BLOCK_SIZE_BYTES, FILE* outputFile);
         
};

class StreamCipher:public Cipher{
    public:
        StreamCipher();
        ~StreamCipher();
        void encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);
        void decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile);

    private:
        

};

