#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> stk;
        std::stringstream ss(path);
        std::string token;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty or current directory ("./") tokens
                continue;
            } else if (token == "..") {
                // Go up one directory (if possible)
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                // Push the valid directory or file name
                stk.push(token);
            }
        }

        // Construct the simplified path
        std::string simplifiedPath;
        while (!stk.empty()) {
            simplifiedPath = "/" + stk.top() + simplifiedPath;
            stk.pop();
        }

        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};

int main() {
    Solution solution;
    std::string path;

    // Test cases
    path = "/home/../usr//bin/./";
    std::cout << "Simplified Path: " << solution.simplifyPath(path) << std::endl;

    path = "/a/./b/../../c/";
    std::cout << "Simplified Path: " << solution.simplifyPath(path) << std::endl;

    path = "/../";
    std::cout << "Simplified Path: " << solution.simplifyPath(path) << std::endl;

    path = "/home//foo/";
    std::cout << "Simplified Path: " << solution.simplifyPath(path) << std::endl;

    return 0;
}
