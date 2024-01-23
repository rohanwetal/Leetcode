#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

private:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
};
