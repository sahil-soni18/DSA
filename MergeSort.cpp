#include <iostream>
using namespace std;

void merge ( int arr[], int mid, int left, int right ) {

    int len1 = mid - left + 1;
    int len2 = right - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = left;

    for ( int  i = 0; i < len1; i++ ) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;

    for ( int  i = 0; i < len2; i++ ) {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = left;

    while ( index1 < len1 && index2 < len2 ) {
        if ( first[index1] < second[index2] ) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while ( index1 < len1 ) {
            arr[mainArrayIndex++] = first[index1++];
    }
    while ( index2 < len2 ) {
            arr[mainArrayIndex++] = second[index2++];
    }

}

void mergeSort( int arr[], int size, int left, int right ) {
    if ( left >= right ) {
        return;
    }

    int mid = left + ( right - left ) / 2;

    mergeSort(arr, size, left, mid);
    mergeSort(arr, size, mid + 1, right);
    merge(arr, mid, left, right);
}

int main () {
    int array[10] = {42, 7, 15, 89, 23, 56, 3, 67, 34, 12};

    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, size, 0, size - 1);

    cout << " The Sorted Array is: " << endl;

    for ( int element: array ) {
        cout << element << " ";
    }
    cout << endl;

    return 0;


}