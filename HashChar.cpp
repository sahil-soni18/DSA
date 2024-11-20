#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findOccurence(string s, vector<char> querySet) {
    vector<int> hash(26, 0); // Store occurrences for characters a-z

    // Count occurrences of each character in the string `s`
    for (char ch : s) {
        hash[ch - 'a']++;
    }

    // Prepare result for characters in `querySet`
    vector<int> result;
    for (char ch : querySet) {
        result.push_back(hash[ch - 'a']); // Get occurrence count for each character
    }

    return result;
}

int main() {
    string s;
    cin >> s; // Input the string

    int query;
    cin >> query; // Number of queries

    vector<char> querySet;
    for (int i = 0; i < query; i++) {
        char ch;
        cin >> ch; // Input character
        querySet.push_back(ch);
    }

    vector<int> result = findOccurence(s, querySet);

    // Print the results
    for (int oc : result) {
        cout << oc << " ";
    }

    return 0;
}
