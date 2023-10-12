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
            delete [] this->powers;
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

        delete [] this->variables;
        delete [] this->powers;

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
    if (this->coefficient != 0) {
        this->numVariables = other.numVariables;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
        for (int i = 0; i < this->numVariables; i++) {
            this->variables[i] = other.variables[i];
            this->powers[i] = other.powers[i];
        }
    } else {
        this->numVariables = 0;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
    }
}

term::term(int c, int n, char* v, int* p) {
    this->coefficient = c;
    if (this->coefficient != 0) {
        this->numVariables = 0;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
        if (v != NULL && p != NULL) {
            for (int i = 0; i < n; i++) {
                this->addVariable(v[i], p[i]);
            }
        }
    } else {
        this->numVariables = 0;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
    }
}

term::term(const char* input) {
    if (input != NULL && input[0] != '\0') {
        this->coefficient = 1;
        this->numVariables = 0;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
        std::string input_string(input);
        std::string trim_string = "";
        for (int i = 0; i < input_string.length(); i++) {
            if (input_string[i] != ' ') {
                trim_string += input_string[i];
            }
        }
        input_string = trim_string;
        bool isDigit = true;
        if (input_string[0] == '+' || input_string[0] == '-') {
            if (input_string[0] == '-') {
                this->coefficient = -1;
            }
            input_string = input_string.substr(1, (input_string.length() - 1));
        }
        if (input_string.length() >= 1) {
            for (int i = 0; i < input_string.length(); i++) {
                if (!isdigit(input_string[i])) {
                    isDigit = false;
                    break;
                }
            }
            if (isDigit) {
                stringstream temp_coefficient (input_string);
                int coefficient_convert = 0;
                temp_coefficient >> coefficient_convert;
                this->coefficient *= coefficient_convert;
                return;
            } else {
                trim_string = "";
                stringstream coefficient_full (input_string);
                getline(coefficient_full, trim_string, '*');
                if (isdigit(trim_string[0])) {
                    stringstream temp_coefficient (trim_string);
                    int coefficient_convert = 0;
                    temp_coefficient >> coefficient_convert;
                    this->coefficient *= coefficient_convert;
                    input_string = input_string.substr(trim_string.length(), (input_string.length() - 1));
                    if (input_string.length() >= 1 && input_string[0] == '*') {
                        input_string = input_string.substr(1, (input_string.length() - 1));
                    }
                }
                if (this->coefficient != 0 && input_string.length() >= 1) {
                    trim_string = "";
                    stringstream variables_and_powers (input_string);
                    while(getline(variables_and_powers, trim_string, '*')) {
                        if (trim_string.length() >= 3) {
                            stringstream variable_n_power (trim_string);
                            trim_string = "";
                            getline(variable_n_power, trim_string, '^');
                            char variable = trim_string[0];
                            trim_string = "";
                            getline(variable_n_power, trim_string);
                            stringstream converter (trim_string);
                            int power = 0;
                            converter >> power;
                            this->addVariable(variable, power);
                        } else if (trim_string.length() == 1) {
                            char variable = trim_string[0];
                            this->addVariable(variable, 1);
                        }
                    }
                }
            }
        }
    } else {
        this->coefficient = 1;
        this->numVariables = 0;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
    }
    if (this->coefficient == 0) {
        this->numVariables = 0;
        delete [] this->variables;
        delete [] this->powers;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
    }
}

term& term::operator=(const term& other) {
    if (this != &other) {
        delete [] this->variables;
        delete [] this->powers;

        this->coefficient = other.coefficient;
        if (this->coefficient != 0) {
            this->numVariables = other.numVariables;
            this->variables = new char[this->numVariables];
            this->powers = new int[this->numVariables];

            for (int i = 0; i < this->numVariables; i++) {
                this->variables[i] = other.variables[i];
                this->powers[i] = other.powers[i];
            }
        } else {
            this->numVariables = 0;
            this->variables = new char[this->numVariables];
            this->powers = new int[this->numVariables];
        }
    }
    return *this;
}

term::~term() {
    delete [] this->variables;
    this->variables = NULL;
    delete [] this->powers;
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
    std::string printing_string = int_to_string.str();
    if (this->numVariables > 0) {
        if (this->coefficient == 1) {
            printing_string = "";
        } else if (this->coefficient == -1) {
            printing_string = "-";
        } else {
            printing_string += "*";
        }
        std::ostringstream output_string;
        for (int i = 0; i < this->numVariables; i++) {
            if (this->powers[i] != 0) {
                output_string << "*" << this->variables[i];
                if (this->powers[i] != 1) {
                    output_string << "^" << this->powers[i];
                }
            }
        }

        std::string combined_string = output_string.str();
        if (combined_string[0] == '*') {
            combined_string.erase(0, 1);
        } else if (combined_string[0] == '-' && combined_string[1] == '*') {
            combined_string.erase(1, 1);
        }
        printing_string += combined_string;
    }
    return printing_string;
}

std::ostream& operator<<(std::ostream& output_string, const term& t) {
    output_string << ~t << std::endl;
    return output_string;
}

istream& operator>>(istream& input_string, term& t) {
    std::string input = "";
    input_string >> input;
    t = term(input.c_str());
    return input_string;
}

const term term::operator*(const term& other) const {
    term newTerm;
    newTerm.coefficient = this->coefficient * other.coefficient;
    if (newTerm.coefficient != 0) {
        for (int i = 0; i < other.numVariables; i++) {
            newTerm.addVariable(other.variables[i], other.powers[i]);
        }
        for (int i = 0; i < this->numVariables; i++) {
            newTerm.addVariable(this->variables[i], this->powers[i]);
        }
    }
    return newTerm;
}

term& term::operator*=(const term& other) {
    this->coefficient *= other.coefficient;
    if (this->coefficient != 0) {
        for (int i = 0; i < other.numVariables; i++) {
            this->addVariable(other.variables[i], other.powers[i]);
        }
    } else {
        this->numVariables = 0;
        delete [] this->variables;
        delete [] this->powers;
        this->variables = new char[this->numVariables];
        this->powers = new int[this->numVariables];
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
                temp.coefficient *= pow(vals[i], temp.powers[index]);
                if (temp.coefficient == 0) {
                    temp.numVariables = 0;
                    delete [] temp.powers;
                    temp.powers = new int[0];
                    delete [] temp.variables;
                    temp.variables = new char[0];
                } else {
                    temp.removeVariable(temp.variables[index]);
                }
            }
        }
        return temp;
    }
}

const term term::operator()(string inp) const {
    std::stringstream input_stream (inp);
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
        if (getline(input_stream, substitution, ' ')) {
            stringstream get_values (substitution);
            getline(get_values, substitution, '=');
            vars[k] = substitution[0];
            getline(get_values, substitution);
            stringstream converter (substitution);
            converter >> vals[k];
        }
    }
    term temp(*this);
    temp = temp(vars, vals, equalsCount);
    delete [] vars;
    delete [] vals;
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
    } else {
        return !(*this < other);
    }
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
