CC = gcc
AR = ar

NAME_SHARED = libmatrix.so
NAME_STATIC = libmatrix.a

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
LIB_DIR = lib

AR_FLAGS = rcs
CC_FLAGS = -g -Wall -Werror -fpic
CC_INCS  = -I$(INC_DIR)
CC_LINKS = -lc -lm

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET_SHARED = $(LIB_DIR)/$(NAME_SHARED)
TARGET_STATIC = $(LIB_DIR)/$(NAME_STATIC)

all: $(TARGET_SHARED) $(TARGET_STATIC)

$(TARGET_SHARED): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -shared -o $@ $(CC_INCS) $(CC_LINKS)

$(TARGET_STATIC): $(OBJS)
	$(AR) $(AR_FLAGS) $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(CC_INCS)

$(OBJ_DIR) $(LIB_DIR):
	mkdir -p $@

clean:
	rm -r $(LIB_DIR)/*
	rm -r $(OBJ_DIR)/*

