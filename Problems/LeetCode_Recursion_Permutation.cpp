#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; i++) {  // Generate string "123...n"
            str += to_string(i);
        }
        
        vector<string> result;
        permute(str, 0, result);

        for ( int i = 0; i < result.size(); i++ ) {
            cout << result[i] << endl;  // Print all permutations for debugging purposes
        }
        
        return result[k - 1]; // k is 1-based, so we access `k - 1`
    }

private:
    void permute(string str, int idx, vector<string>& result) {
        if (idx == str.size() - 1) {
            result.push_back(str);  // Store the permutation
            return;
        }
        
        for (int i = idx; i < str.size(); i++) {
            swap(str[idx], str[i]);            // Swap to create new permutation
            permute(str, idx + 1, result);     // Recur to generate permutations
            swap(str[idx], str[i]);            // Backtrack
        }
    }
};

int main() {
    int n, k;
    cout << "Enter n (number of digits to permute): ";
    cin >> n;
    cout << "Enter k (1-based index of permutation to find): ";
    cin >> k;

    Solution solution;
    string result = solution.getPermutation(n, k);
    cout << "The " << k << "-th permutation of numbers from 1 to " << n << " is: " << result << endl;

    return 0;
}
