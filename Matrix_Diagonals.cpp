// C++ Program to print the Diagonals of a Matrix

#include <iostream>
using namespace std;

const int MAX = 100;

// Function to print the Principal Diagonal
void printPrincipalDiagonal(int mat[][MAX], int n)
{
	cout << "Principal Diagonal: ";

	for (int i = 0; i < n; i++) {
		// Printing principal diagonal
		cout << mat[i][i] << ", ";
	}
	cout << endl;
}

// Function to print the Secondary Diagonal
void printSecondaryDiagonal(int mat[][MAX], int n)
{
	cout << "Secondary Diagonal: ";
	int k = n - 1;
	for (int i = 0; i < n; i++) {
		// Printing secondary diagonal
		cout << mat[i][k--] << ", ";
	}
	cout << endl;
}

// Driver code
int main()
{
	int n = 4;
	int a[][MAX] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 1, 2, 3, 4 },
					{ 5, 6, 7, 8 } };

	printPrincipalDiagonal(a, n);
	printSecondaryDiagonal(a, n);
	return 0;
}


