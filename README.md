# CS356PA1
## Block and stream cipher assignment
DanB_356PA1 is a program that ciphers and de-ciphers ASCII characters to and from a text file.
There are 2 flavors of cipher here, Block: with encrypts 8 bits at a time, Stream: performs a encryption on each bit.
This version of a classic XOR and swap program has the unique feature of running it's swap routine per block. I was unclear is that was correct, or if it should swap the entire file.


##ARGUMENTS - This program takes 5 arguments.
DanB_356PA1 [arg1] [arg2] [arg3] [arg4] [arg5]
    [arg1] - (B) Block or (S) Stream encoding
    [arg2] - input file. A plain text ASCII file to be enctypted or decrypted
    [arg3] - output file. A ciphered ASCII file output
    [arg4] - keyfile. A 16Byte ASCII string to be used as a cipher key for encrypt or decrypt
    [arg5] - (E) Encrypt or (D) decrypt.

##Files
    Makefile - standard make file with testing, building, and running scripts.
        make build: creates the executable DanB_356PA1
        make clean: Cleans object files and executable
    main.cpp - Entry point for the program, creates polymorphic cipher object, loads files.
    encrypt.cpp - The heavy lifting in the program, BlockCipher and StreamCipher inherrit from Cipher parent class. Main methods are encrypt() and decrypt()
    encrypt.h - Header file for Cipher,  BlockCipher, StreamCipher classes containted within encrypt.cpp
    utilities.cpp - A collection of static helper methods for opening and closing files, converting characters to bitstreams, etc.
    utilities.h - Header file for utilities class.
    exception.cpp - playing with custom exceptions to deal with non-valid input. This program may will throw CipherException if any issues arise.
    exception.h - Header file for exception class.
