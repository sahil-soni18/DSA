#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int low, int high, int key) {
    if ( high < low ) return -1;

    
        int mid = (low + high) / 2;
        if ( arr[mid] == key ) {
            return mid;
        } else if ( arr[mid] < key ) return binarySearch(arr, (mid + 1), high, key);

        return binarySearch(arr, low, (mid - 1), key);
    

}

int main () {
    vector<int> array = {5, 18, 28, 2, 0, 1, 19};
    sort(array.begin(), array.end());

    cout << "Array After Sort: " << endl;

    for ( int number: array ) {
        cout << number << " ";
    }

    cout << endl;
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int searchResult = binarySearch(array, 0, array.size(), key);

    if ( searchResult == -1 ) cout << "Element Not Found..." << endl;
    else {
        cout << "Element found at index " << searchResult << endl;
    }

    
}