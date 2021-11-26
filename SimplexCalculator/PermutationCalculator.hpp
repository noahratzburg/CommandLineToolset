#pragma once
#include <string>

class PermutationCalculator
{
public:
	PermutationCalculator();
	~PermutationCalculator();
private:
	unsigned long long int calculate(int n1, int n2);
	unsigned long long int factorial(int n, int end);
	int inputNumber(std::string msg);
};