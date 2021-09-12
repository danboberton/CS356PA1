#include "encrypt.h"
#include "utilities.h"
#include "exception.h"

int main(int argc, char** argv){

    printf("[Dan Butcher Programming Assignment 1]\n[CS356]\n");
    try {
        Cipher* cipher = Cipher::createCipherFromArgs(argc, argv);
        FILE* inputFile = Utilities::openFile(argv[2]);
        FILE* outputFile = Utilities::openFile(argv[3]);
        FILE* keyFile = Utilities::openFile(argv[4]);
        cipher->setMode(argv[5]);
    } catch(CipherException e) {
        e.printExecption();
    }

    
};