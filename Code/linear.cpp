// linear.cpp
#include "linear.h"

// Implement linear class member functions here

// Constructor
linear::linear(char c) : univariate(1, c) {
    // Implement constructor
}

// Constructor from array of terms
linear::linear(term** t, int n) : univariate(t, n) {
    // Implement constructor from array of terms
}

// Constructor from input string
linear::linear(const char* input) : univariate(input) {
    // Implement constructor from input string
}

// Copy constructor
linear::linear(const linear& other) : univariate(other) {
    // Implement copy constructor
}

// Other member function implementations...

