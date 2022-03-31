Target = alg
CC = g++

CFLAGS := -Wall -O0 -m64 -g

CPP := $(shell echo src/*.cpp src/sort/*.cpp)
OBJ := $(patsubst %.cpp, %.o, $(CPP))

$(Target) : $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@

clean :
	rm -f $(OBJ)
	rm -f $(Target)	
