#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;

        for ( int i = 0; i < nums.size(); i++ ) {
            map[nums[i]]++;
        }

        for ( auto x: map ) {
            cout << x.first << " " << x.second << endl;
        }
        cout << endl;

        int max = 0;
        for ( auto x: map ) {
            if ( x.second > max ) {
                max = x.second;
            }
        }

        // cout << "Majority Element: " << max << endl;

        for ( auto x: map ) {
            if ( x.second == max ) {
                // cout << "----------" << x.first << "     " << x.second << endl;
                max = x.first;
                break;
            }
        }



        return max;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1,1,1,1,2,1};

    cout << solution.majorityElement(nums) << endl;

    return 0;
}