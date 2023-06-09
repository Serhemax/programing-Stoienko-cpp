CC = $(CLANG_PREFIX)g++
LAB_OPTS = -I./src src/list.hpp
C_OPTS = $(MAC_OPTS) -fsanitize=address -std=c++14 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

V_FLAGS = --tool=memcheck --leak-check=full --show-reachable=yes \
	--undef-value-errors=yes --track-origins=no --child-silent-after-fork=no \
	--trace-children=no --error-exitcode=1
V_LAGS = valgrind

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< $(ARCH) -fprofile-generate -fprofile-arcs -o ./dist/$@ -lgtest -lgtest_main

test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	$(CLANG_PREFIX)llvm-profdata merge -sparse dist/*.profraw -o dist/test.profdata
	$(CLANG_PREFIX)llvm-cov report ./dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
	$(CLANG_PREFIX)llvm-cov show ./dist/test.bin -instr-profile=dist/test.profdata src/*.cpp --format html > dist/coverage.html

all: clean prep compile
	./dist/main.bin
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	$(CLANG_PREFIX)llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	$(CLANG_PREFIX)llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
	$(CLANG_PREFIX)llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.cpp --format html > dist/coverage.html
check:
	clang-format --verbose -dry-run --Werror src/* test/*
	$(CLANG_PREFIX)clang-tidy src/*.cpp  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --check-config --suppress=*:*/test.cpp  .
	rm -rf src/*.dump test/*.dump
leak-check: clean prep compile
	ASAN_OPTIONS=detect_leaks=1 LSAN_OPTIONS=suppressions=leaks_suppr.txt dist/main.bin
	ASAN_OPTIONS=detect_leaks=1 LSAN_OPTIONS=suppressions=leaks_suppr.txt LLVM_PROFILE_FILE="dist/test.profraw" dist/test.bin

leak-check_main1:clean prep main.bin
	$(V_LAGS) $(V_FLAGS)  --log-file=dist/valgrind_main.log  dist/main.bin
	
leak-check_test1:clean prep test.bin
	$(V_LAGS)  $(V_FLAGS)  --log-file=dist/valgrind_test.log  dist/test.bin

