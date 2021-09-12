#include "encrypt.h"
#include "exception.h"


/*
Arg Order:
1 - Block or Stream (B, S)
2 - Input File Name
3 - Output File name
4 - keyfile
5 - Mode of Operation (E, D)
*/
Cipher* Cipher::createCipherFromArgs(int argc, char** argv) {
    printf("Building cipher...\n");

    char typeChar;
    
    if (argc != 6) throw CipherException(argc, "Invalid Number of Arguments, should be 5.");

    typeChar = tolower(argv[6][0]);
    switch (typeChar){
        case 'b':

            break;
    }

}

void Cipher::setMode(char* cipherDirection) {
    char modeFlag = tolower(cipherDirection[0]);
    switch (modeFlag){
        case 'e':
            this->cipherMode = encrypt;
            break;
        case 'd':
            this->cipherMode = decrypt;
            break;
        default:
            throw CipherException(modeFlag, "Invalid encryption mode. Must be E or D.");
    }
}