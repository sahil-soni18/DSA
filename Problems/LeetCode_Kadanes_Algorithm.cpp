#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

#ifndef INT_MIN
#define INT_MIN (-2147483647 - 1)
#endif


int maxSubArraySum(const vector<int>& nums) {
    int max_sum = INT_MIN; // Initialize max_sum to the smallest integer
    int current_sum = 0;   // Initialize current_sum to 0

    for (int num : nums) {
        current_sum = max(num, current_sum + num); // Extend or reset the subarray
        max_sum = max(max_sum, current_sum);      // Update max_sum if current_sum is greater
    }

    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArraySum(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
