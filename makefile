CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wextra


CC = gcc

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/test_trafficlight.c src/trafficlight.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/trafficlight.c test/vendor/unity.c test/test_trafficlight.c -o tests.out