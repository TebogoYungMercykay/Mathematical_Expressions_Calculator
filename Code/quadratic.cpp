// quadratic.cpp
#include "quadratic.h"

// Implement quadratic class member functions here

// Constructor
quadratic::quadratic(char c) : univariate(2, c) {
    // Implement constructor
}

// Constructor from array of terms
quadratic::quadratic(term** t, int n) : univariate(t, n) {
    // Implement constructor from array of terms
}

// Constructor from input string
quadratic::quadratic(const char* input) : univariate(input) {
    // Implement constructor from input string
}

// Copy constructor
quadratic::quadratic(const quadratic& other) : univariate(other) {
    // Implement copy constructor
}

// Other member function implementations...

