// circle.cpp
#include "circle.h"

bool circle::isCircle() const {
    return false;
}

circle::circle(char c1, char c2) : bivariate(2, c1, c2) {
}

circle::circle(term** t, int n) : bivariate(t, n) {
}

circle::circle(const char* input) : bivariate(input) {
}

circle::circle(const circle& other) : bivariate(other.getTerms(), other.getNumTerms()) {
}

circle::circle(const polynomial &other) : bivariate(other.getTerms(), other.getNumTerms())  {

}

circle::circle(term t) : bivariate(t)  {

}

void circle::printStats() const {

}
