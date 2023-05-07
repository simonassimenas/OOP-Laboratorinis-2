CXX = g++
CXXFLAGS = -std=c++20 -march=native -O3
INSTALL_PATH = "./"

SRC_FILES = main.cpp functions.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
BIN_FILES = main

.PHONY: all clean install

all: $(BIN_FILES)

$(BIN_FILES): %: %.o functions.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: all
	install $(BIN_FILES) $(INSTALL_PATH)

clean:
	rm -f $(BIN_FILES) $(OBJ_FILES) vargsai.txt saunuoliai.txt tests

cleanf:
	rm -f $(BIN_FILES) $(OBJ_FILES)

cleanres:
	rm vargsai.txt saunuoliai.txt

txt:
	rm *.txt

test: Test/tests
	./Test/tests
	rm -f Test/tests

Test/tests:
	cd Test && g++ -std=c++20 -I../includes -o tests test.cpp