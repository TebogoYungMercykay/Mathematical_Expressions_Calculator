// bivariate.cpp
#include "bivariate.h"

// - degree: int
//     - This is the max degree for this bivariate.
// - v1: char
//     - This is one of the variables for the bivariate.
//     - Note that there is no restriction about which variable is v1 and v2, other than that v1 cannot be the same as v2.
// - v2: char
//     - This is one of the variables for the bivariate.
//     - Note that there is no restriction about which variable is v1 and v2, other than that v2 cannot be the same as v1.

// Private:
void bivariate::clearTerms() {
    // If the 2 restrictions mentioned at the start of this subsection are true, then return true. If there are any invalid terms, return false.
    for (int i = 0; i < this->getNumTerms(); i++) {
        term* t = (*this)[i];
        // Check if the term contains the correct variables and has a degree within the allowed range
        if (t->containsVariables(this->v1, this->v2) && t->getDegree() <= this->degree) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool bivariate::isBivariate() const {
    // - This should set the polynomial parameters to their default values.
    // - Don't change the degree or variables.
    return this->v1 != this->v2;
}

// Public
bivariate::bivariate(int d, char c1, char c2) {
    // - This is a parameterized constructor.
    // - Call the default polynomial constructor, and then set the degree and variables to the passed-in parameters.
    this->degree = d;
    this->v1 = c1;
    this->v2 = c2;
}

bivariate::bivariate(term** t, int n) {
    // - This is a parameterized constructor.
    // - Call the corresponding polynomial constructor.
    // - Set the v1 to x, v2 to y, and the degree to 2.
    // - If the bivariate has terms, then set degree to the degree of the first term.
    // - If the first term has a variable, set this object's v1 to the first variable of the first term.
    // - Loop through all the variables in the polynomial and set v2 to the first variable which is not v1.
    // - Use the isBivariate() function to check if the current object is a valid bivariate. If it is not a valid bivariate, then call clearTerms.
    this->degree = 2; // Default degree
    this->v1 = 'x';
    this->v2 = 'y';

    // If the bivariate has terms, update degree, v1, and v2 based on the first term
    if (n > 0) {
        this->degree = (*t[0]).getDegree();
        this->v1 = (*t[0]).getFirstVariable();
        for (int i = 0; i < (*t[0]).getNumVariables(); i++) {
            char var = (*t[0]).getVariable(i);
            if (var != this->v1) {
                this->v2 = var;
                break;
            }
        }
    }

    // Check if the current object is a valid bivariate
    if (!isBivariate()) {
        clearTerms();
    }
}

bivariate::bivariate(const char* input) {
    // - Follow the same rules as the previous constructor.
    this->degree = 2; // Default degree
    this->v1 = 'x';
    this->v2 = 'y';

    // Check if the current object is a valid bivariate
    if (!isBivariate()) {
        clearTerms();
    }
}

bivariate::bivariate(const bivariate& other) {
    // - This is the copy constructor.
    this->degree = other.degree;
    this->v1 = other.v1;
    this->v2 = other.v2;
}

bivariate::bivariate(const polynomial& other) {
    // - Follow the same rules as the string constructor.
    this->degree = 2; // Default degree
    this->v1 = 'x';
    this->v2 = 'y';

    // Check if the current object is a valid bivariate
    if (!isBivariate()) {
        clearTerms();
    }
}
bivariate::bivariate(term t) {
    // - Follow the same rules as the string constructor.
    this->degree = 2; // Default degree
    this->v1 = 'x';
    this->v2 = 'y';

    // Check if the current object is a valid bivariate
    if (!isBivariate()) {
        clearTerms();
    }
}

bivariate& bivariate::operator=(const bivariate& other) {
    // - This is the assignment operator.
    if (this != &other) {
        // Call the base class assignment operator
        polynomial::operator=(other);
        this->degree = other.degree;
        this->v1 = other.v1;
        this->v2 = other.v2;
    }
    return *this;return *this;
}

istream& operator>>(istream& is, bivariate& u) {
    // - This will be used to set the member variables of the passed-in parameter.
    // - Extract one line from the passed-in stream.
    // - Use the string constructor to create a bivariate.
    // - If the created bivariate is a valid bivariate, the passed-in parameter should be changed to this.
    // - If the created bivariate is not a valid bivariate, the passed-in parameter should stay unchanged.
    // - Note: if you called the constructor, the result will always be bivariate; thus, use the numTerms to see if clearTerms() was called.
    string line;
    if (getline(is, line)) {
        // Use the string constructor to create a bivariate
        bivariate temp(line.c_str());

        // If the created bivariate is valid, update the passed-in parameter
        if (temp.isBivariate()) {
            u = temp;
        }
    }
    return is;
}

polynomial* bivariate::operator!() const {
    // - This is the negation operator.
    // - The returned bivariate should be made up of all the negated terms.
    term** negatedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        negatedTerms[i] = new term(-(*(*this)[i]));
    }
    return new bivariate(this->degree, this->v1, this->v2, negatedTerms, this->getNumTerms());
}

polynomial* bivariate::operator()(char* vars, int* vals, int numVals) const {
    // - This is the substitution operator.
    // - The returned bivariate should be the result of calling the substitution operator on every term.
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(*(*this)[i]);
        substitutedTerms[i]->substitute(vars, vals, numVals);
    }
    return new bivariate(this->degree, this->v1, this->v2, substitutedTerms, this->getNumTerms());
}

polynomial* bivariate::operator()(string inp) const {
    // - This is the substitution operator.
    // - This should follow the same rules as the previous operator.
    // - You may assume that the passed-in parameter will be the same format as the term substitution operator
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(*(*this)[i]);
        substitutedTerms[i]->substitute(inp);
    }
    return new bivariate(this->degree, this->v1, this->v2, substitutedTerms, this->getNumTerms());
}

polynomial* bivariate::operator+(const polynomial& other) const {
    // - This should return a bivariate that is the result of adding (this will also be the correct mathematical addition meaning) the bivariate and polynomial together. Note that the result might be an invalid bivariate. This is fine as the return type is polynomial.
    // - polynomial::addOrRemove() should be used to create a bivariate which is the result of adding all the terms together.
    polynomial result = *this + other;
    return new bivariate(result.getDegree(), this->v1, this->v2, result.getTerms(), result.getNumTerms());
}

polynomial& bivariate::operator+=(const polynomial& other) {
    // - This operator might change the current object. If the result of adding the current object and the passed-in parameter is a valid bivariate, then the current object should change to the result.
    // - If the result of adding them together is not bivariate, then the current object should stay unchanged.
    polynomial result = *this + other;
    if (result.isBivariate()) {
        *this = result;
    }
    return *this;
}

polynomial* bivariate::operator-(const polynomial& other) const {
    // - This should return a bivariate that is the result of subtracting the passed-in parameter from the current object. Note that the result might be an invalid bivariate. This is fine as the return type is polynomial.
    // - Hint: Subtraction is just adding the negation.
    polynomial result = *this - other;
    return new bivariate(result.getDegree(), this->v1, this->v2, result.getTerms(), result.getNumTerms());
}

polynomial& bivariate::operator-=(const polynomial& other) {
    // - This operator might change the current object. If the result of subtracting the passedin parameter from the current object is a valid bivariate, then the current object should change to the result.
    // - If the result of subtracting them is not bivariate, then the current object should stay unchanged.
    polynomial result = *this - other;
    if (result.isBivariate()) {
        *this = result;
    }
    return *this;
}

polynomial* bivariate::operator*(const polynomial& other) const {
    // - This should return a bivariate which is the result of multiplying the current object by the passed-in parameter. Note that the result might be an invalid bivariate. This is fine as the return type is polynomial.
    // - The distributive property of polynomial multiplication should be used. This means that you must multiply every term in the first polynomial with every term in the second polynomial. The results of these multiplications should then be added together.
    // - For another explanation, click here.
    polynomial result = *this * other;
    return new bivariate(result.getDegree(), this->v1, this->v2, result.getTerms(), result.getNumTerms());
}

polynomial& bivariate::operator*=(const polynomial& other) {
    // - This operator might change the current object. If the result of multiplying the passedin parameter with the current object is a valid bivariate, then the current object should change to the result.
    // - If the result of multiplying them together is not bivariate, then the current object should stay unchanged.
    polynomial result = *this * other;
    if (result.isBivariate()) {
        *this = result;
    }
    return *this;
}