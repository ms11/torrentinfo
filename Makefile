# "THE BEER-WARE LICENSE" (Revision 42):
# ms11 wrote this file. As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return

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
