#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base cases
        if (n == 1) return true;                // 3^0 = 1, so if n is 1, it is a power of 3.
        if (n <= 0 || n % 3 != 0) return false; // Negative, zero, or non-divisible by 3 means not a power of 3.

        // Recursive call
        return isPowerOfThree(n / 3);
    }
};

int main() {
    Solution solution;
    int testCases[] = {1, 3, 9, 27, 45, 81, 243, 0, -3, 10};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isPowerOfThree(n);
        cout << "Is " << n << " a power of three? " << (result ? "Yes" : "No") << endl;
    }

    return 0;
}
