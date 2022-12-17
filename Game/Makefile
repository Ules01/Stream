CC = gcc
CFlAGS = -std=c99 -pedantic -Wall -Wextra -Werror -Wvla
OBJ = player.o map.o main.o
SRC = Main/main.c Player/player.c Map/map.c
BIN = main


all:
	$(CC) $(CFLAGS) -g $(SRC) -o $(BIN)
	@echo Compilation done

clean:
	$(RM) $(BIN)
