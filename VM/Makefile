SRC_FILES = main.c
SRC_FOLDER = ./src/
OP_FILE = main_vm
OP_FOLDER = ./bin/
CC_FLAGS = -Wall -Wextra -Wunreachable-code -ftabstop=4 \
			-Wmisleading-indentation \
			-Wdouble-promotion \
			-Wshadow \
			-Wfloat-equal \
			-Wparentheses \
			-Wunused \
			-Wunused-const-variable \
			-Wunused-variable \
			-Werror \
			-g \
			-std=c11
CC = gcc

all:
	${CC} ${SRC_FOLDER}${SRC_FILES} ${CC_FLAGS} -o ${OP_FOLDER}${OP_FILE}

.PHONY: clean

clean:
	rm
