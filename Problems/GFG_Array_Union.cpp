#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:

         vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        set<int> uniqueSet;
        
        for ( int i: a ) uniqueSet.insert(i);
        for ( int i: b ) uniqueSet.insert(i);
        
        vector<int> result(uniqueSet.begin(), uniqueSet.end());
        
        return result;
        
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {4, 5, 6, 7, 8};
    vector<int> unionResult = s.findUnion(a, b);
    for ( int i: unionResult ) cout << i << " ";
    return 0;
}