
# code details

EXE = ./bin/voteCount
SRC= main.c checks.c voteCount.c 

# generic build details

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK= 

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

voteCount.o: voteCount.c voteCount.h
checks.o: checks.c checks.h 
main.o:	main.c checks.h voteCount.h

