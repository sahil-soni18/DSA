#include <iostream>
using namespace std;

int main () {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    for ( int i = 0; i < 2*rows - 1; i++ ) {
        for ( int j = 0; j < 2*rows - 1; j++ ) {

            int top = i;
            int left = j;
            int bottom = (2*rows - 2) - i;
            int right = (2 * rows - 2) - j;

            cout << (rows - min(min(top, bottom), min(left, right))) << " ";
        }
        cout << endl;
    }
}