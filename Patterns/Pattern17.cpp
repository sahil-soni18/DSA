#include <iostream>
using namespace std;

int main () {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < rows - i; j++ ) {
            cout << " ";
        }

        
        for ( int j = 0; j <= i; j++) {
            cout << (char)(65 + j);
        }

        for ( int j = i; j > 0; j-- ) {
            cout << (char)(64 + j);
        }

        cout << endl;
        
    }
}