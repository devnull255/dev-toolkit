#makefile for datagenerator
BDIR = bin
LDIR = lib
LIBS = -ldevtools
OBJECTS = $(LDIR)/randint.o $(LDIR)/randchar.o $(LDIR)/mkalpha.o $(LDIR)/mknumeric.o\
	$(LDIR)/mkalphanum.o $(LDIR)/split.o $(LDIR)/strllen.o $(LDIR)/inlist.o $(LDIR)/join.o $(LDIR)/randomstring.o $(LDIR)/hashtable.o
TEST_PROGS = tests/test_randint tests/test_randchar tests/test_mkalpha tests/test_mknumeric tests/test_mkalphanum tests/test_split tests/test_strllen tests/test_inlist tests/test_join tests/test_randomstring tests/test_hashtable
SRC = src
INC = $(SRC)/include
CC = cc
CFLAGS = -Wall -I$(INC)

all: libdevtool
	$(CC) -o $(BDIR)/dg -I$(INC) $(SRC)/$(BDIR)/dg.c -L$(LDIR) $(LIBS) 

libdevtool: $(OBJECTS)
	mkdir -p $(LDIR)
	ar crs $(LDIR)/libdevtools.a $(OBJECTS)

$(LDIR)/randchar.o: $(SRC)/$(LDIR)/randchar.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/randchar.c -I$(INC) -o $(LDIR)/randchar.o  

$(LDIR)/randint.o: $(SRC)/$(LDIR)/randint.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/randint.c -I$(INC) -o $(LDIR)/randint.o

$(LDIR)/mkalpha.o: $(SRC)/$(LDIR)/mkalpha.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/mkalpha.c -I$(INC) -o $(LDIR)/mkalpha.o
	
$(LDIR)/mknumeric.o: $(SRC)/$(LDIR)/mknumeric.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/mknumeric.c -I$(INC) -o $(LDIR)/mknumeric.o
	
$(LDIR)/mkalphanum.o: $(SRC)/$(LDIR)/mkalphanum.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/mkalphanum.c -I$(INC) -o $(LDIR)/mkalphanum.o

$(LDIR)/split.o: $(SRC)/$(LDIR)/split.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/split.c -I$(INC) -o $(LDIR)/split.o

$(LDIR)/strllen.o: $(SRC)/$(LDIR)/strllen.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/strllen.c -I$(INC) -o $(LDIR)/strllen.o

$(LDIR)/inlist.o: $(SRC)/$(LDIR)/inlist.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/inlist.c -I$(INC) -o $(LDIR)/inlist.o

$(LDIR)/join.o: $(SRC)/$(LDIR)/join.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/join.c -I$(INC) -o $(LDIR)/join.o

$(LDIR)/randomstring.o: $(SRC)/$(LDIR)/randomstring.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/randomstring.c -I$(INC) -o $(LDIR)/randomstring.o

$(LDIR)/hashtable.o: $(SRC)/$(LDIR)/hashtable.c
	mkdir -p $(LDIR)
	$(CC) -c $(SRC)/$(LDIR)/hashtable.c -I$(INC) -o $(LDIR)/hashtable.o

test_programs: $(OBJECTS)
	$(CC) $(CFLAGS) -o tests/test_randint $(SRC)/tests/test_randint.c -L$(LDIR) $(LIBS) 
	$(CC) $(CFLAGS) -o tests/test_randchar $(SRC)/tests/test_randchar.c -L$(LDIR) $(LIBS) 
	mkdir -p $(LDIR)
	$(CC) $(CFLAGS) $(SRC)/tests/test_mkalpha.c -L$(LDIR) $(LIBS) -o tests/test_mkalpha 
	$(CC) $(CFLAGS) $(SRC)/tests/test_mknumeric.c -L$(LDIR) $(LIBS) -o tests/test_mknumeric 
	$(CC) $(CFLAGS) $(SRC)/tests/test_mkalphanum.c -L$(LDIR) $(LIBS) -o tests/test_mkalphanum 
	$(CC) $(CFLAGS) $(SRC)/tests/test_split.c -L$(LDIR) $(LIBS) -o tests/test_split 
	$(CC) $(CFLAGS) $(SRC)/tests/test_strllen.c -L$(LDIR) $(LIBS) -o tests/test_strllen
	$(CC) $(CFLAGS) $(SRC)/tests/test_inlist.c -L$(LDIR) $(LIBS) -o tests/test_inlist
	$(CC) $(CFLAGS) $(SRC)/tests/test_join.c -L$(LDIR) $(LIBS) -o tests/test_join
	$(CC) $(CFLAGS) $(SRC)/tests/test_randomstring.c -L$(LDIR) $(LIBS) -o tests/test_randomstring
	$(CC) $(CFLAGS) $(SRC)/tests/test_hashtable.c -L$(LDIR) $(LIBS) -o tests/test_hashtable

alltests: 
	tests/test_funcs.sh

clean:
	rm -f $(TEST_PROGS)
	rm -rf $(LDIR)
	find . -name '*.o' -exec rm "{}" \;	
