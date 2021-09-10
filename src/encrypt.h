# pragma once
#include <cstdio> //FILE
#include <string> //string

enum cipher{block, stream};
enum mode{encrypt, decrypt};

class Cipher{
    public:
        static Cipher* createCipherFromArgs(int argc, char** argv);
        virtual string encrypt(FILE*) = 0;
        virtual string decrypt(FILE*) = 0;
        virtual void runCipher();

    private:
        string clearText;
        string cipherText;
        void writeFile(string file) throw(CipherException);
        string readFile(FILE*) throw(CipherException);

};

class BlockCipher:public Cipher{

};

class StreamCipher:public Cipher{

};

class CipherException{
    public:

        //Constructors
        CipherException(string key, string value);
};