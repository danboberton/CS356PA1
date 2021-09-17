# Makefile for 356PA1
# Dan Butcher
# HEADER and HEADERFILES variables should probably be swapped for consistency.

FILES = encrypt.cpp exception.cpp utilities.cpp main.cpp
HEADER_FILES = encrypt.h exception.h utilities.h
TARGET = DanB_356PA1
SRC_FOLDER=src/
OBJECTS_FOLDER=obj/
TEST_FOLDER=
COMPILE = g++
CFLAGS = -I${SRC_FOLDER}
INCLUDE_CPP_STDLIB = -lstdc++

#Concat
SOURCE_FILES = $(patsubst %, $(SRC_FOLDER)%, $(FILES))
MAKE_OBJECTS = $(patsubst %.cpp, %.o, $(FILES)) 
OBJECTS = $(patsubst %,$(OBJECTS_FOLDER)%,$(MAKE_OBJECTS))
HEADERS = $(patsubst %, $(SRC_FOLDER)%, $(HEADER_FILES))

# Pass Tests
TEST1_ARGS =

#Fail Tests

$(OBJECTS_FOLDER)%.o: $(SRC_FOLDER)%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(COMPILE) -c -g $< -o $@

build: $(OBJECTS)
	$(COMPILE) -g -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -f $(OBJECTS_FOLDER)*.o
	rm $(TARGET)

package:
	make build
	tar -czvf $(TARGET).tar.gz $(TARGET) $(SOURCE_FILES) $(HEADERS) Makefile README.md

testMake:
	echo Source: $(SOURCE_FILES)
	echo Objects: $(OBJECTS)
	echo Headers: $(HEADERS)

test:
	make build
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TARGET) S ./testin.txt ./StreamOut.txt key.txt E
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TARGET) S ./StreamOut.txt StreamDecrypt.txt key.txt D
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TARGET) B ./testin.txt ./newOutFile.txt key.txt E
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TARGET) B ./newOutFile.txt testinDecrypt.txt key.txt D
