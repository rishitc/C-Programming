all: ./bin/check_money_tests


OBJ_FILES_TO_LINK = ./obj/check_money.o ./obj/money.o
OUTPUT_BINARY_FILE = ./bin/check_money_tests


./bin/check_money_tests: $(OBJ_FILES_TO_LINK)
	gcc -g -o \
	$(OUTPUT_BINARY_FILE) $(OBJ_FILES_TO_LINK) \
	-lcheck -lm -lpthread -lrt -lsubunit


./obj/money.o: ./src/money.c ./src/money.h
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
	./src/money.c
	mv ./money.o ./obj/money.o


./obj/check_money.o: ./tests/check_money.c ./src/money.h
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
	./tests/check_money.c
	mv ./check_money.o ./obj/check_money.o


.PHONY: clean

clean:
	rm -i -r ./obj/*.o
	rm -i -r ./bin/*