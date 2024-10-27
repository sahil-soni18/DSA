#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two matrices
vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();          // Number of rows in matrix 'a'
    int p = a[0].size();       // Number of columns in matrix 'a'
    int m = b[0].size();       // Number of columns in matrix 'b'

    // Initialize the result matrix with size n x m and all values as 0
    vector<vector<int>> result(n, vector<int>(m, 0));

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                result[i][j] += a[i][k] * b[k][j]; // Note the correct indices
            }
        }
    }

    return result;
}

int main() {
    // Initialize two matrices
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> matrix2 = {{7, 8}, {9, 10}, {11, 12}};

    // Multiply the matrices
    vector<vector<int>> resultant = multiply(matrix1, matrix2);

    // Print the result matrix
    for (int i = 0; i < resultant.size(); i++) {
        for (int j = 0; j < resultant[0].size(); j++) {
            cout << resultant[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
