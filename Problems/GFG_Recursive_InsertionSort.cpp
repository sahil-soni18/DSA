#include <iostream>
#include <vector>
using namespace std;

void recur_InsertionSort(vector<int> &arr, int i, int n ) {
  
   if ( i == n ) return;
   int j = i;
   while ( j > 0 && arr[ j - 1 ] > arr [ j ] ) {
    swap(arr[j - 1], arr[j]);
    j--;
   }

   recur_InsertionSort(arr, i + 1, n);
}

int main () {
    vector<int> arr = {5, 2, 0, 3, 1};

    recur_InsertionSort(arr, 1, arr.size());

    for ( int i: arr ) {
        cout << i << " ";
    }

    return 0;
}