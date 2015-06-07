#makefile for datagenerator
BDIR = bin
LDIR = lib
LIBS = -ldg
OBJECTS = $(LDIR)/randint.o $(LDIR)/randchar.o $(LDIR)/mkalpha.o $(LDIR)/mknumeric.o\
	$(LDIR)/mkalphanum.o
TEST_PROGS = tests/test_randint tests/test_randchar tests/test_mkalpha tests/test_mknumeric tests/test_mkalphanum
SRC = src
INC = $(SRC)/include
CC = cc
CFLAGS = -Wall -I$(INC)

all: $(OBJECTS) test_programs
	mkdir -p $(BDIR)
	gcc -o $(BDIR)/dg -I$(INC) $(LDIR)/randint.o  $(SRC)/$(BDIR)/dg.c 


$(LDIR)/randchar.o: $(SRC)/$(LDIR)/randchar.c
	mkdir -p $(LDIR)
	gcc -c $(SRC)/$(LDIR)/randchar.c -I$(INC) -o $(LDIR)/randchar.o  

$(LDIR)/randint.o: $(SRC)/$(LDIR)/randint.c
	mkdir -p $(LDIR)
	gcc -c $(SRC)/$(LDIR)/randint.c -I$(INC) -o $(LDIR)/randint.o

$(LDIR)/mkalpha.o: $(SRC)/$(LDIR)/mkalpha.c
	gcc -c $(SRC)/$(LDIR)/mkalpha.c -I$(INC) -o $(LDIR)/mkalpha.o
	
$(LDIR)/mknumeric.o: $(SRC)/$(LDIR)/mknumeric.c
	gcc -c $(SRC)/$(LDIR)/mknumeric.c -I$(INC) -o $(LDIR)/mknumeric.o
	
$(LDIR)/mkalphanum.o: $(SRC)/$(LDIR)/mkalphanum.c
	gcc -c $(SRC)/$(LDIR)/mkalphanum.c -I$(INC) -o $(LDIR)/mkalphanum.o
	
test_programs: $(OBJECTS)
	$(CC) $(CFLAGS) -o tests/test_randint $(LDIR)/randint.o $(SRC)/tests/test_randint.c
	$(CC) $(CFLAGS) -o tests/test_randchar $(LDIR)/randint.o $(LDIR)/randchar.o $(SRC)/tests/test_randchar.c
	$(CC) $(CFLAGS) -o tests/test_mkalpha $(LDIR)/randint.o $(LDIR)/mkalpha.o $(LDIR)/randchar.o $(SRC)/tests/test_mkalpha.c
	$(CC) $(CFLAGS) -o tests/test_mknumeric $(LDIR)/randint.o $(LDIR)/mknumeric.o $(SRC)/tests/test_mknumeric.c
	$(CC) $(CFLAGS) -o tests/test_mkalphanum $(LDIR)/randint.o $(LDIR)/randchar.o $(LDIR)/mkalphanum.o  $(SRC)/tests/test_mkalphanum.c

alltests: 
	tests/test_funcs.sh

clean:
	rm $(TEST_PROGS)
	rm -rf $(LDIR)
	rm -rf $(BDIR)
	find . -name '*.o' -exec rm -rf "{}" \;
