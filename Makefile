# Makefile for 356PA1

COMPILER=gcc
CFLAGS=-I.
FILES=
SRC=/src

build: ${patsubst %,${SRC}/}

clean:

package: