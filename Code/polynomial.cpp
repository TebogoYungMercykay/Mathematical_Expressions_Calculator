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
    // Parse the input string to create terms and initialize the polynomial.
    // You need to implement this part based on your input format.
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
        // Delete existing terms
        for (int i = 0; i < numTerms; ++i) {
            delete terms[i];
        }
        delete[] terms;

        // Copy terms from the other polynomial
        numTerms = other.numTerms;
        terms = new term*[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            terms[i] = new term(*other.terms[i]);
        }
    }
    return *this;
}

polynomial::~polynomial() {
    // Delete all terms
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
    // Implement how you want to print the polynomial
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
        // Handle out-of-bounds index, for example, return NULL or throw an exception.
        return NULL;
    }
}

term* polynomial::operator[](int idx) {
    if (idx >= 0 && idx < numTerms) {
        return terms[idx];
    } else {
        // Handle out-of-bounds index, for example, return NULL or throw an exception.
        return NULL;
    }
}