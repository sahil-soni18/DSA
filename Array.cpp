#include <iostream>
using namespace std;

int* insertElement(int arr[], int& size, int element, int position) {
    // Check if the position is valid
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
        return arr;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;  // Insert the new element
    size++;  // Increase the size of the array

    return arr;
}

void deleteElement ( int arr[], int& size, int element) {
    int index = -1;
    for ( int i = 0; i < size; i++ ) {
        if ( arr[i] == element) {
            index = i;
            break;
        }
    }

    if ( index == -1 ) {
        cout << "Element Not Found!";
        return;
    } else {
        for ( int i = index + 1; i < size; i++ ) {
            arr[i - 1] = arr[i];
        }
    }

    size--;
}

int main() {
    int arr[7] = {1, 2, 3, 4, 5, 6};  // Increased size for one additional element
    int arrSize = 6;  // Current number of elements in the array

    cout << "Array before performing any operation: ";
    for (int number : arr) {
        cout << number << " ";
    }
    cout << endl;

    int ele, pos;
    cout << "Enter Element to insert in array along with the position to insert at: ";
    cin >> ele >> pos;

    // Perform the insertion
    int* SortedArray = insertElement(arr, arrSize, ele, pos);

    cout << "Array after performing the operation: ";
    for (int i = 0; i < arrSize; i++) {
        cout << SortedArray[i] << " ";
    }
    cout << endl;

    int elementToDelete;
    cout << "Enter element to delete from the array: ";
    cin >> elementToDelete;

    deleteElement(arr, arrSize, elementToDelete);

    cout << "Array after deletion: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
