COMMON_OBJ_FILES = ./obj/vector_ops.o ./obj/safetyChecks.o
OBJ_FILES_TO_LINK_FOR_TESTS = ./obj/check_vector.o
OBJ_FILES_TO_LINK_FOR_USER = ./obj/vector_pool.o

OUTPUT_CHECK_BINARY_FILE = ./bin/check_vector
OUTPUT_USER_BINARY_FILE = ./bin/vector

all: $(OUTPUT_CHECK_BINARY_FILE)


$(OUTPUT_CHECK_BINARY_FILE): $(COMMON_OBJ_FILES) $(OBJ_FILES_TO_LINK_FOR_TESTS) $(OBJ_FILES_TO_LINK_FOR_USER)
	gcc -g -o \
	$(OUTPUT_CHECK_BINARY_FILE) $(COMMON_OBJ_FILES) $(OBJ_FILES_TO_LINK_FOR_TESTS) \
	-lcheck -lm -lpthread -lrt -lsubunit

	gcc -g -o \
	$(OUTPUT_USER_BINARY_FILE) $(COMMON_OBJ_FILES) $(OBJ_FILES_TO_LINK_FOR_USER) \
	-lm


./obj/vector_ops.o: ./src/vector_ops.c
	gcc -c \
	-Wall \
	-Wextra \
	-Wunreachable-code \
	-ftabstop=4 \
	-Wmisleading-indentation \
	-Wdouble-promotion \
	-Wshadow \
	-Wfloat-equal \
	-Wparentheses \
	-Wunused \
	-Wunused-const-variable \
	-Wunused-variable \
	-Werror \
	./src/vector_ops.c
	mv ./vector_ops.o ./obj/vector_ops.o


./obj/vector_pool.o: ./src/vector_pool.c
	gcc -c \
	-Wall \
	-Wextra \
	-Wunreachable-code \
	-ftabstop=4 \
	-Wmisleading-indentation \
	-Wdouble-promotion \
	-Wshadow \
	-Wfloat-equal \
	-Wparentheses \
	-Wunused \
	-Wunused-const-variable \
	-Wunused-variable \
	-Werror \
	./src/vector_pool.c
	mv ./vector_pool.o ./obj/vector_pool.o


./obj/safetyChecks.o: ./src/safetyChecks.c
	gcc -c \
	-Wall \
	-Wextra \
	-Wunreachable-code \
	-ftabstop=4 \
	-Wmisleading-indentation \
	-Wdouble-promotion \
	-Wshadow \
	-Wfloat-equal \
	-Wparentheses \
	-Wunused \
	-Wunused-const-variable \
	-Wunused-variable \
	-Werror \
	./src/safetyChecks.c
	mv ./safetyChecks.o ./obj/safetyChecks.o


./obj/check_vector.o: ./tests/check_vector.c
	gcc -c \
	-Wall \
	-Wextra \
	-Wunreachable-code \
	-ftabstop=4 \
	-Wmisleading-indentation \
	-Wdouble-promotion \
	-Wshadow \
	-Wfloat-equal \
	-Wparentheses \
	-Wunused \
	-Wunused-const-variable \
	-Wunused-variable \
	-Werror \
	./tests/check_vector.c
	mv ./check_vector.o ./obj/check_vector.o


.PHONY: clean

clean:
	rm -i -r ./obj/*.o
	rm -i -r ./bin/*