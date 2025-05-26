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
   bool findSum(TreeNode* root,int currSum,int targetSum)
   {
       if(root==NULL) return false;

       currSum+=root->val;

       if(root->left==NULL && root->right==NULL)
       {
        return currSum==targetSum;
       }

       return findSum(root->left,currSum,targetSum) ||
              findSum(root->right,currSum,targetSum);
   }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return findSum(root,0,targetSum);
    }
};