CC=gcc
CFLAGS=-c -ansi -pedantic-errors
LDFLAGS=
SOURCES=main.c project.c project.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

