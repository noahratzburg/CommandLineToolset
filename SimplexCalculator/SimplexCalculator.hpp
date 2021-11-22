#pragma once

#include <string>

class SimplexCalculator
{
public:
	SimplexCalculator();
	~SimplexCalculator();
private:
	int inputNumber(std::string msg);
	double** generateInitialTableau(int rows, int cols);
	std::string* generateRowLabels(int rows);
	std::string* generateColumnLabels(int cols, int num_vars);
	void printTableau(double** tableau, std::string* rowLabels, std::string* colLabels, int rows, int cols);
	void fillTableau(double** tableau, int rows, int cols);
	int getEntryIndex(double** tableau, int rows, int cols);
	int getExitIndex(double** tableau, int rows, int cols, int entry);
	void computeTableau(double** tableau, std::string* rowLabels, std::string* colLabels, int rows, int cols);
};