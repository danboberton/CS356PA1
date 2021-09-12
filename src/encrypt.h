# pragma once
#include <cstdio> //FILE
#include <string> //string

enum cipher{block, stream};
enum mode{encrypt, decrypt};

class Cipher{
    public:
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual void runCipher();


    private:
        std::string clearText;
        std::string cipherText;
        virtual std::string encrypt(FILE*) = 0;
        virtual std::string decrypt(FILE*) = 0;

};

class BlockCipher:public Cipher{
    public:
        // Constructors, Destructors
        BlockCipher();
        ~BlockCipher();

    private:

};

class StreamCipher:public Cipher{
    public:
        // Constructors, Destructors
        StreamCipher();
        ~StreamCipher();

    private:
};

class CipherException{
    public:

        //Constructors
        CipherException(std::string key, std::string value);
};