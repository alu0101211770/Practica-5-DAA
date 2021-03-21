CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g
LDFLAGS = -fsanitize=address

SRC = test/test.cc $(wildcard src/*.cc)
OBJ = $(SRC:.cc=.o)
EXEC = bin/polynomials

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
