#include <iostream>
#include "term.h"
using namespace std;

void testTermConstructors() {
    // // Default Constructor
    // cout << "\n\nTesting Constructor\n";
    // term tempTerm;
    // cout << tempTerm;
    // char ArrV[] = "x";
    // int ArrP[] = {2};
    // // Param Constructor
    // term tempTerm2(1, 1, ArrV, ArrP);
    // cout << tempTerm2;
    // char ArrV1[] = "x";
    // int ArrP1[] = {1};
    // // Param Constructor
    // term tempTerm3(-1, 1, ArrV1, ArrP1);
    // cout << tempTerm3;
    // char ArrV2[] = "x";
    // int ArrP2[] = {-1};
    // // Param Constructor
    // term tempTerm4(1, 1, ArrV2, ArrP2);
    // cout << tempTerm4;
    // char ArrV3[] = {'x','y','z'};
    // int ArrP3[] = {1,2,4};
    // // Param Constructor
    // term tempTerm5(1, 3, ArrV3, ArrP3);
    // cout << tempTerm5;
    // char ArrV4[] = {'x','y','z'};
    // int ArrP4[] = {-1,2,4};
    // // Param Constructor
    // term tempTerm6(tempTerm2);
    // cout << tempTerm6;

    // // Copy
    // cout << "\n\nTesting Copy\n";
    // term tempTerm7(tempTerm4);
    // cout << tempTerm7;

    // term tempTerm8(tempTerm5);
    // cout << tempTerm8;

    // term tempTerm9(tempTerm6);
    // cout << tempTerm9;

    // input
    // cout << "\n\nTesting Inputs\n";
    // const char* inputs[] = {
    //     "10*x^2*w^3*a^1",
    //     "+8*x*x^1*x^0*x^-1*b^8*r^5*b^-2",
    //     "1*x^2",
    //     "-x^2",
    //     "0*x^2",
    //     "+z^-3"
    // };

    // for (int k = 0; k < 6; k++) {
    //     term tempTerm11(inputs[k]);
    //     cout << tempTerm11;
    //     cout << tempTerm11.operator!();
    // }

    // std::string myS = "10*x^2*w^3*a^9";
    // term tr(myS.c_str());
    // std::cout << tr << std::endl;

    // cout << "\n\nTesting User Inputs\n";
    // for (int k = 0; k < 2; k++) {
    //     term tempTerm12;
    //     std::cout << "Enter a string: ";
    //     std::cin >> tempTerm12;
    //     cout << tempTerm12;
    //     cout << tempTerm12.operator!();
    // }

    // cout << "\n\nTesting Multiplication\n";
    // std::string myS2 = "10*x^2*w^3*a^9";
    // term tr1(myS2.c_str());
    // myS2 = "-7*x^9*w^8*a^7";
    // term tr2(myS2.c_str());
    // std::cout << tr2 * tr1 << std::endl;

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
}

void testTerm() {
    // Default Constructor
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
    term tempTerm6(10, 3, ArrV4, ArrP4);
    cout << tempTerm6;
}

int main() {
    testTermConstructors();
    // Example inputs
    // const char* input1 = "10*x^2*w^3*a^1";
    // const char* input2 = "+8*x*x^1*x^0*x^-1";
    // const char* input3 = "1*x^2";
    // const char* input4 = "-x^2";
    // const char* input5 = "0*x^2";
    // const char* input6 = "+z^-3";

    // // Create term objects
    // term term1(input1);
    // term term2(input2);
    // term term3(input3);
    // term term4(input4);
    // term term5(input5);
    // term term6(input6);

    // // Display the results
    // std::cout << term1 << std::endl;
    // std::cout << term2 << std::endl;
    // std::cout << term3 << std::endl;
    // std::cout << term4 << std::endl;

    return 0;
}