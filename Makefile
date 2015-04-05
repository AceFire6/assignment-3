.SUFFIXES:
.SUFFIXES: .cpp .o

CC=g++
FLAGS=-std=c++11
SOURCES=src/HuffmanNode.cpp src/HuffmanTree.cpp src/main.cpp src/Utils.cpp
OBJECTS=$(SOURCES:.cpp=.o)

TEST_SOURCES=src/HuffmanNode.cpp src/HuffmanTree.cpp src/UnitTests.cpp src/Utils.cpp
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)

EXE_NAME=huffencode

default: $(OBJECTS)
	$(CC) $(SOURCES) -o build/$(EXE_NAME) $(FLAGS)

.cpp.o:
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f $(OBJECTS) build/$(EXE_NAME) build/*.z build/*.hdr build/Tests/test

run: default
	cd ./build && ./$(EXE_NAME) $(ARGS)

tests: $(OBJECTS)
	$(CC) $(TEST_SOURCES) -o build/Tests/test $(FLAGS)

run-tests: tests
	cd ./build/Tests && ./test
