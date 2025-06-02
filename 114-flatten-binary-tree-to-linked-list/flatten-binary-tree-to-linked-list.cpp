class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                TreeNode* prev = curr->left;
                // Find the rightmost node in the left subtree
                while (prev->right != NULL) {
                    prev = prev->right;
                }
                // Connect right subtree to the rightmost node of left subtree
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;  
            }
            curr = curr->right;
        }
    }
};
