#include <iostream>
using namespace std;

int main () {
    int rows;

    cout << "Enter the values for rows: ";
    cin >> rows;

    int flag = 1;

    for ( int i = 0; i < rows; i++ ) {
        if ( i % 2 == 0 ) flag = 1;
        else flag = 0;

        for ( int j = 0; j <= i; j++ ) {
            cout << flag;
            flag = 1 - flag;
        }
        cout << endl;
    }
}