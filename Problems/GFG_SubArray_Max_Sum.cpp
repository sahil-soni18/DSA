#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int maxScore(const vector<int>& arr) {
    int n = arr.size();
    int max_sum = INT_MIN;

    stack<int> st; // Monotonic stack to store indices

    for (int i = 0; i < n; ++i) {
        // Maintain monotonic stack
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int top = st.top();
            st.pop();

            // Find the second smallest element
            if (!st.empty()) {
                int second_smallest = arr[st.top()];
                int smallest = arr[top];
                max_sum = max(max_sum, smallest + second_smallest);
            }
        }
        st.push(i);
    }

    
    // Process remaining elements in stack
    while (st.size() > 1) {
        int smallest = arr[st.top()];
        st.pop();
        int second_smallest = arr[st.top()];
        max_sum = max(max_sum, smallest + second_smallest);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {4, 3, 1, 5, 6};
    cout << "Maximum Score: " << maxScore(arr) << endl;
    return 0;
}
