CC = gcc

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
BIN_DIR := bin

VPATH := src

EXE := $(BIN_DIR)/matrix.exe
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

