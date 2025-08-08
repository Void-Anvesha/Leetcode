class Solution {
public:
    int height(TreeNode* root, bool& valid) {
        if (root == nullptr) return 0;

        int lh = height(root->left, valid);
        int rh = height(root->right, valid);

        if (abs(lh - rh) > 1) valid = false;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        bool valid = true;
        height(root, valid);
        return valid;
    }
};
