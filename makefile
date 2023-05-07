CXX = g++
CXXFLAGS = -std=c++20 -march=native -O3
INSTALL_PATH = "./"

SRC_FILES = main.cpp addFunctions.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
BIN_FILES = main

.PHONY: all clean install

all: $(BIN_FILES)

$(BIN_FILES): %: %.o addFunctions.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: all
	install $(BIN_FILES) $(INSTALL_PATH)

test:
	g++ -std=c++20 -Iincludes -o tests test.cpp && ./tests

clean:
	rm -f $(BIN_FILES) $(OBJ_FILES) vargsai.txt saunuoliai.txt tests

cleanf:
	rm -f $(BIN_FILES) $(OBJ_FILES)

cleanres:
	rm vargsai.txt saunuoliai.txt

txt:
	rm *.txt