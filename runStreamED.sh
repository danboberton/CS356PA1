#! /bin/zsh
make build
./DanB_356PA1 S ./testin.txt ./StreamOut.txt key.txt E
./DanB_356PA1 S ./StreamOut.txt StreamDecrypt.txt key.txt D
