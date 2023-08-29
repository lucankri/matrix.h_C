GCC = gcc -Wall -Werror -Wextra -std=c11
TST_LIBS = -lcheck
OS := $(shell uname -s)


ifeq ($(OS),Linux)
		CC+=-D LINUX_OS
		TST_LIBS+= -lrt -lm -lpthread
else
	ifeq ($(OS),Darwin)
		CC+=-D MAC_OS
		TST_LIBS+=-lm -lpthread
	endif
endif


all: clean s21_matrix.a test gcov_report

clean:
	rm -rf *.a && rm -rf *.o *.exe
	rm -rf *.info && rm -rf *.gcda && rm -rf *.gcno &&  rm -rf *.gcov *.html *.css *.cfg
	rm -rf report/ && rm -rf *.out
	rm -rf .clang-format

s21_matrix.a: clean
	$(GCC) -c s21_matrix.c -o ./s21_matrix.o
	ar rcs s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a


test: s21_matrix.a
	$(GCC) tests.c -L. s21_matrix.a $(TST_LIBS) -o ./tests.exe
	$(GCC) --coverage tests.c s21_matrix.c s21_matrix.a -L. s21_matrix.a $(TST_LIBS) -o ./tests.exe
	./tests.exe

gcov_report: s21_matrix.a test
	./tests.exe
	gcov -a -f s21_matrix.gcda
	gcovr --html-details -o report.html

check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c
	clang-format -n *.h
	cppcheck *.c
	cppcheck *.h

