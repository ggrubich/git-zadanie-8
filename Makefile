CFLAGS = -Wall -pedantic-errors

FILES = main.c lib.c
OBJECTS = $(FILES:.c=.o)

main: $(OBJECTS)

clean:
	rm main $(OBJECTS)
