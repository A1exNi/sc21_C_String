NAME = Project
CC = gcc -Wall -Werror -Wextra -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURSES = s21_*.c
OBJECT = $(patsubst %*.c, %*.o,  ${SOURSES})
OS := $(shell uname -s)

ifeq ($(OS), Linux)
 CC += -D OS_LINUX
 ADD_LIB = -lcheck -lm -lrt -lpthread
 TEST_FLAGS =-lpthread -lcheck -pthread -lrt -lm
endif
ifeq ($(OS), Darwin)
 CC += -D OS_MAC
 ADD_LIB =
 TEST_FLAGS =-lcheck
endif

all: clean s21_string.a

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME)

s21_string.a:$(SOURSES)
	$(CC) -c -lcheck $(SOURSES)
	@ar rcs s21_string.a $(OBJECT)

test: test.c
	$(CC) $< s21_string.a $(TEST_FLAGS) -o test

gcov_report: s21_string.a
	@gcc $(GCOVFLAGS) test.c -lcheck $(SOURSES) $(TEST_FLAGS) -o GcovReport
	@./GcovReport
	@lcov -t "GcovReport" -o GcovReport.info -c -d .
	@genhtml -o report GcovReport.info
	@open ./report/index-sort-f.html
	@rm -rf ./*.gcno ./*.gcda ./GcovReport.*

clean:
	@rm -rf ./*.o ./*.a ./a.out ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./string_o ./*.dSYM ./unit-test ./CPPLINT*
clean2:
	@rm -r ./*.o

lo:
	for i in `seq 100 $(OP)`;	do ./test; done;

valgrind_check: s21_string.a
	CK_FORK=no valgrind --tool=memcheck ./test

lik: s21_string.a
	CK_FORK=no leaks -atExit -- ./test

rebuild:
	$(MAKE) clean
	$(MAKE) all
