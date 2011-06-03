CFLAGS=-g -Wall -I/usr/local/include -Isrc

OBJECTS=src/tst.o src/repl.o src/dict.o src/list.o src/hash.o src/array.o src/token.o src/struct.o src/types.o src/label.o src/function.o src/gen.o src/error.o src/allocator.o
MAIN=src/earing.o
TESTS=tests/tst_tests.o tests/repl_tests.o tests/module_tests.o tests/array_tests.o tests/token_tests.o tests/struct_tests.o tests/hash_tests.o tests/dict_tests.o tests/list_tests.o tests/error_tests.o tests/allocator_tests.o
TESTS_SRC=tests/tst_tests.c tests/repl_tests.c tests/module_tests.c tests/array_tests.c tests/token_tests.c tests/struct_tests.c tests/hash_tests.c tests/dict_tests.c tests/list_tests.c tests/error_tests.c tests/allocator_tests.c

# CUT sucks, it should be replaced with minunit
# check: tests/cutcheck.o ${OBJECTS} ${TESTS}
# 	gcc -Isrc tests/cutcheck.c -o build/cutcheck -lcut -lgc -lcord -ldl ${OBJECTS} ${TESTS}
# 	./build/cutcheck
# 
# tests/cutcheck.c: ${TESTS_SRC}
# 	software/cut-2.6/cutgen ${TESTS_SRC} -o tests/cutcheck.c

src/lexer.c: src/lexer.rl
	ragel -C -G2 src/lexer.rl

src/grammar.c: src/grammar.y
	cd src && ../software/lemon -s grammar.y

gen:
	python src/ops_gen.py

clean:
	rm -f tests/*.o src/*.o tests/cutcheck*

earing: ${OBJECTS}
	gcc ${CFLAGS} -L/usr/local/lib -lcord -lgc -ldl -o build/earing ${OBJECST} ${MAIN} /usr/local/lib/libudis86.a

