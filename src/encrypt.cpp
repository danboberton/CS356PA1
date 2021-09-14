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
Cipher::Cipher(){

}

// Cipher::~Cipher(){
//     NULL;
// }

BlockCipher::BlockCipher(){
};

BlockCipher::~BlockCipher(){

}

StreamCipher::StreamCipher(){

};

StreamCipher::~StreamCipher(){

}

void Cipher::runCipher(FILE* inputFile, FILE* outputFile, FILE* keyFile){
    
    try{
        switch (this->cipherMode){
        case modeEncrypt:
            this->encrypt(inputFile, outputFile, keyFile);
            break;
        case modeDecrypt:
            this->decrypt(inputFile, outputFile, keyFile);
        }   
    } catch(CipherException e){
        throw;
    }
    
        
}

Cipher* Cipher::createCipherFromArgs(int argc, char** argv) {
    printf("[Building cipher...]\n");

    char typeChar;
    char switchType = argv[1][0];
    
    if (argc != 6) throw CipherException(argc, "Invalid Number of Arguments, should be 5.");

    typeChar = tolower(switchType);
    switch (typeChar){
        case 'b':
            return new BlockCipher();
            break;
        case 's':
            return new StreamCipher();
            break;
        default:
           throw CipherException(typeChar, "Cipher type should be either (B) block or (S) stream.");
    }

}

void Cipher::setMode(char* cipherDirection) {
    char modeFlag = tolower(cipherDirection[0]);
    switch (modeFlag){
        case 'e':
            this->cipherMode = modeEncrypt;
            break;
        case 'd':
            this->cipherMode = modeDecrypt;
            break;
        default:
            throw CipherException(modeFlag, "Invalid encryption mode. Must be E or D.");
    }
}

void BlockCipher::encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){
    const int BLOCK_SIZE_BYTES = 16;
    int sourceFileSize = 0;
    char* writeBuffer;
    int bytesToProcess;
    int processIndex = 0;
    char* key = Cipher::getKey(16, keyFile);

    try{

        Utilities::allocateBufferSizeOfFilePadded(inputFile, writeBuffer, BLOCK_SIZE_BYTES);
        bytesToProcess = sizeof(writeBuffer);


        while(processIndex < bytesToProcess){
            encryptBlock(&processIndex, BLOCK_SIZE_BYTES, key, writeBuffer);
        }

    } catch(...){
        throw new CipherException("blockCipher Encryption", "Error in BlockCipher::encrypt");
    }

    // save file
    free(writeBuffer);
}

void BlockCipher::decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){

}

char* Cipher::getKey(int sizeInBytes, FILE* keyFile){
    char* key = new char[sizeInBytes];
    int c;
    size_t keySizeCounter = 0;

    try{
        while(keySizeCounter < sizeInBytes && c != EOF){
            c = fgetc(keyFile);
            key[keySizeCounter] = c;
            keySizeCounter++;
        }
        if (c == EOF) throw new CipherException(keySizeCounter, "Key too short.");
    } catch(...){
        throw new CipherException(keySizeCounter, "Error getting key.");
    }
    return key;
}

void Cipher::encryptBlock(int* position, const int BLOCK_SIZE, char* key, char* outputArray){
    char* keyBuffer = key; 

    for (int i = 0; i < BLOCK_SIZE; i++){
        // TODO stuck here
        // outputArray[*position] = encryptByte();
    }
}

void StreamCipher::encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){
    
}

void StreamCipher::decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){

}