#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for ( int i = 0; i < nums.size() - 1; i++ ) {
            int min = i;
            for ( int j = i + 1; j < nums.size(); j++ ) {
                if ( nums[j] < nums[min] ) {
                    min = j;
                }
            }
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);
    
    for ( int num : nums ) {
        cout << num << " ";
    }
    
    return 0;
}