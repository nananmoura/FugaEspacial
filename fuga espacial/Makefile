CC = gcc
CFLAGS = -Wall -I../cli-lib/include -I./src

# Pastas
SRC_DIR = src
BUILD_DIR = build
CLI_LIB = ../cli-lib/src

# Arquivos fonte
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/jogo.c \
      $(SRC_DIR)/nave.c \
      $(SRC_DIR)/meteoro.c \
      $(CLI_LIB)/screen.c \
      $(CLI_LIB)/keyboard.c \
      $(CLI_LIB)/timer.c

# Executável final
OUT = $(BUILD_DIR)/fuga_espacial

# Regra principal
all: $(OUT)

# Compilação
$(OUT): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) -lm

# Executar o jogo
run: all
	./$(OUT)

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD_DIR)