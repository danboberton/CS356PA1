// encrypt.h

#pragma once
#include <cstdio> //FILE
#include <string> //string

enum mode{encrypt, decrypt};

class Cipher{
    public:
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual std::string encrypt(FILE*) = 0;
        virtual std::string decrypt(FILE*) = 0;
        virtual void runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile) = 0;
        virtual void setMode(char* cipherDirection);


    private:
        mode cipherMode;
        std::string clearText;
        std::string cipherText;
      

};

class BlockCipher:public Cipher{

};

class StreamCipher:public Cipher{

};

