// polynomial.cpp
#include "polynomial.h"

polynomial::polynomial() : numTerms(0), terms(NULL) {}

polynomial::polynomial(term** t, int n) : numTerms(n) {
    terms = new term*[numTerms];
    for (int i = 0; i < numTerms; ++i) {
        terms[i] = new term(*t[i]);
    }
}

polynomial::polynomial(const char* input) : numTerms(0), terms(NULL) {
}

polynomial::polynomial(const polynomial& other) : numTerms(other.numTerms) {
    terms = new term*[numTerms];
    for (int i = 0; i < numTerms; ++i) {
        terms[i] = new term(*other.terms[i]);
    }
}

polynomial::polynomial(term t) : numTerms(1) {
    terms = new term*[1];
    terms[0] = new term(t);
}

polynomial& polynomial::operator=(const polynomial& other) {
    if (this != &other) {
        for (int i = 0; i < numTerms; ++i) {
            delete terms[i];
        }
        delete[] terms;

        numTerms = other.numTerms;
        terms = new term*[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            terms[i] = new term(*other.terms[i]);
        }
    }
    return *this;
}

polynomial::~polynomial() {
    for (int i = 0; i < numTerms; ++i) {
        delete terms[i];
    }
    delete[] terms;
}

term** polynomial::getTerms() const {
    return terms;
}

int polynomial::getNumTerms() const {
    return numTerms;
}

ostream& operator<<(ostream& os, const polynomial& p) {
    for (int i = 0; i < p.numTerms; ++i) {
        os << *p.terms[i];
        if (i < p.numTerms - 1) {
            os << " + ";
        }
    }
    return os;
}

term* polynomial::operator[](int idx) const {
    if (idx >= 0 && idx < numTerms) {
        return terms[idx];
    } else {
        return NULL;
    }
}

term* polynomial::operator[](int idx) {
    if (idx >= 0 && idx < numTerms) {
        return terms[idx];
    } else {
        return NULL;
    }
}