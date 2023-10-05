// bivariate.cpp
#include "bivariate.h"

// Bivariate inherits publically from polynomial. This is a specialised version of polynomial, with 2 restrictions.
// The first restriction is that the polynomial can have at most 2 types of variables.
// The second restriction is a degree restriction. The bivariate class has a degree variable.
// All terms in the bivariate must have a degree less than or equal to the degree variable.
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
    for (int i = 0; i < this->getNumTerms(); i++) {
        delete (*this)[i];
        term* t = (*this)[i];
        t = NULL;
    }
    delete[] this->terms;
    this->terms = new term*[0];
    this->numTerms = 0;
}

bool bivariate::isBivariate() const {
    for (int i = 0; i < this->getNumTerms(); i++) {
        term* t = (*this)[i];
        if (t->getVarIndex(this->v1) == -1 || t->getVarIndex(this->v2) == -1 || t->getDegree() > this->degree || t->getNumVariables != 2) {
            return false;
        }
    }
    return true;
}

// Public
bivariate::bivariate(int d, char c1, char c2) : polynomial() {
    this->degree = d;
    this->v1 = c1;
    this->v2 = c2;
}

bivariate::bivariate(term** t, int n) : polynomial(t, n) {
    this->degree = 2;
    this->v1 = 'x';
    this->v2 = 'y';

    if (this->numTerms > 0) {
        this->degree = t[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < t[k]->getNumVariables(); i++) {
                    char checkVariable = t[k]->getVariables()[i];
                    if (checkVariable != this->v1) {
                        this->v2 = checkVariable;
                        exitBothLoops = true;
                        break;
                    }
                }
                if (exitBothLoops) {
                    break;
                }
            }
        }
    }

    // Check if the current object is a valid bivariate
    if (!this->isBivariate()) {
        this->clearTerms();
    }
}

bivariate::bivariate(const char* input) : polynomial(input) {
    this->degree = 2;
    this->v1 = 'x';
    this->v2 = 'y';

    if (this->numTerms > 0) {
        this->degree = t[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < t[k]->getNumVariables(); i++) {
                    char checkVariable = t[k]->getVariables()[i];
                    if (checkVariable != this->v1) {
                        this->v2 = checkVariable;
                        exitBothLoops = true;
                        break;
                    }
                }
                if (exitBothLoops) {
                    break;
                }
            }
        }
    }

    // Check if the current object is a valid bivariate
    if (!this->isBivariate()) {
        this->clearTerms();
    }
}

bivariate::bivariate(const bivariate& other) : polynomial(other) {
    this->degree = other.degree;
    this->v1 = other.v1;
    this->v2 = other.v2;
}

bivariate::bivariate(const polynomial& other) : polynomial(other) {
    this->degree = 2;
    this->v1 = 'x';
    this->v2 = 'y';

    if (this->numTerms > 0) {
        this->degree = t[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < t[k]->getNumVariables(); i++) {
                    char checkVariable = t[k]->getVariables()[i];
                    if (checkVariable != this->v1) {
                        this->v2 = checkVariable;
                        exitBothLoops = true;
                        break;
                    }
                }
                if (exitBothLoops) {
                    break;
                }
            }
        }
    }

    // Check if the current object is a valid bivariate
    if (!this->isBivariate()) {
        this->clearTerms();
    }
}

bivariate::bivariate(term t) : polynomial(t) {
    this->degree = 2;
    this->v1 = 'x';
    this->v2 = 'y';

    if (this->numTerms > 0) {
        this->degree = t[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < t[k]->getNumVariables(); i++) {
                    char checkVariable = t[k]->getVariables()[i];
                    if (checkVariable != this->v1) {
                        this->v2 = checkVariable;
                        exitBothLoops = true;
                        break;
                    }
                }
                if (exitBothLoops) {
                    break;
                }
            }
        }
    }

    // Check if the current object is a valid bivariate
    if (!this->isBivariate()) {
        this->clearTerms();
    }
}

bivariate& bivariate::operator=(const bivariate& other) {
    // - This is the assignment operator.
    if (this != &other) {
        polynomial::operator=(other);
        this->degree = other.degree;
        this->v1 = other.v1;
        this->v2 = other.v2;
    }
    return *this;
}

istream& operator>>(istream& is, bivariate& u) {
    string line;
    getline(is, line);

    bivariate temp(line.c_str());
    if (temp.isBivariate() && temp.numTerms != 0) {
        u = temp;
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
    term** negatedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        negatedTerms[i] = new term((!(*(*this)[i])));
    }
    return new bivariate(negatedTerms, this->getNumTerms());
}

polynomial* bivariate::operator()(string inp) const {
    // - This is the substitution operator.
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(this->terms[i]->operator()(inp));
    }
    return new bivariate(substitutedTerms, this->getNumTerms());
}

polynomial* bivariate::operator+(const polynomial& other) const {
    // - This should return a bivariate that is the result of adding the bivariate and polynomial together.
    bivariate* tempAdd = new bivariate(*this);
    for (int i = 0; i < other.getNumTerms(); i++) {
        tempAdd->addOrRemoveTerm(other[i]);
    }

    return tempAdd;
}

polynomial& bivariate::operator+=(const polynomial& other) {
    bivariate* tempAdd = new bivariate(*this);
    for (int i = 0; i < other.getNumTerms(); i++) {
        tempAdd->addOrRemoveTerm(other[i]);
    }

    if (tempAdd->isBivariate()) {
        *this = *tempAdd;
    }
    return *this;
}

polynomial* bivariate::operator-(const polynomial& other) const {
    // - Subtraction is just adding the negation
    bivariate* tempAdd = new bivariate((*this));
    polynomial* negated = !other;
    for (int i = 0; i < negated->getNumTerms(); i++) {
        tempAdd->addOrRemoveTerm((*negated)[i]);
    }

    return tempAdd;
}

polynomial& bivariate::operator-=(const polynomial& other) {
    bivariate* tempAdd = new bivariate(*this);
    polynomial* negated = !other;
    for (int i = 0; i < negated->getNumTerms(); i++) {
        tempAdd->addOrRemoveTerm((*negated)[i]);
    }

    if (tempAdd->isBivariate()) {
        *this = *tempAdd;
    }
    return *this;
}

polynomial* bivariate::operator*(const polynomial& other) const {
    // // - This should return a bivariate which is the result of multiplying the current object by the passed-in parameter. Note that the result might be an invalid bivariate. This is fine as the return type is polynomial.
    // // - The distributive property of polynomial multiplication should be used. This means that you must multiply every term in the first polynomial with every term in the second polynomial. The results of these multiplications should then be added together.
    // // - For another explanation, click here.
    // polynomial result = *this * other;
    // return new bivariate(result.getDegree(), this->v1, this->v2, result.getTerms(), result.getNumTerms());
    return this;
}

polynomial& bivariate::operator*=(const polynomial& other) {
    // // - This operator might change the current object. If the result of multiplying the passedin parameter with the current object is a valid bivariate, then the current object should change to the result.
    // // - If the result of multiplying them together is not bivariate, then the current object should stay unchanged.
    // polynomial result = *this * other;
    // if (result.isBivariate()) {
    //     *this = result;
    // }
    return *this;
}