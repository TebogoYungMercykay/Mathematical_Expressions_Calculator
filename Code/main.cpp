#include <iostream>
#include "term.h"
#include "polynomial.h"
#include "univariate.h"
#include "bivariate.h"
#include "linear.h"
#include "quadratic.h"


using namespace std;

void testUnivariateClass();
void testBivariateClass();
void testTermClass();
void testPolynomialClass();
void testLinear();
void testQuadratic();

int main() {
    // cout << "Testing Term class:" << endl;
    // testTermClass();

    // cout << "Testing Polynomial class:" << endl;
    // testPolynomialClass();

    // cout << "Testing univariate class:" << endl;
    // testUnivariateClass();

    // cout << "Testing linear class:" << endl;
    // testLinear();

    cout << "Testing Quadratic class:" << endl;
    testQuadratic();

    // cout << "\nTesting bivariate class:" << endl;
    // testBivariateClass();

    cout << "\n\nTests Complete!" << endl;
    return 0;
}

void testLinear() {
    // Test default constructor
    linear u1('x');
    u1.printRoots();

    // Test parameterized constructor
    linear u2('y');
    u2.printRoots();

    // Test string constructor
    linear u3("3*y + 3");
    u3.printRoots();

    // Test copy constructor
    linear u4(u2);
    u4.printRoots();

    linear u43(u2.getTerms(), u2.getNumTerms());
    u43.printRoots();

    term tr1("10*x^2*w^3*a^9");
    linear u44(tr1);
    u44.printRoots();

    term tr2("10*x^2*9");
    linear u45(tr2);
    u45.printRoots();

    // copy constructor
    u44 = u45;
    u44.printRoots();
}

void testQuadratic() {
    // Test default constructor
    linear u1('x');
    u1.printRoots();

    // Test parameterized constructor
    linear u2('y');
    u2.printRoots();

    // Test string constructor
    linear u3("3*y + 3");
    u3.printRoots();

    // Test copy constructor
    linear u4(u2);
    u4.printRoots();

    linear u43(u2.getTerms(), u2.getNumTerms());
    u43.printRoots();

    term tr1("10*x^2*w^3*a^9");
    linear u44(tr1);
    u44.printRoots();

    term tr2("10*x^2*9");
    linear u45(tr2);
    u45.printRoots();

    // copy constructor
    u44 = u45;
    u44.printRoots();
}


void testUnivariateClass() {
    // Test default constructor
    univariate u1(1, 'x');
    cout << "Default constructor: " << u1 << endl;

    // Test parameterized constructor
    univariate u2(2, 'x');
    cout << "Parameterized constructor: " << u2 << endl;

    // Test string constructor
    univariate u3("3*x^2 + 2*x - 5");
    cout << "String constructor: " << u3 << endl;

    // Test copy constructor
    univariate u4(u2);
    cout << "Copy constructor: " << u4 << endl;

    univariate u43(u2.getTerms(), u2.getNumTerms());
    cout << "Constructor (term**, int): " << u43 << endl;

    term tr1("10*x^2*w^3*a^9");
    univariate u44(tr1);
    cout << "Constructor (term): " << u44 << endl;

    term tr2("10*x^2*9");
    univariate u45(tr2);
    cout << "Constructor (term): " << u45 << endl;

    // copy constructor
    u44 = u45;
    cout << "Copy Constructor: " << u44 << endl;

    // Test arithmetic operations
    polynomial* u5 = u2 + u3;
    cout << "u2 + u3: " << *u5 << endl;

    *u5 += u4;
    cout << "u5 += u4: " << *u5 << endl;

    polynomial* u6 = u2 * u3;
    cout << "u2 * u3: " << *u6 << endl;

    *u6 *= u3;
    cout << "u6 *= u3: " << *u6 << endl;

    // Test negation and substitution
    polynomial* u7 = !u2;
    cout << "!u2: " << *u7 << endl;

    char vars[] = { 'x' };
    int vals[] = { 2 };
    polynomial* u8 = u2(vars, vals, 1);
    cout << "u2(x=2): " << *u8 << endl;

    polynomial* u9 = u3("x=3");
    cout << "u3(x=3): " << *u9 << endl;

    // Test istream operator
    univariate u10(2, 'x');
    cout << "Enter a univariate polynomial (e.g., 3*x^2 + 2*x - 5): ";
    cin >> u10;
    cout << "User input: " << u10 << endl;

    // Test negation operator
    univariate u11("2*x - 4");
    polynomial* neg_u11 = !u11;
    cout << "!u11: " << *neg_u11 << endl;

    // Test substitution operator
    univariate u12("3*x^2 + 2*x - 5");
    polynomial* sub_u12 = u12(vars, vals, 1);
    cout << "u12(x=2): " << *sub_u12 << endl;

    univariate u13("x^2 - 2*x + 1");
    polynomial* sub_u13 = u13("x=3");
    cout << "u13(x=3): " << *sub_u13 << endl;

    delete u5;
    delete u6;
    delete u7;
    delete u8;
    delete u9;
    delete neg_u11;
    delete sub_u12;
    delete sub_u13;
}

void testBivariateClass() {
// Test default constructor
    bivariate u1(5, 'x', 'y');
    cout << "Default constructor: " << u1 << endl;

    // Test parameterized constructor
    bivariate u2(5, 'x', 'y');
    cout << "Parameterized constructor: " << u2 << endl;

    // Test string constructor
    bivariate u3("3*x^2 + 2*x - 5");
    cout << "String constructor: " << u3 << endl;

    // Test copy constructor
    bivariate u4(u2);
    cout << "Copy constructor: " << u4 << endl;

    bivariate u43(u2.getTerms(), u2.getNumTerms());
    cout << "Constructor (term**, int): " << u43 << endl;

    term tr1("10*x^2*w^3*a^9");
    bivariate u44(tr1);
    cout << "Constructor (term): " << u44 << endl;

    term tr2("10*x^2*9");
    bivariate u45(tr2);
    cout << "Constructor (term): " << u45 << endl;

    // copy constructor
    u44 = u45;
    cout << "Copy Constructor: " << u44 << endl;

    // Test arithmetic operations
    polynomial* u5 = u2 + u3;
    cout << "u2 + u3: " << *u5 << endl;

    *u5 += u4;
    cout << "u5 += u4: " << *u5 << endl;

    polynomial* u6 = u2 * u3;
    cout << "u2 * u3: " << *u6 << endl;

    *u6 *= u3;
    cout << "u6 *= u3: " << *u6 << endl;

    // Test negation and substitution
    polynomial* u7 = !u2;
    cout << "!u2: " << *u7 << endl;

    char vars[] = { 'x' };
    int vals[] = { 2 };
    polynomial* u8 = u2(vars, vals, 1);
    cout << "u2(x=2): " << *u8 << endl;

    polynomial* u9 = u3("x=3");
    cout << "u3(x=3): " << *u9 << endl;

    // Test istream operator
    bivariate u10(2, 'x', 'y');
    cout << "Enter a bivariate polynomial (e.g., 3*x^2 + 2*x - 5): ";
    cin >> u10;
    cout << "User input: " << u10 << endl;

    // Test negation operator
    bivariate u11("2*x - 4");
    polynomial* neg_u11 = !u11;
    cout << "!u11: " << *neg_u11 << endl;

    // Test substitution operator
    bivariate u12("3*x^2 + 2*x - 5");
    polynomial* sub_u12 = u12(vars, vals, 1);
    cout << "u12(x=2): " << *sub_u12 << endl;

    bivariate u13("x^2 - 2*x + 1");
    polynomial* sub_u13 = u13("x=3");
    cout << "u13(x=3): " << *sub_u13 << endl;

    delete u5;
    delete u6;
    delete u7;
    delete u8;
    delete u9;
    delete neg_u11;
    delete sub_u12;
    delete sub_u13;
}

// void testPolynomialClass() {
//     // TODO: Make sure you Remove all the Pure Virtual methods before Doing This.
//     // cout << "\n\nTesting Inputs Constructor\n";
//     // const char* inputs[] = {
//     //     "x^2*y^2 + 2*x*y + 1 + x^-3",
//     //     "- -a^2*y^2 - -2*a*y - -1",
//     //     "-x^2*b^1 - 2*x*b^5 - 1 + b^-5",
//     //     "- +c*y^2 - +2*c^3*y - +1",
//     //     "+ -c^2*y^2 + -2*c*y + -1",
//     //     "e^-3 + f^-2"
//     // };

//     // // string s = "";
//     // // polynomial tempTerm11(s.c_str());
//     // // cout << tempTerm11;

//     // // std::string myS = "-x";
//     // // term tr(myS.c_str());
//     // // std::cout << tr;

//     // polynomial tempTerm14;
//     // for (int k = 0; k < 6; k++) {
//     //     polynomial tempTerm12(inputs[k]);
//     //     if (k == 2) {
//     //         tempTerm14 = tempTerm12;
//     //     }
//     //     cout << tempTerm12;
//     //     cout << endl;
//     // }

//     // cout << "\n\nTesting Operator=\n";
//     // cout << tempTerm14;

//     // cout << "\n\nTesting Copy Constructor\n";
//     // polynomial tempTerm15(tempTerm14);
//     // cout << tempTerm15;

//     // cout << "\n\nTesting Param Constructor\n";
//     // polynomial tempTerm16(tempTerm14.getTerms(), tempTerm14.getNumTerms());
//     // cout << tempTerm16;

//     // cout << "\n\nTesting termIndex\n";
//     // int ti = tempTerm16.termIndex(tempTerm14[2]);
//     // cout << ti << endl;
// }

void testTermClass() {
    cout << "\nTesting Constructors\n";
    term tempTerm;
    cout << tempTerm;
    char ArrV[] = "x";
    int ArrP[] = {2};
    // Param Constructor
    term tempTerm2(1, 1, ArrV, ArrP);
    cout << tempTerm2;
    char ArrV1[] = "x";
    int ArrP1[] = {1};
    // Param Constructor
    term tempTerm3(-1, 1, ArrV1, ArrP1);
    cout << tempTerm3;
    char ArrV2[] = "x";
    int ArrP2[] = {-1};
    // Param Constructor
    term tempTerm4(1, 1, ArrV2, ArrP2);
    cout << tempTerm4;
    char ArrV3[] = {'x','y','z'};
    int ArrP3[] = {1,2,4};
    // Param Constructor
    term tempTerm5(1, 3, ArrV3, ArrP3);
    cout << tempTerm5;
    char ArrV4[] = {'x','y','z'};
    int ArrP4[] = {-1,2,4};
    // Param Constructor
    term tempTerm6(tempTerm2);
    cout << tempTerm6;

    // Copy
    cout << "\n\nTesting Copy\n";
    term tempTerm7(tempTerm4);
    cout << tempTerm7;

    term tempTerm8(tempTerm5);
    cout << tempTerm8;

    term tempTerm9(tempTerm6);
    cout << tempTerm9;

    cout << "\n\nTesting User Inputs\n";
    const char* inputs[] = {
        "10*x^2*w^3*a^1",
        "+8*x*x^1*x^0*x^-1*b^8*r^5*b^-2",
        "1*x^2",
        "-x^2",
        "0*x^2",
        "+z^-3",
        "3*x"
    };

    for (int k = 0; k < 7; k++) {
        term tempTerm12(inputs[k]);
        cout << "Parsed Term: " << tempTerm12;
        cout << "Negation: " << tempTerm12.operator!() << endl;
    }

    cout << "\n\nTesting Multiplication\n";
    term tr1("10*x^2*w^3*a^9");
    term tr2("-7*x^9*w^8*a^7");
    cout << "Multiplication: " << tr2 * tr1 << endl;

    term tr3("10*x^2*w^3*a^9");
    term tr4("-7*x^9*w^8*a^7");
    tr4 *= tr3;
    cout << "Multiplication (In-Place): " << tr4 << endl;

    cout << "\n\nTesting Substitution\n";
    term tr6("2*x^2*y^3*z^4");
    cout << "Original: " << tr6 << endl;
    tr6 = tr6("x=2 a=1 y=2 z=4");
    cout << "Substituted: " << tr6 << endl;

    cout << "\n\nTesting Equals\n";
    term tr8("2*x^2*y^3*z^4");
    term tr9("9*x^2*y^3*z^4");
    bool isEquals = tr8==tr9;
    cout << "Equality Check: " << (isEquals ? "True" : "False") << endl;

    cout << "\n\nTesting Greater/Less\n";
    term tr10;
    term tr11;
    term tr5("5*x^2*y^3*z^4");
    cout << "Comparison (tr10 < tr11): " << (tr10 < tr11) << endl;
    cout << "Comparison (tr9 < tr8): " << (tr9 < tr8) << endl;
    cout << "Comparison (tr6 < tr5): " << (tr6 < tr5) << endl;
    cout << "Comparison (tr6 < tr8): " << (tr6 < tr8) << endl;
    cout << "Comparison (tr5 < tr11): " << (tr5 < tr11) << endl;
    cout << "Comparison (tr10 > tr11): " << (tr10 > tr11) << endl;
    cout << "Comparison (tr9 > tr8): " << (tr9 > tr8) << endl;
    cout << "Comparison (tr6 > tr5): " << (tr6 > tr5) << endl;
    cout << "Comparison (tr6 > tr8): " << (tr6 > tr8) << endl;
    cout << "Comparison (tr5 > tr11): " << (tr5 > tr11) << endl;
}