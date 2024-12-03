#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void printMatrix(const vector<vector<vector<int>>>& matrix) {
    for (const auto& plane : matrix) {
        for (const auto& row : plane) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


vector<int> flattenMatrix(const vector<vector<vector<int>>>& matrix) {
    vector<int> flat;
    for (const auto& plane : matrix) {
        for (const auto& row : plane) {
            for (int val : row) {
                flat.push_back(val);
            }
        }
    }
    return flat;
}


vector<vector<vector<int>>> reshapeMatrix(const vector<int>& flat, int x, int y, int z) {
    vector<vector<vector<int>>> matrix(x, vector<vector<int>>(y, vector<int>(z)));
    int index = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                matrix[i][j][k] = flat[index++];
            }
        }
    }
    return matrix;
}

void generateNegativeCombinations(const vector<vector<vector<int>>>& matrix) {

    vector<int> flat = flattenMatrix(matrix);
    int n = flat.size();


    int totalCombinations = pow(2, n);

    cout << "All possible negative combinations:\n";
    for (int mask = 0; mask < totalCombinations; mask++) {
        vector<int> current = flat;


        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { 
                current[i] = -current[i];
            }
        }

        vector<vector<vector<int>>> reshaped = reshapeMatrix(current, matrix.size(), matrix[0].size(), matrix[0][0].size());
        printMatrix(reshaped);
    }
}

int main() {
    vector<vector<vector<int>>> matrix = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    generateNegativeCombinations(matrix);

    return 0;
}

