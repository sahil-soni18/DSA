#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countSubPalindrome(string const &s) {
    int count = s.size(); // Each character is a palindrome by itself
    int n = s.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) { // Fix to j <= n
            string sub = s.substr(i, j - i); // Get substring from i of length j - i
            string reversed_sub = sub;
            reverse(reversed_sub.begin(), reversed_sub.end());
            if (sub == reversed_sub) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s("abbabdbd");
    cout << "Original String: " << s << endl;

    int palindromeSubStrings = countSubPalindrome(s);

    cout << "Number of Palindromic Substrings: " << palindromeSubStrings << endl;

    return 0;
}
