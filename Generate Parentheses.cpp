#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, n, "", ans);
        return ans;
    }

private:
    void dfs(int l, int r, string path, vector<string>& ans) {
        if (l == 0 && r == 0) {
            ans.push_back(path);
            return;
        }

        if (l > 0) {
            dfs(l - 1, r, path + '(', ans);
        }
        if (l < r) {
            dfs(l, r - 1, path + ')', ans);
        }
    }
};
