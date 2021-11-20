/* 
* A console application whose sole purpose is to solve the tableau of a Simplex Maximization problem.
* I created this to help solve the hundreds of Simplex problems I have been assigned in my Finite Mathematics
* and Linear Algebra course.
   
* Author - Noah Ratzburg
* Begin Date - 11/17/2021
* End Date - 11/19/2021
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <float.h>

using std::cin; 
using std::cout; 
using std::endl; 
using std::string;
using std::setw;
using std::setprecision;
using std::to_string;
using std::regex;

/*
* Returns an integer input using regular expressions to verify user input.
*/
int inputNumber(string msg)
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
/* 
* Generates the 2-dimentional array that will be used to store
* the initial tableau of the simplex problem.
*/
double** generateInitialTableau(int rows, int cols)
{
    int i, j;
    double** tableau;
    
    tableau = new double* [rows];
    for (i = 0; i < rows; i++)
    {
        tableau[i] = new double[cols];
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            tableau[i][j] = 0.0;
        }
    }

    return tableau;
}

/*
* Generates the labels for the rows
*/
string* generateRowLabels(int rows)
{
    int i;
    string* rowLabels = new string[rows];
    for (i = 0; i < rows - 1; i++)
    {
        rowLabels[i] = ("s" + to_string(i + 1));
    }
    rowLabels[rows - 1] = "P";
    return rowLabels;
}

/*
* Generates the labels for the columns
*/
string* generateColumnLabels(int cols, int num_vars)
{
    int i, j = 1, z = num_vars;
    string* colLabels = new string[cols];
    for (i = 0; i < cols - 2; i++)
    {
        if (z != 0)
        {
            colLabels[i] = ("x" + to_string(i + 1));
            z--;
        }
        else
        {
            colLabels[i] = ("s" + to_string(j));
            j++;
        }
    }
    colLabels[cols - 2] = "P";
    colLabels[cols - 1] = "RESULTS";
    return colLabels;
}

/*
* Prints the tableau to terminal.
*/
void printTableau(double** tableau, string* rowLabels, string* colLabels, int rows, int cols)
{
    cout << "{ Resulting Tableau }" << endl;
    int i, j;
    
    /* Print column labels */
    cout << setw(10) << "~~~~~~~~~";
    for (i = 0; i < cols; i++)
    {
        cout << setw(11) << colLabels[i];
    }
    cout << endl;

    /* Print the remaining data to the terminal */
    for (i = 0; i < rows; i++)
    {
        cout << setw(10) << rowLabels[i];
        for (j = 0; j < cols; j++)
        {
           cout << setw(10) << setprecision(3) << std::fixed << tableau[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
* Function that takes user input to fill the tableau after initializing
* it. No error handling at the moment.
*/
void fillTableau(double** tableau, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        cout << "{ Begin filling for Row " << i + 1 << " left to right }" << endl;
        for (j = 0; j < cols; j++)
        {
            tableau[i][j] = inputNumber("");
        }
        system("cls");
    }
}

/*
* Computes the entry index to be used in reducing the tableau.
*/
int getEntryIndex(double** tableau, int rows, int cols)
{
    int i;
    int j = -1;
    double tmp = 0.0;
    for (i = 0; i < cols - 1; i++)
    {
        if (tableau[rows - 1][i] < 0)
        {
            tmp = tableau[rows - 1][i];
            break;
        }
    }

    /* If no negative was found */
    if (i == cols - 1 && tableau[rows - 1][i] >= 0) return -1;
    
    for (i = 0; i < cols - 1; i++)
    {
        if (tableau[rows - 1][i] <= tmp)
        {
            tmp = tableau[rows - 1][i];
            j = i;
        }
    }
    return j;
}

/*
* Computes the exit index to be used in reducing the tableau.
*/
int getExitIndex(double** tableau, int rows, int cols, int entry)
{
    int i;
    int j = -1;
    double tmp = DBL_MAX;
    for (i = 0; i < rows - 1; i++)
    {
        if (tableau[i][cols - 1] / tableau[i][entry] < tmp)
        {
            tmp = tableau[i][cols - 1] / tableau[i][entry];
            j = i;
        }
    }
    return j;
}

void computeTableau(double** tableau, string* rowLabels, string* colLabels, int rows, int cols)
{
    int i, j;
    bool running = true;
    double divisor = 0.0;
    double multiplier = 0.0;
    int entry = getEntryIndex(tableau, rows, cols);
    while (entry != -1)
    {
        int exit = getExitIndex(tableau, rows, cols, entry);
        divisor = tableau[exit][entry];

        rowLabels[exit] = colLabels[entry];

        /* Divides entire exit row by tableau[exit][entry] */
        for (i = 0; i < cols; i++)
        {
            tableau[exit][i] = tableau[exit][i] / divisor;
        }

        for (i = 0; i < rows; i++)
        {
            if (i != exit)
            {
                multiplier = -1 * tableau[i][entry];
                for (j = 0; j < cols; j++)
                {
                    tableau[i][j] = tableau[i][j] + (tableau[exit][j] * multiplier);
                }
            }
        }
        entry = getEntryIndex(tableau, rows, cols);
    }
}

int main()
{
    int running = 1;

    double** tableau;
    string* colLabels;
    string* rowLabels;

    int rows = -1;
    int cols = -1;
    int num_vars = -1;

    while(running == 1)
    {
        while (rows < 0 && cols < 0 && num_vars < 0)
        {
            rows = inputNumber("{ Enter number of rows in initial tableau } ");
            cols = inputNumber("{ Enter number of columns in initial tableau } ");
            num_vars = inputNumber("{ Enter number of variables } ");

            system("cls");
            if (rows < 0) cout << "~# NUMBER OF ROWS MUST BE POSITIVE #~" << endl;
            if (cols < 0) cout << "~# NUMBER OF COLUMNS MUST BE POSITIVE #~" << endl;
            if (num_vars < 0) cout << "~# NUMBER OF VARIABLES MUST BE POSITIVE #~" << endl;
        }

        tableau = generateInitialTableau(rows, cols);
        rowLabels = generateRowLabels(rows);
        colLabels = generateColumnLabels(cols, num_vars);

        fillTableau(tableau, rows, cols);
        computeTableau(tableau, rowLabels, colLabels, rows, cols);
        
        system("cls");
        printTableau(tableau, rowLabels, colLabels, rows, cols); 
        rows = -1;
        cols = -1;
        num_vars = -1;

        running = inputNumber("{ Press <1> to continue | Press <any other #> to exit } ");
        system("cls");
        
        int i;
        for (i = 0; i < rows; i++)
            delete[] tableau[i];
        delete[] tableau;
        delete[] colLabels;
        delete[] rowLabels;
    }
    
    return 1;
}
