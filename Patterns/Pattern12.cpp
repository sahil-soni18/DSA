#include <iostream>
using namespace std;

int main () {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    int counter;

    for ( int i = 1; i <= rows; i++ ) {
        for ( int j = 1; j <= i; j++ ) {
            cout << j;
            counter = j;
        }

        for ( int j = 1; j <= 2*rows - 2*i; j++ ) {
            cout << " ";
        }

        for ( int j = counter; j >= 1; j-- ) {
            cout << j;
        }
        cout << endl;
    }
}