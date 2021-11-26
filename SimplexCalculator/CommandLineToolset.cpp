#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

#include "SimplexCalculator.hpp"
#include "PermutationCalculator.hpp"

using std::cin; 
using std::cout; 
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using std::regex;

int page = 0;
int running = 1;

int inputNumber()
{
    string str;
    regex regex_pattern("-?[0-9]+");
    while (!regex_match(str, regex_pattern))
    {
        cin >> str;
    }
    return stoi(str);
}

void displayPage()
{
    switch (page)
    {
    case 0:
        cout << setw(1) << "(1) : Simplex Maximization Calculator" << "\n";
        cout << setw(1) << "(2) : Permutation Calculator" << "\n";
        cout << setw(1) << "(3) : N/A" << "\n";
        cout << setw(1) << "(4) : N/A" << "\n";
        cout << setw(1) << "(5) : N/A" << "\n";
        cout << setw(1) << "(6) : N/A" << "\n";
        cout << setw(1) << "Page : " << page << endl;
        break;
    default:
        cout << setw(1) << "(1) : N/A" << "\n";
        cout << setw(1) << "(2) : N/A" << "\n";
        cout << setw(1) << "(3) : N/A" << "\n";
        cout << setw(1) << "(4) : N/A" << "\n";
        cout << setw(1) << "(5) : N/A" << "\n";
        cout << setw(1) << "(6) : N/A" << "\n";
        cout << setw(1) << "Page : " << page << endl;
        break;
    }
}

void display()
{
    cout << setw(1) << "##################################################" << "\n";
    cout << setw(1) << "#                                                #" << "\n";
    cout << setw(1) << "#                                                #" << "\n";
    cout << setw(1) << "#                                                #" << "\n";
    cout << setw(1) << "#              COMMAND LINE TOOLSET              #" << "\n";
    cout << setw(1) << "#                                                #" << "\n";
    cout << setw(1) << "#                                                #" << "\n";
    cout << setw(1) << "#                                                #" << "\n";
    cout << setw(1) << "##################################################" << "\n";
    cout << "\n";
    displayPage();
    cout << setw(1) << "<-- (7) | (8) --> | (9) Exit" << endl;
    cout << setw(1) << "Enter Selection : ";
}

void manageSelection(int selection)
{
    SimplexCalculator* sc = NULL;
    PermutationCalculator* pc = NULL;
    switch (page)
    {
    case 0:
        switch (selection)
        {
        case 1:
            system("cls");
            sc = new SimplexCalculator();
            sc->~SimplexCalculator();
            break;
        case 2:
            system("cls");
            pc = new PermutationCalculator();
            pc->~PermutationCalculator();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            if (page > 0) page -= 1;
            break;
        case 8:
            page += 1; 
            break;
        case 9:
            running = -1;
            break;
        default:
            break;
        }
        break;
    default:
        switch (selection)
        {
        case 7:
            if (page > 0) page -= 1;
            break;
        case 8:
            page += 1;
            break;
        case 9:
            running = -1;
            break;
        default:
            break;
        }
        break;
    }
}

int main()
{
    int selection = -1;

    while (running == 1)
    {
        display();
        while (selection <= 0)
        {
            selection = inputNumber();
        }
        manageSelection(selection);

        if (running != 1) break;

        selection = -1;
        system("cls");
    }

	return 1;
}