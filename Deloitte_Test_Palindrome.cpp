#include <iostream>

using namespace std;

bool isPalindrome ( int number ) {
    int temp = number;
    int reverse = 0;
    while ( temp != 0 ) {
        reverse = ( reverse * 10 ) + ( temp % 10 );
        temp /= 10;
    
    }
    if ( reverse == number ) return true;
    return false;
}

int main() {
    int number;
    cout << "Enter the number to check for palindrome: ";
    cin >> number;
    cout << endl;
    bool res = isPalindrome (number);
    cout << (res ? "Is palindrome" : "Not palindrome") << endl;

    return 0;
}