// // C++ code to 
// // sort 2D matrix row-wise
// #include <iostream>
// using namespace std;

// void sortRowWise(int m[][4],
// 				int r, int c)
// {
// // loop for rows of matrix
// for (int i = 0; i < r; i++) 
// {
// 	// loop for column of matrix
// 	for (int j = 0; j < c; j++) 
// 	{
// 	// loop for comparison and swapping
// 	for (int k = 0; k < c - j - 1; k++) 
// 	{
// 		if (m[i][k] > m[i][k + 1]) 
// 		{
// 		// swapping of elements
// 		swap(m[i][k], m[i][k + 1]);
// 		}
// 	}
// 	}
// }

// // printing the sorted matrix
// for (int i = 0; i < r; i++) 
// {
// 	for (int j = 0; j < c; j++)
// 	cout << m[i][j] << " ";
// 	cout << endl;
// }
// }

// // Driver code
// int main()
// {
// int m[][4] = {{9, 8, 7, 1},
// 				{7, 3, 0, 2},
// 				{9, 5, 3, 2},
// 				{6, 3, 1, 2}};
// int c = sizeof(m[0]) / sizeof(m[0][0]);
// int r = sizeof(m) / sizeof(m[0]);
// sortRowWise(m, r, c);
// return 0;
// }


// Column Wise:

#include <iostream>
#include <vector>
#include <algorithm>  // For sorting

using namespace std;

void sortMatrixColumns(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Loop through each column
    for (int col = 0; col < cols; col++) {
        // Extract the current column elements into a temporary vector
        vector<int> columnElements;
        for (int row = 0; row < rows; row++) {
            columnElements.push_back(matrix[row][col]);
        }

        // Sort the column elements
        sort(columnElements.begin(), columnElements.end());

        // Place the sorted elements back into the matrix
        for (int row = 0; row < rows; row++) {
            matrix[row][col] = columnElements[row];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example 3x3 matrix
    vector<vector<int>> matrix = {
        {1, 4, 7},
        {3, 2, 5},
        {9, 6, 8}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Sort the matrix column-wise
    sortMatrixColumns(matrix);

    cout << "Column-wise Sorted Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}

