# Compilers use flags to control what options are used to compile the C source code. Commonly called CFLAGS
#  - The compiler is pretty smart and can warn you of various things. Use "-Wall -Wextra" to enable them
#  - We'll be using the 2011 version of C with GCC specific extensions (needed later in the course). Use "-std=gnu11"
#  - The unit test framework will be using is called "unity." We need to find where the header file is, so tell the
#  compiler that it's in ../unity
CFLAGS:= -Wall -Wextra -std=gnu11 -I../unity

# Linkers also use flags to control the options used. Commonly called LDFLAGS
LDFLAGS:= -Wall -Wextra -std=gnu11

# The list of programs this Makefile will build
TESTS:= test_string_length test_string_copy

# This line tells what to do when we type "make":
all: $(TESTS)

# This line tells what to do when we type "make clean": removes all .o files and the list of programs in PROGS
clean:
	$(RM) *.o $(TESTS)

# This is the line that will compile and build test cases for Level 3 Part A
test_string_length: test_string_length.o string.o ../unity/unity.o
	$(CC) ${LDFLAGS} -I../unity $^ -o $@

# This is the line that will compile and build test cases for Level 3 Part B
test_string_copy: test_string_copy.o string.o ../unity/unity.o
	$(CC) ${LDFLAGS} -I../unity $^ -o $@


