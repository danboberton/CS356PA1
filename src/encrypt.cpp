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
    char workBlock[BLOCK_SIZE_BYTES];
    char* key = Cipher::getKey(16, keyFile);
    bool endOfFile = false;

    try{
        while(!endOfFile){
            getBlockWithPadding(inputFile, BLOCK_SIZE_BYTES, workBlock, endOfFile);
            encryptBlock(workBlock, BLOCK_SIZE_BYTES, key);
            swapBytes(workBlock, BLOCK_SIZE_BYTES, key);
            saveBlock(workBlock, BLOCK_SIZE_BYTES, outputFile);
        }
        
    } catch(CipherException){
        throw;
    } 
    catch(...){
        throw CipherException("blockCipher Encryption", "Error in BlockCipher::encrypt");
    }
    delete[] key;
}

void BlockCipher::decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){
    const int BLOCK_SIZE_BYTES = 16;
    char workBlock[BLOCK_SIZE_BYTES];
    char* key = Cipher::getKey(16, keyFile);
    bool endOfFile = false;
    int saveSize = BLOCK_SIZE_BYTES;

    try{
        while(!endOfFile){
            getBlockWithPadding(inputFile, BLOCK_SIZE_BYTES, workBlock, endOfFile);
            swapBytes(workBlock, BLOCK_SIZE_BYTES, key);
            encryptBlock(workBlock, BLOCK_SIZE_BYTES, key);
            removePadding(workBlock, BLOCK_SIZE_BYTES, saveSize, endOfFile);
            saveBlock(workBlock, saveSize, outputFile);
        }
        
    } catch(CipherException){
        throw;
    } 
    catch(...){
        throw CipherException("blockCipher Decryption", "Error in BlockCipher::decrypt");
    }
    delete[] key;
}

char* Cipher::getKey(int sizeInBytes, FILE* keyFile){
    char* key = new char[sizeInBytes];
    int c = 0;
    size_t keySizeCounter = 0;

    try{
        while(keySizeCounter < sizeInBytes && c != EOF){
            c = fgetc(keyFile);
            key[keySizeCounter] = c;
            keySizeCounter++;
        }
        if (c == EOF) throw CipherException(keySizeCounter, "Key too short.");
    } catch(...){
        throw CipherException(keySizeCounter, "Error getting key.");
    }
    return key;
}

void BlockCipher::encryptBlock(char* workBlock, const int BLOCK_SIZE_BYTES, char* key){
    const size_t BLOCK_SIZE_BITS = BLOCK_SIZE_BYTES * 8;
    
    std::bitset<128> bitsetBlock = Utilities::getBitsetFromChars(workBlock, BLOCK_SIZE_BYTES);
    std::bitset<128> bitsetKey = Utilities::getBitsetFromChars(key, BLOCK_SIZE_BYTES);
    std::bitset<128> result;
    std::bitset<8> charBuffer;

    for(int i = 0; i < 128; i++){
        result[i] = bitsetBlock[i] ^ bitsetKey[i];
    }

    for(size_t i = 0; i < BLOCK_SIZE_BYTES; i++){
        for (size_t k = 0; k < 8; k++){
            charBuffer[k] = result[(i*8)+k];
        }

        *(workBlock + i) = Utilities::getCharFromBinaryByte(charBuffer);
    }
    
}

void StreamCipher::encrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){
    
}

void StreamCipher::decrypt(FILE* inputFile, FILE* outputFile, FILE* keyFile){

}

void BlockCipher::getBlockWithPadding(FILE* inputFile, const int &BLOCK_SIZE_BYTES, char* workBlock, bool &endOfFile){
    int static blockCount = 0;

    char curChar;
    for (int i = 0; i < BLOCK_SIZE_BYTES; i++){
        curChar = fgetc(inputFile);
        if (curChar == EOF){
            endOfFile = true;

            if (i == 0) {
                break; // end of file, block not necessary
                } 

            // Pad
            while(i < BLOCK_SIZE_BYTES){
                *workBlock = 0;
                i++;
                workBlock++;
            }
        } else {
            *workBlock = curChar;
            workBlock++;
        }

        
    }    
    blockCount++;
}

void BlockCipher::swapBytes(char* workBlock, int const &BLOCK_SIZE_BYTES, char* key){

    char* startPtr = workBlock;
    char* endPtr = workBlock + (BLOCK_SIZE_BYTES - 1);
    char swapBuffer;
    char* keyPtr = key;
    int keyIncrement = 0;

    while (startPtr != endPtr){
        if((*(key + keyIncrement) % 2) == 1){
            swapBuffer = *startPtr;
            *startPtr = *endPtr;
            *endPtr = swapBuffer;
            startPtr++;
            endPtr--;
            keyIncrement++;
            if (keyIncrement > (BLOCK_SIZE_BYTES - 1)) {
                keyIncrement = 0;
                }
           
        } else {
            startPtr++;
        }

    }

}

void BlockCipher::saveBlock(char* workBlock, int BLOCK_SIZE_BYTES, FILE* outputFile){

    try {
        for (int i = 0; i < BLOCK_SIZE_BYTES; i++){
            fputc(*(workBlock + i), outputFile);
        }

    } catch(...){
        throw CipherException(outputFile->_fileno, "Error saving block in BlockCipher::saveBlock");
    }
}

void BlockCipher::removePadding(char* workBlock, int BLOCK_SIZE_BITS, int &saveSize, bool &endOfFileFlag){
    int static blockCount = 0;

    for(int i = 0; i < BLOCK_SIZE_BITS; i++){
        if (*(workBlock + i) == 0){
            saveSize--;
            endOfFileFlag = true;
        }
    }

    blockCount++;
}
