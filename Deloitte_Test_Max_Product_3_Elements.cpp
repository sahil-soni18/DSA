#include <iostream>
#include <vector>
#include <climits>  

using namespace std;

int max_product(vector<int>& arr) {
    if (arr.size() < 3) {

        return 0;
    }


    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : arr) {

        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }


    int product1 = max1 * max2 * max3; 
    int product2 = min1 * min2 * max1;  


    return max(product1, product2);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int maxProduct = max_product(arr);
    cout << "The maximum product of three numbers is: " << maxProduct << endl;
    return 0;
}