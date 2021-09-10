#include "encrypt.h"


Cipher* makeCipher(int argc, char** argv){
    Cipher* cipher = NULL;
    try{
        cipher = Cipher::createCipherFromArgs(argc, argv);
    } catch (CipherException e){
        // TODO catch
    }
    return cipher;
}

int main(int argc, char** argv){

    printf("[Dan Butcher Programming Assignment 1]\n[CS356]\n");
    Cipher* cipher = makeCipher(argc, argv);
    cipher->runCipher();
    
}