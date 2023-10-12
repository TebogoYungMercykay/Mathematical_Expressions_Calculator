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
    if (this->v1 == this->v2 || this->numTerms != 3) {
        return false;
    }

    bool existsV1 = false;
    bool existsV2 = false;
    for (int i = 0; i < this->getNumTerms(); i++) {
        term* t = (*this)[i];
        int varIndexV1 = t->getVarIndex(this->v1);
        int varIndexV2 = t->getVarIndex(this->v2);
        if (varIndexV1 == -1 && varIndexV2 == -1 && (t->getNumVariables() != 0)) {
            return false;
        }
        if (varIndexV1 != -1) {
            existsV1 = true;
        }
        if (varIndexV2 != -1) {
            existsV2 = true;
        }
        if (t->getDegree() > this->degree) {
            return false;
        }
    }

    if ((existsV1 == false) || (existsV2 == false)) {
        return false;
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
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < this->terms[k]->getNumVariables(); i++) {
                    char checkVariable = this->terms[k]->getVariables()[i];
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
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < this->terms[k]->getNumVariables(); i++) {
                    char checkVariable = this->terms[k]->getVariables()[i];
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
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < this->terms[k]->getNumVariables(); i++) {
                    char checkVariable = this->terms[k]->getVariables()[i];
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
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->v1 = this->terms[0]->getVariables()[0];
            bool exitBothLoops = false;
            for (int k = 0; k < this->numTerms; k++) {
                for (int i = 0; i < this->terms[k]->getNumVariables(); i++) {
                    char checkVariable = this->terms[k]->getVariables()[i];
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

istream& operator>>(istream& input_string, bivariate& u) {
    string line;
    getline(input_string, line);

    bivariate temp(line.c_str());
    if (temp.isBivariate() && temp.numTerms != 0) {
        u = temp;
    }
    return input_string;
}

polynomial* bivariate::operator!() const {
    // - This is the negation operator.
    term** negatedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        negatedTerms[i] = new term((!(*(*this)[i])));
    }
    polynomial* th = new bivariate(negatedTerms, this->getNumTerms());
    for (int i = 0; i < this->numTerms; i++) {
        delete negatedTerms[i];
        negatedTerms[i] = NULL;
    }
    delete[] negatedTerms;
    negatedTerms = NULL;
    return th;
}

polynomial* bivariate::operator()(char* vars, int* vals, int numVals) const {
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(this->terms[i]->operator()(vars, vals, numVals));
    }
    polynomial* th = new bivariate(substitutedTerms, this->getNumTerms());
    for (int i = 0; i < this->numTerms; i++) {
        delete substitutedTerms[i];
        substitutedTerms[i] = NULL;
    }
    delete[] substitutedTerms;
    substitutedTerms = NULL;
    return th;
}

polynomial* bivariate::operator()(string inp) const {
    // - This is the substitution operator.
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(this->terms[i]->operator()(inp));
    }
    polynomial* th = new bivariate(substitutedTerms, this->getNumTerms());
    for (int i = 0; i < this->numTerms; i++) {
        delete substitutedTerms[i];
        substitutedTerms[i] = NULL;
    }
    delete[] substitutedTerms;
    substitutedTerms = NULL;
    return th;
}

polynomial* bivariate::operator+(const polynomial& other) const {
    // - This should return a bivariate that is the result of adding the bivariate and polynomial together.
    bivariate* result = new bivariate(*this);
    for (int i = 0; i < other.getNumTerms(); i++) {
        result->addOrRemoveTerm(other[i]);
    }

    return result;
}

polynomial& bivariate::operator+=(const polynomial& other) {
    polynomial* tempPolynomial = (*this + other);
    bivariate* result = new bivariate(*tempPolynomial);

    if (result->isBivariate()) {
        *this = *result;
    }

    delete tempPolynomial;
    delete result;
    return *this;
}

polynomial* bivariate::operator-(const polynomial& other) const {
    // - Subtraction is just adding the negation
    bivariate* result = new bivariate((*this));
    polynomial* negated = !other;
    for (int i = 0; i < negated->getNumTerms(); i++) {
        result->addOrRemoveTerm((*negated)[i]);
    }

    delete negated;
    return result;
}

polynomial& bivariate::operator-=(const polynomial& other) {
    polynomial* tempPolynomial = (*this - other);
    bivariate* result = new bivariate(*tempPolynomial);

    if (result->isBivariate()) {
        *this = *result;
    }

    delete tempPolynomial;
    delete result;
    return *this;
}

polynomial* bivariate::operator*(const polynomial& other) const {
    bivariate* result = new bivariate(this->degree, 'x', 'y');
    for (int i = 0; i < this->getNumTerms(); i++) {
        for (int j = 0; j < other.getNumTerms(); j++) {
            term* t1 = (*this)[i];
            term* t2 = other[j];
            term* t_product = new term((*t1) * (*t2));
            result->addOrRemoveTerm(t_product);
            delete t_product;
        }
    }
    return result;
}

polynomial& bivariate::operator*=(const polynomial& other) {
    polynomial* tempPolynomial = (*this * other);
    bivariate* result = new bivariate(*tempPolynomial);

    if (result->isBivariate()) {
        *this = *result;
    }

    delete tempPolynomial;
    delete result;
    return *this;
}