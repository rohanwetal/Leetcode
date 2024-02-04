#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> ans;

        for (int i = 1; i <= n; ++i) {
            std::string s;
            if (i % 3 == 0)
                s += "Fizz";
            if (i % 5 == 0)
                s += "Buzz";
            ans.push_back(s.empty() ? std::to_string(i) : s);
        }

        return ans;
    }
};
