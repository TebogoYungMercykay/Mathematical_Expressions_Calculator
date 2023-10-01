// ellipse.cpp
#include "ellipse.h"

ellipse::ellipse(char c1, char c2) : bivariate(2, c1, c2) {
}

ellipse::ellipse(term** t, int n) : bivariate(t, n) {
}

ellipse::ellipse(const char* input) : bivariate(input) {
}

ellipse::ellipse(const ellipse& other) : bivariate(other.getTerms(), other.getNumTerms()) {
}

ellipse::ellipse(const polynomial& other) : bivariate(other.getTerms(), other.getNumTerms()) {

}

ellipse::ellipse(term t) : bivariate(t) {

}

void ellipse::printStats() const {

}
