CC = gcc
CFLAGS = -Wall -I./cli-lib/include -I./fuga_espacial/src

SRC_DIR = fuga_espacial/src
BUILD_DIR = fuga_espacial/build
CLI_LIB = cli-lib/src

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/jogo.c \
      $(SRC_DIR)/nave.c \
      $(SRC_DIR)/meteoro.c \
      $(SRC_DIR)/tiro.c \
      $(SRC_DIR)/vidas.c \
      $(SRC_DIR)/placar.c \
      $(SRC_DIR)/borda.c \
      $(CLI_LIB)/screen.c \
      $(CLI_LIB)/keyboard.c \
      $(SRC_DIR)/nivel.c \
      $(CLI_LIB)/timer.c

OUT = $(BUILD_DIR)/fuga_espacial

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) -lm

run: all
	./$(OUT)

clean:
	rm -rf $(BUILD_DIR)
