#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertElement(vector<int>& arr, int& size, int element) {
    
    arr.push_back(0); 
    int i = size;  

    
    while (i > 0 && element < arr[i - 1]) {
        arr[i] = arr[i - 1];  
        i--;
    }

    arr[i] = element;  
    size++; 
}


int binarySearch(const vector<int>& arr, int low, int high, int key) {
    if (high < low) return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, high, key);
    }

    return binarySearch(arr, low, mid - 1, key);
}
void deleteElement (  vector<int>& arr, int& size, int key ) {
    int position = binarySearch( arr, 0, size - 1, key );

    if ( position == -1 ) {
        cout << "Element Not Found" << endl;
        return;
    }

    for ( int i = position ; i < size; i++ ) {
        arr[i] = arr[i + 1];
    }

    size--;
}


int main() {
    vector<int> array = {5, 18, 28, 2, 0, 1, 19};
    sort(array.begin(), array.end());

    cout << "Array After Sort: " << endl;
    for (int number : array) {
        cout << number << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the element to Insert: ";
    cin >> key;

    int size = array.size(); 
    insertElement(array, size, key); 

    cout << "Array After Insertion: " << endl;
    for (int number : array) {
        cout << number << " ";
    }
    cout << endl;

    int elementToDelete;
    cout << "Enter element to delete from the array: ";
    cin >> elementToDelete;

    deleteElement(array, size, elementToDelete);

    cout << "Array after deletion: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
