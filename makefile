CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g -O3

SRC = test/main.cc $(wildcard src/*.cc)
SRC_T = test/test.cc $(wildcard src/*.cc)
OBJ = $(SRC:.cc=.o)
OBJ_T = $(SRC_T:.cc=.o)
EXEC = bin/polynomials
EXEC_T = bin/test_polynomials

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

test: $(EXEC_T)

$(EXEC_T): $(OBJ_T)
	$(CXX) -o $@ $(OBJ_T) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC) $(OBJ_T) $(EXEC_T)
