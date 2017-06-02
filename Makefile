# Yuval Hamberg
# yuval.hamberg@gmail.com
# 28/5/2017
# memManager

# File names
EXE_NAME = Mem
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
H_FILES = $(wildcard *.h)

CC = g++
CFLAGS = -g -pedantic -Wall -std=c++11

.Phony : clean rebuild run

# Main target
$(EXE_NAME): $(OBJECTS) $(H_FILES) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE_NAME) 
 
# To obtain object files
%.o: %.c $(H_FILES)
	$(CC) -c $(CFLAGS) $< -o $@

run: ${EXE_NAME}
	./${EXE_NAME} 

clean:
	rm -f *.o
	rm -f *~
	rm -f $(EXE_NAME)
	rm -f a.out

rebuild : clean $(EXE_NAME)


