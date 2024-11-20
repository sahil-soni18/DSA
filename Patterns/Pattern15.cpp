#include <iostream>
using namespace std;

int main ( ) {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    for ( int i = rows - 1; i >= 0; i-- ) {
        for ( int j = 0; j <= i; j++ ) {
            cout << (char)(65 + j) << " ";
        }
        cout << endl;
    }
}