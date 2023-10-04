#include <iostream>
#include "term.h"
#include "polynomial.h"
#include "univariate.h"
#include "bivariate.h"

using namespace std;

void testUnivariateClass();
void testBivariateClass();
void testTermClass();
void testPolynomialClass();

int main() {
    cout << "Testing Term class:" << endl;
    // testTermClass();
    cout << "Testing Polynomial class:" << endl;
    // testPolynomialClass();

    cout << "Testing univariate class:" << endl;
    testUnivariateClass();

    cout << "\nTesting bivariate class:" << endl;
    testBivariateClass();

    cout << "\n\nTests Complete!" << endl;
    return 0;
}

// void testTermClass() {
//     cout << "\n\nTesting Constructors\n";
//     term tempTerm;
//     cout << tempTerm;
//     char ArrV[] = "x";
//     int ArrP[] = {2};
//     // Param Constructor
//     term tempTerm2(1, 1, ArrV, ArrP);
//     cout << tempTerm2;
//     char ArrV1[] = "x";
//     int ArrP1[] = {1};
//     // Param Constructor
//     term tempTerm3(-1, 1, ArrV1, ArrP1);
//     cout << tempTerm3;
//     char ArrV2[] = "x";
//     int ArrP2[] = {-1};
//     // Param Constructor
//     term tempTerm4(1, 1, ArrV2, ArrP2);
//     cout << tempTerm4;
//     char ArrV3[] = {'x','y','z'};
//     int ArrP3[] = {1,2,4};
//     // Param Constructor
//     term tempTerm5(1, 3, ArrV3, ArrP3);
//     cout << tempTerm5;
//     char ArrV4[] = {'x','y','z'};
//     int ArrP4[] = {-1,2,4};
//     // Param Constructor
//     term tempTerm6(tempTerm2);
//     cout << tempTerm6;

//     // Copy
//     cout << "\n\nTesting Copy\n";
//     term tempTerm7(tempTerm4);
//     cout << tempTerm7;

//     term tempTerm8(tempTerm5);
//     cout << tempTerm8;

//     term tempTerm9(tempTerm6);
//     cout << tempTerm9;

//     cout << "\n\nTesting User Inputs\n";
//     for (int k = 0; k < 2; k++) {
//         term tempTerm12;
//         cout << "Enter a string: ";
//         cin.ignore();  // Clear any previous newline characters
//         cin >> tempTerm12;
//         cout << "Parsed Term: " << tempTerm12;
//         cout << "Negation: " << *tempTerm12.operator!() << endl;
//     }

//     cout << "\n\nTesting Multiplication\n";
//     term tr1("10*x^2*w^3*a^9");
//     term tr2("-7*x^9*w^8*a^7");
//     cout << "Multiplication: " << tr2 * tr1 << endl;

//     term tr3("10*x^2*w^3*a^9");
//     term tr4("-7*x^9*w^8*a^7");
//     tr4 *= tr3;
//     cout << "Multiplication (In-Place): " << tr4 << endl;

//     cout << "\n\nTesting Substitution\n";
//     term tr6("2*x^2*y^3*z^4");
//     cout << "Original: " << tr6 << endl;
//     tr6 = tr6("x=2 a=1 y=2 z=4");
//     cout << "Substituted: " << tr6 << endl;

//     cout << "\n\nTesting Equals\n";
//     term tr8("2*x^2*y^3*z^4");
//     term tr9("9*x^2*y^3*z^4");
//     bool isEquals = tr8==tr9;
//     cout << "Equality Check: " << (isEquals ? "True" : "False") << endl;

//     cout << "\n\nTesting Greater/Less\n";
//     term tr10;
//     term tr11;
//     cout << "Comparison (tr10 < tr11): " << (tr10 < tr11) << endl;
//     cout << "Comparison (tr9 < tr8): " << (tr9 < tr8) << endl;
//     cout << "Comparison (tr6 < tr5): " << (tr6 < tr5) << endl;
//     cout << "Comparison (tr6 < tr8): " << (tr6 < tr8) << endl;
//     cout << "Comparison (tr5 < tr11): " << (tr5 < tr11) << endl;
//     cout << "Comparison (tr10 > tr11): " << (tr10 > tr11) << endl;
//     cout << "Comparison (tr9 > tr8): " << (tr9 > tr8) << endl;
//     cout << "Comparison (tr6 > tr5): " << (tr6 > tr5) << endl;
//     cout << "Comparison (tr6 > tr8): " << (tr6 > tr8) << endl;
//     cout << "Comparison (tr5 > tr11): " << (tr5 > tr11) << endl;
// }

// void testPolynomialClass() {
//     // TODO: Make sure you Remove all the Pure Virtual methods before Doing This.
//     cout << "\n\nTesting Inputs Constructor\n";
//     const char* inputs[] = {
//         "x^2*y^2 + 2*x*y + 1 + x^-3",
//         "- -a^2*y^2 - -2*a*y - -1",
//         "-x^2*b^1 - 2*x*b^5 - 1 + b^-5",
//         "- +c*y^2 - +2*c^3*y - +1",
//         "+ -c^2*y^2 + -2*c*y + -1",
//         "e^-3 + f^-2"
//     };

//     // string s = "";
//     // polynomial tempTerm11(s.c_str());
//     // cout << tempTerm11;

//     // std::string myS = "-x";
//     // term tr(myS.c_str());
//     // std::cout << tr;

//     polynomial tempTerm14;
//     for (int k = 0; k < 6; k++) {
//         polynomial tempTerm12(inputs[k]);
//         if (k == 2) {
//             tempTerm14 = tempTerm12;
//         }
//         cout << tempTerm12;
//         cout << endl;
//     }

//     cout << "\n\nTesting Operator=\n";
//     cout << tempTerm14;

//     cout << "\n\nTesting Copy Constructor\n";
//     polynomial tempTerm15(tempTerm14);
//     cout << tempTerm15;

//     cout << "\n\nTesting Param Constructor\n";
//     polynomial tempTerm16(tempTerm14.getTerms(), tempTerm14.getNumTerms());
//     cout << tempTerm16;

//     // cout << "\n\nTesting termIndex\n";
//     // int ti = tempTerm16.termIndex(tempTerm14[2]);
//     // cout << ti << endl;
// }

// void testUnivariateClass() {
//     // Test default constructor
//     univariate u1;
//     cout << "Default constructor: " << u1 << endl;

//     // Test parameterized constructor
//     univariate u2(2, 'x');
//     cout << "Parameterized constructor: " << u2 << endl;

//     // Test string constructor
//     univariate u3("3x^2 + 2x - 5");
//     cout << "String constructor: " << u3 << endl;

//     // Test copy constructor
//     univariate u4(u2);
//     cout << "Copy constructor: " << u4 << endl;

//     // Test arithmetic operations
//     univariate u5 = u2 + u3;
//     cout << "u2 + u3: " << u5 << endl;

//     u5 += u4;
//     cout << "u5 += u4: " << u5 << endl;

//     univariate u6 = u2 * u3;
//     cout << "u2 * u3: " << u6 << endl;

//     u6 *= u3;
//     cout << "u6 *= u3: " << u6 << endl;

//     // Test negation and substitution
//     univariate u7 = !u2;
//     cout << "!u2: " << u7 << endl;

//     char vars[] = { 'x' };
//     int vals[] = { 2 };
//     univariate u8 = u2(vars, vals, 1);
//     cout << "u2(x=2): " << u8 << endl;

//     univariate u9 = u3("x=3");
//     cout << "u3(x=3): " << u9 << endl;

//     // Test istream operator
//     univariate u10;
//     cout << "Enter a univariate polynomial (e.g., 3x^2 + 2x - 5): ";
//     cin >> u10;
//     cout << "User input: " << u10 << endl;

//     // Test negation operator
//     univariate u11("2x - 4");
//     univariate neg_u11 = !u11;
//     cout << "!u11: " << *neg_u11 << endl;

//     // Test substitution operator
//     char vars[] = { 'x' };
//     int vals[] = { 2 };
//     univariate u12("3x^2 + 2x - 5");
//     univariate sub_u12 = u12(vars, vals, 1);
//     cout << "u12(x=2): " << *sub_u12 << endl;

//     univariate u13("x^2 - 2x + 1");
//     univariate sub_u13 = u13("x=3");
//     cout << "u13(x=3): " << *sub_u13 << endl;
// }

// void testBivariateClass() {
//     // Test default constructor
//     bivariate b1;
//     cout << "Default constructor: " << b1 << endl;

//     // Test parameterized constructor
//     bivariate b2(2, 'x', 'y');
//     cout << "Parameterized constructor: " << b2 << endl;

//     // Test string constructor
//     bivariate b3("3x^2 + 2xy - 5y^3");
//     cout << "String constructor: " << b3 << endl;

//     // Test copy constructor
//     bivariate b4(b2);
//     cout << "Copy constructor: " << b4 << endl;

//     // Test arithmetic operations
//     bivariate b5 = b2 + b3;
//     cout << "b2 + b3: " << b5 << endl;

//     b5 += b4;
//     cout << "b5 += b4: " << b5 << endl;

//     bivariate b6 = b2 * b3;
//     cout << "b2 * b3: " << b6 << endl;

//     b6 *= b3;
//     cout << "b6 *= b3: " << b6 << endl;

//     // Test negation and substitution
//     bivariate b7 = !b2;
//     cout << "!b2: " << b7 << endl;

//     char vars[] = { 'x', 'y' };
//     int vals[] = { 2, 3 };
//     bivariate b8 = b2(vars, vals, 2);
//     cout << "b2(x=2, y=3): " << b8 << endl;

//     bivariate b9 = b3("x=3, y=1");
//     cout << "b3(x=3, y=1): " << b9 << endl;

//     // Test istream operator
//     bivariate b10;
//     cout << "Enter a bivariate polynomial (e.g., 3x^2 + 2xy - 5y^3): ";
//     cin >> b10;
//     cout << "User input: " << b10 << endl;

//     // Test negation operator
//     bivariate b11("2xy - 4y^2");
//     bivariate neg_b11 = !b11;
//     cout << "!b11: " << *neg_b11 << endl;

//     // Test substitution operator
//     char vars[] = { 'x', 'y' };
//     int vals[] = { 2, 3 };
//     bivariate b12("3x^2 + 2xy - 5y^3");
//     bivariate sub_b12 = b12(vars, vals, 2);
//     cout << "b12(x=2, y=3): " << *sub_b12 << endl;

//     bivariate b13("x^2 - 2xy + y^2");
//     bivariate sub_b13 = b13("x=3, y=1");
//     cout << "b13(x=3, y=1): " << *sub_b13 << endl;
// }