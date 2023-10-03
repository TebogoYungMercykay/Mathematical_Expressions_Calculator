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

bool isUnivariate() const {
    // - If the 2 restrictions mentioned at the start of this subsection are true, then return true. If there are any invalid terms, return false.
}

void clearTerms() {
    // - This should set the polynomial parameters to their default values.
    // - Don't change the degree or variable
}

univariate::univariate(int d, char c) {
    // - This is a parameterized constructor.
    // - Call the default polynomial constructor, and then set the degree and variable to the passed-in parameter.
}

univariate::univariate(term** t, int n) {
    // - This is a parameterized constructor.
    // - Call the corresponding polynomial constructor.
    // - Set variable equal to x, and degree to 2.
    // - If the univariate has terms, then set degree to the degree of the first term.
    // - If the first term contains a variable, set this object’s variable to the first variable of the first term.
    // - Use the isUnivariate() function to check if the current object is a valid univariate. If it is not a valid univariate, then call clearTerms.
}

univariate::univariate(const char* input) {
    // - Follow the same rules as the previous constructor.
}

univariate::univariate(const univariate& other) {
    // - This is the copy constructor.
}

univariate::univariate(const polynomial& other) {
    // - Follow the same rules as the string constructor.
}
univariate::univariate(term t) {
    // - Follow the same rules as the string constructor.
}

univariate& univariate::operator=(const univariate& other) {
    // - This is the assignment operator.
    return *this;
}

istream& operator>>(istream& is, univariate& u) {
    // - This will be used to set the member variables of the passed-in parameter.
    // - Extract one line from the passed-in stream.
    // - Use the string constructor to create a univariate.
    // - If the created univariate is a valid univariate, the passed-in parameter should be changed to this.
    // - If the created univariate is not a valid univariate, the passed-in parameter should stay unchanged.
    // - Note: if you called the constructor, the result will always be univariate; thus, use the numTerms to see if clearTerms() was called.
    return is;
}

polynomial* univariate::operator!() const {
    // - This is the negation operator. This won’t change the current object.
    // - The returned univariate, should be made up of all the negated terms.
    return new univariate(2,'r');
}

polynomial* univariate::operator()(char* vars, int* vals, int numVals) const {
    // - This is the substitution operator.
    // - The returned univariate, should be the result of calling the substitution operator on every term
    return new univariate(2,'r');
}

polynomial* univariate::operator()(string inp) const {
    // - This is the substitution operator.
    // - This should follow the same rules as the previous operator.
    // - You may assume that the passed-in parameter will be the same format as the term substitution operator.
    return new univariate(2,'r');
}

polynomial* univariate::operator+(const polynomial& other) const {
    // - This should return a univariate that is the result of adding (this will also be the correct mathematical addition meaning) the univariate and polynomial together. Note that the result might be an invalid univariate. This is fine as the return type is polynomial.
    // - polynomial::addOrRemove() should be used to create a univariate which is the result of adding all the terms together.  
    return new univariate(2,'r');
}

polynomial& univariate::operator+=(const polynomial& other) {
    // - This operator might change the current object. If the result of adding the current object and the passed-in parameter is a valid univariate, then the current object should change to the result.
    // - If the result of adding them together is not univariate, then the current object should stay unchanged.
    return *(new univariate(2,'r'));
}

polynomial* univariate::operator-(const polynomial& other) const {
    // - This should return a univariate that is the result of subtracting the passed-in parameter from the current object. Note that the result might be an invalid univariate. This is fine as the return type is polynomial.
    // - Hint: Subtraction is just adding the negation
    return new univariate(2,'r');
}

polynomial& univariate::operator-=(const polynomial& other) {
    // - This operator might change the current object. If the result of subtracting the passedin parameter from the current object is a valid univariate, then the current object should change to the result.
    // - If the result of subtracting them is not univariate, then the current object should stay unchanged.
    return *(new univariate(2,'r'));
}

polynomial* univariate::operator*(const polynomial& other) const {
    // - This should return a univariate which is the result of multiplying the current object by the passed-in parameter. Note that the result might be an invalid univariate. This is fine as the return type is polynomial.
    // - The distributive property of polynomial multiplication should be used. This means that you must multiply every term in the first polynomial with every term in the second polynomial. The results of these multiplications should then be added together.
    // - For another explanation, click here.
    return new univariate(2,'r');
}

polynomial& univariate::operator*=(const polynomial& other) {
    // - This operator might change the current object. If the result of multiplying the passedin parameter with the current object is a valid univariate, then the current object should change to the answer.
    // - If the result of multiplying them together is not univariate, then the current object should stay unchanged.
    // - Note that the same variable and degree should be used as the current object.
    eturn *(new univariate(2,'r'));
}
