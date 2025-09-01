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
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;

        int leftData=(root->left!=NULL)?root->left->val:0;
        int rightData=(root->right!=NULL)?root->right->val:0;

        return (root->val==(root->left->val+root->right->val))&&
               checkTree(root->left) &&
               checkTree(root->right);
               
    }
};