// ellipse.cpp
#include "ellipse.h"
// Ellipse inherits publically from bivariate. This is a specialised version of bivariate. In this class, the degree variable is set to 2.
// Additionally, we will only be using ellipses centred around the origin. Thus only three terms are allowed.
// The first and second terms must have a degree of 2, and the last term must have a degree of 0.

// Private:
bool ellipse::isEllipse() const {
    if (this->getNumTerms() == 3) {
        if ((this->getTerms()[2])->getDegree() == 0) {
            if ((this->getTerms()[0])->getDegree() == (this->getTerms()[1])->getDegree()) {
                if ((this->getTerms()[1])->getDegree() == 2) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Public:
ellipse::ellipse(char c1, char c2) : bivariate(2, c1, c2) {}

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
    if (isEllipse()) {
        double c = (*(this->getTerms()[0]))[6];
        double d = (*(this->getTerms()[1]))[6];
        double f = (*(this->getTerms()[2]))[6];
        char c1 = std::min(this->v1, this->v2);
        char c2 = std::max(this->v1, this->v2);
        if (f < 0) {
            double a = sqrt((-1 * f)/c);
            double b = sqrt((-1 * f)/d);
            std::cout << std::fixed << std::setprecision(2) << "Area = " << (M_PI * a * b) << " units^2.Perimeter = " << (2 * M_PI * sqrt((a * a + b * b)/2)) << " units.Intercepts : " << c1 << " = " << a << " , " << c1 << " = " << -1 * a << " , " << c2 << " = " << b << " , " << c2 << " = " << -1 * b << std::endl;
        } else {
            std::cout << "Not a real ellipse" << std::endl;
        }
    } else {
        std::cout << "Not a real ellipse" << std::endl;
    }
}