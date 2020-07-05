all: ./bin/vector


OBJ_FILES_TO_LINK = ./obj/vector_ops.o ./obj/vector_pool.o
OUTPUT_BINARY_FILE = ./bin/vector


./bin/vector: $(OBJ_FILES_TO_LINK)
	gcc -g -o \
	$(OUTPUT_BINARY_FILE) $(OBJ_FILES_TO_LINK) \
	-lcheck -lm -lpthread -lrt -lsubunit


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


./obj/vector_pool.o: ./tests/vector_pool.c
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
	./tests/vector_pool.c
	mv ./vector_pool.o ./obj/vector_pool.o


.PHONY: clean

clean:
	rm -i -r ./obj/*.o
	rm -i -r ./bin/*