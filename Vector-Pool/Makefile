all: ./bin/check_vector


OBJ_FILES_TO_LINK = ./obj/vector_ops.o ./obj/vector_pool.o ./src/safetyChecks.c
OUTPUT_CHECK_BINARY_FILE = ./bin/check_vector
OUTPUT_BINARY_FILE = ./bin/vector


$(OUTPUT_CHECK_BINARY_FILE): $(OBJ_FILES_TO_LINK)
	gcc -g -o \
	$(OUTPUT_CHECK_BINARY_FILE) $(OBJ_FILES_TO_LINK) \
	-lcheck -lm -lpthread -lrt -lsubunit

	gcc -g -o \
	$(OUTPUT_BINARY_FILE) $(OBJ_FILES_TO_LINK) \
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
	-Wunsuffixed-float-constants \
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
	-Wunsuffixed-float-constants \
	-Wunused \
	-Wunused-const-variable \
	-Wunused-variable \
	-Werror \
	./src/vector_pool.c
	mv ./vector_pool.o ./obj/vector_pool.o


./obj/safetyChecks.c: ./src/safetyChecks.c
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
	-Wunsuffixed-float-constants \
	-Wunused \
	-Wunused-const-variable \
	-Wunused-variable \
	-Werror \
	./src/safetyChecks.c
	mv ./safetyChecks.o ./obj/safetyChecks.o


.PHONY: clean

clean:
	rm -i -r ./obj/*.o
	rm -i -r ./bin/*