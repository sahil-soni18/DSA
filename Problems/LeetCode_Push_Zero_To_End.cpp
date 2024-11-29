#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;

        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] != 0 ) {
                nums[index++] = nums[i];
            }
        }

        while ( index < nums.size() ) {
            nums[index++] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    
    for ( int num : nums ) {
        cout << num << " ";
    }
    
    return 0;

}
