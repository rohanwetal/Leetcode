#include <vector> 

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        preorder(root, ans);
        return ans;
    }

private:
    void preorder(TreeNode* root, std::vector<int>& ans) {
        if (root == nullptr)
            return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};
