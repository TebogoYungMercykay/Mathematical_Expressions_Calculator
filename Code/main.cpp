#include "term.h"

void print(term* p_c_string) {
    cout << "numVariables: " << p_c_string->getNumVariables() << " variables: [";
    int num = p_c_string->getNumVariables();
    char* tmpV = p_c_string->getVariables();
    string pw = "";
    for (int i = 0; i < num; i++) {
        stringstream ss;
        ss << p_c_string->operator[](i);
        
        if (i+1 < num) {
            cout << tmpV[i] <<",";
            pw += ss.str()  + ",";
        } else {
            cout << tmpV[i];
            pw += ss.str();
        }
    }
    cout << "] powers: [" << pw << "] degree: " << p_c_string->getDegree() << " ~: ";
    cout << *p_c_string;
}

// term(int c, int n, char* v, int* p)
void printParameter(int c, int n, char* v, int* p) {
    term* termParameter = new term(c, n, v, p);
    print(termParameter);
    delete termParameter;
}

int main() {
    term* newTerm = new term();
    cout << newTerm->getNumVariables() << endl;
    cout << *newTerm;
    term* copy = new term(*newTerm);
    cout << copy->getNumVariables() << endl;
    cout << *copy;

    char* variables = new char[2];
    variables[0] = 'x';
    variables[1] = 'y';
    int* powers = new int[2];
    powers[0] = 3;
    powers[1] = 2;

    term* parameters = new term(10,2,variables,powers);
    cout << parameters->getNumVariables() << endl;
    cout << *parameters;

    const char* c_string = parameters->operator~().c_str();

    term* parameters_c_string = new term(c_string);
    cout << parameters_c_string->getNumVariables() << endl;
    cout << *parameters_c_string;

    cout << "---------------------------------------" << endl;

    string termV = "10*x^2*w^3*a^1";
    term* p_c_string = new term(termV.c_str());
    print(p_c_string);
    int* arr = new int[p_c_string->getNumVariables()];
    for (int i = 0; i < p_c_string->getNumVariables(); i++) {
        arr[i] = (* p_c_string)[i];
    }
    printParameter(10, p_c_string->getNumVariables(), p_c_string->getVariables(), arr);
    delete p_c_string;
    delete [] arr;
    arr = NULL;

    termV = "+8*x*x^1*x^0*x^-1";
    p_c_string = new term(termV.c_str());
    print(p_c_string);
    delete p_c_string;

    termV = "1*x^2";
    p_c_string = new term(termV.c_str());
    print(p_c_string);
    delete p_c_string;

    termV = "-x^2";
    p_c_string = new term(termV.c_str());
    print(p_c_string);
    delete p_c_string;

    termV = "0*x^2";
    p_c_string = new term(termV.c_str());
    print(p_c_string);
    delete p_c_string;

    termV = "+z^-3";
    p_c_string = new term(termV.c_str());
    print(p_c_string);
    delete p_c_string;

    termV = "+2*x^2*y^3*z^4";
    p_c_string = new term(termV.c_str());
    print(p_c_string);
    char charArray[] = "xa";
    int intArray[2] = {2, 0};
    term parenthesis = p_c_string->operator()(charArray, intArray,2);
    print(&parenthesis);
    parenthesis = p_c_string->operator()("x=2 a=0");
    print(&parenthesis);
    delete p_c_string;

    cout << "---------------------------------------" << endl;

    termV = "+z^-3";
    p_c_string = new term(termV.c_str());
    termV = "10*x^2*w^3*a^1";
    istringstream input(termV.c_str());
    input >> (*p_c_string);
    print(p_c_string);
    cout << (*p_c_string)[-1] << endl;
    delete p_c_string;

    delete [] powers;
    delete [] variables;
    delete parameters;
    delete newTerm;
    delete copy;
    delete parameters_c_string;

    p_c_string = NULL;
    parameters_c_string = NULL;
    parameters = NULL;
    newTerm = NULL;
    copy = NULL;
    return 0;
}