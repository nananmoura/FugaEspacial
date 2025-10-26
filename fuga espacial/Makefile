CC = gcc
CFLAGS = -I../cli-lib/include
SRC = src/main.c src/jogo.c ../cli-lib/src/*.c
OUT = build/fuga_espacial

all: build $(OUT)

build:
	mkdir -p build

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) -lm

run: all
	./$(OUT)

clean:
	rm -rf build