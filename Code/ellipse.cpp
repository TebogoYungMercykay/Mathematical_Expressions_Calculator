// ellipse.cpp
#include "ellipse.h"

// Implement ellipse class member functions here

// Constructor
ellipse::ellipse(char c1, char c2) : bivariate(2, c1, c2) {
    // Implement constructor
}

// Constructor from array of terms
ellipse::ellipse(term** t, int n) : bivariate(t, n) {
    // Implement constructor from array of terms
}

// Constructor from input string
ellipse::ellipse(const char* input) : bivariate(input) {
    // Implement constructor from input string
}

// Copy constructor
ellipse::ellipse(const ellipse& other) : bivariate(other.getTerms(), other.getNumTerms()) {
    // Implement copy constructor
}

ellipse::ellipse(const polynomial& other) : bivariate(other.getTerms(), other.getNumTerms()) {

}

ellipse::ellipse(term t) : bivariate(t) {

}

void ellipse::printStats() const {

}
