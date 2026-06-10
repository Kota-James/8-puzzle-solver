# コンパイラとフラグ
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
LDFLAGS =

# ディレクトリ設定
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
BIN_NAME = puzzle_solver

# ソースファイルとオブジェクトファイルのリスト
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ターゲット
all: $(BIN_NAME)

$(BIN_NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップ
clean:
	rm -rf $(OBJ_DIR) $(BIN_NAME)

.PHONY: all clean