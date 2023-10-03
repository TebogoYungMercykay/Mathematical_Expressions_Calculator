#include <iostream>
#include "term.h"
#include "polynomial.h"
using namespace std;

void testTermClass();
void testPolynomialClass() {
    cout << "\n\nTesting Inputs Constructor\n";
    const char* inputs[] = {
        "x^2*y^2 + 2*x*y + 1 + x^-3",
        "- -a^2*y^2 - -2*a*y - -1",
        "-x^2*b^1 - 2*x*b^5 - 1 + b^-5",
        "- +c*y^2 - +2*c^3*y - +1",
        "+ -c^2*y^2 + -2*c*y + -1",
        "e^-3 + f^-2"
    };

    // string s = "";
    // polynomial tempTerm11(s.c_str());
    // cout << tempTerm11;

    std::string myS = "-x";
    term tr(myS.c_str());
    std::cout << tr;

    // for (int k = 0; k < 6; k++) {
    //     polynomial tempTerm12(inputs[k]);
    //     cout << tempTerm12;
    // }

}

int main() {
    // testTermClass();
    testPolynomialClass();
    cout << "Hello World!" << endl;
    return 0;
}

void testTermClass() {
    cout << "\n\nTesting Constructors\n";
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

    cout << "\n\nTesting Inputs\n";
    const char* inputs[] = {
        "10*x^2*w^3*a^1",
        "+8*x*x^1*x^0*x^-1*b^8*r^5*b^-2",
        "1*x^2",
        "-x^2",
        "0*x^2",
        "+z^-3"
    };

    for (int k = 0; k < 6; k++) {
        term tempTerm11(inputs[k]);
        cout << tempTerm11;
        cout << tempTerm11.operator!();
    }

    std::string myS = "10*x^2*w^3*a^9";
    term tr(myS.c_str());
    std::cout << tr << std::endl;

    cout << "\n\nTesting User Inputs\n";
    for (int k = 0; k < 2; k++) {
        term tempTerm12;
        std::cout << "Enter a string: ";
        std::cin >> tempTerm12;
        cout << tempTerm12;
        cout << tempTerm12.operator!();
    }

    cout << "\n\nTesting Multiplication\n";
    std::string myS2 = "10*x^2*w^3*a^9";
    term tr1(myS2.c_str());
    myS2 = "-7*x^9*w^8*a^7";
    term tr2(myS2.c_str());
    std::cout << tr2 * tr1 << std::endl;

    std::string myS3 = "10*x^2*w^3*a^9";
    term tr3(myS3.c_str());
    myS3 = "-7*x^9*w^8*a^7";
    term tr4(myS3.c_str());
    tr4 *= tr3;
    std::cout << tr4 << std::endl;

    cout << "\n\nTesting Substitution\n";
    std::cout << tr4 << std::endl;
    char varss[] = {'a','w','b'};
    int valss[] = {3,11,4};
    term tr5;
    tr5 = tr4(varss, valss, 3);
    std::cout << tr4 << std::endl;
    std::cout << tr5 << std::endl;
    char varss2[] = {'x','a','b'};
    int valss2[] = {2,0,4};
    myS3 = "2*x^2*y^3*z^4";
    term tr6(myS3.c_str());
    tr5 = tr6(varss2, valss2, 3);
    std::cout << tr6 << std::endl;
    std::cout << tr5 << std::endl;

    tr5 = tr6("x=2 a=1 y=2 z=4");
    std::cout << "Original: " << tr6 << std::endl;
    std::cout << "Converted: " << tr5 << std::endl;

    cout << "\n\nTesting Equals\n";
    std::cout << "Converted: " << tr5 << std::endl;
    myS3 = "2*x^2*y^3*z^4";
    term tr8(myS3.c_str());
    tr5 = tr8;
    myS3 = "9*x^2*y^3*z^4";
    term tr9(myS3.c_str());
    bool t = tr8==tr9;
    std::cout << "True = 1 && False = 0: " << t << endl;

    cout << "\n\nTesting Greater/Less\n";
    term tr10;
    term tr11;
    std::cout << (tr10 < tr11) << std::endl;
    std::cout << (tr9 < tr8) << std::endl;
    std::cout << (tr6 < tr5) << std::endl;
    std::cout << (tr6 < tr8) << std::endl;
    std::cout << (tr5 < tr11) << std::endl;
    std::cout << (tr10 > tr11) << std::endl;
    std::cout << (tr9 > tr8) << std::endl;
    std::cout << (tr6 > tr5) << std::endl;
    std::cout << (tr6 > tr8) << std::endl;
    std::cout << (tr5 > tr11) << std::endl;
}