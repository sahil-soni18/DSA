#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int N) {
    // Create a boolean array "isPrime[0..N]" and initialize
    // all entries as true. A value in isPrime[i] will
    // be false if i is Not a prime, otherwise true.
    vector<bool> isPrime(N + 1, true);

    // Set 0 and 1 as non-prime numbers
    isPrime[0] = isPrime[1] = false;

    // Mark all multiples of i as non-prime
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    cout << "Prime numbers less than or equal to " << N << " are:\n";
    sieveOfEratosthenes(N);

    return 0;
}
