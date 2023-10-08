// univariate.cpp
#include "univariate.h"

// Univariate inherits publically from polynomial.
// This is a specialised version of polynomial, with 2 restrictions. The first restriction is that the polynomial can only contain one type of variable.
// The second restriction is a degree restriction. The univariate class has a degree variable.
// All terms in the univariate must have a degree less than or equal to the degree variable.
// # Members
// - degree: int
//     - This is the max degree for this univariate.
// - variable: char
//     - This is the only variable allowed in this univariate.

// Private
bool univariate::isUnivariate() const {
    for (int i = 0; i < this->getNumTerms(); i++) {
        term* t = (*this)[i];
        if ((t->getNumVariables() > 0 && t->getVarIndex(this->variable) == -1) || t->getDegree() > this->degree) {
            return false;
        }
    }
    return true;
}

void univariate::clearTerms() {
    for (int i = 0; i < this->getNumTerms(); i++) {
        delete (*this)[i];
        term* t = (*this)[i];
        t = NULL;
    }
    delete[] this->terms;
    this->terms = new term*[0];
    this->numTerms = 0;
}

// Public
univariate::univariate(int d, char c) : polynomial() {
    this->degree = d;
    this->variable = c;
}

univariate::univariate(term** t, int n) : polynomial(t, n) {
    this->degree = 2;
    this->variable = 'x';

    if (this->numTerms > 0) {
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->variable = this->terms[0]->getVariables()[0];
        }
    }

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

univariate::univariate(const char* input) : polynomial(input) {
    this->degree = 2;
    this->variable = 'x';

    if (this->numTerms > 0) {
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->variable = this->terms[0]->getVariables()[0];
        }
    }

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

univariate::univariate(const univariate& other) : polynomial(other) {
    // - This is the copy constructor.
    this->degree = other.degree;
    this->variable = other.variable;
}

univariate::univariate(const polynomial& other) : polynomial(other) {
    this->degree = 2;
    this->variable = 'x';

    if (this->numTerms > 0) {
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->variable = this->terms[0]->getVariables()[0];
        }
    }

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

univariate::univariate(term t) : polynomial(t) {
    this->degree = 2;
    this->variable = 'x';

    // Check if the current object is a valid univariate
    if (this->numTerms > 0) {
        this->degree = this->terms[0]->getDegree();
        if (this->terms[0]->getNumVariables() > 0) {
            this->variable = this->terms[0]->getVariables()[0];
        }
    }

    // Check if the current object is a valid univariate
    if (!this->isUnivariate()) {
        this->clearTerms();
    }
}

univariate& univariate::operator=(const univariate& other) {
    // - This is the assignment operator.
    if (this != &other) {
        polynomial::operator=(other);
        this->degree = other.degree;
        this->variable = other.variable;
    }
    return *this;
}

istream& operator>>(istream& is, univariate& u) {
    string line;
    getline(is, line);

    univariate temp(line.c_str());
    if (temp.isUnivariate() && temp.numTerms != 0) {
        u = temp;
    }
    return is;
}

polynomial* univariate::operator!() const {
    term** negatedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        negatedTerms[i] = new term((!(*(*this)[i])));
    }
    polynomial* th = new univariate(negatedTerms, this->getNumTerms());
    for (int i = 0; i < this->numTerms; i++) {
        delete negatedTerms[i];
        negatedTerms[i] = NULL;
    }
    delete[] negatedTerms;
    negatedTerms = NULL;
    return th;
}

polynomial* univariate::operator()(char* vars, int* vals, int numVals) const {
    // - This is the substitution operator.
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(this->terms[i]->operator()(vars, vals, numVals));
    }
    polynomial* th = new univariate(substitutedTerms, this->getNumTerms());
    for (int i = 0; i < this->numTerms; i++) {
        delete substitutedTerms[i];
        substitutedTerms[i] = NULL;
    }
    delete[] substitutedTerms;
    substitutedTerms = NULL;
    return th;
}

polynomial* univariate::operator()(string inp) const {
    // - This is the substitution operator.
    term** substitutedTerms = new term*[this->getNumTerms()];
    for (int i = 0; i < this->getNumTerms(); i++) {
        substitutedTerms[i] = new term(this->terms[i]->operator()(inp));
    }
    polynomial* th = new univariate(substitutedTerms, this->getNumTerms());
    for (int i = 0; i < this->numTerms; i++) {
        delete substitutedTerms[i];
        substitutedTerms[i] = NULL;
    }
    delete[] substitutedTerms;
    substitutedTerms = NULL;
    return th;
}

polynomial* univariate::operator+(const polynomial& other) const {
    // - This should return a univariate that is the result of adding the univariate and polynomial together.
    univariate* tempAdd = new univariate(*this);
    for (int i = 0; i < other.getNumTerms(); i++) {
        tempAdd->addOrRemoveTerm(other[i]);
    }

    return tempAdd;
}

polynomial& univariate::operator+=(const polynomial& other) {
    polynomial* myP = (*this + other);
    univariate* result = new univariate(*myP);
    if (result->isUnivariate()) {
        *this = *result;
    }
    delete myP;
    delete result;
    return *this;
}

polynomial* univariate::operator-(const polynomial& other) const {
    // - Subtraction is just adding the negation
    univariate* tempAdd = new univariate((*this));
    polynomial* negated = !other;
    for (int i = 0; i < negated->getNumTerms(); i++) {
        tempAdd->addOrRemoveTerm((*negated)[i]);
    }
    delete negated;
    return tempAdd;
}

polynomial& univariate::operator-=(const polynomial& other) {
    polynomial* myP = (*this - other);
    univariate* result = new univariate(*myP);
    if (result->isUnivariate()) {
        *this = *result;
    }
    delete myP;
    delete result;
    return *this;
}

// polynomial* univariate::operator*(const polynomial& other) const {
//     // - This should multiply the current object by the passed-in parameter.
//     if (other.getNumTerms() == 1) {
//         univariate* result = new univariate(*this);
//         for (int i = 0; i < result->getNumTerms(); i++) {
//             term* t = (*result)[i];
//             (*t) *= *(other[0]);
//         }
//         return result;
//     } else if (this->getNumTerms() == 1) {
//         univariate* result = new univariate(other);
//         for (int i = 0; i < result->getNumTerms(); i++) {
//             term* t = (*result)[i];
//             (*t) *= *(this->terms[0]);
//         }
//         return result;
//     } else if (this->getNumTerms() == 2) {
//         univariate* result = new univariate(*this);
//         term* trm = new term(!(*result->getTerms()[1]));
//         term* trm1 = new term(!(*result->getTerms()[0]));
//         result->addOrRemoveTerm(trm);
//         univariate* result_2 = new univariate(*this);
//         result_2->addOrRemoveTerm(trm1);
//         // std::cout << *result << std::endl;
//         // std::cout << *result_2 << std::endl;
//         univariate* final_result = new univariate(other);
//         for (int i = 0; i < final_result->getNumTerms(); i++) {
//             term* t = (*final_result)[i];
//             (*t) *= *((*result)[0]);
//         }
//         univariate* final_result_2 = new univariate(other);
//         for (int i = 0; i < final_result_2->getNumTerms(); i++) {
//             term* t = (*final_result_2)[i];
//             (*t) *= *((*result_2)[0]);
//         }

//         for (int k = 0; k < final_result->getNumTerms(); k++) {
//             final_result_2->addOrRemoveTerm((*final_result)[k]);
//         }

//         delete trm;
//         delete trm1;
//         delete result;
//         delete result_2;
//         delete final_result;
//         return final_result_2;
//     } else {
//         univariate* result = new univariate(other);
//         return result;
//     }
// }

polynomial* univariate::operator*(const polynomial& other) const {
    univariate* result = new univariate(this->degree, 'x');
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

polynomial& univariate::operator*=(const polynomial& other) {
    polynomial* myP = (*this * other);
    univariate* result = new univariate(*myP);
    if (result->isUnivariate()) {
        *this = *result;
    }
    delete myP;
    delete result;
    return *this;
}
