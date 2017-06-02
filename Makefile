# Yuval Hamberg
# yuval.hamberg@gmail.com
# 28/5/2017
# memManager_t

# File names
EXE_NAME = Mem
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
H_FILES = $(wildcard *.h)

CC = g++
HPATH = ../../util/header
LIBPATH = 
CFLAGS = -g -ansi -pedantic -Wall -I $(HPATH)

DYN_LIB_PATH = 

.Phony : clean rebuild run


# Main target
$(EXE_NAME): $(OBJECTS) $(H_FILES) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE_NAME) 
 
# To obtain object files
%.o: %.c $(H_FILES)
	$(CC) -c $(CFLAGS) $< -o $@


run: ${EXE_NAME}
	$(DYN_LIB_PATH) ./${EXE_NAME} 

clean:
	rm -f *.o
#	rm -f object/*.o
	rm -f *~
	rm -f $(EXE_NAME)
	rm -f a.out
	#rm -f $(LIBPATH)/$(LIBSCREATE)
#	rm -f $(LIBPATH)/$(LIBNEEDED1)

rebuild : clean $(EXE_NAME)


