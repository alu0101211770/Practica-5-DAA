CXX = g++
CXXFLAGS = -g -o3
LDFLAGS =

SRC = test/test.cc $(wildcard src/*.cc)
OBJ = $(SRC:.cc=.o)
EXEC = bin/polynomials

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
