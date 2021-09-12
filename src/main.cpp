#include "encrypt.h"
#include "utilities.h"



int main(int argc, char** argv){

    printf("[Dan Butcher Programming Assignment 1]\n[CS356]\n");
    try {
        Cipher* cipher = Cipher::createCipherFromArgs(argc, argv);
        FILE* inputFile = Utilities::openFile();
        FILE* outputFile = Utilities::openFile();
        FILE* keyFile = Utilities::openFile();
    } catch(UtilityException, CipherException)
    
    
    
}