#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int num : nums) {
            single ^= num; // XOR all numbers
        }
        return single;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 4, 4, 5, 5};
    cout << "The single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}