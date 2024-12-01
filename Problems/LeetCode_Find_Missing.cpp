#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        int totalSum = n * (n + 1) / 2;
        int arraySum = 0;
        
        for (int num : nums) {
            arraySum += num; 
        }
        
        return totalSum - arraySum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 0, 1};
    cout << solution.missingNumber(nums) << endl; // Output: 2
    
    nums = {0, 1};
    cout << solution.missingNumber(nums) << endl; // Output: 2
    
    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << solution.missingNumber(nums) << endl; // Output: 8
    
    return 0;
}