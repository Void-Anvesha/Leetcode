/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both are null, so they are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Base case 2: One is null and the other is not, so they are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Check if current nodes have the same value AND
        // if their left subtrees are the same AND
        // if their right subtrees are the same
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};