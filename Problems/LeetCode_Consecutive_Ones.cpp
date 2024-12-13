#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> countRecord;
        int count = 0;
        nums.push_back(0);
        for ( int i: nums ) {
            if ( i == 1 ) count++;
            else {
                countRecord.push_back(count);
                count = 0;
            }
        }

        int consecutiveOnes = *max_element(countRecord.begin(), countRecord.end());
        return consecutiveOnes;
    }
};

int main() {
    Solution solution;
    
    // Test case
    std::vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    std::vector<int> nums2 = {0, 1, 1, 0, 1, 1, 1, 0, 0, 1};
    std::vector<int> nums3 = {1, 0, 1, 1, 0, 1};
    std::vector<int> nums4 = {1, 1, 1, 0, 0, 0, 1, 1, 1};
    std::vector<int> nums5 = {0, 0, 0, 0, 0};
    
    std::cout << "Output: " << solution.findMaxConsecutiveOnes(nums1) << std::endl;  // Output: 3
    std::cout << "Output: " << solution.findMaxConsecutiveOnes(nums2) << std::endl;  // Output: 5
    std::cout << "Output: " << solution.findMaxConsecutiveOnes(nums3) << std::endl;  // Output: 2
    std::cout << "Output: " << solution.findMaxConsecutiveOnes(nums4) << std::endl;  // Output: 3
    std::cout << "Output: " << solution.findMaxConsecutiveOnes(nums5) << std::endl;  // Output: 0
    
    return 0;
}