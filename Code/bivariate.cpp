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
        delete this->terms[i];
        this->terms[i] = NULL;
    }

    delete [] this->terms;
    this->terms = NULL;

    this->numTerms = 0;
    this->terms = new term*[this->numTerms];
}

bool bivariate::isBivariate() const {
    if (this->numTerms > 0) {
        char variableTest[2] = {'9', '9'};
        int variableCount = 0;
        for (int i = 0; i < this->getNumTerms(); i++) {
            term* t = this->terms[i];
            if (t->getDegree() > this->degree) {
                return false;
            }
            if (t->getNumVariables() > 0) {
                for(int j = 0; j < t->getNumVariables(); j++) {
                    if (variableCount < 2) {
                        if (variableTest[0] == '9') {
                            variableTest[0] = t->getVariables()[j];
                            variableCount++;
                        } else if (variableTest[0] != t->getVariables()[j]) {
                            if (variableTest[1] == '9') {
                                variableTest[1] = t->getVariables()[j];
                                variableCount++;
                            } else if (variableTest[1] != t->getVariables()[j]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        if(variableCount == 2) {
            return true;
        }
    }
    return false;
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
    // - This is the copy constructor.
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
        negatedTerms[i] = new term((!(*this->terms[i])));
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
    polynomial* result = ((*this) + other);
    bivariate tempBivariate(*result);

    if (tempBivariate.numTerms != 0) {
        *this = tempBivariate;
    }

    delete result;
    return *this;
}

polynomial* bivariate::operator-(const polynomial& other) const {
    // - Subtraction is just adding the negation
    bivariate* result = new bivariate(*this);
    polynomial* negated = !other;

    for (int i = 0; i < negated->getNumTerms(); i++) {
        result->addOrRemoveTerm((*negated)[i]);
    }

    delete negated;
    return result;
}

polynomial& bivariate::operator-=(const polynomial& other) {
    polynomial* result = ((*this) - other);
    bivariate tempBivariate(*result);

    if (tempBivariate.numTerms != 0) {
        *this = tempBivariate;
    }

    delete result;
    return *this;
}

polynomial* bivariate::operator*(const polynomial& other) const {
    bivariate* result = new bivariate(this->degree, 'x', 'y');
    for (int i = 0; i < this->getNumTerms(); i++) {
        for (int j = 0; j < other.getNumTerms(); j++) {
            term* t1 = this->terms[i];
            term* t2 = other[j];
            term* t_product = new term((*t1) * (*t2));
            result->addOrRemoveTerm(t_product);
            delete t_product;
        }
    }
    return result;
}

polynomial& bivariate::operator*=(const polynomial& other) {
    polynomial* result = ((*this) * other);
    bivariate tempBivariate(*result);

    if (tempBivariate.numTerms != 0) {
        *this = tempBivariate;
    }

    delete result;
    return *this;
}
