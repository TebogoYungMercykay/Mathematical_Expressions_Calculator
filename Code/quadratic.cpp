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
    // - This function should print out the roots of the object.
    // - The explanation will assume the polynomial has the form ax2 + bx + c.
    // - Note that the x can be any variable.
    // - Extract the values of a, b and c from the quadratic polynomial.
    // - If a is 0, then this is a linear polynomial of the from bx + c. Thus use the previous subsection.
    // - If a is not 0, then calculate the discriminant of the quadratic equation:
    //     d = b^2 - 4ac
    // - If the discriminant is negative, then print the following on its own line
    //     No roots
    // - If d is positive, then print out the following on its own line, with the roots displayed to 2 decimal values.
    // - Note that values in curly braces should be evaluated, and _ indicates spaces. Note that you should still use this format even if the roots are the same. 
    //         variable has been shortened to var to allow the line to fit.
    // - Roots_:_{var}_=_{(-b+sqrt(d))/(2a)}_,_{var}_=_{(-b-sqrt(d))/(2a)}

    // double a = getCoefficient(2);
    // double b = getCoefficient(1);
    // double c = getCoefficient(0);

    // double discriminant = b * b - 4 * a * c;
    // if (discriminant > 0) {
    //     double root1 = (-b + sqrt(discriminant)) / (2 * a);
    //     double root2 = (-b - sqrt(discriminant)) / (2 * a);
    //     cout << "Root 1: " << root1 << endl;
    //     cout << "Root 2: " << root2 << endl;
    // } else if (discriminant == 0) {
    //     double root = -b / (2 * a);
    //     cout << "Double Root: " << root << endl;
    // } else {
    //     cout << "No Real Roots" << endl;
    // }
}
