#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::string removeChars(std::string string1, std::string string2) {
        std::string result;
        std::unordered_set<char> charsToRemove(string2.begin(), string2.end());
    
        for (char ch : string1) {
            if (charsToRemove.find(ch) == charsToRemove.end()) {
                result += ch;  // Add to result if not in charsToRemove
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;

    // Test case
    std::string string1 = "geeksforgeeks";
    std::string string2 = "mask";

    std::string result = solution.removeChars(string1, string2);
    std::cout << "Resulting string after removing characters: " << result << std::endl;  // Expected output: "geeforgee"

    return 0;
}
