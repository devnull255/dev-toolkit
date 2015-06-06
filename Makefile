#makefile for datagenerator
BDIR = bin
LDIR = libdg
LIBS = -ldg
OBJECTS = randint.o
TEST_PROGS = tests/test_randint
SRC = src
INC = $(SRC)/include
CC = cc
CFLAGS = -Wall -I$(INC)

all: $(OBJECTS)
	mkdir -p $(BDIR)
	mkdir -p $(LDIR)
	gcc -o $(BDIR)/dg -I$(INC) $(LDIR)/randint.o  $(SRC)/dg/dg.c 


randint.o:
	gcc -c $(SRC)/$(LDIR)/randint.c -I$(INC) -o $(LDIR)/randint.o


alltests: $(OBJECTS) $(TEST_PROGS)
	$(CC) $(CFLAGS) -o tests/test_randint $(LDIR)/randint.o $(SRC)/tests/test_randint.c
	tests/test_funcs.sh

clean:
	rm -rf $(LDIR)
	rm -rf $(BDIR)
	find . -name '*.o' -exec rm -rf "{}" \;
