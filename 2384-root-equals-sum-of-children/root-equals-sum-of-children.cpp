/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root == NULL)return true;
        //If both are null return true
        if(root->left == NULL && root->right == NULL)return true;

        int leftVal = 0, rightVal = 0;
        if(root->left) leftVal = root->left->val;
        if(root->right) rightVal = root->right->val;

        if(leftVal + rightVal != root->val)return false;
        //Check for subtrees
        return checkTree(root->left) && checkTree(root->right);


    }
};