#include <iostream>
using namespace std;

int main () {
    int row;

    cout << "Enter the value for row: ";
    cin >> row;

    for ( int i = row - 1; i >= 0; i-- ) {
        for ( int j = i; j >= 0; j-- ) {
            cout << "* ";
        }
        cout << endl;
    }
}