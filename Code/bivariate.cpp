// bivariate.cpp
#include "bivariate.h"

bivariate::bivariate(int d, char c1, char c2) {
}

bivariate::bivariate(term** t, int n) {
}

bivariate::bivariate(const char* input) {
}

bivariate::bivariate(const bivariate& other) {
}

bivariate::bivariate(const polynomial& other) {
    
}
bivariate::bivariate(term t) {
    
}

bivariate& bivariate::operator=(const bivariate& other) {
    return *this;
}

istream& operator>>(istream& is, univariate& u) {
    return is;
}

polynomial* bivariate::operator!() const {
    return new bivariate(2,'r', 'r');
}

polynomial* bivariate::operator()(char* vars, int* vals, int numVals) const {
    return new bivariate(2,'r', 'r');
}

polynomial* bivariate::operator()(string inp) const {
    return new bivariate(2,'r', 'r');
}

polynomial* bivariate::operator+(const polynomial& other) const {
    return new bivariate(2,'r', 'r');
}

polynomial& bivariate::operator+=(const polynomial& other) {
    return *(new bivariate(2,'r', 'r'));
}

polynomial* bivariate::operator-(const polynomial& other) const {
    return new bivariate(2,'r', 'r');
}

polynomial& bivariate::operator-=(const polynomial& other) {
    return *(new bivariate(2,'r', 'r'));
}

polynomial* bivariate::operator*(const polynomial& other) const {
    return new bivariate(2,'r', 'r');
}

polynomial& bivariate::operator*=(const polynomial& other) {
    return *(new bivariate(2,'r', 'r'));
}