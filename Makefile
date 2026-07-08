HEADERS = param.hpp parse.hpp shell.hpp
TEST_SOURCES = test/param_test.cpp test/parse_test.cpp test/shell_test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECTS = shell.o param.o parse.o main.o
TEST_TARGETS = $(TEST_SOURCES:.cpp=.out)
MAIN_TARGET = main_executable

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.

.PHONY: all run-test main run-main clean test

all: $(MAIN_TARGET)

# only build tests if test files have content
test: $(TEST_TARGETS)

$(TEST_TARGETS): %.out: %.o param.o parse.o shell.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run-test: $(TEST_TARGETS)
	for test in $(TEST_TARGETS); do ./$$test; done

main: $(MAIN_TARGET)

run-main: main
	./$(MAIN_TARGET)

clean:
	rm -f $(TEST_OBJECTS) $(TEST_TARGETS) $(MAIN_OBJECTS) $(MAIN_TARGET)