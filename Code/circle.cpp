// circle.cpp
#include "circle.h"
// Circle inherits publically from bivariate. This is a specialised version of bivariate.
// In this class, the degree variable is set to 2. Additionally, we will only be using circles centred around the origin.
// Thus only three terms are allowed. The first and second terms must have a degree of 2, and the last term
// must have a degree of 0. The first two terms must also have the same coefficient.

// Private:
bool circle::isCircle() const {
    circle myCircle = (*this);
    if (myCircle.getNumTerms() == 3 && myCircle[2]->getDegree() == 0) {
        if (myCircle[0]->getDegree() == myCircle[1]->getDegree()) {
            if (myCircle[1]->getDegree() == 2 && (myCircle[0])[6] == (myCircle[1])[6]) {
                delete myCircle;
                return true;
            }
        }
    }
    delete myCircle;
    return false;
}

// Public
circle::circle(char c1, char c2) : bivariate(2, c1, c2) {}

circle::circle(term** t, int n) : bivariate(t, n) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(const char* input) : bivariate(input) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(const circle& other) : bivariate(other.getTerms(), other.getNumTerms()) {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(const polynomial &other) : bivariate(other.getTerms(), other.getNumTerms())  {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(term t) : bivariate(t)  {
    this->degree = 2;

    // Check if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

void circle::printStats() const {
    // - This function will print statistics about the circle.
    // - The explanation will assume our circle has the equation: cx2 + dy2 + f.
    // - Note that the x, y can be any variables.
    // - Start by extracting the values for c, d and f.
    // - If f is not negative or the circle is invalid, then print out the following on its own line:
    //     Not a real circle
    // - Calculate the radius of the circle using r = sqrt((−f)/c).
    // - Look at the two character member variables. Save the smallest of these two in c1 and the larger in c2.
    // - Print out the following on its own line. Note that everything should be on one line, even though the spec shows multiple lines. All values should be displayed to 2 decimal values. Note that values in curly braces should be evaluated, and _ indicates spaces.
    //     Area_=_{pi*r*r}_units^2.Perimeter_=_{2*pi*r}_units.1
    //     Intercepts_:_{c1}_=_{r}_,_{c1}_=_{-r}_,_{c2}_=_{r}_,_{c2}_=_{-r}
    //     - Example
    //         Area = 28.27 units^2. Perimeter = 18.85 units .Intercepts : a = 3 , a = -3 , b = 3 , b = -3
}