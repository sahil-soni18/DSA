#include <iostream>
#include <vector>
using namespace std;

void recur_bubbleSort(vector<int> &arr, int n ) {
    if ( n == 1 ) return;

    for ( int i = 0; i < n - 1; i++ ) {
        if ( arr[i] > arr[i + 1] ) {
            swap(arr[i], arr[i + 1]);
        }
    }

    recur_bubbleSort(arr, n - 1);
}

int main () {
    vector<int> arr = {5, 3, 1, 2, 0, 8};

    recur_bubbleSort(arr, arr.size());

    for ( int i: arr ) {
        cout << i << " ";
    }

    return 0;
}