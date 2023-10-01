// circle.cpp
#include "circle.h"

// Implement circle class member functions here
bool circle::isCircle() const {
    return false;
}

// Constructor
circle::circle(char c1, char c2) : bivariate(2, c1, c2) {
    // Implement constructor
}

// Constructor from array of terms
circle::circle(term** t, int n) : bivariate(t, n) {
    // Implement constructor from array of terms
}

// Constructor from input string
circle::circle(const char* input) : bivariate(input) {
    // Implement constructor from input string
}

// Copy constructor
circle::circle(const circle& other) : bivariate(other.getTerms(), other.getNumTerms()) {
    // Implement copy constructor
}

circle::circle(const polynomial &other) : bivariate(other.getTerms(), other.getNumTerms())  {

}

circle::circle(term t) : bivariate(t)  {

}

void circle::printStats() const {

}
