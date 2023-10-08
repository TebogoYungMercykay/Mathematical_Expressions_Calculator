// ellipse.cpp
#include "ellipse.h"
// Ellipse inherits publically from bivariate. This is a specialised version of bivariate. In this class, the degree variable is set to 2.
// Additionally, we will only be using ellipses centred around the origin. Thus only three terms are allowed.
// The first and second terms must have a degree of 2, and the last term must have a degree of 0.

// Private:
bool ellipse::isEllipse() const {
    ellipse myEllipse = (*this);
    if (myEllipse.getNumTerms() == 3 && myEllipse[2]->getDegree() == 0) {
        if (myEllipse[1]->getDegree() == 2 && myEllipse[0]->getDegree() == myEllipse[1]->getDegree()) {
            delete myEllipse;
            return true;
        }
    }
    delete myEllipse;
    return false;
}

// Public
ellipse::ellipse(char c1, char c2) : bivariate(2, c1, c2) {
}

ellipse::ellipse(term** t, int n) : bivariate(t, n) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isEllipse()) {
        this->clearTerms();
    }
}


ellipse::ellipse(const char* input) : bivariate(input) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isEllipse()) {
        this->clearTerms();
    }
}

ellipse::ellipse(const ellipse& other) : bivariate(other.getTerms(), other.getNumTerms()) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isEllipse()) {
        this->clearTerms();
    }
}

ellipse::ellipse(const polynomial& other) : bivariate(other.getTerms(), other.getNumTerms()) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isEllipse()) {
        this->clearTerms();
    }// - Follow the same rules as the string constructor.

}

ellipse::ellipse(term t) : bivariate(t) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isEllipse()) {
        this->clearTerms();
    }
}

void ellipse::printStats() const {
    // - This function will print statistics about the ellipse.
    // - The explanation will assume our ellipse has the equation: cx2 + dy2 + f.
    // - Note that the x, y can be any variables.
    // - Start by extracting the values for c, d and f.
    // - If f is not negative or the ellipse is invalid, then print out the following on its own line
    //     Not a real ellipse 1
    // - Calculate the following values : a = sqrt((-f)/c) , b = sqrt((-f)/d).
    // - Look at the two character member variables. Save the smallest of these two in c1 and the larger in c2.
    // - Print out the following on its own line. The same formatting rules as circle apply.
    //     Area_=_{pi*a*b}_units^2.Perimeter_=_{2*pi*sqrt([a*a+b*b]/2)}_units.
    //     Intercepts_:_{c1}_=_{a}_,_{c1}_=_{-a}_,_{c2}_=_{b}_,_{c2}_=_{-b}
    // - Example
    //         Area = 28.27 units^2. Perimeter = 18.85 units . Intercepts : a = 3 , a = -3 , b = 3 , b = -3
}