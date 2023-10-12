// linear.cpp
#include "linear.h"
// Linear inherits publically from univariate.
// This is a specialised version of univariate. In this class, the degree variable is set to 1.

linear::linear(char c) : univariate(1, c) {}

linear::linear(term** t, int n) : univariate(t, n) {
    this->degree = 1;

    // Checking if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(const char* input) : univariate(input) {
    this->degree = 1;

    // Checking if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(const linear& other) : univariate(other) {
    this->degree = 1;

    // Checking if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(const polynomial& other) : univariate(other) {
    this->degree = 1;

    // Checking if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

linear::linear(term t) : univariate(t) {
    this->degree = 1;

    // Checking if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

void linear::printRoots() const {
    double m = 0;
    int c = 0;
    if (this->numTerms >= 2) {
        m = (*(this->getTerms()[0]))[this->getTerms()[0]->getNumVariables() + 1];
        c = (*(this->getTerms()[1]))[this->getTerms()[1]->getNumVariables() + 1];
        if (m == 0) {
            std::cout << "No roots" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(2) << "Roots : " << this->variable << " = " << (-c/m) << std::endl;
        }
    } else {
        std::cout << "No roots" << std::endl;
    }
}