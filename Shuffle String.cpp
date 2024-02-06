#include <string> 
#include <vector> 

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string ans(s.length(), '.');

        for (int i = 0; i < indices.size(); ++i)
            ans[indices[i]] = s[i];

        return ans;
    }
};
