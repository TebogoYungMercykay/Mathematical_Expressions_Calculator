// linear.cpp
#include "linear.h"

linear::linear(char c) : univariate(1, c) {
}

linear::linear(term** t, int n) : univariate(t, n) {
}

linear::linear(const char* input) : univariate(input) {
}

linear::linear(const linear& other) : univariate(other) {
}

linear::linear(const polynomial& other) : univariate(other) {
    
}

linear::linear(term t) : univariate(t) {
    
}

void linear::printRoots() const {
    
}

