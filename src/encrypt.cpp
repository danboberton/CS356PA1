#include "encrypt.h"


/*
Arg Order:
1 - Block or Stream (B, S)
2 - Input File Name
3 - Output File name
4 - keyfile
5 - Mode of Operation (E, D)
*/
Cipher* Cipher::createCipherFromArgs(int argc, char** argv) throw (CipherException){
    printf("Building cipher...\n");

    char typeChar;
    
    if (argc != 6) throw CipherException(argc, "Invalid Number of Arguments, should be 5.");

    typeChar = tolower(argv[6][0]);
    switch (typeChar){
        case 'b':

            break;
    }

}

void runCipher() throw(CipherException){

}