#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1; // Target not found
        }

        int mid = left + (right - left) / 2; // Avoid potential overflow
        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] > target) {
            return binarySearch(nums, target, left, mid - 1); // Search in the left half
        } else {
            return binarySearch(nums, target, mid + 1, right); // Search in the right half
        }
    }
};


int main() {
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 0;
    cout << solution.search(nums, target) << endl; // Output: 4
    return 0;
}