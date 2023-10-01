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

quadratic::quadratic(const polynomial& other) : univariate(other) {

}

quadratic::quadratic(term t) : univariate(t) {
    
}

void quadratic::printRoots() const {
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
