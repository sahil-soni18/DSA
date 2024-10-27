#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& array, int size) {  // Pass vector by reference
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        // Sort in descending order (if array[j] < key)
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;  // Correct position for key
    }
}

int main() {
    vector<int> array = {5, 18, 28, 2, 0, 1, 19};
    int size = array.size();

    cout << "Array: " << endl;
    for (int number : array) {
        cout << number << " ";
    }
    cout << endl;

    insertionSort(array, size);  // Sorting in descending order

    cout << "Array After Insertion Sort: " << endl;
    for (int number : array) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
