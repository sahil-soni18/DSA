#include <iostream>
#include <vector>

using namespace std;

// Implementing Sliding Window.

int maxSubArraySum(vector<int> arr, int range) {
    int max_sum = 0;


    for ( int i = 0; i < range; i++ ) {
        max_sum += arr[i];
    }

    int max_window_sum = max_sum;
    for ( int i = range; i < arr.size(); i++ ) {
        max_window_sum += arr[i] - arr[i - range];
        max_sum = max(max_sum, max_window_sum);
    }

    return max_sum;
}

int main () {

    vector<int> array = {-12, 35, -7, 18, 5, 25};
    cout << "The Maximum Sum Of Sub Array is: " << maxSubArraySum(array, 2);

    return 0;
}