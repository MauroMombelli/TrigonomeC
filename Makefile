CC=gcc
LD=$(CC)
CFLAGS= -Wall -Wextra -Wpedantic -I . -std=c11

@echo "Please execute next commands:"

PROJECTNAME=Test_TrigonomeC

ODIR=build

LIBS=-lm

SOURCE=$(shell find my_math -follow -name "*.c")

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	mkdir -p $(ODIR)
	@echo "lol"
	$(LD) $(CFLAGS) $(LIBS) $(SOURCE) -o $(ODIR)/$(PROJECTNAME)

.PHONY: clean

clean:
	rm -f $(ODIR) 