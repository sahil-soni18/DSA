#include <iostream>
using namespace std;

void printPattern ( int rows ) {
    static int number = 1;

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            cout << number++;
        }
        cout << endl;
    }
}

int main () {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

   printPattern(rows);

}