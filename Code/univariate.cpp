// univariate.cpp
#include "univariate.h"

// Implement univariate class member functions here

// Constructor
univariate::univariate(int d, char c) {
    // Implement constructor
}

// Constructor from array of terms
univariate::univariate(term** t, int n) {
    // Implement constructor from array of terms
}

// Constructor from input string
univariate::univariate(const char* input) {
    // Implement constructor from input string
}

// Copy constructor
univariate::univariate(const univariate& other) {
    // Implement copy constructor
}

univariate::univariate(const polynomial& other) {
    
}
univariate::univariate(term t) {
    
}

// Assignment operator
univariate& univariate::operator=(const univariate& other) {
    // Implement assignment operator
    return *this;
}

polynomial* univariate::operator!() const {
    return new univariate(2,'r');
}

polynomial* univariate::operator()(char* vars, int* vals, int numVals) const {
    return new univariate(2,'r');
}

polynomial* univariate::operator()(string inp) const {
    return new univariate(2,'r');
}

polynomial* univariate::operator+(const polynomial& other) const {
    return new univariate(2,'r');
}

polynomial& univariate::operator+=(const polynomial& other) {
    return *(new univariate(2,'r'));
}

polynomial* univariate::operator-(const polynomial& other) const {
    return new univariate(2,'r');
}

polynomial& univariate::operator-=(const polynomial& other) {
    return *(new univariate(2,'r'));
}

polynomial* univariate::operator*(const polynomial& other) const {
    return new univariate(2,'r');
}

polynomial& univariate::operator*=(const polynomial& other) {
    return *(new univariate(2,'r'));
}
