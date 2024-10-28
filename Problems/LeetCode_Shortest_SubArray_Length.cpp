#include <iostream>
#include <vector>
#include <limits.h> // for INT_MAX

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;

        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int end = start; end < n; ++end) {
                sum += nums[end];
                // Check if the current subarray's sum is >= k
                if (sum >= k) {
                    minLength = min(minLength, end - start + 1);
                    break; // Move to the next starting index since we want the shortest
                }
            }
        }
        
        // If minLength wasn't updated, it means no subarray met the condition
        return minLength == INT_MAX ? -1 : minLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -1, 2, 1, -3, 4};
    int k = 3;
    
    int result = sol.shortestSubarray(nums, k);
    if (result == -1) {
        cout << "No subarray with sum >= " << k << " found." << endl;
    } else {
        cout << "Length of the shortest subarray with sum >= " << k << ": " << result << endl;
    }
    
    return 0;
}
