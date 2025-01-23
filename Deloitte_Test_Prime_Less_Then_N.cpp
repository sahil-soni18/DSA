#include <iostream>
#include <vector>
#include <cmath> // For sqrt function

using namespace std;

vector<int> returnPrime(int n) {
    vector<int> primes;

    // Start from 2, since 1 is not a prime number
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;

        // Check divisibility up to the square root of i
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break; // No need to check further if i is divisible by j
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int number;
    cout << "Enter number to print prime numbers up to: ";
    cin >> number;

    vector<int> primesTillN = returnPrime(number);

    for (int prime : primesTillN) {
        cout << prime << " ";
    }

    return 0;
}