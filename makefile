Target = alg
CC = g++

CPP := $(shell echo ./*.cpp)
OBJ := $(patsubst %.cpp, %.o, $(CPP))

$(Target) : $(OBJ)
	$(CC) $^ -o $@

clean :
	rm -f $(OBJ)
	rm -f $(Target)	
