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
    if (this->coefficient != 0 && pow > 0) {
        int i;
        for (i = 0; i < this->numVariables; i++) {
            if (this->variables[i] == var) {
                this->powers[i] += pow;
                return; // Exit the function
            }
            if (this->variables[i] > var) {
                break;
            }
        }

        char* newVariables = new char[this->numVariables + 1];
        int* newPowers = new int[this->numVariables + 1];
        for (int j = 0; j < i; j++) {
            newVariables[j] = this->variables[j];
            newPowers[j] = this->powers[j];
        }

        newVariables[i] = var;
        newPowers[i] = pow;

        for (int j = i+1; j < this->numVariables + 1; j++) {
            newVariables[j] = this->variables[j-1];
            newPowers[j] = this->powers[j-1];
        }

        if (this->variables != NULL) {
            delete [] this->variables;
            this->variables = NULL;
        }
        if (this->powers != NULL) {
            delete[] this->powers;
            this->powers = NULL;
        }

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
        for (int j = indexToRemove; j < this->numVariables - 1; j++) {
            this->variables[j] = this->variables[j + 1];
            this->powers[j] = this->powers[j + 1];
        }
        this->variables[this->numVariables - 1] = '\0';
        this->powers[this->numVariables - 1] = 0;
        this->numVariables--;

        char* newVariables = new char[this->numVariables];
        int* newPowers = new int[this->numVariables];
        for (int i = 0; i < this->numVariables; i++) {
            newVariables[i] = this->variables[i];
            newPowers[i] = this->powers[i];
        }

        delete[] this->variables;
        delete[] this->powers;

        this->variables = newVariables;
        this->powers = newPowers;
    }
}

// Public Members

term::term() {
    this->coefficient = 1;
    this->numVariables = 0;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];
}

term::term(const term& other) {
    this->coefficient = other.coefficient;
    this->numVariables = other.numVariables;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];
    for (int i = 0; i < this->numVariables; i++) {
        this->variables[i] = other.variables[i];
        this->powers[i] = other.powers[i];
    }
}

term::term(int c, int n, char* v, int* p) {
    this->coefficient = c;
    this->numVariables = 0;
    this->variables = new char[this->numVariables];
    this->powers = new int[this->numVariables];
    if (v != NULL && p != NULL) {
        for (int i = 0; i < n; i++) {
            this->addVariable(v[i], p[i]);
        }
    }
}

term::term(const char* input) {
    if (input != NULL && input[0] != '\0') {
        this->coefficient = 1;
        this->numVariables = 0;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
        std::string input_string(input);
        if (input_string.length() == 1) {
            if (isdigit(input_string[0])) {
                stringstream coeff (input_string);
                int coeff_conv = 0;
                coeff >> coeff_conv;
                this->coefficient *= coeff_conv;
            } else {
                char variable = input_string[0];
                this->addVariable(variable, 1);
            }
        } else if (input_string.length() == 2 && (input_string[0] == '-' || input_string[0] == '+')) {
            if (isdigit(input_string[1])) {
                stringstream coeff (input_string);
                int coeff_conv = 0;
                coeff >> coeff_conv;
                this->coefficient *= coeff_conv;
            } else {
                if (input_string[0] == '-') {
                    this->coefficient = -1;
                }
                char variable = input_string[1];
                this->addVariable(variable, 1);
            }
        } else if (input_string.length() > 1) {
            if (input_string[0] == '-') {
                this->coefficient *= -1;
                input_string = input_string.substr(1);
            } else if (input_string[0] == '+') {
                input_string = input_string.substr(1);
            }

            stringstream coeff_full (input_string);
            string general_use_string = "";
            getline(coeff_full, general_use_string, '*');
            if (isdigit(general_use_string[0])) {
                stringstream coeff (general_use_string);
                int coeff_conv = 0;
                coeff >> coeff_conv;
                this->coefficient *= coeff_conv;
                input_string = input_string.substr(general_use_string.length() + 1);
            }
            // std::cout << "Coeff: " << this->coefficient << " Other: " << input_string << std::endl;
            if (this->coefficient != 0 && input_string.length() > 1) {
                general_use_string = "";
                stringstream variables_and_powers (input_string);
                while(getline(variables_and_powers, general_use_string, '*')) {
                    // std::cout << "Printing: " << general_use_string << std::endl;
                    if (general_use_string.length() >= 3) {
                        stringstream variable_n_power (general_use_string);
                        general_use_string = "";
                        getline(variable_n_power, general_use_string, '^');
                        char variable = general_use_string[0];
                        general_use_string = "";
                        getline(variable_n_power, general_use_string);
                        stringstream conv (general_use_string);
                        int power = 0;
                        conv >> power;
                        this->addVariable(variable, power);
                    } else if (general_use_string.length() == 1) {
                        char variable = general_use_string[0];
                        this->addVariable(variable, 1);
                    }
                }
            }
        }
    }
}

term& term::operator=(const term& other) {
    if (this != &other) {
        delete[] this->variables;
        delete[] this->powers;

        this->coefficient = other.coefficient;
        this->numVariables = other.numVariables;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];

        for (int i = 0; i < this->numVariables; i++) {
            this->variables[i] = other.variables[i];
            this->powers[i] = other.powers[i];
        }
    }
    return *this;
}

term::~term() {
    delete[] this->variables;
    this->variables = NULL;
    delete[] this->powers;
    this->powers = NULL;
}


char* term::getVariables() const {
    return this->variables;
}

int term::getNumVariables() const {
    return this->numVariables;
}

int term::getDegree() const {
    int degree = 0;
    for (int i = 0; i < this->numVariables; i++) {
        degree += this->powers[i];
    }
    return degree;
}

int term::getVarIndex(char var) const {
    for (int i = 0; i < this->numVariables; i++) {
        if (this->variables[i] == var) {
            return i;
        }
    }
    return -1;
}

std::string term::operator~() const {
    std::stringstream int_to_string;
    int_to_string << this->coefficient;
    std::string myStr = int_to_string.str();
    if (this->numVariables > 0) {
        if (this->coefficient == 1) {
            myStr = "";
        } else if (this->coefficient == -1) {
            myStr = "-";
        } else {
            myStr += "*";
        }
        std::ostringstream os;
        for (int i = 0; i < this->numVariables; i++) {
            if (this->powers[i] != 0) {
                os << "*" << this->variables[i];
                if (this->powers[i] != 1) {
                    os << "^" << this->powers[i];
                }
            }
        }

        std::string str = os.str();
        if (str[0] == '*') {
            str.erase(0, 1);
        } else if (str[0] == '-' && str[1] == '*') {
            str.erase(1, 1);
        }
        myStr += str;
    }
    return myStr;
}

std::ostream& operator<<(std::ostream& os, const term& t) {
    os << ~t << std::endl;
    return os;
}

istream& operator>>(istream& is, term& t) {
    std::string input = "";
    is >> input;
    t = term(input.c_str());
    // std::cout << t << std::endl;
    return is;
}

const term term::operator*(const term& other) const {
    term newTerm(*this);
    newTerm.coefficient *= other.coefficient;
    for (int i = 0; i < other.numVariables; i++) {
        newTerm.addVariable(other.variables[i], other.powers[i]);
    }
    return newTerm;
}

term& term::operator*=(const term& other) {
    this->coefficient *= other.coefficient;
    for (int i = 0; i < other.numVariables; i++) {
        this->addVariable(other.variables[i], other.powers[i]);
    }
    return *this;
}

const term term::operator()(char* vars, int* vals, int numVals) const {
    term temp(*this);
    if (vars == NULL || vals == NULL or numVals == 0) {
        return temp;
    } else {
        for (int i = 0; i < numVals; i++) {
            int index = temp.getVarIndex(vars[i]);
            if (index != -1) {
                int power = temp.powers[index];
                power -= vals[i];
                temp.removeVariable(temp.variables[index]);
                temp.addVariable(vars[i], power);
            }
        }
        return temp;
    }
}

const term term::operator()(string inp) const {
    std::stringstream ss(inp);
    string substitution;
    int equalsCount = 0;
    for (int k = 0; k < inp.length(); k++) {
        if (inp[k] == '=') {
            equalsCount += 1;
        }
    }
    char* vars = new char[equalsCount];
    int* vals = new int[equalsCount];
    int i = 0;
    for (int k = 0; k < equalsCount; k++) {
        if (getline(ss, substitution, ' ')) {
            stringstream get_values (substitution);
            getline(get_values, substitution, '=');
            vars[k] = substitution[0];
            getline(get_values, substitution);
            stringstream conv (substitution);
            conv >> vals[k];
        }
    }
    term temp(*this);
    temp = temp(vars, vals, equalsCount);
    delete[] vars;
    delete[] vals;
    return temp;
}

bool term::operator==(const term& other) const {
    if (this->numVariables == other.numVariables) {
        for (int i = 0; i < this->numVariables; i++) {
            if (this->variables[i] != other.variables[i] || this->powers[i] != other.powers[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}


bool term::operator<(const term& other) const {
    if (*this == other) {
        return false;
    }
    if (this->numVariables == 0) {
        return false;
    }
    if (other.numVariables == 0) {
        return true;
    }

    int minimum = std::min(this->numVariables, other.numVariables);
    for (int i = 0; i < minimum; i++) {
        if (this->variables[i] == other.variables[i]) {
            if (this->powers[i] != other.powers[i]) {
                return this->powers[i] > other.powers[i];
            }
        } else {
            return !(this->variables[i] > other.variables[i]);
        }
    }

    return (this->numVariables < other.numVariables);
}

bool term::operator>(const term& other) const {
    if (*this == other) {
        return false;
    }
    if (this->numVariables == 0) {
        return !false;
    }
    if (other.numVariables == 0) {
        return !true;
    }

    int minimum = std::min(this->numVariables, other.numVariables);
    for (int i = 0; i < minimum; i++) {
        if (this->variables[i] == other.variables[i]) {
            if (this->powers[i] != other.powers[i]) {
                return !(this->powers[i] > other.powers[i]);
            }
        } else {
            return (this->variables[i] > other.variables[i]);
        }
    }

    return !(this->numVariables < other.numVariables);
}

int& term::operator[](int idx) {
    if (idx >= 0 && idx < this->numVariables) {
        return this->powers[idx];
    } else {
        return this->coefficient;
    }
}

const term term::operator!() const {
    term negated = *this;
    negated.coefficient *= -1;
    return negated;
}
