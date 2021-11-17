#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int running = 1;
    
    int arr_w = -1;
    int arr_h = -1;
    int num_vars = -1;

    while ( arr_w < 0 && arr_h < 0 && num_vars < 0 )
    {
        cout << "Enter number of rows in initial tableau: ";
        cin >> arr_h;
        cout << "Enter number of columns in initial tableau: ";
        cin >> arr_w;
        cout << "Enter number of variables: ";
        cin >> num_vars;

        if (arr_h < 0) cout << "~# NUMBER OF ROWS MUST BE POSITIVE #~" << endl;
        if (arr_w < 0) cout << "~# NUMBER OF COLUMNS MUST BE POSITIVE #~" << endl;
        if (num_vars < 0) cout << "~# NUMBER OF VARIABLES MUST BE POSITIVE #~" << endl;
    }

    cout << "Creating initial tableau | Rows " << arr_h << " | Columns " << arr_h << " | Variables " << num_vars << endl;

    return 1;
}
