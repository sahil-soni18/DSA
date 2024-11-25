#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        // Sort the input array
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long total = 0; // To keep the running sum of differences
        int l = 0;      // Left pointer for the sliding window
        int maxFreq = 1;

        for (int r = 0; r < n; ++r)
        {
            // Accumulate the total operations needed to make all elements in the window equal to nums[r]
            total += (long)(nums[r] - nums[r - 1]) * (r - l);

            // If total operations exceed k, shrink the window
            while (total > k)
            {
                total -= nums[r] - nums[l];
                l++;
            }

            // Update maximum frequency
            maxFreq = max(maxFreq, r - l + 1);
        }

    

        return maxFreq;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 4};
    int k = 5;

    // Calling the function and displaying the result
    cout << "Max Frequency: " << sol.maxFrequency(nums, k) << endl;

    return 0;
}
