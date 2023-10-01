// univariate.cpp
#include "univariate.h"

univariate::univariate(int d, char c) {
}

univariate::univariate(term** t, int n) {
}

univariate::univariate(const char* input) {
}

univariate::univariate(const univariate& other) {
}

univariate::univariate(const polynomial& other) {
    
}
univariate::univariate(term t) {
    
}

univariate& univariate::operator=(const univariate& other) {
    return *this;
}

polynomial* univariate::operator!() const {
    return new univariate(2,'r');
}

polynomial* univariate::operator()(char* vars, int* vals, int numVals) const {
    return new univariate(2,'r');
}

polynomial* univariate::operator()(string inp) const {
    return new univariate(2,'r');
}

polynomial* univariate::operator+(const polynomial& other) const {
    return new univariate(2,'r');
}

polynomial& univariate::operator+=(const polynomial& other) {
    return *(new univariate(2,'r'));
}

polynomial* univariate::operator-(const polynomial& other) const {
    return new univariate(2,'r');
}

polynomial& univariate::operator-=(const polynomial& other) {
    return *(new univariate(2,'r'));
}

polynomial* univariate::operator*(const polynomial& other) const {
    return new univariate(2,'r');
}

polynomial& univariate::operator*=(const polynomial& other) {
    return *(new univariate(2,'r'));
}
