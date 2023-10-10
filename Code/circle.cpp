// circle.cpp
#include "circle.h"
// Circle inherits publically from bivariate. This is a specialised version of bivariate.
// In this class, the degree variable is set to 2. Additionally, we will only be using circles centred around the origin.
// Thus only three terms are allowed. The first and second terms must have a degree of 2, and the last term
// must have a degree of 0. The first two terms must also have the same coefficient.

// Private:
bool circle::isCircle() const {
    if (this->getNumTerms() == 3) {
        if ((this->getTerms()[2])->getDegree() == 0) {
            if ((this->getTerms()[0])->getDegree() == (this->getTerms()[1])->getDegree()) {
                if ((this->getTerms()[1])->getDegree() == 2 && (*(this->getTerms()[0]))[6] == (*(this->getTerms()[1]))[6]) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Public:
circle::circle(char c1, char c2) : bivariate(2, c1, c2) {}

circle::circle(term** t, int n) : bivariate(t, n) {
    this->degree = 2;

    // Checking if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(const char* input) : bivariate(input) {
    this->degree = 2;

    // Checking if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(const circle& other) : bivariate(other.getTerms(), other.getNumTerms()) {
    this->degree = 2;

    // Checking if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(const polynomial &other) : bivariate(other.getTerms(), other.getNumTerms())  {
    this->degree = 2;

    // Checking if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

circle::circle(term t) : bivariate(t)  {
    this->degree = 2;

    // Checking if the current object is a valid univariate
    if (!this->isCircle()) {
        this->clearTerms();
    }
}

void circle::printStats() const {
    // - This function will print statistics about the circle.
    if (this->isCircle()) {
        double c = (*(this->getTerms()[0]))[6];
        double d = (*(this->getTerms()[1]))[6];
        double f = (*(this->getTerms()[2]))[6];
        char c1 = std::min(v1, v2);
        char c2 = std::max(v1, v2);
        if (f < 0) {
            double r = sqrt((-1 * f)/c);
            std::cout << std::fixed << std::setprecision(2) << "Area = " << (M_PI * r * r) << " units^2.Perimeter = " << (2 * M_PI * r) << " units.Intercepts : " << c1 << " = " << r << " , " << c1 << " = " << -1 * r << " , " << c2 << " = " << r << " , " << c2 << " = " << -1 * r << std::endl;
        } else {
            std::cout << "Not a real circle" << std::endl;
        }
    } else {
        std::cout << "Not a real circle" << std::endl;
    }
}