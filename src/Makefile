# Makefile to build driver program
# --- macros
CC=g++
CFLAGS=  -Wall -g
TEST_OBJ= String.o TestString.o
#
#
# # --- targets

str:   $(TEST_OBJ) 
	$(CC)  -o str  $(TEST_OBJ) 

TestString.o: TestString.cpp
	$(CC) $(CFLAGS) -c TestString.cpp

String.o: String.cpp
	$(CC) $(CFLAGS) -c String.cpp

# --- remove binary and executable files
clean:
	rm -f str $(TEST_OBJ) 
