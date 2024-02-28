#include <iostream> 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int ans = 0;
    int m = 0;
    
    void pre(TreeNode* root, int val) {
        if (!root) return; 
        if (m < val) {
            m = val;
            ans = root->val;
        }
        if (root->left) pre(root->left, val + 1);
        if (root->right) pre(root->right, val + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return -1; 
        if (!root->left && !root->right) return root->val; 
        pre(root, 0);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution sol;
    std::cout << "Bottom left value: " << sol.findBottomLeftValue(root) << std::endl;
    return 0;
}
