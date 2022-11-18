CC = gcc
CFLAGS=-c -lm -Wall -pedantic
SRC = $(wildcard Source_Code/*.c)
OBJ = $(wildcard Objects/*.o)
DEPS = $(wildcard Source_Code/*.h)
OUT = Objects/
IN = Source_Code/
EXE = exe

all: CreateFolder Compile GenExe

Compile: $(SRC) $(DEPS)
	@$(CC) -o $(OUT)tGame.o $(IN)tGame.c $(CFLAGS)
	@$(CC) -o $(OUT)main.o $(IN)main.c $(CFLAGS)
	@echo compilado objetos!

GenExe:
	@$(CC) -o $(IN)$(EXE) $(OBJ) -lm
	@echo compilado executavel!

PlayGame:
	@./$(IN)$(EXE)

CreateFolder:
	@mkdir -p Objects

clear:
	@rm -rf Objects && rm $(IN)exe