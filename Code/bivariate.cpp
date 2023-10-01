// bivariate.cpp
#include "bivariate.h"

// Implement bivariate class member functions here

// Constructor
bivariate::bivariate(int d, char c1, char c2) {
    // Implement constructor
}

// Constructor from array of terms
bivariate::bivariate(term** t, int n) {
    // Implement constructor from array of terms
}

// Constructor from input string
bivariate::bivariate(const char* input) {
    // Implement constructor from input string
}

// Copy constructor
bivariate::bivariate(const bivariate& other) {
    // Implement copy constructor
}

bivariate::bivariate(const polynomial& other) {
    
}
bivariate::bivariate(term t) {
    
}

// Assignment operator
bivariate& bivariate::operator=(const bivariate& other) {
    // Implement assignment operator
    return *this;
}

istream& operator>>(istream& is, univariate& u) {
    return is;
}

polynomial* bivariate::operator!() const {
    return new bivariate(2,'r', 'r');
}

polynomial* bivariate::operator()(char* vars, int* vals, int numVals) const {
    return new bivariate(2,'r', 'r');
}

polynomial* bivariate::operator()(string inp) const {
    return new bivariate(2,'r', 'r');
}

polynomial* bivariate::operator+(const polynomial& other) const {
    return new bivariate(2,'r', 'r');
}

polynomial& bivariate::operator+=(const polynomial& other) {
    return *(new bivariate(2,'r', 'r'));
}

polynomial* bivariate::operator-(const polynomial& other) const {
    return new bivariate(2,'r', 'r');
}

polynomial& bivariate::operator-=(const polynomial& other) {
    return *(new bivariate(2,'r', 'r'));
}

polynomial* bivariate::operator*(const polynomial& other) const {
    return new bivariate(2,'r', 'r');
}

polynomial& bivariate::operator*=(const polynomial& other) {
    return *(new bivariate(2,'r', 'r'));
}