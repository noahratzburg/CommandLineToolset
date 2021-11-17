/* 
* A console application whose sole purpose is to solve the tableau of a Simplex Maximization problem.
* I created this to help solve the hundreds of Simplex problems I have been assigned in my Finite Mathematics
* and Linear Algebra course.
   
* Author - Noah Ratzburg
* Date - 11/17/2021
*/

#include <iostream>
#include <iomanip>
#include <string>

using std::cin; 
using std::cout; 
using std::endl; 
using std::string;
using std::setw;
using std::setprecision;
using std::to_string;

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
        rowLabels[i] = ("s" + to_string(i));
    }
    rowLabels[rows - 1] = "RESULTS";
    return rowLabels;
}

/*
* Generates the labels for the columns
*/
string* generateColumnLabels(int cols, int num_vars)
{
    int i, j = 1, z = num_vars;
    string* colLabels = new string[cols];
    for (i = 0; i < cols - 1; i++)
    {
        if (z != 0)
        {
            colLabels[i] = ("x" + to_string(i));
            z--;
        }
        else
        {
            colLabels[i] = ("s" + to_string(j));
            j++;
        }
    }
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
           cout << setw(10) << setprecision(10) << tableau[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fillTableau(double** tableau, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        cout << "{ Begin filling for Row " << i << " left to right }" << endl;
        for (j = 0; j < cols; j++)
        {
            cin >> tableau[i][j];
        }
        cout << endl;
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

    while ( rows < 0 && cols < 0 && num_vars < 0 )
    {
        cout << "{ Enter number of rows in initial tableau } ";
        cin >> rows;
        cout << "{ Enter number of columns in initial tableau } ";
        cin >> cols;
        cout << "{ Enter number of variables } ";
        cin >> num_vars;

        cout << endl;

        if (rows < 0) cout << "~# NUMBER OF ROWS MUST BE POSITIVE #~" << endl;
        if (cols < 0) cout << "~# NUMBER OF COLUMNS MUST BE POSITIVE #~" << endl;
        if (num_vars < 0) cout << "~# NUMBER OF VARIABLES MUST BE POSITIVE #~" << endl;
    }

    tableau = generateInitialTableau(rows, cols);
    rowLabels = generateRowLabels(rows);
    colLabels = generateColumnLabels(cols, num_vars);

    printTableau(tableau, rowLabels, colLabels, rows, cols);

    fillTableau(tableau, rows, cols);
    printTableau(tableau, rowLabels, colLabels, rows, cols);

    cout << "Creating initial tableau | Rows " << rows << " | Columns " << cols << " | Variables " << num_vars << endl;
    
    int i;
    for (i = 0; i < rows; i++)
        delete[] tableau[i];
    delete[] tableau;
    delete[] colLabels;
    delete[] rowLabels;
    return 1;
}
