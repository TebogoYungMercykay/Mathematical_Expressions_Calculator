// polynomial.cpp
#include "polynomial.h"

// - numTerms: int
//     - This is the number of terms in the polynomial.
//     - The default value for this is 0.
// - terms: term**
//     - This is a 1D dynamic array of dynamic term objects of size numTerms.
//     - This will store the terms in the polynomial.
//     - This array will always be sorted ascending using the term relational operators.
//     - The default value for this is an array of size 0.

// Private
void polynomial::addOrRemoveTerm(term* t) {
    if (t != NULL) {
        int i = 0;
        for (i = 0; i < this->numTerms; i++) {
            if ((*this->terms[i]) == *t) {
                int& coeffLHS = (*this->terms[i])[(this->terms[i])->getNumVariables()];
                int coeffRHS = (*t)[t->getNumVariables()];

                coeffLHS += coeffRHS;
                if (coeffLHS == 0) {
                    delete this->terms[i];
                    this->terms[i] = NULL;
                    for (int j = i; j < this->numTerms - 1; j++) {
                        this->terms[j] = this->terms[j + 1];
                    }
                    this->numTerms--;
                    return;
                }

                return; // Exit the function
            }
            if ((*this->terms[i]) > *t) {
                break;
            }
        }
        term** newTerms = new term*[this->numTerms + 1];

        for (int p = 0; p < i; p++) {
            newTerms[p] = this->terms[p];
        }

        newTerms[i] = new term(*t);
        for (int p = i; p < this->numTerms; p++) {
            newTerms[p + 1] = this->terms[p];
        }

        delete[] this->terms;
        this->terms = newTerms;
        this->numTerms++;
    }
}

int polynomial::termIndex(term* t) const {
    if (t != NULL) {
        for (int i = 0; i < this->numTerms; i++) {
            if (*t == *(this->terms[i])) {
                return i;
            }
        }
    }
    return -1;
}

// Public
polynomial::polynomial() {
    this->numTerms = 0;
    this->terms = new term*[this->numTerms];
}

polynomial::polynomial(term** t, int n) {
    this->numTerms = 0;
    this->terms = new term*[this->numTerms];
    if (t != NULL) {
        for (int i = 0; i < n; i++) {
            if (t[i] != NULL) {
                this->addOrRemoveTerm(t[i]);
            }
        }
    }
}

polynomial::polynomial(const char* input) {
    this->numTerms = 0;
    this->terms = new term*[this->numTerms];
    if (input != NULL && input[0] != '\0') {
        std::string input_string(input);
        string general_use_string = "", general_use_string2 = "";
        for (int i = 0; i < input_string.length(); i++) {
            if (input_string[i] != ' ') {
                general_use_string += input_string[i];
            }
        }
        for (int i = 0; i < general_use_string.length(); i++) {
            if (general_use_string[i] == '+' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '-')) {
                general_use_string2 += '-';
                i += 1;
            } else if (general_use_string[i] == '-' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '+')) {
                general_use_string2 += '-';
                i += 1;
            } else if (general_use_string[i] == '-' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '-')) {
                general_use_string2 += '+';
                i += 1;
            } else if (general_use_string[i] == '+' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '+')) {
                general_use_string2 += '+';
                i += 1;
            } else {
                general_use_string2 += general_use_string[i];
            }
        }
        std::string delimiter = "";
        size_t pos = 0;
        while ((pos = general_use_string2.find_first_of("+-", pos)) != std::string::npos) {
            if (pos > 0 && general_use_string2[pos - 1] == '^') {
                pos++;
            } else {
                std::string sign(1, general_use_string2[pos]);  // Extract the sign character
                general_use_string2.insert(pos, ",");
                pos += 2;
            }
        }
        if (general_use_string2[0] == ',') {
            general_use_string2 = general_use_string2.substr(1);
        }
        stringstream separate (general_use_string2);
        general_use_string = "";
        while (getline(separate, general_use_string, ',')) {
            term* t = new term(general_use_string.c_str());
            this->addOrRemoveTerm(t);
            delete t;
            general_use_string = "";
        }
    }
}

polynomial::polynomial(const polynomial& other) {
    this->numTerms = other.numTerms;
    this->terms = new term*[this->numTerms];

    for (int i = 0; i < this->numTerms; i++) {
        this->terms[i] = new term(*other.terms[i]);
    }
}

polynomial::polynomial(term t) {
    this->numTerms = 1;
    this->terms = new term*[1];
    this->terms[0] = new term(t);
}

polynomial& polynomial::operator=(const polynomial& other) {
    if (this != &other) {
        for (int i = 0; i < this->numTerms; i++) {
            delete this->terms[i];
            this->terms[i] = NULL;
        }
        delete[] this->terms;

        this->numTerms = other.numTerms;
        this->terms = new term*[this->numTerms];

        for (int i = 0; i < this->numTerms; i++) {
            this->terms[i] = new term(*other.terms[i]);
        }
    }
    return *this;
}

polynomial::~polynomial() {
    for (int i = 0; i < this->numTerms; i++) {
        delete this->terms[i];
        this->terms[i] = NULL;
    }
    delete[] this->terms;
    this->terms = NULL;
}

term** polynomial::getTerms() const {
    return this->terms;
}

int polynomial::getNumTerms() const {
    return this->numTerms;
}

ostream& operator<<(ostream& output_string, const polynomial& p) {
    if (p.numTerms == 0) {
        output_string << "0" << std::endl;
        return output_string;
    } else {
        for (int i = 0; i < p.numTerms; i++) {
            output_string << ~(*p[i]);
            if (i < p.numTerms - 1) {
                output_string << " + ";
            }
        }
        output_string << std::endl;
        return output_string;
    }
}

term* polynomial::operator[](int idx) const {
    if (idx >= 0 && idx < this->numTerms) {
        return this->terms[idx];
    } else {
        return NULL;
    }
}

term* polynomial::operator[](int idx) {
    if (idx >= 0 && idx < this->numTerms) {
        return this->terms[idx];
    } else {
        return NULL;
    }
}