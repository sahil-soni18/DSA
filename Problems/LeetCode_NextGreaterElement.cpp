#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            int element = nums1[i];
            int max_element = -1;  
            
            int j = 0;
            while (j < nums2.size() && nums2[j] != element) {
                j++;
            }
            
            // Look for the next greater element to the right of `element` in `nums2`
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > element) {
                    max_element = nums2[k];
                    break;
                }
            }
            
            result.push_back(max_element);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    // Output the result
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
