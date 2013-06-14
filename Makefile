PROJNAME := torrentinfo
CC := gcc 
CFLAGS := -Wall -g -std=c99 -pedantic

sources := $(wildcard *.c)
objects := ${sources:.c=.o}


%.o: %.c
	@echo "CC $*.c -> $@"
	@$(CC) $(CFLAGS) -o $@ -c $*.c

$(PROJNAME) : $(objects)
	@echo "LD $< -> $@"
	@$(CC) $(CFLAGS) -o $(PROJNAME) $(objects)

clean:
	@echo "Clean";
	@if [ -f $(PROJNAME) ]; then rm $(PROJNAME); fi
	@if [ -f $(PROJNAME).zip ]; then rm $(PROJNAME).zip; fi
	@find -name "*.o" -exec rm {} ';'
