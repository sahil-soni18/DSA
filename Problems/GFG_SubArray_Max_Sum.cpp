#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int maxScore(const vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
    {
        // If there are fewer than 2 elements, return 0 (or handle invalid input).
        return 0;
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < n - 1; ++i)
    {
        max_sum = max(max_sum, arr[i] + arr[i + 1]);
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {4, 3, 1, 5, 6};
    cout << "Maximum Score: " << maxScore(arr) << endl;
    return 0;
}
