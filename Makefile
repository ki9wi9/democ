PROJECT=demo_mcp23008
CC=gcc
CFLAGS=-I.
DEPS =
OBJ = mcp23008.o demo_mcp23008.o
EXTRA_LIBS=-lwiringPi -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROJECT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f $(PROJECT) $(OBJ)
