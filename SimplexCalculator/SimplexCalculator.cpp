/* 
* A console application whose sole purpose is to solve the tableau of a Simplex Maximization problem.
* I created this to help solve the hundreds of Simplex problems I have been assigned in my Finite Mathematics
* and Linear Algebra course.
   
* Author - Noah Ratzburg
* Date - 11/17/2021
*/

#include <iostream>

using std::cin; using std::cout; using std::endl;

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
            tableau[i][j] = 0.69;
        }
    }

    return tableau;
}

/*
* Prints the tableau to terminal.
*/
void printTableau(double** tableau, int rows, int cols, int num_vars)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
           cout << tableau[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int running = 1;
    
    double** tableau;
    int rows = -1;
    int cols = -1;
    int num_vars = -1;

    while ( rows < 0 && cols < 0 && num_vars < 0 )
    {
        cout << "Enter number of rows in initial tableau: ";
        cin >> rows;
        cout << "Enter number of columns in initial tableau: ";
        cin >> cols;
        cout << "Enter number of variables: ";
        cin >> num_vars;

        if (rows < 0) cout << "~# NUMBER OF ROWS MUST BE POSITIVE #~" << endl;
        if (cols < 0) cout << "~# NUMBER OF COLUMNS MUST BE POSITIVE #~" << endl;
        if (num_vars < 0) cout << "~# NUMBER OF VARIABLES MUST BE POSITIVE #~" << endl;
    }

    tableau = generateInitialTableau(rows, cols);
    printTableau(tableau, rows, cols, num_vars);

    cout << "Creating initial tableau | Rows " << rows << " | Columns " << cols << " | Variables " << num_vars << endl;

    delete[] tableau;
    return 1;
}
