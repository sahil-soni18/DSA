#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> rearrangeArray(vector<int>& nums ) {
        int n = nums.size();
        if (n < 2) {
            return nums;
        }
        vector<int> positiveArray;
        vector<int> negativeArray;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                positiveArray.push_back(nums[i]);
            } else {
                negativeArray.push_back(nums[i]);
            }
        }
        vector<int> result;
        int i = 0, j = 0;
        while (i < positiveArray.size() && j < negativeArray.size()) {
            result.push_back(positiveArray[i]);
            result.push_back(negativeArray[j]);
            i++;
            j++;
        }
        while (i < positiveArray.size()) {
            result.push_back(positiveArray[i]);
            i++;
        }
        while (j < negativeArray.size()) {
            result.push_back(negativeArray[j]);
            j++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> result = s.rearrangeArray(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}