#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& array, int size, int start, int end) {
    int pivot = array[start];

    int count = 0;

    for ( int  i = start + 1; i < size; i++ ) {
        if ( array[i] <= pivot ) count++;
    }

    int pivotIndex = start + count;
    swap(array[pivotIndex], array[start]);

    int i = start, j = end;

    while ( i < pivotIndex && j > pivotIndex ) {
        if ( array[i] < pivot ) i++;
        if ( array[j] > pivot ) j++;

        if ( i < pivotIndex && j > pivotIndex ) {
            swap(array[i++], array[j--]);
        }
    }

    return pivotIndex;
}


/*
DRIVER FUNCTION
1. Handle base case,
2. divide the array around the pivot,
3. Sort the subarrays using recursion.
*/
void quickSort (vector<int>& array, int size, int start, int end) {
    // base Case
    if (start >= end)
        return;

    int pivotIndex = partition(array, size, start, end);

    quickSort(array, size, start, pivotIndex);
    quickSort(array, size, pivotIndex + 1, end);

}

int main () {
    vector<int> array = {42, 7, 15, 89, 23, 56, 3, 67, 34, 12};
    int size = array.size();

    quickSort (array, size, 0, size - 1);

    for ( int i = 0; i < size; i++ ) {
        cout << array[i] << " ";
    } 
    cout << endl;

    return 0;
}