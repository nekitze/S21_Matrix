CC = gcc
CFLAGS = -Wall -Werror -Wextra
LD_S21_MATRIX_FLAGS = -L. -ls21_matrix -lm
LD_CHECK_FLAGS = -lcheck -lpthread -lm
GCOV_FLAGS = 

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
        LD_CHECK_FLAGS +=  -lsubunit
endif

SOURCES = $(wildcard functions/*.c) 
OBJ_DIR := ./obj
OBJECTS := $(addprefix obj/,$(SOURCES:.c=.o))

HEADER = s21_matrix.h

SUITE_SOURCES = $(wildcard tests/tests*.c tests/suites/*.c)
SUITE_OBJECTS = $(addprefix obj/,$(SUITE_SOURCES:.c=.o))
SUITE_HEADER = tests/tests.h

all: s21_matrix.a

gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test > /dev/null
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

test: make_dir $(SUITE_HEADER) $(SUITE_OBJECTS) s21_matrix.a 
	gcc $(wildcard $(OBJ_DIR)/obj_test*.o) $(LD_S21_MATRIX_FLAGS) $(LD_CHECK_FLAGS) $(GCOV_FLAGS) -o $@

mytest: mytest.c s21_matrix.a
	$(CC) $< $(LD_S21_matrix_FLAGS) -o $@

s21_matrix.a: make_dir $(OBJECTS)
	ar rcs $@ $(OBJ_DIR)/*.o
	ranlib $@
	cp s21_matrix.a libs21_matrix.a
	
make_dir:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) -c $< $(GCOV_FLAGS) $(CFLAGS) -o $(OBJ_DIR)/$(subst /,_,$@)

clean:
	rm -rf obj *.a test mytest html_report report.info
