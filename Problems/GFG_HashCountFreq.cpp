#include <iostream>
#include <vector>
using namespace std;

// Function to count the frequency of elements in the array
vector<int> frequencyCount(vector<int>& arr) {
    // Create a hash table to store frequencies, initialized to 0
    vector<int> hash(arr.size() + 1, 0);

    // Count occurrences of elements in the range [1, N]
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 1 && arr[i] <= arr.size()) {
            hash[arr[i]]++;
        }
    }

    // Only return frequencies for indices 1 to N
    vector<int> result(arr.size(), 0);
    for (int i = 1; i <= arr.size(); i++) {
        result[i - 1] = hash[i];
    }

    return result;
}

int main() {
    // Input array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the frequencyCount function
    vector<int> frequencies = frequencyCount(arr);

    // Output the frequencies
    cout << "Frequency of elements from 1 to " << n << ": ";
    for (int freq : frequencies) {
        cout << freq << " ";
    }
    cout << endl;

    return 0;
}
