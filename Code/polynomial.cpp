// polynomial.cpp
#include "polynomial.h"

// Private
void polynomial::addOrRemoveTerm(term* t) {
    int i = 0;
    for (i = 0; i < this->numTerms; i++) {
        if ((*this->terms[i]) == *t) {
            // operator*=
            (*this->terms[i]) *= (*t);
            if (this->terms[i][this->terms[i]->getNumVariables() + 2] == 0) {
                for (int j = i; j < this->numTerms - 1; j++) {
                    this->terms[j] = this->terms[j + 1];
                }
                delete this->terms[this->numTerms - 1];
                this->terms[this->numTerms - 1] = NULL;
                this->numTerms--;
                term** newTerm = new term*[this->numTerms];
                for (int p = 0; p < this->numTerms; p++) {
                    newTerm[p] = this->terms[p];
                }
                delete[] this->terms;
                this->terms = newTerm;
            }
            return; // Exit the function
        }
        if ((*this->terms[i]) > *t) {
            break;
        }
    }
    term** newTerm1 = new term*[this->numTerms + 1];
    for (int p = 0; p < i; p++) {
        newTerm1[p] = this->terms[p];
    }

    // Adding
    newTerm1[i] = t;

    for (int p = i + 1; p < this->numTerms + 1; p++) {
        newTerm1[p] = this->terms[p - 1];
    }

    if (this->terms != NULL) {
        delete[] this->terms;
        this->terms = NULL;
    }
    this->terms = newTerm1;
    this->numTerms++;
}

int polynomial::termIndex(term* t) const {
    for (int i = 0; i < this->numTerms; i++) {
        if (*t == *(this->terms[i])) {
            return i;
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
            this->addOrRemoveTerm(t[i]);
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
            if (input_string[i] == ' ') {
                continue;
            } else {
                general_use_string += input_string[i];
            }
        }
        for (int i = 0; i < general_use_string.length(); i++) {
            if (general_use_string[i] == '+' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '-')) {
                general_use_string2 += '-';
                i += 1;
            }
            else if (general_use_string[i] == '-' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '+')) {
                general_use_string2 += '-';
                i += 1;
            }
            else if (general_use_string[i] == '-' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '-')) {
                general_use_string2 += '+';
                i += 1;
            }
            else if (general_use_string[i] == '+' && (i < general_use_string.length() - 2 && general_use_string[i + 1] == '+')) {
                general_use_string2 += '+';
                i += 1;
            }
            else {
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
            std::cout << general_use_string << std::endl;
            term* t = new term(general_use_string.c_str());
            std::cout << ~(*t);
            // this->addOrRemoveTerm(t);
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

ostream& operator<<(ostream& os, const polynomial& p) {
    if (p.numTerms == 0) {
        os << "0" << std::endl;
        return os;
    } else {
        for (int i = 0; i < p.numTerms; i++) {
            os << ~(*p.terms[i]);
            if (i < p.numTerms - 1) {
                os << " + ";
            }
        }
        os << std::endl;
        return os;
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