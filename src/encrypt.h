# pragma once
#include <cstdio> //FILE
#include <string> //string

enum mode{encrypt, decrypt};

class Cipher{
    public:
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual std::string encrypt(FILE*) = 0;
        virtual std::string decrypt(FILE*) = 0;
        virtual void runCipher();

    private:
        mode cipherMode;
        std::string clearText;
        std::string cipherText;
        FILE* inputFile;
        FILE* outputFile;

};

class BlockCipher:public Cipher{

};

class StreamCipher:public Cipher{

};

class CipherException{
    public:

        //Constructors
        CipherException(std::string value, std::string error);
        CipherException(int value, std::string error);
};