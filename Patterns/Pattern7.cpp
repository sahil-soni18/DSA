#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter the value for rows: ";
    cin >> rows;

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < rows - i - 1; j++ ) {
            cout << " ";
        }

        for ( int j = 0; j < 2*i+1; j++ ) {
            cout << "*";
        }

        for ( int j = 0; j < rows - i - 1; j++ ) {
            cout << " ";
        }

        cout << endl;
        
    }
}