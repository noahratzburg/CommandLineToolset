#include <iostream>
#include <string>
#include <regex>

#include "PermutationCalculator.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::regex;
using std::string;

PermutationCalculator::PermutationCalculator()
{
    int v1 = -1;
    int v2 = -1;
    int running = 1;
    unsigned long long int result;
    while (running == 1)
    {
        system("cls");

        while (v1 <= 0) v1 = inputNumber("Enter first number: ");
        while (v2 <= 0 && v2 <= v1) v2 = inputNumber("Enter second number: ");
        
        result = calculate(v1, v2);

        cout << v1 << "P" << v2 << " = " << result << "\n";
        
        v1 = -1;
        v2 = -1;
        running = inputNumber("Press <1> to continue: ");
    }
    
}

int PermutationCalculator::inputNumber(string msg)
{
    string str;
    regex regex_pattern("-?[0-9]+");
    while (!regex_match(str, regex_pattern))
    {
        cout << msg;
        cin >> str;
    }
    return stoi(str);
}

unsigned long long int PermutationCalculator::factorial(int n)
{
    unsigned long long int tmp = n;
    unsigned long long int result = 1;
    while (tmp != 0)
    {
        result *= tmp;
        tmp -= 1;
    }
    cout << result << endl;
    return result;
}

unsigned long long int PermutationCalculator::calculate(int n1, int n2)
{
    return (factorial(n1)) / (factorial((n1 - n2)));
}

PermutationCalculator::~PermutationCalculator()
{

}