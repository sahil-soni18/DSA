#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
     bool check(vector<int>& nums) {
        int count = 0; // Count the number of "breaks" in sorted order.
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if the current element is greater than the next element.
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // The array can be rotated to sorted order if there is at most one "break".
        return count <= 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,4,5,1,2};
    cout << solution.check(nums) << endl;  // Output: 1
    return 0;
}
