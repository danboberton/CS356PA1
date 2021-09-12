# Makefile for 356PA1
# Dan Butcher


FILES = encrypt.cpp exception.cpp utilities.cpp main.cpp
HEADER_FILES = encrypt.h exception.h utilities.h
SRC_FOLDER=src/
OBJECTS_FOLDER=obj/
COMPILE = gcc
CFLAGS = -I${SRC_FOLDER}

SOURCE_FILES = $(patsubst %, $(SRC_FOLDER)%, $(FILES))
MAKE_OBJECTS = $(patsubst %.cpp, %.o, $(FILES)) 
OBJECTS = $(patsubst %,$(OBJECTS_FOLDER)%,$(MAKE_OBJECTS))
HEADERS = $(patsubst %, $(SRC_FOLDER)%, $(HEADER_FILES))

$(OBJECTS): $(SRC_FOLDER)*.cpp $(HEADERS)
	$(COMPILE) -c $< -o $@

build: $(OBJECTS)
	$(COMPILE) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJECTS_FOLDER)*.o

package:

testMake:
	echo Source: $(SOURCE_FILES)
	echo Objects: $(OBJECTS)
	echo Headers: $(HEADERS)
