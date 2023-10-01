// term.cpp
#include "term.h"

// Implement term class member functions here
/*
- coefficient: int
    - This is the number that forms the first part of the term.
    - In the example, this will have the value 10.
    - If this is 0, that means the whole term is 0. Thus, numVariables should be 0, and the sizes of the variables array and powers array should also be 0. If this is 0 at any time, then the arrays should be cleared to achieve this->
    - The default value for this member variable is 1.
- numVariables: int
    - This is the number of unique variables within the term.
    - In the example, this will have the value 3.
    - The default value for this is 0.
- variables: char*
    - This is a character array which holds the unique variables within the term.
    - In the example, this will have the value [x,y,z].
    - This array will always be of length numVariables.
    - This array will always be sorted alphabetically.
    - The default value for this is an array of length 0.
- powers: int*
    - This is an integer array which holds the powers of the term.
    - In the example, this will have the value [2,3,4].
    - This array will always be of length numVariables.
    - The indices of this array will match the variables array. Thus, the value at position 0, is the power of the variable that is stored in variables[0].
    - The default value for this is an array of length 0.
*/
// Private Members
void term::addVariable(char var, int pow) {
    if (this->numVariables == 0) {
        // Create arrays with one element
        this->variables = new char[1];
        this->powers = new int[1];
        this->variables[0] = var;
        this->powers[0] = pow;
        this->numVariables = 1;
    }
    else {
        // Check if the variable is already in the term
        for (int i = 0; i < this->numVariables; i++) {
            if (this->variables[i] == var) {
                // Variable already exists, increase the power
                this->powers[i] += pow;
                return; // Exit the function
            }
        }

        // Variable doesn't exist, add it to the term
        char* newVariables = new char[this->numVariables + 1];
        int* newPowers = new int[this->numVariables + 1];
        for (int i = 0; i < this->numVariables; i++) {
            newVariables[i] = this->variables[i];
            newPowers[i] = this->powers[i];
        }

        newVariables[this->numVariables] = var;
        newPowers[this->numVariables] = pow;

        delete[] variables;
        delete[] powers;

        this->variables = newVariables;
        this->powers = newPowers;
        this->numVariables++;
    }
}

void term::removeVariable(char var) {
    int indexToRemove = -1;
    for (int i = 0; i < this->numVariables; i++) {
        if (variables[i] == var) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1) {
        // Shift elements to the left to remove the variable
        for (int j = indexToRemove; j < this->numVariables - 1; j++) {
            this->variables[j] = this->variables[j + 1];
            this->powers[j] = this->powers[j + 1];
        }
        // Clear the last element
        this->variables[this->numVariables - 1] = '\0';
        this->powers[this->numVariables - 1] = 0;
        this->numVariables--;

        // Resize the arrays to the new size
        char* newVariables = new char[this->numVariables];
        int* newPowers = new int[this->numVariables];
        for (int i = 0; i < this->numVariables; i++) {
            newVariables[i] = this->variables[i];
            newPowers[i] = this->powers[i];
        }

        delete[] variables;
        delete[] powers;

        this->variables = newVariables;
        this->powers = newPowers;
    }
}

// term constructor
term::term() {
    // Implement constructor
    this->coefficient = 1;
    this->numVariables = 0;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];
}

// Copy constructor
term::term(const term& other) {
    // Implement copy constructor
    this->coefficient = other.coefficient;
    this->numVariables = other.numVariables;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];
    for (int i = 0; i < this->numVariables; i++) {
        this->variables[i] = other.variables[i];
        this->powers[i] = other.powers[i];
    }
}

// Parameterized constructor
term::term(int c, int n, char* v, int* p) {
    // Implement parameterized constructor
    this->coefficient = c;
    this->numVariables = n;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];
    for (int i = 0; i < this->numVariables; i++) {
        this->variables[i] = v[i];
        this->powers[i] = p[i];
    }
}

// Constructor from input string
term::term(const char* input) {
    // Implement constructor from input string
}

// Assignment operator
term& term::operator=(const term& other) {
    // Implement assignment operator
    return *(new term());
}

// Destructor
term::~term() {
    // Implement destructor
}

char* term::getVariables() const {
    return this->variables;
}

int term::getNumVariables() const {
    return this->numVariables;
}

int term::getDegree() const {
    return 0 /*this->*/;
}

int term::getVarIndex(char var) const {
    for (int i = 0; i < numVariables; i++) {
        if (variables[i] == var) {
            return i;
        }
    }
    return -1;
}

string term::operator~() const {
    return "";
}

ostream& operator<<(ostream& os, const term& t) {
    return os;
}

istream& operator>>(istream& is, term& t) {
    return is;
}

const term term::operator*(const term& other) const {
    return other;
}

term& term::operator*=(const term& other) {
    return *(new term());
}

const term term::operator()(char* vars, int* vals, int numVals) const {
    return NULL;
}

const term term::operator()(string inp) const {
    return NULL;
}

bool term::operator==(const term& other) const {
    return false;
}

bool term::operator<(const term& other) const {
    return false;
}

bool term::operator>(const term& other) const {
    return false;
}

int& term::operator[](int idx) {
    return *(new int(0));
}

const term term::operator!() const {
    return NULL;
}
