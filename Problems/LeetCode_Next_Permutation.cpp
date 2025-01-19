#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    bool isRowMatch(const std::vector<int> &row, const std::vector<int> &target)
    {
        if (row.size() != target.size())
            return false;
        for (size_t i = 0; i < row.size(); ++i)
        {
            if (row[i] != target[i])
            {
                return false;
            }
        }
        return true;
    }

    void generatePermutations(vector<vector<int>> &result, vector<int> &permute, int idx)
    {
        if (idx == permute.size())
        {
            result.push_back(permute);
            return;
        }
        for (int i = idx; i < permute.size(); ++i)
        {
            swap(permute[idx], permute[i]);
            generatePermutations(result, permute, idx + 1);
            swap(permute[idx], permute[i]); // Backtrack
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        vector<vector<int>> permutations;
        vector<int> sortedNums(nums);

        // Sort the array to generate permutations in lexicographical order
        sort(sortedNums.begin(), sortedNums.end());
        generatePermutations(permutations, sortedNums, 0);

        sort(permutations.begin(), permutations.end());

        // Debugging output: Display all permutations
        cout << "Generated permutations: " << endl;
        for (const auto &row : permutations)
        {
            for (const auto &val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }

        // Find the index of the current permutation
        int currentIndex = -1;
        for (int i = 0; i < permutations.size(); ++i)
        {
            if (isRowMatch(permutations[i], nums))
            {
                currentIndex = i;
                break;
            }
        }

        // Get the next permutation
        int nextIndex = (currentIndex + 1) % permutations.size(); // Wrap around to the first permutation
        nums = permutations[nextIndex];

        cout << "Next permutation index: " << nextIndex << endl;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 5};
    s.nextPermutation(nums);

    cout << "Next permutation: ";
    for (const auto &x : nums)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
