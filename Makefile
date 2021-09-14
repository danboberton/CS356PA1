# Makefile for 356PA1
# Dan Butcher


FILES = encrypt.cpp exception.cpp utilities.cpp main.cpp
HEADER_FILES = encrypt.h exception.h utilities.h
TARGET = DanB_356PA1
SRC_FOLDER=src/
OBJECTS_FOLDER=obj/
COMPILE = g++
CFLAGS = -I${SRC_FOLDER}
INCLUDE_CPP_STDLIB = -lstdc++

SOURCE_FILES = $(patsubst %, $(SRC_FOLDER)%, $(FILES))
MAKE_OBJECTS = $(patsubst %.cpp, %.o, $(FILES)) 
OBJECTS = $(patsubst %,$(OBJECTS_FOLDER)%,$(MAKE_OBJECTS))
HEADERS = $(patsubst %, $(SRC_FOLDER)%, $(HEADER_FILES))

$(OBJECTS_FOLDER)%.o: $(SRC_FOLDER)%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(COMPILE) -c -g $< -o $@

build: $(OBJECTS)
	$(COMPILE) -g -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -f $(OBJECTS_FOLDER)*.o
	rm $(TARGET)

package:

testMake:
	echo Source: $(SOURCE_FILES)
	echo Objects: $(OBJECTS)
	echo Headers: $(HEADERS)
