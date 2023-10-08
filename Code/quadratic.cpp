// quadratic.cpp
#include "quadratic.h"
// Quadratic inherits publically from univariate. This is a specialised version of univariate.
// In this class, the degree variable is set to 2.

quadratic::quadratic(char c) : univariate(2, c) {}

quadratic::quadratic(term** t, int n) : univariate(t, n) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

quadratic::quadratic(const char* input) : univariate(input) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

quadratic::quadratic(const quadratic& other) : univariate(other) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

quadratic::quadratic(const polynomial& other) : univariate(other) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

quadratic::quadratic(term t) : univariate(t) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

void quadratic::printRoots() const {
    if (this->numTerms == 3) {
        double a = (*(this->getTerms()[0]))[6];
        double b = (*(this->getTerms()[1]))[6];
        double c = (*(this->getTerms()[2]))[6];

        // std::cout << a << " - " << b << " - " << c << endl;
        if (a == 0) {
            if (b == 0) {
                std::cout << "No roots" << std::endl;
            } else {
                std::cout << "Roots : " << this->variable << " = " << (-c/b) << std::endl;
            }
        } else {
            double discriminant = (b * b) - (4 * a * c);
            if (discriminant >= 0) {
                double root1 = (-b + sqrt(discriminant)) / (2 * a);
                double root2 = (-b - sqrt(discriminant)) / (2 * a);
                cout << std::fixed << std::setprecision(2) << "Root : " << this->variable << " = " << root1 << " , "  << this->variable << " = " << root2 << endl;
            } else {
                std::cout << "No roots" << std::endl;
            }
        }
    } else {
        std::cout << "No roots" << std::endl;
    }
}
