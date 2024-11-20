#include <iostream>
using namespace std;

int main() {
    int row;

    cout << "Enter the value of row: ";
    cin >> row;

    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            cout << "* ";
        }
        cout << endl;
    }

    for ( int i = row - 2; i >= 0; i-- ) {
        for ( int j = i; j >= 0; j-- ) {
            cout << "* ";
        }
        cout << endl;
    }
}