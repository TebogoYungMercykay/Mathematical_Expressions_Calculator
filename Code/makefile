CXX = g++
CXXFLAGS = -std=c++98 -pedantic
LDFLAGS = --coverage

SRC_FILES = *.cpp
EXECUTABLE = main

.PHONY: all clean run tar untar coverage

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
    $(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
    rm -f *.o *.tar.gz $(EXECUTABLE)
    reset
    clear

run: $(EXECUTABLE)
    valgrind --leak-check=full ./$(EXECUTABLE)

tar:
    tar -cvz *.* -f Code.tar.gz

untar:
    tar -zxvf *.tar.gz

coverage: $(EXECUTABLE)
    ./$(EXECUTABLE)
    gcov -f -m -r -j term $(SRC_FILES)
    lcov -c -d . -o coverage.info
    genhtml coverage.info -o coverage_report
