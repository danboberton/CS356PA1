#include "encrypt.h"
#include "utilities.h"
#include "exception.h"

int main(int argc, char** argv){
    Cipher* cipher = NULL;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    FILE* keyFile = NULL;

    printf("[Dan Butcher Programming Assignment 1]\n[CS356]\n");
    try {
        cipher = Cipher::createCipherFromArgs(argc, argv);
        inputFile = Utilities::openFile(argv[2]);
        outputFile = Utilities::prepFileForWrite(argv[3]);
        keyFile = Utilities::prepFileForWrite(argv[4]);
        cipher->setMode(argv[5]);
    } catch(CipherException e) {
        e.printExecption("Error initializing arguments.");
    }

    try{
        cipher->runCipher(inputFile, outputFile, keyFile);
    } catch (CipherException e){
        e.printExecption("Error running cipher.");
    }

    printf("Cipher successful.\n");

    Utilities::closeFile(inputFile);
    Utilities::closeFile(outputFile);
    Utilities::closeFile(keyFile);

    printf("(exit)\n");
    
};