#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumIndex; // To store (prefixSum, first index)
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            // Case 1: If the prefix sum equals k, update the max length
            if (prefixSum == k) {
                maxLength = i + 1;
            }

            // Case 2: If (prefixSum - k) exists in the map, update max length
            if (prefixSumIndex.find(prefixSum - k) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum - k]);
            }

            // Case 3: Store prefix sum in the map if not already present
            if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end()) {
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution s;
    vector<int> arr = {94, -33, -13, 40, -82, 94, -33, -13, 40, -82};
    int k = 52;
    cout << "Length of longest subarray with sum equal to " << k << ": " << s.lenOfLongestSubarr(arr, k) << endl;
    return 0;
}
