CFLAGS= -std=c99 -Wall -Wextra -Werror -Wvla -pedantic
OBJ=mult.o prog.o
STATIC = libprog.a
SHARED = libprog.so
BIN = prog

all: $(STATIC) 

shared: $(SHARED)

$(STATIC): $(OBJ)
	$(AR) csr $@ $^

$(SHARED): $(OBJ)
	$(CC) -fPIC -shared -o $@ $^

clean:
	$(RM) *.o *.a *.so
