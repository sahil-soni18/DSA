#include <iostream>
#include <vector>
using namespace std;

int getMedium ( vector<int>& arr1, vector<int>& arr2, int size1, int size2 ) {
    int newSize = size1 + size2;
    cout << " newSize: " << newSize << endl;
    vector<int> newArr;

    int i = 0;

    while ( i < newSize && i < size1 ) {
        newArr.push_back(arr1[i]);
        i++;
    }

    i = 0;

    while ( i < newSize && i < size2 ) {
        newArr.push_back(arr2[i]);
        i++;
    }

    cout << "Printing new Array..." << endl;

    for ( int num: newArr) {
        cout << num << " ";
    }

    cout << endl;

    if ( newSize % 2 != 0 ) {
        int mid = (0 + newSize) / 2;
        cout << " Int the Odd If Returning midium = " << mid << endl;
        return newArr[mid];
    }

    int mid = (0 + newSize) / 2;
    cout << "mid = " << mid << endl;
    int medium = (newArr[mid] + newArr[mid - 1]) / 2;
    cout << " The Values are ( for debugging ) " <<  (newArr[mid] + newArr[mid + 1]) << "  " << (newArr[mid] + newArr[mid + 1]) / 2 << endl;
    cout << "Return Even Midium of: " << medium << endl;
    return medium;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int arr1Size = arr1.size();
    vector<int> arr2 = {8, 9, 10};
    int arr2Size = arr2.size();

    int medium = getMedium(arr1, arr2, arr1Size, arr2Size);

    cout << medium << endl;
    return 0;
}