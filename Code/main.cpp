#include <iostream>
#include "term.h"
using namespace std;

int main() {
    // Example inputs
    const char* input1 = "10*x^2*w^3*a^1";
    const char* input2 = "+8*x*x^1*x^0*x^-1";
    const char* input3 = "1*x^2";
    const char* input4 = "-x^2";
    const char* input5 = "0*x^2";
    const char* input6 = "+z^-3";

    // Create term objects
    term term1(input1);
    term term2(input2);
    term term3(input3);
    term term4(input4);
    term term5(input5);
    term term6(input6);

    // Display the results
    std::cout << term1 << std::endl;
    std::cout << term2 << std::endl;
    std::cout << term3 << std::endl;
    std::cout << term4 << std::endl;

    return 0;
}