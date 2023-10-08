// linear.cpp
#include "linear.h"
// Linear inherits publically from univariate.
// This is a specialised version of univariate. In this class, the degree variable is set to 1.

linear::linear(char c) : univariate(1, c) {}

linear::linear(term** t, int n) : univariate(t, n) {
    this->degree = 1;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(const char* input) : univariate(input) {
    this->degree = 1;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(const linear& other) : univariate(other) {
    this->degree = 1;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(const polynomial& other) : univariate(other) {
    this->degree = 1;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(term t) : univariate(t) {
    this->degree = 1;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

void linear::printRoots() const {
    // - This function should print out the roots of the object.
    // - The explanation will assume the polynomial has the form mx + c.
    // - Note that the x can be any variable.
    // - Extract the values of m and c from the linear polynomial.
    // - If m is 0, then print out the following on its own line.
    //     No roots 1
    // - If m is not 0, then print out the following on its own line, with the root displayed to 2 decimal values.
    // - Note that values in curly braces should be evaluated, and _ indicates spaces.
    //     Roots_ : _ { variable } _ = _ { - c/ m }
}

